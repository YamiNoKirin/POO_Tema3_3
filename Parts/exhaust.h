//
// Created by chris on 21-Apr-18.
//

#ifndef POO_TEMA3_3_POLLUTION_H
#define POO_TEMA3_3_POLLUTION_H

#include <cstdlib>
#include <algorithm>
#include "partset.h"

namespace automoto {
    class Exhaust {
        static const int BurnsOilPlastic;
        static const int BurnsOilScrews;

    private:
        bool mIsOld;
        bool mBurnsOil;

    public:
        Exhaust() {
            mBurnsOil = false;
            mIsOld = false;
        }

        Exhaust(bool burnsOil, bool isOld) {
            mBurnsOil = burnsOil;
            mIsOld = isOld;
        }

        void damage() {
            mBurnsOil = (bool) std::max((int) mBurnsOil, rand() % 2);
        }

        PartSet getMissing() {
            PartSet partSet;
            if (mBurnsOil) {
                partSet.addPlastic(BurnsOilPlastic);
                partSet.addScrew(BurnsOilScrews);
            }

            return partSet;
        }
    };

    const int Exhaust::BurnsOilPlastic = 20;
    const int Exhaust::BurnsOilScrews = 50;
}

#endif //POO_TEMA3_3_POLLUTION_H
