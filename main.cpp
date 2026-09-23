#include <iostream>
#include <string>
#include "supermario.cpp"
using namespace std;

int main() {
    string move;
    SuperMarioMundo mundo;

    int playerRow = 28;
    int playerCol = 5;

    do {
        cout << move;
        move_player(playerRow,playerCol, move);
        mundo.draw_world( playerRow, playerCol);
        mundo.review(playerRow, playerCol);
        mundo.upcoins();
        mundo.render();
    } while (cin >> move && !Over(playerRow, playerCol + 12) && mundo.coins != 3);

    cout << "game over" <<"\n";
    return 0;
}
