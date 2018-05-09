#include <iostream>
#include "Vehicles/bicycle.h"
#include "Vehicles/motorcycle.h"
#include "Vehicles/automobile.h"
#include "autoshop.h"

int main() {
    automoto::AutoShop shop = automoto::AutoShop::getInstance();

    automoto::Motorcycle motorcycle;
    automoto::Automobile automobile;
    automoto::Bicycle bicycle;

    std::cout << "Dmg before, moto: " << shop.assessDamage(motorcycle) << '\n';
    std::cout << "Dmg before, car: " << shop.assessDamage(automobile) << '\n';
    std::cout << "Dmg before, bike: " << shop.assessDamage(bicycle) << '\n';
    std::cout << '\n';

    const int DamageCnt = 1000;
    for (int i = 0; i < DamageCnt; ++i) {
        motorcycle.damage();
        automobile.damage();
        bicycle.damage();
    }

    std::cout << "Dmg after damage, moto: " << shop.assessDamage(motorcycle) << '\n';
    shop.repair(motorcycle);
    std::cout << "Dmg after fix, moto: " << shop.assessDamage(motorcycle) << '\n';
    std::cout << '\n';

    std::cout << "Dmg after damage, car: " << shop.assessDamage(automobile) << '\n';
    shop.repair(automobile);
    std::cout << "Dmg after fix, car: " << shop.assessDamage(automobile) << '\n';
    std::cout << '\n';

    std::cout << "Dmg after damage, bike: " << shop.assessDamage(bicycle) << '\n';
    shop.repair(bicycle);
    std::cout << "Dmg after fix, bike: " << shop.assessDamage(bicycle) << '\n';
    std::cout << '\n';

    return 0;
}