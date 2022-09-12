#ifndef BOOMER_FIELD_H
#define BOOMER_FIELD_H

#include <array>
#include <iostream>
#include <numeric>
#include <algorithm>
#include <ranges>

#include "Cell.h"

template<int Size, int BombsNumber>
class Field {
    static_assert(BombsNumber <= (Size * Size), "BombsNumber must be less than the field Size squared.");
public:
    Field() {
        Init();
    };

    void Init() {
        // Init with zeros.
        m_field.fill(Cell{CellState::DEFAULT, CellValue::ZERO});

        // Place bombs.
        {
            std::array<int, Size * Size> indexes;
            std::iota(indexes.begin(), indexes.end(), 0);
            std::random_shuffle(indexes.begin(), indexes.end());
            for (int i = 0; i < BombsNumber; ++i) {
                m_field[indexes[i]].Value = CellValue::BOMB;
            }
        }

        // Count surrounding bombs.
        for (int rowIdx = 0; rowIdx < Size; ++rowIdx) {
            for (int colIdx = 0; colIdx < Size; ++colIdx) {
                auto &cell = m_field[rowIdx * Size + colIdx];

                if (cell.Value == CellValue::BOMB) {
                    continue;
                }

                cell.Value = static_cast<CellValue>(
                        ((rowIdx > 0 && colIdx > 0) &&
                         m_field[(rowIdx - 1) * Size + (colIdx - 1)].Value == CellValue::BOMB) +
                        ((rowIdx > 0) &&
                         m_field[(rowIdx - 1) * Size + (colIdx)].Value == CellValue::BOMB) +
                        ((rowIdx > 0 && colIdx < Size - 1) &&
                         m_field[(rowIdx - 1) * Size + (colIdx + 1)].Value == CellValue::BOMB) +
                        ((colIdx > 0) &&
                         m_field[(rowIdx) * Size + (colIdx - 1)].Value == CellValue::BOMB) +
                        ((colIdx < Size - 1) &&
                         m_field[(rowIdx) * Size + (colIdx + 1)].Value == CellValue::BOMB) +
                        ((rowIdx < Size - 1 && colIdx > 0) &&
                         m_field[(rowIdx + 1) * Size + (colIdx - 1)].Value == CellValue::BOMB) +
                        ((rowIdx < Size - 1) &&
                         m_field[(rowIdx + 1) * Size + (colIdx)].Value == CellValue::BOMB) +
                        ((rowIdx < Size - 1 && colIdx < Size - 1) &&
                         m_field[(rowIdx + 1) * Size + (colIdx + 1)].Value == CellValue::BOMB)
                );
            }
        }
    }

    void print() {
        for (int i = 0; i < Size; ++i) {
            std::cout << "| ";
            for (int j = 0; j < Size; ++j) {
                std::cout << static_cast<int>(m_field[i * Size + j].Value) << " | ";
            }
            std::cout << '\n';
        }
    }

    std::array<Cell, Size * Size> m_field;
};


#endif //BOOMER_FIELD_H
