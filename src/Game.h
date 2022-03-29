#pragma once

#include <array>
#include <memory>
#include <string_view>
#include <utility>
#include <vector>

#include "GestureTable.h"
#include "Winner.h"
#include "moves/Move.h"
#include "moves/Paper.h"
#include "moves/Rock.h"
#include "moves/Scissors.h"
#include "strategies/GameStrategy.h"
#include "util/Random.h"

namespace game {

class Game
{
public:
    Game(GameStrategy *strat = nullptr)
      : m_paper(new Paper()), m_rock(new Rock()), m_scissors(new Scissors()),
        m_gesture_table(m_rock, m_paper, m_scissors), m_game_strategy(strat)
    {
        m_choices.push_back(m_paper);
        m_choices.push_back(m_rock);
        m_choices.push_back(m_scissors);
    }

    ~Game()
    {
        for (auto *ptr : m_choices) { delete ptr; }
        delete m_game_strategy;
    }

    bool valid(std::string_view gesture) { return m_gesture_table.valid(gesture); }

    Winner versus(std::string_view);

    std::string_view move() { return m_current_move->name; }

private:
    Move *m_pick_gesture();

private:
    Paper *m_paper;
    Rock *m_rock;
    Scissors *m_scissors;
    std::vector<Move *> m_choices;

    GestureTable m_gesture_table;
    Move *m_current_move;

    GameStrategy *m_game_strategy;
};

} // namespace game