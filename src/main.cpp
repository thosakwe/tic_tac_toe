#include <iostream>
#include <cstring>
#include "game.h"
#include "greedy_player.h"
#include "user_controlled_player.h"

int main(int argc, char **argv) {
    int board_size = 3;
    bool easy = false, two_player = true, hard = false;

    for (int i = 1; i < argc; i++) {
        auto * arg = argv[i];

        if (!strcmp(arg, "--easy")) {
            easy = true;
            two_player = hard = false;
        } else if (!strcmp(arg, "--hard")) {
            hard = true;
            two_player = easy = false;
        } else {
            char *pEnd;
            long int converted = strtol(arg, &pEnd, 10);

            if (converted != 0L)
                board_size = static_cast<int>(converted);
            else {
                std::cerr << "fatal error: invalid board size provided; must be integer" << std::endl;
                return 1;
            }
        }
    }

    Player* player1 = new UserControlledPlayer("X");
    Player* player2;

    // TODO: Option for trained AI...
    if (easy) {
        player2 = new GreedyPlayer("O");
    } else {
        player2 = new UserControlledPlayer("O");
    }

    auto *game = new Game(board_size, player1, player2);
    auto * winner = game->start();

    if (winner == nullptr) {
        std::cout << "Stalemate!" << std::endl;
    } else {
        std::cout << "Congratulations, Player " << winner << "!" << std::endl;
    }

    delete (game);
    //delete(player1);
    return 0;
}