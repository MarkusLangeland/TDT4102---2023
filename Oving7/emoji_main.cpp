#include "AnimationWindow.h"
#include "Emoji.h"

// Definer størrelse på vindu og emoji
constexpr int xmax = 1000;
constexpr int ymax = 600;
constexpr int emojiRadius = 50;

vector<std::unique_ptr<Emoji>> CreateEmojiVec()
{
	vector<std::unique_ptr<Emoji>> emojis;
	int radius = 100;
	emojis.emplace_back(new SmilingFace(Point{120, 120}, radius));
	emojis.emplace_back(new SadFace(Point{420, 120}, radius));
	emojis.emplace_back(new AngryFace(Point{720, 120}, radius));
	emojis.emplace_back(new WinkingFace(Point{120, 420}, radius));
	emojis.emplace_back(new SurprisedFace(Point{420, 420}, radius));
	return emojis;
}

void AddEmojisToScreen(vector<std::unique_ptr<Emoji>> &emojis, AnimationWindow &win)
{
	for (int i = 0; i < emojis.size(); i++)
	{
		emojis.at(i)->draw(win);
	}
}

int main()
{

	const Point tl{100, 100};
	const string win_label{"Emoji factory"};
	AnimationWindow win{tl.x, tl.y, xmax, ymax, win_label};

	vector<std::unique_ptr<Emoji>> emojis = CreateEmojiVec();
	AddEmojisToScreen(emojis, win);
	win.wait_for_close();

	return 0;
}
