//
// Created by chris on 21-Apr-18.
//

#ifndef POO_TEMA3_3_TWOWHEELVEHICLE_H
#define POO_TEMA3_3_TWOWHEELVEHICLE_H

#include "vehicle.h"
#include "../Parts/brake.h"

namespace automoto {
    class TwoWheelVehicle : virtual public Vehicle{

    public:
        TwoWheelVehicle() {
            parts.emplace_back(std::make_shared<TwoWheelBody>(TwoWheelBody()));
            parts.emplace_back(std::make_shared<TwoWheelSteering>(TwoWheelSteering()));
        }
    };
}

#endif //POO_TEMA3_3_TWOWHEELVEHICLE_H
