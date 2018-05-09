//
// Created by chris on 21-Apr-18.
//

#ifndef POO_TEMA3_3_MOTORVEHICLE_H
#define POO_TEMA3_3_MOTORVEHICLE_H

#include "vehicle.h"
#include "../Parts/engine.h"
#include "../Parts/exhaust.h"

namespace automoto {
    class MotorVehicle : virtual public Vehicle{
    public:
        MotorVehicle() {
            parts.emplace_back(std::make_shared<Exhaust>(Exhaust()));
        }
    };
}

#endif //POO_TEMA3_3_MOTORVEHICLE_H
