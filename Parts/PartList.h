//
// Created by chris on 22-Apr-18.
//

#ifndef POO_TEMA3_3_PARTLIST_H
#define POO_TEMA3_3_PARTLIST_H

#include <memory>

namespace automoto {
    class Part {
    public:
        virtual PartSet getMissing() const = 0;
        virtual void damage() = 0;
        virtual void repair() = 0;
    };

    using PartPtr = std::shared_ptr<Part>;
    using PartVector = std::vector<PartPtr>;
}

#endif //POO_TEMA3_3_PARTLIST_H
