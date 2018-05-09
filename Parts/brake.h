//
// Created by chris on 21-Apr-18.
//

#ifndef POO_TEMA3_3_BRAKE_H
#define POO_TEMA3_3_BRAKE_H

#include <vector>
#include <algorithm>
#include "partset.h"
#include "PartList.h"

namespace automoto {
    class Brake : public Part{
    protected:
        std::vector<DamageLevel> mShoe;
        std::vector<DamageLevel> mDisk;
        bool mKaput;

        Brake() {
            mKaput = false;
        }

        Brake(int n, int m, bool kaput) {
            mShoe.assign(n, NONE);
            mShoe.assign(m, NONE);
            mKaput = kaput;
        }

    public:
        static const int PartialShoeScrews;
        static const int TotalShoeScrews;
        static const int PartialShoePlastic;
        static const int TotalShoePlastic;
        static const int PartialDiskScrews;
        static const int TotalDiskScrews;

        void damage() override {
            std::for_each(mDisk.begin(), mDisk.end(), [](DamageLevel &disk) {
                DamageComponent(disk);
            });

            std::for_each(mShoe.begin(), mShoe.end(), [](DamageLevel &shoe) {
                DamageComponent(shoe);
            });
        }

        PartSet getMissing() const override {
            if (mKaput) {
                return PartSet::HOPELESS;
            }

            PartSet partSet = getMissingForShoe();
            partSet += getMissingForDisk();

            return partSet;
        }

        PartSet getMissingForShoe() const {
            if (mKaput) {
                return PartSet::HOPELESS;
            }

            PartSet partSet;
            std::for_each(mShoe.begin(), mShoe.end(), [&partSet](const DamageLevel &shoe) {
                AddMaterial(shoe, partSet, SCREW, PartialShoeScrews, TotalShoeScrews);
                AddMaterial(shoe, partSet, PLASTIC, PartialShoePlastic, TotalShoePlastic);
            });

            return partSet;
        }

        PartSet getMissingForDisk() const {
            if (mKaput) {
                return PartSet::HOPELESS;
            }

            PartSet partSet;
            std::for_each(mDisk.begin(), mDisk.end(), [&partSet](const DamageLevel &disk) {
                AddMaterial(disk, partSet, SCREW, PartialDiskScrews, TotalDiskScrews);
            });

            return partSet;
        }

        virtual void repair() {
            std::for_each(mDisk.begin(), mDisk.end(), [](DamageLevel &disk) {
                disk = NONE;
            });

            std::for_each(mShoe.begin(), mShoe.end(), [](DamageLevel &shoe) {
                shoe = NONE;
            });
        }
    };

    const int Brake::PartialShoeScrews = 5;
    const int Brake::TotalShoeScrews = 10;
    const int Brake::PartialShoePlastic = 50;
    const int Brake::TotalShoePlastic = 100;
    const int Brake::PartialDiskScrews = 20;
    const int Brake::TotalDiskScrews = 30;


    class MotorBrake : public Brake {
    public:
        MotorBrake() = default;

        MotorBrake(int n, int m, bool kaput) : Brake(n, m, kaput) {}

    };

    class MotorlessBrake : public Brake {
    private:
        static const int PartialChainScrews;
        static const int TotalChainScrews;
        static const int PartialChainMetal;
        static const int TotalChainMetal;

        DamageLevel mChain;
    public:
        MotorlessBrake() {
             mChain = NONE;
        }

        MotorlessBrake(int n, int m, DamageLevel k, bool kaput) : Brake(n, m, kaput) {
            mChain = k;
        }

        void damage() override {
            Brake::damage();
            DamageComponent(mChain);
        }

        PartSet getMissing() const override {
            if (mKaput) {
                return PartSet::HOPELESS;
            }

            PartSet partSet = Brake::getMissing();
            partSet += getMissingForChain();

            return partSet;
        }

        PartSet getMissingForChain() const {
            PartSet partSet;
            AddMaterial(mChain, partSet, SCREW, PartialChainScrews, TotalChainScrews);
            AddMaterial(mChain, partSet, METAL, PartialChainMetal, TotalChainMetal);

            return partSet;
        }

        void repair() override {
            Brake::repair();
            mChain = NONE;
        }
    };

    const int MotorlessBrake::PartialChainScrews = 5;
    const int MotorlessBrake::TotalChainScrews = 10;
    const int MotorlessBrake::PartialChainMetal = 20;
    const int MotorlessBrake::TotalChainMetal = 40;
}

#endif //POO_TEMA3_3_BRAKE_H
