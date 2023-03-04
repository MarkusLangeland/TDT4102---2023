#include "masterVisual.h"
#include "std_lib_facilities.h"
#include "mastermind.h"
#include "utilities.h"

std::map<int, Color> colorConverter{
	{1, Color::red},
	{2, Color::green},
	{3, Color::yellow},
	{4, Color::blue},
	{5, Color::blue_violet},
	{6, Color::dark_cyan}};

void addGuess(MastermindWindow &mwin, const std::string code, const char startLetter)
{
	Guess guess = {.code = code, .startLetter = startLetter};
	mwin.guesses.push_back(guess);
}

void addFeedback(MastermindWindow &mwin, const int correctPosition, const int correctCharacter)
{
	Feedback feedback = {.correctPosition = correctPosition, .correctCharacter = correctCharacter};
	mwin.feedbacks.push_back(feedback);
}

void MastermindWindow::drawCodeHider()
{
	if (code_hidden)
	{
		draw_rectangle(Point{padX, 3 * padY}, winW - size * padX, padY, Color::black);
	}
}

MastermindWindow::MastermindWindow(int x, int y, int w, int h, int size, const std::string &title)
	: AnimationWindow(x, y, w, h, title),
	  guessBtn{{upperLeftCornerBtn.x, upperLeftCornerBtn.y}, btnW, btnH, "Add"},
	  guess{{upperLeftCornerInBox.x, upperLeftCornerInBox.y}, inBoxW, inBoxH, ""},
	  size(size)
{
	add(guess);
	add(guessBtn);
	guessBtn.setCallback(std::bind(&MastermindWindow::newGuess, this));
};

string MastermindWindow::wait_for_guess()
{

	while (!button_pressed && !should_close())
	{
		for (int guessIndex = 0; guessIndex < static_cast<int>(guesses.size()); guessIndex++)
		{
			// Implementer gjett slik at det vises fargede rektangler i grafikkvinduet
			Guess guess = guesses.at(guessIndex);
			for (int x = 0; x < 4; x++)
			{
				// Tegn rektangler ved bruk av draw_rectangle(). Bruk: colorConverter.at() for å få riktig farge
				draw_rectangle(Point{upperLeftCornerInBox.x + btnW * x + padX * x, upperLeftCornerInBox.y + btnH * guessIndex + 2 * padY + padY * guessIndex}, btnW, btnH, colorConverter.at(int(guess.code[x]) - int(guess.startLetter) + 1));
			}
		}

		for (int feedbackIndex = 0; feedbackIndex < static_cast<int>(feedbacks.size()); feedbackIndex++)
		{
			// Implementer feedback
			Feedback feeback = feedbacks.at(feedbackIndex);
			int correctPosition = feeback.correctPosition;
			int correctCharacter = feeback.correctCharacter;

			for (int i = 0; i < size; i++)
			{
				if (correctPosition > i)
				{
					draw_circle(Point{upperLeftCornerInBox.x + btnW * 4 + padX * 4 + 10 * i, upperLeftCornerInBox.y + 4 * padY + padY / 2 + 2 * padY * feedbackIndex}, 5, Color::black);
				}
				else if (correctCharacter > i)
				{
					draw_circle(Point{upperLeftCornerInBox.x + btnW * 4 + padX * 4 + 10 * i, upperLeftCornerInBox.y + 4 * padY + padY / 2 + 2 * padY * feedbackIndex}, 5, Color::gray);
				}
				else
				{
					draw_circle(Point{upperLeftCornerInBox.x + btnW * 4 + padX * 4 + 10 * i, upperLeftCornerInBox.y + 4 * padY + padY / 2 + 2 * padY * feedbackIndex}, 5, Color::light_gray);
				}
			}
		}

		// Burde tegnes sist siden den skal ligge på toppen
		drawCodeHider();

		next_frame();
	}
	button_pressed = false;

	string newGuess = guess.getText();
	guess.setText("");

	return newGuess;
}

string MastermindWindow::getInput(unsigned int n, char lower, char upper)
{
	bool validInput = false;
	string guess;
	while (!validInput && !should_close())
	{
		guess.clear();
		string input = wait_for_guess();
		if (input.size() == n)
		{
			for (unsigned int i = 0; i < n; i++)
			{
				char ch = input.at(i);
				if (isalpha(ch) && toupper(ch) <= upper && lower <= toupper(ch))
				{
					guess += toupper(ch);
				}
				else
					break;
			}
		}
		if (guess.size() == n)
		{
			validInput = true;
		}
		else
		{
			cout << "Invalid input guess again" << endl;
		}
	}
	return guess;
}

void MastermindWindow::setCodeHidden(bool hidden)
{
	code_hidden = hidden;
}

void playMastermindVisual()
{
	// Bruker constexpr for at verdiene skal være definert ved compiletime.
	constexpr int size = 4;
	constexpr int letters = 6;
	constexpr int maxGuessAmount = 6;

	MastermindWindow mwin{800, 20, winH, winW, size, "MasterMind"};
	mwin.setCodeHidden(true);
	string code = randomizeString(size, 0, letters - 1);
	addGuess(mwin, code, 'A');
	string guess;
	// cout << code << endl;
	for (int x = 0; x < maxGuessAmount; x++)
	{
		guess = mwin.getInput(size, 'A', 'F');
		addGuess(mwin, guess, 'A');
		int charAndPos = checkCharactersAndPosition(guess, code);
		int checkChar = checkCharacters(guess, code);
		addFeedback(mwin, charAndPos, checkChar);
		cout << "Current guess: " << guess << endl;
		if (guess == code)
		{
			cout << "You guessed correctly!" << endl;
			mwin.setCodeHidden(false);
		}
	}
}
