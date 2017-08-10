#include <iostream>
#include "game.h"

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

    auto *game = new Game(board_size, nullptr, nullptr);
    game->get_board()->print();
    //game->start();
    delete (game);
    return 0;
}