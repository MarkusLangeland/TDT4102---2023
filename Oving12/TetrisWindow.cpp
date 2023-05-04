#include "TetrisWindow.h"
#include <iostream>
#include <map>
#include <fstream>
#include "std_lib_facilities.h"

const std::map<TetrominoType, TDT4102::Color> typeToCsolorMap{
    {TetrominoType::T, TDT4102::Color::purple},
    {TetrominoType::J, TDT4102::Color::blue},
    {TetrominoType::I, TDT4102::Color::light_blue},
    {TetrominoType::Z, TDT4102::Color::red},
    {TetrominoType::L, TDT4102::Color::orange},
    {TetrominoType::S, TDT4102::Color::lime_green},
    {TetrominoType::O, TDT4102::Color::yellow},
};

TetrisWindow::TetrisWindow() : AnimationWindow{startPos.x, startPos.y, blockW * gridW, blockH * gridH + 100},
                               currentTetromino{},
                               gridMatrix{gridH, std::vector<TetrominoType>(gridW, TetrominoType::NONE)},
                               lostPopUp{TDT4102::Point{0, (gridH * blockH) / 3}, gridW * blockW, 50, "You lost!"},
                               scoreText{TDT4102::Point{0, blockH * gridH}, gridW * blockW, 100, "Score: 0"},
                               restartBtn{TDT4102::Point{0, (gridH * blockH) / 3 + 50}, gridW * blockW, 50, "Restart"}
{
    generateRandomTetromino();

    add(lostPopUp);
    add(scoreText);
    add(restartBtn);
    lostPopUp.setVisible(false);
    restartBtn.setVisible(false);

    restartBtn.setCallback(bind(&TetrisWindow::restart, this));
    // read from file and set high score:
    std::fstream file;
    file.open("highScore.txt", std::ios::in);
    if (file.is_open())
    {
        std::string higestScore;
        while (getline(file, higestScore))
        {
            highScore = stoi(higestScore);
            scoreText.setText("Score: " + std::to_string(currScore) + "\n" + "HighScore: " + higestScore);
        }
    }

    // highScore
}

void TetrisWindow::run()
{
    unsigned int framesSinceLastTetronimoMove = 0;
    const unsigned int framesPerTetronimoMove = 20;

    while (!should_close())
    {
        framesSinceLastTetronimoMove++;
        if (framesSinceLastTetronimoMove >= framesPerTetronimoMove)
        {
            framesSinceLastTetronimoMove = 0;
            /********************************************************/
            // Kall moveTetrominoDown() her
            moveTetrominoDown();
            /********************************************************/
        }
        handleInput();

        /********************************************************/
        // Kall draw-funksjonene her
        drawGridMatrix();
        drawCurrentTetromino();
        /********************************************************/

        next_frame();
    }
}

