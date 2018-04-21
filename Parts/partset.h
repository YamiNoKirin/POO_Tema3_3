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

    enum Material {
        SCREW,
        METAL,
        PLASTIC
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

        PartSet(int screw, int metal, int plastic) {
            mScrew = screw;
            mMetal = metal;
            mPlastic = plastic;
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
    const PartSet HOPELESS = PartSet(-1, -1, -1);

    void AddMaterial(const DamageLevel &component, PartSet &partSet, const Material &material, const int &partialAdd,
                     const int &totalAdd) {

        int toAdd = 0;
        switch (component) {
            case NONE:
                break;
            case PARTIAL:
                toAdd = partialAdd;
                break;
            case TOTAL:
                toAdd = totalAdd;
                break;
        }

        switch (material) {
            case SCREW:
                partSet.addScrew(toAdd);
                break;
            case METAL:
                partSet.addMetal(toAdd);
                break;
            case PLASTIC:
                partSet.addPlastic(toAdd);
                break;
        }
    }

    void DamageComponent(DamageLevel &component) {
        int rand3 = rand() % 3;
        switch (rand3) {
            case 0:
                break;
            case 1:
                if (component == NONE) {
                    component = PARTIAL;
                }

                break;
            case 2:
                component = TOTAL;
        }

    }
}


#endif //POO_TEMA3_3_AUTO_CONSTANTS_H
