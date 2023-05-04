#pragma once
#include "AnimationWindow.h"
#include "Tetromino.h"
#include "widgets/TextInput.h"
#include "widgets/Button.h"
#include <vector>

// constexpr int windowW = 500;
// constexpr int windowH = 800;
constexpr int blockW = 25;
constexpr int blockH = 25;
constexpr int gridH = 20;
constexpr int gridW = 15;

constexpr TDT4102::Point startPoint{gridW / 2 - 1, 1};
constexpr TDT4102::Point startPos{50, 50};

class TetrisWindow : public TDT4102::AnimationWindow
{

public:
    TetrisWindow();
    void run();
    void generateRandomTetromino();
    void drawCurrentTetromino();
    void moveTetrominoDown();
    void fastenTetromino();
    void drawGridMatrix();
    bool hasChrashed();
    bool predictCrash(TDT4102::Point currPos);
    void removeFullRows();
    bool checkRow(int row);

    void lostGame();
    void saveHighscore();
    void restart();

    TDT4102::TextInput lostPopUp;
    TDT4102::TextInput scoreText;
    TDT4102::Button restartBtn;

private:
    std::vector<std::vector<TetrominoType>> gridMatrix;
    Tetromino currentTetromino;

    void handleInput();
    int currScore = 0;
    int highScore;
};