void TetrisWindow::handleInput()
{

    static bool lastZKeyState = false;
    static bool lastUpKeyState = false;
    static bool lastDownKeyState = false;
    static bool lastLeftKeyState = false;
    static bool lastRightKeyState = false;
    static bool lastSpaceKeyState = false;

    bool currentZKeyState = is_key_down(KeyboardKey::Z);
    bool currentUpKeyState = is_key_down(KeyboardKey::UP);
    bool currentDownKeyState = is_key_down(KeyboardKey::DOWN);
    bool currentLeftKeyState = is_key_down(KeyboardKey::LEFT);
    bool currentRightKeyState = is_key_down(KeyboardKey::RIGHT);
    bool currentSpaceKeyState = is_key_down(KeyboardKey::SPACE);

    if (currentZKeyState && !lastZKeyState)
    {
        currentTetromino.rotateCounterClockwise();
        if (hasChrashed())
        {
            if (!predictCrash({currentTetromino.getPostion().x - 1, currentTetromino.getPostion().y}))
            {
                currentTetromino.moveLeft();
            }
            else if (!predictCrash({currentTetromino.getPostion().x + 1, currentTetromino.getPostion().y}))
            {
                currentTetromino.moveRight();
            }
            else if (!predictCrash({currentTetromino.getPostion().x - 2, currentTetromino.getPostion().y}))
            {
                currentTetromino.moveLeft();
                currentTetromino.moveLeft();
            }
            else if (!predictCrash({currentTetromino.getPostion().x + 2, currentTetromino.getPostion().y}))
            {
                currentTetromino.moveRight();
                currentTetromino.moveLeft();
            }
            else
            {
                currentTetromino.rotateClockwise();
            }
        }
    }

    if (currentUpKeyState && !lastUpKeyState)
    {

        currentTetromino.rotateClockwise();
        if (hasChrashed())
        {
            if (!predictCrash({currentTetromino.getPostion().x - 1, currentTetromino.getPostion().y}))
            {
                currentTetromino.moveLeft();
            }
            else if (!predictCrash({currentTetromino.getPostion().x + 1, currentTetromino.getPostion().y}))
            {
                currentTetromino.moveRight();
            }
            else if (!predictCrash({currentTetromino.getPostion().x - 2, currentTetromino.getPostion().y}))
            {
                currentTetromino.moveLeft();
                currentTetromino.moveLeft();
            }
            else if (!predictCrash({currentTetromino.getPostion().x + 2, currentTetromino.getPostion().y}))
            {
                currentTetromino.moveRight();
                currentTetromino.moveLeft();
            }
            else
            {
                currentTetromino.rotateCounterClockwise();
            }
        }
    }
    if (currentDownKeyState && !lastDownKeyState)
    {
        if (!predictCrash({currentTetromino.getPostion().x, currentTetromino.getPostion().y + 1}))
        {
            currentTetromino.moveDown();
        }
    }
    if (currentLeftKeyState && !lastLeftKeyState)
    {
        if (!predictCrash({currentTetromino.getPostion().x + -1, currentTetromino.getPostion().y}))
        {
            currentTetromino.moveLeft();
        }
    }
    if (currentRightKeyState && !lastRightKeyState)
    {
        if (!predictCrash({currentTetromino.getPostion().x + 1, currentTetromino.getPostion().y}))
        {
            currentTetromino.moveRight();
        }
    }
    if (currentSpaceKeyState && !lastSpaceKeyState)
    {
        for (int col = 0; col < gridH; col++)
        {
            if (!predictCrash({currentTetromino.getPostion().x, currentTetromino.getPostion().y + 1}))
            {
                currentTetromino.moveDown();
                currScore++;
                if (currScore > highScore)
                {
                    highScore = currScore;
                }
                scoreText.setText("Score: " + std::to_string(currScore) + "\n" + "HighScore: " + std::to_string(highScore));

                continue;
            }
        }
    }

    lastZKeyState = currentZKeyState;
    lastUpKeyState = currentUpKeyState;
    lastDownKeyState = currentDownKeyState;
    lastLeftKeyState = currentLeftKeyState;
    lastRightKeyState = currentRightKeyState;
    lastSpaceKeyState = currentSpaceKeyState;
}

void TetrisWindow::generateRandomTetromino()
{
    int randomShape = rand() % (7);
    Tetromino t{startPoint, static_cast<TetrominoType>(randomShape)};
    currentTetromino = t;
}

void TetrisWindow::drawCurrentTetromino()
{
    TDT4102::Point topLeftPos = currentTetromino.getPostion();
    int size = currentTetromino.getMatrixSize();

    for (int row = 0; row < size; row++)
    {
        for (int col = 0; col < size; col++)
        {
            if (currentTetromino.getBlock(row, col) != TetrominoType::NONE)
            {
                draw_rectangle(TDT4102::Point{(topLeftPos.x + col) * blockH, (topLeftPos.y + row) * blockW}, blockW, blockH, typeToCsolorMap.at(currentTetromino.getBlock(row, col)), TDT4102::Color::black);
            }
        }
    }
}

