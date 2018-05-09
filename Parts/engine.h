//
// Created by chris on 21-Apr-18.
//

#ifndef POO_TEMA3_3_ENGINE_H
#define POO_TEMA3_3_ENGINE_H

#include <cstdlib>
#include <ntdef.h>
#include <algorithm>
#include "partset.h"
#include "PartList.h"

namespace automoto {
    class Engine : public Part {
    protected:
        bool mLowOil;
        bool mMelted;

        Engine() {
            mLowOil = false;
            mMelted = false;
        }

        Engine(bool lowOil, bool melted) {
            mLowOil = lowOil;
            mMelted = melted;
        }

        void damage() override {
            mLowOil = true;
            mMelted = (bool) std::max((int) mMelted, rand() % 2);
        }

        void repair() override {
            mLowOil = false;
        };
    };

    class MotoEngine: public Engine {
        static const int LowOilScrews;

    public:
        MotoEngine() : Engine() {}

        MotoEngine(bool lowOil, bool melted) : Engine(lowOil, melted) {}

        PartSet getMissing() const override {
            PartSet partSet;
            if (Engine::mMelted) {
                return PartSet::HOPELESS;
            }

            if (mLowOil) {
                partSet.addScrew(LowOilScrews);
            }

            return partSet;
        }
    };

    const int MotoEngine::LowOilScrews = 5;

    class CarEngine : public Engine {
        static const int LowOilScrews;
        static const int DirtyCarburatorScrews;

    private:
        bool mDirtyCarburator;

    public:
        CarEngine() : Engine() {
            mDirtyCarburator = false;
        }

        CarEngine(bool lowOil, bool melted, bool dirtyCarburator) : Engine(lowOil, melted) {
            mDirtyCarburator = dirtyCarburator;
        }

        PartSet getMissing() const override {
            PartSet partSet;

            if (mMelted) {
                return PartSet::HOPELESS;
            }

            if (mLowOil) {
                partSet.addScrew(LowOilScrews);
            }

            if (mDirtyCarburator) {
                partSet.addScrew(DirtyCarburatorScrews);
            }

            return partSet;
        }

        void repair() override {
            Engine::repair();
            mDirtyCarburator = false;
        }
    };

    const int CarEngine::LowOilScrews = 10;
    const int CarEngine::DirtyCarburatorScrews = 30;
}
#endif //POO_TEMA3_3_ENGINE_H
