#pragma once

#include <iostream>
#include <string_view>
#include <unordered_map>

#include "moves/Move.h"
#include "moves/Paper.h"
#include "moves/Rock.h"
#include "moves/Scissors.h"

namespace game {

class GestureTable
{
public:
    GestureTable(Rock *r, Paper *p, Scissors *s)
    {
        m_table["fist"] = r;
        m_table["openhand"] = p;
        m_table["fingers"] = s;
    }

    Move *get_by_gesture(std::string_view gesture) { return m_table[gesture]; }

    bool valid(std::string_view gesture) { return m_table.contains(gesture); }

private:
    std::unordered_map<std::string_view, Move *> m_table;
};

} // namespace game