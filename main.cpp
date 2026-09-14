#include <iostream>
#include <string>
#include "supermario.cpp"
using namespace std;

int main() {
    string move;
    World world;
    crear_world(world);
    // Posición inicial de Mario
    int playerRow = 28;
    int playerCol = 5;
    // Dibujar todos los elementos
    draw_world(world, playerRow, playerCol);
    // Mostrar mundo
    render(world);
    // algun dia avanzaremos esto
    cin >> move;

    return 0;
}