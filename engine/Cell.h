#ifndef BOOMER_CELL_H
#define BOOMER_CELL_H

enum class CellState: char {
    DEFAULT = 0,
    OPENED = 1,
    FLAG = 2,
    BOMB = 3,
};

enum class CellValue: char {
    BOMB = -1,
    ZERO = 0,
    ONE = 1,
    TWO = 2,
    THREE = 3,
    FOUR = 4,
    FIVE = 5,
};

struct Cell {
    CellState State;
    CellValue Value;
};


#endif //BOOMER_CELL_H
