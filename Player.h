#include <SFML/Graphics.hpp>
#include <cmath>

#define M_PI 3.14159265359

class Player: public sf::Drawable, public sf::Transformable
{
public:

    void slower();
    void update(float);
    void accelerate();
    void rotate(float);
	void changeLife(int);

    float getRotation() const;
    float getVelocity() const;
    int getLife() const;

    sf::FloatRect getRect() const;
    sf::Sprite getSprite() const;
    sf::Vector2f getPosition() const;

    Player(int index);

private:

    sf::Sprite player[2];
    sf::Texture texture[2];
    sf::Vector2f wektor;
    sf::FloatRect rect;

	std::string track[24];

    int index=0;
    float radian;
    int life;
    float velocity;

    virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
};
