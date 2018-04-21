//
// Created by chris on 21-Apr-18.
//

#ifndef POO_TEMA3_3_AUTO_CONSTANTS_H
#define POO_TEMA3_3_AUTO_CONSTANTS_H

namespace automoto {
    enum DamageLevel {
        NONE,
        PARTIAL,
        TOTAL
    };

    class PartSet {
        static const int screwCost;
        static const int metalCost;
        static const int plasticCost;

    private:
        int mScrew;
        int mMetal;
        int mPlastic;

    public:
        PartSet() {
            mScrew = 0;
            mMetal = 0;
            mPlastic = 0;
        }

        void addScrew(int n) {
            ++mScrew;
        }

        void addMetal(int n) {
            ++mMetal;
        }

        void addPlastic(int n) {
            ++mPlastic;
        }

        int getCost() {
            return mScrew * screwCost + mMetal * metalCost + mPlastic * plasticCost;
        }

        PartSet &operator+=(const PartSet &other) {
            mScrew += other.mScrew;
            mMetal += other.mMetal;
            mPlastic += other.mPlastic;
            return *this;
        }
    };

    const int PartSet::screwCost = 1;
    const int PartSet::metalCost = 20;
    const int PartSet::plasticCost = 5;
}


#endif //POO_TEMA3_3_AUTO_CONSTANTS_H
