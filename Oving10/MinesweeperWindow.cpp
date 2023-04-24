#include "MinesweeperWindow.h"
#include <iostream>

MinesweeperWindow::MinesweeperWindow(int x, int y, int width, int height, int mines, const string &title)
	: // Initialiser medlemsvariabler, bruker konstruktoren til AnimationWindow-klassen
	  AnimationWindow{x, y, width * cellSize, (height + 1) * cellSize + 20, title},
	  width{width}, height{height}, mines{mines}, numMinesLeft{mines},
	  winOrLose{Point{width * cellSize / 2 - 100, height * cellSize / 2}, 200, 50, ""},
	  quit{Point{width * cellSize / 2 - 100, height * cellSize / 2 + 50}, 100, 50, "Quit"},
	  restart{Point{width * cellSize / 2, height * cellSize / 2 + 50}, 100, 50, "Restart"},
	  minesLeft{Point{width * cellSize / 2 - 100, height * cellSize + 5}, 200, 50, "Mines left: " + to_string(mines)}
{
	// Legg til alle tiles i vinduet
	add(winOrLose);
	add(minesLeft);
	add(quit);
	add(restart);
	quit.setCallback(std::bind(&MinesweeperWindow::cb_quit, this));
	restart.setCallback(std::bind(&MinesweeperWindow::cb_restart, this));

	quit.setVisible(false);
	restart.setVisible(false);
	winOrLose.setVisible(false);
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			tiles.emplace_back(new Tile{Point{j * cellSize, i * cellSize}, cellSize});
			tiles.back()->setCallback(std::bind(&MinesweeperWindow::cb_click, this));
			auto temp = tiles.back().get();
			add(*temp);
		}
	}

	for (int i = 0; i < mines; i++)
	{
		int randInt = std::rand() % (tiles.size() + 1);
		while (tiles[randInt]->getIsMine())
		{
			randInt = std::rand() % (tiles.size() + 1);
		}
		tiles[randInt]->setIsMine(true);
	}
}

vector<Point> MinesweeperWindow::adjacentPoints(Point xy) const
{
	vector<Point> points;
	for (int di = -1; di <= 1; ++di)
	{
		for (int dj = -1; dj <= 1; ++dj)
		{
			if (di == 0 && dj == 0)
			{
				continue;
			}

			Point neighbour{xy.x + di * cellSize, xy.y + dj * cellSize};
			if (inRange(neighbour))
			{
				points.push_back(neighbour);
			}
		}
	}
	return points;
}

void MinesweeperWindow::openTile(Point xy)
{
	if (at(xy)->getState() == Cell::closed)
	{
		at(xy)->open();
		if (!at(xy)->getIsMine())
		{
			int numMinesAround = countMines(adjacentPoints(xy));
			if (numMinesAround > 0)
			{
				at(xy)->setAdjMines(numMinesAround);
				at(xy)->setButtonColor(TDT4102::Color::azure);
				at(xy)->setLabel(to_string(numMinesAround));
			}
			else
			{
				vector<Point> tilesArround = adjacentPoints(xy);
				for (int i = 0; i < tilesArround.size(); i++)
				{
					openTile(tilesArround[i]);
				}
			}
		}
		else
		{
			winOrLose.setVisible(true);
			quit.setVisible(true);
			restart.setVisible(true);
			winOrLose.setText("            You Lost!");

			for (int i = 0; i < tiles.size(); i++)
			{
				if (tiles[i]->getIsMine())
				{
					tiles[i]->setLabelColor(TDT4102::Color::red);
					tiles[i]->setLabel("X");
				}
			}
		}

		opendSquares++;
		if (opendSquares == width * height - mines)
		{
			winOrLose.setVisible(true);
			quit.setVisible(true);
			restart.setVisible(true);
			winOrLose.setText("            You Won!");

			for (int i = 0; i < tiles.size(); i++)
			{
				if (tiles[i]->getIsMine() && tiles[i]->getState() != Cell::flagged)
				{
					tiles[i]->flag();
				}
			}
		}
	}
}

void MinesweeperWindow::flagTile(Point xy)
{
	if ((at(xy)->getState() == Cell::closed || at(xy)->getState() == Cell::flagged))
	{
		at(xy)->flag();
		if (at(xy)->getState() == Cell::flagged)
		{
			numMinesLeft--;
		}
		else
		{
			numMinesLeft++;
		}
		minesLeft.setText("Mines left: " + to_string(numMinesLeft));
	}
}

// Kaller openTile ved venstreklikk og flagTile ved hoyreklikk
void MinesweeperWindow::cb_click()
{

	Point xy{this->get_mouse_coordinates()};
	// std::cout << xy.x << " " << xy.y <<": " << xy.x / (cellSize) + (xy.y / cellSize) * width<<"\n";

	if (!inRange(xy))
	{
		return;
	}
	if (this->is_left_mouse_button_down())
	{
		openTile(xy);
	}
	else if (this->is_right_mouse_button_down())
	{
		flagTile(xy);
	}
}

int MinesweeperWindow::countMines(vector<Point> points)
{
	int numMines = 0;
	for (int i = 0; i < points.size(); i++)
	{
		if (at(points[i])->getIsMine())
		{
			numMines++;
		}
	}
	return numMines;
}

void MinesweeperWindow::cb_quit()
{
	this->close();
};
void MinesweeperWindow::cb_restart()
{
	quit.setVisible(false);
	restart.setVisible(false);
	winOrLose.setVisible(false);

	for (auto tile : tiles)
	{
		tile->resetTile();
	}
	int numMines = 0;
	while (numMines < mines)
	{
		int randInt = std::rand() % (tiles.size());
		cout << randInt << endl;
		if (!tiles[randInt]->getIsMine())
		{
			tiles[randInt]->setIsMine(true);
			numMines++;
		}
	}

	opendSquares = 0;
	numMinesLeft = mines;
	minesLeft.setText(to_string(mines));
};