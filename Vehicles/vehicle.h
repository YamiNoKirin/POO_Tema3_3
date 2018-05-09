//
// Created by chris on 21-Apr-18.
//

#ifndef POO_TEMA3_3_VEHICLE_H
#define POO_TEMA3_3_VEHICLE_H

#include <cstdlib>
#include "../Parts/steering.h"
#include "../Parts/body.h"
#include "../Parts/PartList.h"

namespace automoto {
    class Vehicle {
        friend class AutoShop;

    protected:
        PartVector parts;

    public:
        void damage() {
            std::for_each(parts.begin(), parts.end(), [](PartPtr part) {
                part->damage();
            });
        };

        PartSet getMissing() const {
            PartSet partSet;
            std::for_each(parts.begin(), parts.end(), [&partSet](const PartPtr part) {
                partSet += part->getMissing();
            });

            return partSet;
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
