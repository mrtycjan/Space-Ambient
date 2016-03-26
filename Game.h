#include "Engine.h"
#include "Audio.h"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>

class Game
{
public:
    sf::RenderWindow window;
    sf::Vector2f windowSize;

    void runGame();

    explicit Game(void);

private:
    Audio audio;

    sf::Font font[2];
    sf::Text text[10];
    sf::Texture texture[3];
    sf::Sprite background;
	sf::Sprite arrow[2];
	sf::Sprite player[12];
	sf::Texture textures[12];
    sf::ContextSettings context;

    std::string strings[10];
	std::string toString(int);

    enum GameState {ENTRANCE, MENU, ENGINE, END, OPTIONS, ABOUT};
    GameState state;

	int index;
	int level;
	int score;

    void start();
    void options();
    void about();
    void menu();
	void entrance();
};
