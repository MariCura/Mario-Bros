#include <iostream>
#include <string>
#include "supermario.cpp"
using namespace std;

int main() {
    string move;
    SuperMarioMundo mundo;


    // Posición inicial de Mario
    int playerRow = 28;
    int playerCol = 5;
    // Dibujar todos los elementos
    // Mostrar mundo

    // esto todavia no funciona

    do {
        cout << move;
        move_player(playerRow,playerCol, move);
        mundo.draw_world( playerRow, playerCol);
        mundo.render();
    } while (cin >> move && !Over(playerRow, playerCol + 12) && mundo.coins != 3);

    cout << "game over" <<"\n";
    return 0;
}