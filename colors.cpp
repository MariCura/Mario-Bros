// estos son solo los colores, las otras dos lo llaman
#ifndef COLORS_H
#define COLORS_H

using namespace std;

// BUENAS, ahora aca iran las constantes del proyecto: colores, sprites y paletas.

#include <iostream>
#include <string>

enum class Color {
    BLACK,
    LIGHTBLACK_EX,
    RED,
    LIGHTRED_EX,
    GREEN,
    LIGHTGREEN_EX,
    YELLOW,
    LIGHTYELLOW_EX,
    BLUE,
    LIGHTBLUE_EX,
    MAGENTA,
    LIGHTMAGENTA_EX,
    CYAN,
    LIGHTCYAN_EX,
    WHITE,
    LIGHTWHITE_EX,
    NONE
};

const string RESET = "\033[0m";

inline string color(Color colore  ) { // luigi, il colore por favore...

    switch (colore) {
        case Color::BLACK:          return "\033[30m";
        case Color::LIGHTBLACK_EX:  return "\033[90m";

        case Color::RED:            return "\033[31m";
        case Color::LIGHTRED_EX:    return "\033[91m";

        case Color::GREEN:          return "\033[32m";
        case Color::LIGHTGREEN_EX:  return "\033[92m";

        case Color::YELLOW:         return "\033[33m";
        case Color::LIGHTYELLOW_EX: return "\033[93m";

        case Color::BLUE:           return "\033[34m";
        case Color::LIGHTBLUE_EX:   return "\033[94m";

        case Color::MAGENTA:        return "\033[35m";
        case Color::LIGHTMAGENTA_EX:return "\033[95m";

        case Color::CYAN:           return "\033[36m";
        case Color::LIGHTCYAN_EX:   return "\033[96m";

        case Color::WHITE:          return "\033[37m";
        case Color::LIGHTWHITE_EX:  return "\033[97m";

        default:                    return "";
    }
}

inline void printCell(Color colore) {

    if (colore == Color::NONE) {
        cout << "  ";
    }
    else {
        cout << color(colore) << "██" << RESET;
    }
}

// ----------------------------- SPRITES/PALETAS ----------------------------------------------------


// mario de 16 filas x 12 columnas (FALTA HACERLE BIEN SU OJO)
const int MARIO_SPRITE[16][12] = {
    {0,0,0,1,1,1,1,1,0,0,0,0},
    {0,0,1,1,1,1,1,1,1,1,1,0},
    {0,0,2,2,2,3,3,2,3,0,0,0},
    {0,2,3,2,3,3,3,2,3,3,3,0},
    {0,2,3,2,2,3,3,3,2,3,3,3},
    {0,2,2,3,3,3,3,2,2,2,2,0},
    {0,0,0,3,3,3,3,3,3,3,0,0},
    {0,0,1,1,4,1,1,4,1,1,0,0},
    {0,1,1,1,4,1,1,4,1,1,1,0},
    {1,1,1,1,4,4,4,4,1,1,1,1},
    {3,3,1,4,5,4,4,5,1,1,3,3},
    {3,3,3,4,4,4,4,4,4,3,3,3},
    {3,3,4,4,4,4,4,4,4,4,3,3},
    {0,0,4,4,4,0,0,4,4,4,0,0},
    {0,0,2,2,0,0,0,0,2,2,0,0},
    {0,2,2,2,0,0,0,0,2,2,2,0}
};
const Color MARIO_PALETTE[6] = {
    Color::WHITE,
    Color::LIGHTRED_EX,
    Color::BLACK,
    Color::LIGHTWHITE_EX,
    Color::LIGHTBLUE_EX,
    Color::LIGHTYELLOW_EX
};


// Goomba (la kk) de 16 filas x 16 columnas
const int GOOMBA_SPRITE[16][16] = {
    {0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0},
    {0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0},
    {0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0},
    {0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0},
    {0,0,1,2,2,1,1,1,1,1,1,2,2,1,0,0},
    {0,1,1,1,3,2,1,1,1,1,2,3,1,1,1,0},
    {0,1,1,1,3,2,2,2,2,2,2,3,1,1,1,0},
    {1,1,1,1,3,2,3,1,1,3,2,3,1,1,1,1},
    {1,1,1,1,3,3,3,1,1,3,3,3,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {0,1,1,1,1,3,3,3,3,3,3,1,1,1,1,0},
    {0,0,0,0,3,3,3,3,3,3,3,3,0,0,0,0},
    {0,0,0,2,3,3,3,3,3,3,3,3,2,0,0,0},
    {0,0,2,2,2,2,3,3,3,3,2,2,2,2,0,0},
    {0,0,2,2,2,2,2,0,0,2,2,2,2,2,0,0},
    {0,0,0,2,2,2,2,0,0,2,2,2,2,0,0,0},
};
const Color GOOMBA_PALETTE[4] = {
    Color::WHITE,
    Color::YELLOW,
    Color::BLACK,
    Color::LIGHTWHITE_EX
};

// arbust (se tienen que hacer 4, 3 pegados y uno separado)
// 7 filas x 8 columnas

const int TREE_SPRITE[7][8] = {
    {0,0,0,1,1,0,0,0},
    {0,0,1,1,1,1,0,0},
    {0,1,1,1,1,1,1,0},
    {1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1}
};
const Color TREE_PALETTE[2] = {
    Color::WHITE,
    Color::GREEN
};


// la madera roja (9 filas x 9 columnas)
// se hacen 3 (intercalados con los lucky blocks)

const int BLOCK_MADERA_SPRITE[9][9] = {

    {0,0,0,0,1,0,0,0,0},
    {0,0,0,0,1,0,0,0,0},
    {1,1,1,1,1,1,1,1,1},
    {0,0,1,0,0,0,1,0,0},
    {0,0,1,0,0,0,1,0,0},
    {0,0,1,0,0,0,1,0,0},
    {1,1,1,1,1,1,1,1,1},
    {0,0,0,0,1,0,0,0,0},
    {0,0,0,0,1,0,0,0,0}
};
const Color BLOCK_MADERA_PALETTE[2] = {

    Color::RED,
    Color::BLACK
};

// Lucky Blocks (9 filas x 9 columnas)
// Se hacen 3, uno justo sobre los tres arbustos y dos intercalados con las maderas

const int BLOCK_SIGNO_SPRITE[9][9] = {

    {0,0,0,0,0,0,0,0,0},
    {0,0,0,1,1,1,0,0,0},
    {0,0,1,0,0,0,1,0,0},
    {0,0,0,0,0,1,1,0,0},
    {0,0,0,0,0,1,1,0,0},
    {0,0,0,0,1,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,1,0,0,0,0},
    {0,0,0,0,0,0,0,0,0}
};
const int BLOCK_SIGNO_QUEMADO[9][9] = {

    {1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1}
};
const Color BLOCK_SIGNO_PALETTE[2] = {
    Color::YELLOW,
    Color::BLACK
};




#endif