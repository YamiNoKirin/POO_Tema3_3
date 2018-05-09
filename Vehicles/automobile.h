//
// Created by chris on 02-May-18.
//

#ifndef POO_TEMA3_3_AUTOMOBILE_H
#define POO_TEMA3_3_AUTOMOBILE_H

#include "fourwheelvehicle.h"
#include "motorvehicle.h"

namespace automoto {
    class Automobile : public MotorVehicle, public FourWheelVehicle{
    public:

        Automobile() {
            parts.emplace_back(std::make_shared<CarEngine>(CarEngine()));
            parts.emplace_back(std::make_shared<MotorBrake>(MotorBrake()));
            parts.emplace_back(std::make_shared<MotorBrake>(MotorBrake()));
            parts.emplace_back(std::make_shared<MotorBrake>(MotorBrake()));
            parts.emplace_back(std::make_shared<MotorBrake>(MotorBrake()));
        }
    };
}

#endif //POO_TEMA3_3_AUTOMOBILE_H
