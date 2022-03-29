#pragma once

#include <array>
#include <iostream>

namespace game {

enum class Winner { TIE, AI, PLAYER };

inline std::ostream &operator<<(std::ostream &out, const Winner &winner)
{
    switch (winner) {
    case Winner::TIE:
        out << "Tie";
        break;
    case Winner::AI:
        out << "AI";
        break;
    case Winner::PLAYER:
        out << "Player";
        break;
    }
    return out;
}

} // namespace game