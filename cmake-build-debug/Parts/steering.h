//
// Created by chris on 21-Apr-18.
//

#ifndef POO_TEMA3_3_STEERING_H
#define POO_TEMA3_3_STEERING_H

#include "partset.h"

namespace automoto {
    class Steering {
        friend class AutoShop;
    private:
        DamageLevel mWheelBend;
        bool mKaput;



    protected:
        Steering() {
            mKaput = false;
            mWheelBend = NONE;
        }

        explicit Steering(bool kaput) {
            mKaput = kaput;
            mWheelBend = TOTAL;
        }
    };

    class TwoWheelSteering : public Steering {
        DamageLevel mHandleBend;

        TwoWheelSteering() : Steering() {
            mHandleBend = NONE;
        }

        explicit TwoWheelSteering(bool kaput) : Steering(kaput) {
            mHandleBend = TOTAL;
        }
    };

    class FourWheelSteering : public Steering {

    };
}

#endif //POO_TEMA3_3_STEERING_H
