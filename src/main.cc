#include <iostream>
#include <string>

#include "Game.h"
#include "strategies/RandomStrategy.h"

void game_driver(game::Game &g, std::uint64_t N)
{
    std::string player_move;
    std::cout << "Remaining number of games: " << N << '\n';
    do {
        std::cout << "\t Available options: { fist, openhand, fingers }" << std::endl;
        std::cout << "\t Your move: ";
        std::cin >> player_move;
    } while (!g.valid(player_move));
    auto winner = g.versus(player_move);
    std::cout << "\t AI has played: " << g.move() << std::endl;
    std::cout << "\t Winner: " << winner << std::endl;
}

int main(int argc, char *argv[])
{
    if (argc < 2) {
        std::cerr << "Please input the number of games N as an argument!\n";
        exit(1);
    }
    std::uint64_t N = std::stol(argv[1]);
    std::cout << "We're playing the game " << N << " times.\n";
    for (; N > 0; --N) {
        game::Game *g = new game::Game(new game::RandomStrategy);
        game_driver(*g, N);
        delete g;
    }
    return 0;
}