//
// Created by chris on 02-May-18.
//

#ifndef POO_TEMA3_3_BICYCLE_H
#define POO_TEMA3_3_BICYCLE_H

#include "motorlessvehicle.h"
#include "twowheelvehicle.h"

namespace automoto {
    class Bicycle : public TwoWheelVehicle, public MotorlessVehicle {

    public:
        Bicycle() {
            parts.emplace_back(std::make_shared<MotorlessBrake>(MotorlessBrake()));
            parts.emplace_back(std::make_shared<MotorlessBrake>(MotorlessBrake()));
        }
    };
}

#endif //POO_TEMA3_3_BICYCLE_H
