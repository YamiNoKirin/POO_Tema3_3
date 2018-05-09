//
// Created by chris on 21-Apr-18.
//

#ifndef POO_TEMA3_3_FOURWHEELVEHICLE_H
#define POO_TEMA3_3_FOURWHEELVEHICLE_H

#include "vehicle.h"

namespace automoto {
    class FourWheelVehicle : virtual public Vehicle {

    public:
        FourWheelVehicle() {
            parts.emplace_back(std::make_shared<FourWheelBody>(FourWheelBody()));
            parts.emplace_back(std::make_shared<FourWheelSteering>(FourWheelSteering()));
        }
    };
}

#endif //POO_TEMA3_3_FOURWHEELVEHICLE_H
