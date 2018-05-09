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
        static std::unique_ptr<AutoShop> mShopPtr;

        AutoShop() = default;

    public:
        static AutoShop &getInstance() {
            if (AutoShop::mShopPtr == nullptr) {
                AutoShop::mShopPtr = std::make_unique<AutoShop>(AutoShop());
            }

            return *AutoShop::mShopPtr;
        }

        //returns cost of repairs
        int assessDamage(const Vehicle &vehicle) const {
            PartSet missing = vehicle.getMissing();
            return missing.getCost();
        }

        //repairs a vehicle
        void repair(Vehicle &vehicle) const {
            std::for_each(vehicle.parts.begin(), vehicle.parts.end(), [](PartPtr p) {
                p->repair();
            });
        }

    };

    std::unique_ptr<AutoShop> AutoShop::mShopPtr = nullptr;
}

#endif //POO_TEMA3_3_AUTOSHOP_H
