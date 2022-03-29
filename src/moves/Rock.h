#pragma once

#include "Move.h"

namespace game {

class Rock : public Move
{
public:
    Rock() : Move("Rock") {}

    Move *beats(Move *move) override
    {
        if (this == move) return nullptr;
        if (move->name == "Scissors") return this;
        return move;
    }
};

} // namespace game