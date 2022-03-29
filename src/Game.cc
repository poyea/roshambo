#include "Game.h"

namespace game {

Move *Game::m_pick_gesture() { return m_game_strategy->pick(m_choices); }

Winner Game::versus(const std::string_view player_gesture)
{
    m_current_move = m_pick_gesture();
    auto *player_move = m_gesture_table.get_by_gesture(player_gesture);
    auto *beat_result = m_current_move->beats(player_move);

    if (beat_result == nullptr) return Winner::TIE;
    if (beat_result == m_current_move) return Winner::AI;
    return Winner::PLAYER;
}

} // namespace game
