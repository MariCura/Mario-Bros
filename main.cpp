#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "supermario.cpp"
using namespace std;

int main() {
    string linea;
    crear_world();
    bool booleano = false;
    int playerRow = 28;
    int playerCol = 3;
    vector<string> movimientos;

    cout<<"$ init"<<"\n";
    cout<<"$ Welcome to the world of super mario bros xyz"<<"\n";
    draw_world( playerRow, playerCol);
    render();
    cout << "$ Coins = " << coins << "\n";

    while (true) {
        cout<<"$ ";
        getline(cin, linea);

        movimientos.push_back(linea);
        cout<<"$ init"<<"\n";
        for (size_t i = 0; i < movimientos.size(); i++) {
            cout<<"$ "<<movimientos[i]<<"\n";
        }

        stringstream ss(linea);
        string move;

        while (ss >> move) {
            move_player(playerRow,playerCol, move, booleano);
            if (booleano) {
                break;
            }
        }

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