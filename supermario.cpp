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

int coins = 0;
bool bl_check[3]={false,false,false};
int blrow[3]={10,10,10};
int blcol[3]={35,83,101};

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
            if (r >= 0 && r < ROWS &&
                c >= 0 && c < COLS) {
                if (GOOMBA_SPRITE[i][j] != 0) {
                        papita[r][c] = GOOMBA_PALETTE[GOOMBA_SPRITE[i][j]];
                }
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

void draw_coin(int row, int col) {
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            int r = row + i;
            int c = col + j;
            if (r >= 0 && r < ROWS && c >= 0 && c < COLS) {
                papita[r][c] = COIN_PALLETE[COIN_SPRITE[i][j]];
            }
        }
    }
}

void crear_world() {
    for (int i = 0; i < ROWS; i++){
        for (int j = 0; j < COLS; j++){
            papita[i][j] = Color::WHITE;
        }
    }
}

// el mundo enterillo // Luigi, il mondo porfavore

bool touch (int Mariow, int Mariol, int n) {
    int tpblow = blrow[n];
    int flblow = blrow[n] + 8;

    int tpcol = blcol[n];       //son los limites de columna y fila que se deben considerar para un "toco el bloque"
    int flcol = blcol[n]+8;

    int marioLeft = Mariol;
    int marioRight = Mariol + 11;

    bool touchfil;

    if (Mariow >= tpblow && Mariow <= flblow) {
        touchfil =true;
    }else {
        touchfil =false;
    }

    bool touchcol;
    if (marioLeft <= flcol && marioRight >= tpcol){
        touchcol=true;
    }else{
        touchcol =false;
    }

    bool is_touch;

    if (touchfil && touchcol) {
        //en caso tanto fila como columna (osea cual de los 3 bloques toco) esto kabom dice si lo toco
        is_touch =true;
    }else {
        is_touch =false;
    }


    return is_touch;   //miami lo confirmo
}


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
    draw_tree( 37, 98);

    // acá las cordenadas del resto
    draw_signo( 10, 35);
    draw_madera( 10, 74);
    draw_signo( 10, 83);
    draw_madera( 10, 92);
    draw_signo( 10, 101);
    draw_madera( 10, 110);


    // coordenadas de woomba
    draw_goomba(28, 104);

    // coordenadas de mario (!! Estas las vamos a mover cuando se mueva)
    draw_player(playerRow, playerCol);

    if (!bl_check[0] && touch(playerRow, playerCol, 0)) {
        draw_coin( 3, 36);
    }

    if (!bl_check[1] && touch(playerRow, playerCol, 1)) {
        draw_coin( 3, 84);
    }

    if (!bl_check[2] && touch(playerRow, playerCol, 2)) {
        draw_coin( 3, 102);
    }

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
        cout<<"\n";
    }
}

void review (int Mariow, int Mariol){
    for (int i=0; i<3;i++) {
        if ( !bl_check[i] && touch(Mariow, Mariol,i)) {        //es para revisar si lo toco suma la plata y check si paso
            bl_check[i]=true;
            coins++;
        }
    }
}

void draw_signal(int row, int col, int playerRow, int playerCol) {
    for (int i =0; i<9; i++) {
        for (int j=0; j<9; j++) {              //para pintar el bloque a quemado
            int r = row + i;
            int c = col + j;
            if (r>=0 && r < ROWS && c >= 0 && c<COLS)
                papita[r][c]=BLOCK_SIGNO_PALETTE[BLOCK_SIGNO_QUEMADO[i][j]];
        }
    }
    draw_player(playerRow, playerCol);
}

void upcoins(int playerRow, int playerCol) {
    for (int i= 0; i<3; i++) {
        if (bl_check [i])
            draw_signal(blrow[i],blcol[i], playerRow, playerCol);    //y este los re-pinta
    }
}


void move_player( int& playerRow, int& playerCol, const string& option, bool& booleano) {
    if (option == "right") {
        playerCol += 12;
    } else if (option == "left") {
        playerCol -= 12;
    } else if (option == "up") {
        playerRow -= 16;
        draw_world( playerRow, playerCol);
        review(playerRow, playerCol);
        upcoins(playerRow, playerCol);
        render();
        playerRow += 16;
    } else if (option == "up-right") {

        playerCol += 12;
        playerRow -= 16;
        draw_world( playerRow, playerCol);
        review(playerRow, playerCol);
        upcoins(playerRow, playerCol);
        render();
        playerRow += 16;
    } else if (option == "up-left") {
        playerCol -= 12;
        playerRow -= 16;
        draw_world( playerRow, playerCol);
        review(playerRow, playerCol);
        upcoins(playerRow, playerCol);
        render();
        playerRow += 16;
    }

    if (playerRow < 0 || playerRow + 16 > ROWS || playerCol < 0 || playerCol + 12 > COLS) {
        cout << "invalid operation" <<"\n";
        booleano = true;
    }

}


bool Over(int Mariorow, int Mariocol) {
    if ((Mariorow >= 28 && Mariorow <= 43) && (Mariocol >= 104 && Mariocol <= 119)) {
        return true;
    } else {
        return false;
    }
}


#endif