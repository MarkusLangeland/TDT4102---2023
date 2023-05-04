#include "Tetromino.h"
#include <map>
#include <cassert>
#include "iostream"

const std::map<TetrominoType, std::vector<std::vector<int>>> initialMatrixMap{

    {TetrominoType::T,
     {{0, 0, 0},
      {1, 1, 1},
      {0, 1, 0}}},

    {TetrominoType::J,
     {{0, 0, 0},
      {1, 1, 1},
      {0, 0, 1}}},

    {TetrominoType::I,
     {{0, 1, 0, 0, 0, 0},
      {0, 1, 0, 0, 0, 0},
      {0, 1, 0, 0, 0, 0},
      {0, 1, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0}}},

    {TetrominoType::Z,
     {{0, 0, 0},
      {1, 1, 0},
      {0, 1, 1}}},

    {TetrominoType::L,
     {{0, 0, 0},
      {1, 1, 1},
      {1, 0, 0}}},

    {TetrominoType::S,
     {{0, 0, 0},
      {0, 1, 1},
      {1, 1, 0}}},
    {TetrominoType::O,
     {{1, 1},
      {1, 1}}}};

Tetromino::Tetromino(TDT4102::Point startingPoint, TetrominoType tetType) : topLeftCorner{startingPoint},
                                                                            matrixSize{static_cast<int>(initialMatrixMap.at(tetType).size())},
                                                                            blockMatrix(matrixSize, std::vector<TetrominoType>(matrixSize, TetrominoType::NONE))
{

    for (int x = 0; x < matrixSize; x++)
    {
        for (int y = 0; y < matrixSize; y++)
        {
            if (initialMatrixMap.at(tetType)[x][y])
            {
                blockMatrix[x][y] = tetType;
            }
        }
    }
}

Tetromino::Tetromino() : topLeftCorner{TDT4102::Point{0, 0}}, matrixSize{0} {}

void Tetromino::rotateCounterClockwise()
{
    // Første rotasjon, med hensyn på diagonalen
    for (int row = 0; row < matrixSize; row++)
    {
        for (int column = 0; column < row; column++)
        {
            std::swap(blockMatrix[row][column], blockMatrix[column][row]);
        }
    }

    // Andre rotasjon, med hensyn på den midtre raden
    for (int row = 0; row < matrixSize / 2; row++)
    {
        for (int column = 0; column < matrixSize; column++)
        {
            std::swap(blockMatrix[row][column], blockMatrix[matrixSize - row - 1][column]);
        }
    }
}

void Tetromino::rotateClockwise()
{
    // Første rotasjon, med hensyn på diagonalen
    for (int row = 0; row < matrixSize; row++)
    {
        for (int column = 0; column < row; column++)
        {
            std::swap(blockMatrix[row][column], blockMatrix[column][row]);
        }
    }

    // Andre rotasjon, med hensyn på den midtre kolonnen
    for (int row = 0; row < matrixSize; row++)
    {
        for (int column = 0; column < matrixSize / 2; column++)
        {
            std::swap(blockMatrix[row][column], blockMatrix[row][matrixSize - column - 1]);
        }
    }
}

void Tetromino::moveDown()
{
    topLeftCorner = {topLeftCorner.x, topLeftCorner.y + 1};
}
void Tetromino::moveLeft()
{
    topLeftCorner = {topLeftCorner.x - 1, topLeftCorner.y};
}
void Tetromino::moveRight()
{
    topLeftCorner = {topLeftCorner.x + 1, topLeftCorner.y};
}

bool Tetromino::blockExist(int row, int col) const
{
    if (blockMatrix[row][col] == TetrominoType::NONE)
    {
        return false;
    }
    return true;
}

TetrominoType Tetromino::getBlock(int row, int col) const
{
    // assert(blockExist(row, col));
    return blockMatrix[row][col];
}

int Tetromino::getMatrixSize() const
{
    return matrixSize;
}

TDT4102::Point Tetromino::getPostion() const
{
    return topLeftCorner;
}
