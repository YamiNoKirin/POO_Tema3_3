//
// Created by chris on 21-Apr-18.
//

#ifndef POO_TEMA3_3_STEERING_H
#define POO_TEMA3_3_STEERING_H

#include <vector>
#include <algorithm>
#include "partset.h"

namespace automoto {
    class Steering {
        friend class AutoShop;

    protected:
        static const int PartialWheelBendScrews;
        static const int TotalWheelBendScrews;
        static const int PartialWheelBendMetal;
        static const int TotalWheelBendMetal;

        std::vector<DamageLevel> mWheelBend;
        bool mKaput;

        Steering() {
            mKaput = false;
        }

        explicit Steering(bool kaput) {
            mKaput = kaput;
        }

    public:
        virtual void damage() {
            std::for_each(mWheelBend.begin(), mWheelBend.end(), [](DamageLevel &wheel) {
                DamageComponent(wheel);
            });
        }

        virtual PartSet getMissing() = 0;

        void kaputify() {
            mKaput = true;
        }
    };

    const int Steering::PartialWheelBendMetal = 10;
    const int Steering::TotalWheelBendMetal = 20;
    const int Steering::PartialWheelBendScrews = 20;
    const int Steering::TotalWheelBendScrews = 40;

    class TwoWheelSteering : public Steering {
        static const int PartialHandleBendScrews;
        static const int TotalHandleBendScrews;
        static const int PartialHandleBendMetal;
        static const int TotalHandleBendMetal;

        DamageLevel mHandleBend;

    public:
        TwoWheelSteering() : Steering() {
            mHandleBend = NONE;
            Steering::mWheelBend.assign(2, NONE);
        }

        explicit TwoWheelSteering(bool kaput) : Steering(kaput) {
            if (kaput) {
                mHandleBend = TOTAL;
                Steering::mWheelBend.assign(2, TOTAL);
            }
            else {
                mHandleBend = NONE;
                Steering::mWheelBend.assign(2, NONE);
            }
        }

        void damage() override {
            Steering::damage();
            DamageComponent(mHandleBend);
        }

        PartSet getMissing() override {
            if (mKaput) {
                return HOPELESS;
            }

            PartSet partSet;
            AddMaterial(mHandleBend, partSet, SCREW, PartialHandleBendScrews, TotalHandleBendScrews);
            AddMaterial(mHandleBend, partSet, METAL, PartialHandleBendMetal, TotalHandleBendMetal);
        }
    };

    const int TwoWheelSteering::PartialHandleBendScrews = 5;
    const int TwoWheelSteering::TotalHandleBendScrews = 10;
    const int TwoWheelSteering::PartialHandleBendMetal = 30;
    const int TwoWheelSteering::TotalHandleBendMetal = 60;

    class FourWheelSteering : public Steering {
    public:
        FourWheelSteering() : Steering() {
            mWheelBend.assign(4, NONE);
        }

        explicit FourWheelSteering(bool kaput) : Steering(kaput) {
            if (kaput) {
                mWheelBend.assign(4, TOTAL);
            }
            else {
                mWheelBend.assign(4, NONE);
            }
        }

        PartSet getMissing() override {
            if (mKaput) {
                return HOPELESS;
            }

            PartSet partSet;
            std::for_each(mWheelBend.begin(), mWheelBend.end(), [&partSet](const DamageLevel &bend) {
                AddMaterial(bend, partSet, SCREW, Steering::PartialWheelBendScrews, Steering::TotalWheelBendScrews);
                AddMaterial(bend, partSet, METAL, Steering::PartialWheelBendMetal, Steering::TotalWheelBendMetal);
            });

            return partSet;
        }
    };
}

#endif //POO_TEMA3_3_STEERING_H
