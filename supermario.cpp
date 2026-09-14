#ifndef SUPERMARIO_H
#define SUPERMARIO_H

#include <iostream>
#include <string>
#include "colors.cpp"

using namespace std;

// Aquí las medidas del mundo
const int ROWS = 50;
const int COLS = 120;


// se crea
typedef Color World[ROWS][COLS];


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
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0},
    {0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0},
    {0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0},
    {0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0},
    {0,0,0,1,1,1,1,1,1,1,1,2,2,1,0,0},
    {0,0,1,1,1,3,1,1,1,1,2,3,1,1,1,0},
    {0,0,1,1,1,2,2,2,2,2,2,3,1,1,1,0},
    {0,1,1,1,1,2,3,1,1,3,2,3,1,1,1,1},
    {0,1,1,1,1,3,3,1,1,3,3,3,1,1,1,1},
    {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {0,0,1,1,1,1,3,3,3,3,3,1,1,1,1,0},
    {0,0,0,0,3,3,3,3,3,3,3,3,0,0,0,0},
    {0,0,0,3,3,3,3,3,3,3,3,3,2,0,0,0},
    {0,0,0,2,2,2,3,3,3,3,2,2,2,2,0,0},
    {0,0,0,2,2,2,2,0,0,2,2,2,2,2,0,0}
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


// para crear el world
void crear_world(World world) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            world[i][j] = Color::WHITE;
        }
    }
}


// aquí se dibuja mario
void draw_player(World world, int row, int col) {
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 12; j++) {
            int r = row + i;
            int c = col + j;
            if (r >= 0 && r < ROWS &&
                c >= 0 && c < COLS) {
                int colorIndex = MARIO_SPRITE[i][j];
                world[r][c] = MARIO_PALETTE[colorIndex];
            }
        }
    }
}


// se dibuja sprite
void draw_sprite(
    World world,
    const int sprite[][16],
    const Color palette[],
    int alto,
    int ancho,
    int row,
    int col
) {

    for (int i = 0; i < alto; i++) {
        for (int j = 0; j < ancho; j++) {
            int r = row + i;
            int c = col + j;
            if (r >= 0 && r < ROWS &&
                c >= 0 && c < COLS) {
                int colorIndex = sprite[i][j];
                world[r][c] = palette[colorIndex];
            }
        }
    }
}


// se dibuja el goomba
void draw_goomba(World world, int row, int col) {

    for (int i = 0; i < 16; i++) {

        for (int j = 0; j < 16; j++) {

            int r = row + i;
            int c = col + j;

            if (r >= 0 && r < ROWS &&
                c >= 0 && c < COLS) {

                world[r][c] =
                    GOOMBA_PALETTE[GOOMBA_SPRITE[i][j]];
            }
        }
    }
}


// dibuja arbol
void draw_tree(World world, int row, int col) {

    for (int i = 0; i < 7; i++) {

        for (int j = 0; j < 8; j++) {

            int r = row + i;
            int c = col + j;

            if (r >= 0 && r < ROWS &&
                c >= 0 && c < COLS) {

                world[r][c] =
                    TREE_PALETTE[TREE_SPRITE[i][j]];
            }
        }
    }
}


// las madera
void draw_madera(World world, int row, int col) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            int r = row + i;
            int c = col + j;
            if (r >= 0 && r < ROWS &&
                c >= 0 && c < COLS) {
                world[r][c] =
                    BLOCK_MADERA_PALETTE[
                        BLOCK_MADERA_SPRITE[i][j]
                    ];
            }
        }
    }
}


// los lucky
void draw_signo(World world, int row, int col) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            int r = row + i;
            int c = col + j;
            if (r >= 0 && r < ROWS &&
                c >= 0 && c < COLS) {
                world[r][c] =
                    BLOCK_SIGNO_PALETTE[
                        BLOCK_SIGNO_SPRITE[i][j]
                    ];
            }
        }
    }
}


// el mundo enterillo
void draw_world(World world, int playerRow, int playerCol) {

    // --------------------------------------------------------
    // PISO
    // --------------------------------------------------------

    for (int i = ROWS - 6; i < ROWS; i++) {

        for (int j = 0; j < COLS; j++) {

            world[i][j] = Color::RED; // el piso
        }
    }


    // acá las coordenadas de los arboles
    draw_tree(world, 37, 22);
    draw_tree(world, 37, 30);
    draw_tree(world, 37, 38);
    draw_tree(world, 37, 84);


    // acá las cordenadas del resto
    draw_signo(world, 10, 35);

    draw_madera(world, 10, 70);

    draw_signo(world, 10, 79);

    draw_madera(world, 10, 88);

    draw_signo(world, 10, 97);

    draw_madera(world, 10, 106);


    // coordenadas de woomba
    draw_goomba(world, 28, 96);


    // coordenadas de mario (!! Estas las vamos a mover cuando se mueva)
    draw_player(world, playerRow, playerCol);
}

// aquí el ansi
string ansiColor(Color color) {
    switch (color) {
        case Color::BLACK:
            return "\033[40m";
        case Color::RED:
            return "\033[41m";
        case Color::GREEN:
            return "\033[42m";
        case Color::YELLOW:
            return "\033[43m";
        case Color::WHITE:
            return "\033[47m";
        case Color::LIGHTRED_EX:
            return "\033[101m";
        case Color::LIGHTWHITE_EX:
            return "\033[107m";
        case Color::LIGHTBLUE_EX:
            return "\033[104m";
        case Color::LIGHTYELLOW_EX:
            return "\033[103m";
        default:
            return "\033[47m";
    }
}


// render
void render(World world) {

    for (int i = 0; i < ROWS; i++) {

        for (int j = 0; j < COLS; j++) {

            cout << ansiColor(world[i][j]);

            // !!ESTO NO SE CAMBIA, CON 3 ESPACIOS ES PERFECTO
            cout << "   ";

            // Restauramos después de cada celda
            cout << "\033[0m";
        }

        cout << endl;
    }
}


// EHM ESTA PARTE NO FUNCIONA CREO, HAY QUE CAMBIAR

void move_player( int& playerRow, int& playerCol, const string& option) {

    if (option == "right") {

        playerCol += 12;
    }

    else if (option == "left") {

        playerCol -= 12;
    }

    else if (option == "up") {

        playerRow -= 16;
    }

    else if (option == "up-right") {

        playerCol += 12;
        playerRow -= 16;
    }

    else if (option == "up-left") {

        playerCol -= 12;
        playerRow -= 16;
    }


    // validar limites ()
    if (playerRow < 0 ||
        playerRow + 16 > ROWS ||
        playerCol < 0 ||
        playerCol + 12 > COLS) {

        cout << "invalid operation" << endl;
    }
}

#endif