#include <iostream>
#include "game.h"
#include "user_controlled_player.h"

int main(int argc, char **argv) {
    int board_size = 3;

    if (argc > 1) {
        char *pEnd;
        long int converted = strtol(argv[1], &pEnd, 10);

        if (converted != 0L)
            board_size = static_cast<int>(converted);
        else {
            std::cerr << "fatal error: invalid board size provided; must be integer" << std::endl;
            return 1;
        }
    }

    Player* player1 = new UserControlledPlayer("X");

    auto *game = new Game(board_size, player1, nullptr);
    game->start();
    delete (game);
    //delete(player1);
    return 0;
}