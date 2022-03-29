#pragma once

#include "Move.h"

namespace game {

class Scissors : public Move
{
public:
    Scissors() : Move("Scissors") {}

    Move *beats(Move *move) override
    {
        if (this == move) return nullptr;
        if (move->name == "Paper") return this;
        return move;
    }
};

} // namespace game