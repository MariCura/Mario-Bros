#include <iostream>
#include <string>
#include "supermario.cpp"
using namespace std;

int main() {
    string move;
    World world;
    SuperMarioMundo mundo;


    // Posición inicial de Mario
    int playerRow = 28;
    int playerCol = 5;
    // Dibujar todos los elementos
    mundo.draw_world( playerRow, playerCol);
    // Mostrar mundo
    mundo.render();

    // esto todavia no funciona
    // while (cin >> move && !mundo.Over()) {

    // aqui iran todos llamados y el juego si
    // Over sera una funcion que determine si se termina el juego (mario x_x)
    // }


    return 0;
}