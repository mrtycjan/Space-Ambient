#include "Player.h"
#include "Bullet.h"
#include "Audio.h"
#include "Meteor.h"
#include "Collision.h"
#include "UI.h"
#include "Ufo.h"
#include "Bonus.h"
#include "Explosion.h"

#include <SFML/Graphics.hpp>
#include <cstdlib>


class Engine
{
public:

    void engine();
    explicit Engine(sf::RenderWindow &win, sf::Vector2f &win_size, Audio &sound, int index);

private:

	int id;
    Ufo  ufo;
    Meteor meteor;
    Bullet playerBullet;
    Bullet ufoBullet;
    Audio *audio;
	UI ui = id;
	Player player = id;
    Bonus bonus;
	Explosion explosion;

    sf::Texture texture;
    sf::Vector2f *windowSize;
    sf::RenderWindow *window;
    sf::Sprite background;
    sf::Vector2f bounds;
    sf::Vector2f view;

    void update(float);
    void setView();
    void collision();
    void control();
    void draw();
    void gamePlay();

	int *score;
	
	bool menu;
    volatile float delta;
};
