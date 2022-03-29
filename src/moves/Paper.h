#pragma once

#include "Move.h"

namespace game {

class Paper : public Move
{
public:
    Paper() : Move("Paper") {}

    Move *beats(Move *move) override
    {
        if (this == move) return nullptr;
        if (move->name == "Rock") return this;
        return move;
    }
};

} // namespace game