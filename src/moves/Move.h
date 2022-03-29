#pragma once

#include "../Winner.h"

namespace game {

class Move
{
public:
    Move(std::string_view name) : name(name) {}

    virtual ~Move() = default;

    virtual Move *beats(Move *) = 0;

    std::string_view name;
};

} // namespace game