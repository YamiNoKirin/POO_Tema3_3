//
// Created by chris on 21-Apr-18.
//

#ifndef POO_TEMA3_3_VEHICLE_H
#define POO_TEMA3_3_VEHICLE_H

#include <cstdlib>
#include "Parts/steering.h"
#include "Parts/body.h"

namespace automoto {
//interface
    class Vehicle {
        Steering steering;

        void damage() {
//            steering.damage();
        }

        PartSet getMissing() {

        }

        //possibility of a crash
        void use() {
            int safeChance = rand() % 1000;

            //0.1% chance of crash
            if (safeChance == 0) {
                damage();
            }
        };
    };
}
#endif //POO_TEMA3_3_VEHICLE_H
