//
// Created by chris on 21-Apr-18.
//

#ifndef POO_TEMA3_3_VEHICLE_H
#define POO_TEMA3_3_VEHICLE_H

#include <cstdlib>
#include "../Parts/steering.h"
#include "../Parts/body.h"

namespace automoto {
//interface
    class Vehicle {

    public:
        virtual void damage() = 0;

        PartSet getMissing() {

        }

        //possibility of getting damaged
        void use() {
            int safeChance = rand() % 10;

            //10% chance of getting damaged
            if (safeChance == 0) {
                damage();
            }
        };
    };
}
#endif //POO_TEMA3_3_VEHICLE_H
