//
// Created by chris on 21-Apr-18.
//

#ifndef POO_TEMA3_3_AUTOSHOP_H
#define POO_TEMA3_3_AUTOSHOP_H

#include <memory>
#include "Vehicles/vehicle.h"

namespace automoto {
//singleton
    class AutoShop {
    private:
        std::unique_ptr<AutoShop> mShopPtr;

        AutoShop() = default;

    public:
        AutoShop &getInstance() {
            if (mShopPtr == nullptr) {
                mShopPtr = new AutoShop;
            }

            return *mShopPtr;
        }

        //returns cost of repairs
        int assessDamage(const Vehicle &vehicle) const {

        }

        //repairs a vehicle
        void repair(Vehicle &vehicle) const {

        }

    };
}

#endif //POO_TEMA3_3_AUTOSHOP_H
