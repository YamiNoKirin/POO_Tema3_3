//
// Created by chris on 21-Apr-18.
//

#ifndef POO_TEMA3_3_BODY_H
#define POO_TEMA3_3_BODY_H

#include <vector>
#include <algorithm>
#include "partset.h"

namespace automoto {
    class Body {
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

        virtual PartSet getMissing() {
            PartSet missing = getMissingForCorrosion();
            missing += getMissingForBend();
            return missing;
        };

        virtual PartSet getMissingForCorrosion() = 0;
        virtual PartSet getMissingForBend() = 0;

    public:
        virtual void damage() {
                int rand3 = rand() % 3;
                switch (rand3) {
                    case 0:
                        mCorrosion = NONE;
                        break;
                    case 1:
                        mCorrosion = PARTIAL;
                        break;
                    case 2:
                        mCorrosion = TOTAL;
                }

                std::for_each(mBend.begin(), mBend.end(), [](DamageLevel &dmg) {
                    int rand3 = rand() % 3;
                    switch (rand3) {
                        case 0:
                            dmg = NONE;
                            break;
                        case 1:
                            dmg = PARTIAL;
                            break;
                        case 2:
                            dmg = TOTAL;
                    }
                });
            }
    };

    class FourWheelBody : public Body {
        friend class AutoShop;

        static const int PartialBendMetal;
        static const int TotalBendMetal;
        static const int PartialCorrodeMetal;
        static const int TotalCorrodeMetal;

    private:
        PartSet getMissingForBend() override {
            PartSet partSet;
            std::for_each(mBend.begin(), mBend.end(), [&partSet](const DamageLevel &dmg) {
                switch (dmg) {
                    case NONE:
                        break;
                    case PARTIAL:
                        partSet.addMetal(PartialBendMetal);
                        break;
                    case TOTAL:
                        partSet.addMetal(TotalBendMetal);
                }
            });

            return partSet;
        }

        PartSet getMissingForCorrosion() override {
            PartSet partSet;

            switch (Body::mCorrosion) {
                case NONE:
                    break;
                case PARTIAL:
                    partSet.addMetal(PartialCorrodeMetal);
                    break;
                case TOTAL:
                    partSet.addMetal(TotalCorrodeMetal);
                    break;
            }

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

    class TwoWheelBody : public Body {
        friend class AutoShop;

        static const int PartialBendMetal;
        static const int TotalBendMetal;
        static const int PartialCorrodeMetal;
        static const int TotalCorrodeMetal;

    private:
        PartSet getMissingForBend() override {
            PartSet partSet;
            std::for_each(mBend.begin(), mBend.end(), [&partSet](const DamageLevel &dmg) {
                switch (dmg) {
                    case NONE:
                        break;
                    case PARTIAL:
                        partSet.addMetal(PartialBendMetal);
                        break;
                    case TOTAL:
                        partSet.addMetal(TotalBendMetal);
                }
            });

            return partSet;
        }

        PartSet getMissingForCorrosion() override {
            PartSet partSet;

            switch (Body::mCorrosion) {
                case NONE:
                    break;
                case PARTIAL:
                    partSet.addMetal(PartialCorrodeMetal);
                    break;
                case TOTAL:
                    partSet.addMetal(TotalCorrodeMetal);
                    break;
            }

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
}

#endif //POO_TEMA3_3_BODY_H
