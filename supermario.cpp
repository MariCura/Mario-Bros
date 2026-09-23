#ifndef SUPERMARIO_H
#define SUPERMARIO_H

#include <iostream>
#include <string>
#include "colors.cpp"

using namespace std;

// Aquí las medidas del mundo
const int ROWS = 50;
const int COLS = 120;
typedef Color World[ROWS][COLS]; // se crea


// ----------------------------------------- Colores a utilizar --------------------------------------------

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

// -------------------------------- Clase SuperMarioMundo Para crear el mundo ----------------------------------

class SuperMarioMundo {
private:
    World papita;



    void draw_player(int row, int col) {
        for (int i = 0; i < 16; i++) {
            for (int j = 0; j < 12; j++) {
                int r = row + i;
                int c = col + j;
                if (r >= 0 && r < ROWS &&
                    c >= 0 && c < COLS) {
                    int colorIndex = MARIO_SPRITE[i][j];
                    if (colorIndex !=0){
                        papita[r][c] = MARIO_PALETTE[colorIndex];
                    }
                }
            }
        }
    }




    void draw_goomba(int row, int col) {
        for (int i = 0; i < 16; i++) {
            for (int j = 0; j < 16; j++) {
                int r = row + i;
                int c = col + j;

                if (r >= 0 && r < ROWS && c >= 0 && c < COLS) {
                    papita[r][c] = GOOMBA_PALETTE[GOOMBA_SPRITE[i][j]];
                }
            }
        }
    }

    void draw_tree(int row, int col) {

        for (int i = 0; i < 7; i++) {
            for (int j = 0; j < 8; j++) {
                int r = row + i;
                int c = col + j;

                if (r >= 0 && r < ROWS && c >= 0 && c < COLS) {
                    papita[r][c] = TREE_PALETTE[TREE_SPRITE[i][j]];
                }
            }
        }
    }

    void draw_madera(int row, int col) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                int r = row + i;
                int c = col + j;

                if (r >= 0 && r < ROWS && c >= 0 && c < COLS) {

                    papita[r][c] = BLOCK_MADERA_PALETTE[BLOCK_MADERA_SPRITE[i][j]];
                }
            }
        }
    }

    void draw_signo(int row, int col) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                int r = row + i;
                int c = col + j;
                if (r >= 0 && r < ROWS && c >= 0 && c < COLS) {
                    papita[r][c] = BLOCK_SIGNO_PALETTE[BLOCK_SIGNO_SPRITE[i][j]];
                }
            }
        }
    }


public:
    SuperMarioMundo() {
        crear_world();
    }
    int coins = 0;
    void crear_world() {
        for (int i = 0; i < ROWS; i++){
            for (int j = 0; j < COLS; j++){
                papita[i][j] = Color::WHITE;
            }
        }
    }

    // el mundo enterillo // Luigi, il mondo porfavore
    void draw_world( int playerRow, int playerCol) {
        crear_world();
        for (int i = ROWS - 6; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                papita[i][j] = Color::RED; // el piso
            }
        }

        // acá las coordenadas de los arboles
        draw_tree( 37, 22);
        draw_tree( 37, 30);
        draw_tree( 37, 38);
        draw_tree( 37, 84);


        // acá las cordenadas del resto
        draw_signo( 10, 35);
        draw_madera( 10, 70);
        draw_signo( 10, 79);
        draw_madera( 10, 88);
        draw_signo( 10, 97);
        draw_madera( 10, 106);

        // coordenadas de woomba
        draw_goomba(28, 96);

        // coordenadas de mario (!! Estas las vamos a mover cuando se mueva)
        draw_player(playerRow, playerCol);
    }

    void render() {

        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                cout << ansiColor(papita[i][j]);
                // !!ESTO NO SE CAMBIA, CON 3 ESPACIOS ES PERFECTO
                cout << "   ";
                // Restauramos después de cada celda
                cout << "\033[0m";
            }
            cout<<endl;
        }
    }

};

SuperMarioMundo mundo;

void move_player( int& playerRow, int& playerCol, const string& option) {

    if (playerRow < 0 || playerRow + 16 > ROWS || playerCol < 0 || playerCol + 12 > COLS) {
        cout << "invalid operation" <<"\n";
    } else {
        if (option == "right") {
            playerCol += 12;
        }
        else if (option == "left") {

            playerCol -= 12;
        }

        else if (option == "up") {

            playerRow -= 16;
            mundo.draw_world( playerRow, playerCol);
            mundo.render();
            playerRow += 16;
        }

        else if (option == "up-right") {

            playerCol += 12;
            playerRow -= 16;
            mundo.draw_world( playerRow, playerCol);
            mundo.render();
            playerRow += 16;
        }

        else if (option == "up-left") {

            playerCol -= 12;
            playerRow -= 16;
            mundo.draw_world( playerRow, playerCol);
            mundo.render();
            playerRow += 16;
        }
    }
}

bool Over(int Mariorow, int Mariocol) {
    if ((Mariorow >= 28 && Mariorow <= 44) && (Mariocol >= 96 && Mariocol <= 110)) {
        return true;
    } else {
        return false;
    }
}


#endif