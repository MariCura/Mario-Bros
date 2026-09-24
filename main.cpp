#include <iostream>
#include <string>
#include "supermario.cpp"
#include <vector>
using namespace std;

int main() {
    string move;
    crear_world();
    vector<string>movimientos;
    bool booleano = false;
    int playerRow = 28;
    int playerCol = 5;

    cout<<"$ init"<<"\n";
    cout<<"$ Welcome to the world of super mario bros xyz"<<"\n";
    draw_world( playerRow, playerCol);
    render();

    while (cin >> move && coins != 3) {
        movimientos.push_back(move);
        cout<<"$ init"<<"\n";

        for (size_t i = 0; i < movimientos.size(); i++) {
            cout<<"$ "<<movimientos[i]<<"\n";
        }

        move_player(playerRow,playerCol, move, booleano);
        draw_world( playerRow, playerCol);
        review(playerRow, playerCol);
        upcoins(playerRow, playerCol);
        render();

        cout << "$ Coins = " << coins << "\n";
        if (Over(playerRow, playerCol + 12) || booleano) {
            cout << "$ Game over" <<"\n";
            break;
        }
    }

    return 0;
}