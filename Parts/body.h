//
// Created by chris on 21-Apr-18.
//

#ifndef POO_TEMA3_3_BODY_H
#define POO_TEMA3_3_BODY_H

#include <vector>
#include <algorithm>
#include "partset.h"

namespace automoto {
    class Body : public Part{
        friend class AutoShop;

    protected:
        DamageLevel mCorrosion;
        std::vector<DamageLevel> mBend;
        //front, back, left, right, hood, fender
        explicit Body(int n) {
            mCorrosion = NONE;
            mBend.assign(n, NONE);
        }

        explicit Body(DamageLevel corrosion) {
            mCorrosion = corrosion;
        }

        Body(int n, DamageLevel corrosion) {
            mCorrosion = corrosion;
            mBend.assign(n, NONE);
        }

        virtual PartSet getMissing() const override {
            PartSet missing = getMissingForCorrosion();
            missing += getMissingForBend();
            return missing;
        };

        virtual PartSet getMissingForCorrosion() const = 0;
        virtual PartSet getMissingForBend() const = 0;

    public:
        void damage() override {
            DamageComponent(mCorrosion);

            std::for_each(mBend.begin(), mBend.end(), [](DamageLevel &bend) {
                DamageComponent(bend);
            });
        }

        virtual void repair() {
            mCorrosion = NONE;
            std::for_each(mBend.begin(), mBend.end(), [](DamageLevel &bend) {
                bend = NONE;
            });
        }
    };

    class FourWheelBody : public Body {
        static const int PartialBendMetal;
        static const int TotalBendMetal;
        static const int PartialBendScrews;
        static const int TotalBendScrews;
        static const int PartialCorrodeScrews;
        static const int TotalCorrodeScrews;
        static const int PartialCorrodeMetal;
        static const int TotalCorrodeMetal;

    private:
        PartSet getMissingForBend() const override {
            PartSet partSet;
            std::for_each(Body::mBend.begin(), Body::mBend.end(), [&partSet](const DamageLevel &bend) {
                AddMaterial(bend, partSet, METAL, PartialBendMetal, TotalBendMetal);
                AddMaterial(bend, partSet, SCREW, PartialBendScrews, TotalBendScrews);
            });

            return partSet;
        }

        PartSet getMissingForCorrosion() const override {
            PartSet partSet;

            AddMaterial(Body::mCorrosion, partSet, METAL, PartialCorrodeMetal, TotalCorrodeMetal);
            AddMaterial(Body::mCorrosion, partSet, SCREW, PartialCorrodeScrews, TotalCorrodeScrews);

            return partSet;
        }

    public:

        FourWheelBody() : Body(6) {}

        explicit FourWheelBody(DamageLevel corrosion) : Body(6, corrosion) {}
    };

    const int FourWheelBody::PartialBendMetal = 10;
    const int FourWheelBody::TotalBendMetal = 20;
    const int FourWheelBody::PartialCorrodeMetal = 5;
    const int FourWheelBody::TotalCorrodeMetal = 10;
    const int FourWheelBody::PartialBendScrews = 50;
    const int FourWheelBody::TotalBendScrews = 100;
    const int FourWheelBody::PartialCorrodeScrews = 30;
    const int FourWheelBody::TotalCorrodeScrews = 60;

    class TwoWheelBody : public Body {
        friend class AutoShop;

        static const int PartialBendMetal;
        static const int TotalBendMetal;
        static const int PartialCorrodeMetal;
        static const int TotalCorrodeMetal;
        static const int PartialBendScrews;
        static const int TotalBendScrews;
        static const int PartialCorrodeScrews;
        static const int TotalCorrodeScrews;

    private:
        PartSet getMissingForBend() const override {
            PartSet partSet;
            std::for_each(mBend.begin(), mBend.end(), [&partSet](const DamageLevel &bend) {
                AddMaterial(bend, partSet, METAL, PartialBendMetal, TotalBendMetal);
                AddMaterial(bend, partSet, SCREW, PartialBendScrews, TotalBendScrews);
            });

            return partSet;
        }

        PartSet getMissingForCorrosion() const override {
            PartSet partSet;

            AddMaterial(Body::mCorrosion, partSet, METAL, PartialCorrodeMetal, TotalCorrodeMetal);
            AddMaterial(Body::mCorrosion, partSet, SCREW, PartialCorrodeScrews, TotalCorrodeScrews);

            return partSet;
        }

    public:
        TwoWheelBody() : Body(2) {}

        explicit TwoWheelBody(DamageLevel corrosion) : Body(2, corrosion) {}
    };

    const int TwoWheelBody::PartialBendMetal = 5;
    const int TwoWheelBody::TotalBendMetal = 10;
    const int TwoWheelBody::PartialCorrodeMetal = 3;
    const int TwoWheelBody::TotalCorrodeMetal = 5;
    const int TwoWheelBody::PartialBendScrews = 50;
    const int TwoWheelBody::TotalBendScrews = 100;
    const int TwoWheelBody::PartialCorrodeScrews = 30;
    const int TwoWheelBody::TotalCorrodeScrews = 60;
}

#endif //POO_TEMA3_3_BODY_H
