#include <SFML/Graphics.hpp>
#include <vector>
#include <math.h>
#include <cstdlib>

#pragma once

class Ufo: public sf::Drawable, public sf::Transformable
{
public:
    void add(sf::Vector2f, int);
    void update(sf::Vector2f, float, float);
    void remover(int);
    float getRotation(int) const;
    int getAmount() const;

    sf::Vector2f getPosition(int) const;
    sf::Sprite getSprite(int) const;
    sf::FloatRect getRect(int) const;

    explicit Ufo(void);

private:

    std::vector<sf::Sprite> ufo;
    std::vector<sf::FloatRect> rect;
    std::vector<sf::Vector2f> wektor;
    std::vector<float> angle;

    sf::Texture texture[24];

	float acceleration;

    void draw(sf::RenderTarget&, sf::RenderStates) const;

};