void TetrisWindow::moveTetrominoDown()
{
    if (!predictCrash({currentTetromino.getPostion().x, currentTetromino.getPostion().y + 1}))
    {
        currentTetromino.moveDown();
    }
    else
    {
        if (!hasChrashed())
        {
            fastenTetromino();
            generateRandomTetromino();
            removeFullRows();
        }
        else
        {
            lostGame();
        }
    }
}
void TetrisWindow::lostGame()
{
    lostPopUp.setVisible(true);
    restartBtn.setVisible(true);
    saveHighscore();
}

void TetrisWindow::saveHighscore()
{
    std::fstream file;
    file.open("highScore.txt", std::ios::out);
    if (file.is_open())
    {
        file << highScore;
    }
}

void TetrisWindow::fastenTetromino()
{
    TDT4102::Point currPos = currentTetromino.getPostion();
    int size = currentTetromino.getMatrixSize();

    for (int row = 0; row < size; row++)
    {
        for (int col = 0; col < size; col++)
        {
            if (currentTetromino.blockExist(row, col))
            {
                gridMatrix.at(currPos.y + row).at(currPos.x + col) = currentTetromino.getBlock(row, col);
            }
        }
    }
    currentTetromino = Tetromino{};
}

void TetrisWindow::drawGridMatrix()
{
    for (int row = 0; row < gridH; row++)
    {
        for (int col = 0; col < gridW; col++)
        {
            if (gridMatrix.at(row).at(col) != TetrominoType::NONE)
            {
                draw_rectangle(TDT4102::Point{col * blockW, row * blockH}, blockW, blockH, typeToCsolorMap.at(gridMatrix.at(row).at(col)), TDT4102::Color::black);
            }
        }
    }
}

bool TetrisWindow::predictCrash(TDT4102::Point currPos)
{
    int size = currentTetromino.getMatrixSize();
    for (int row = 0; row < size; row++)
    {
        for (int col = 0; col < size; col++)
        {
            if (currentTetromino.blockExist(row, col))
            {
                if (currPos.x + col > gridW || currPos.x + col < 0 || currPos.y + row >= gridH || gridMatrix[currPos.y + row][currPos.x + col] != TetrominoType::NONE)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

bool TetrisWindow::hasChrashed()
{
    TDT4102::Point currPos = currentTetromino.getPostion();
    return predictCrash(currPos);
}

void TetrisWindow::removeFullRows()
{
    int numRowsRemoved = 0;
    for (int row = 0; row < gridH; row++)
    {
        int numBlocks = 0;
        for (int col = 0; col < gridW; col++)
        {
            if (gridMatrix[row][col] != TetrominoType::NONE)
            {
                numBlocks++;
            }
        }

        if (numBlocks == gridW)
        {
            // MOve down row:
            numRowsRemoved++;
            std::cout << "Full row detected!";
            for (int row_above = row; row_above > 0; row_above--)
            {
                for (int col = 0; col < gridW; col++)
                {
                    gridMatrix[row_above][col] = gridMatrix[row_above - 1][col];
                }
            }
        }
    }
    std::cout << "numRowsRemoved: " << numRowsRemoved;
    switch (numRowsRemoved)
    {
    case 1:
        currScore += 40;
        break;
    case 2:
        currScore += 100;
        break;

    case 3:
        currScore += 300;
        break;

    case 4:
        currScore += 1200;
        break;

    default:
        currScore += 0;
    }
    if (currScore > highScore)
    {
        highScore = currScore;
    }
    scoreText.setText("Score: " + std::to_string(currScore) + "\n" + "HighScore: " + std::to_string(highScore));
}

void TetrisWindow::restart()
{
    // Clear board:
    for (int row = 0; row < gridH; row++)
    {
        for (int col = 0; col < gridW; col++)
        {
            gridMatrix[row][col] = TetrominoType::NONE;
        }
    }
    lostPopUp.setVisible(false);
    restartBtn.setVisible(false);
    currScore = 0;
    scoreText.setText("Score: " + std::to_string(currScore) + "\n" + "HighScore: " + std::to_string(highScore));
}