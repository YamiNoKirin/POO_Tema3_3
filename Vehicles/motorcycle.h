//
// Created by chris on 02-May-18.
//

#ifndef POO_TEMA3_3_MOTORCYCLE_H
#define POO_TEMA3_3_MOTORCYCLE_H

#include "twowheelvehicle.h"
#include "motorvehicle.h"

namespace automoto {
    class Motorcycle : public MotorVehicle, public TwoWheelVehicle {

    public:
        Motorcycle() {
            parts.emplace_back(std::make_shared<MotoEngine>(MotoEngine()));
            parts.emplace_back(std::make_shared<MotorBrake>(MotorBrake()));
            parts.emplace_back(std::make_shared<MotorBrake>(MotorBrake()));
        }
    };
}

#endif //POO_TEMA3_3_MOTORCYCLE_H
