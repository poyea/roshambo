#pragma once

#include "../moves/Move.h"

namespace game {

class GameStrategy
{
public:
    virtual ~GameStrategy() = default;
    virtual Move *pick(const std::vector<Move *> choices) const = 0;
};

} // namespace game
