#include "engine/Game.h"
#include "engine/Field.h"

int main() {
    Game<Field<5, 5>> game;

    game.m_field.print();

    return EXIT_SUCCESS;
}
