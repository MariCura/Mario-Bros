// estos son solo los colores, las otras dos lo llaman
#ifndef COLORS_H
#define COLORS_H

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

const std::string RESET = "\033[0m";

inline std::string color(Color c) {

    switch (c) {
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
inline void printCell(Color c) {

    if (c == Color::NONE) {
        std::cout << "  ";
    }
    else {
        std::cout << color(c) << "██" << RESET;
    }
}

#endif