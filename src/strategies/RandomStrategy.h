#pragma once

#include "../util/Random.h"
#include "GameStrategy.h"

namespace game {

class RandomStrategy : public GameStrategy
{
public:
    Move *pick(const std::vector<Move *> choices) const override
    {
        auto it = choices.begin();
        std::advance(it, util::Random::rand(choices.size()));
        return *it;
    }
};

} // namespace game
