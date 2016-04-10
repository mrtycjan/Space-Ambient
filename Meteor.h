#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <cstdlib>

#define M_PI 3.14159265359

class Meteor: public sf::Drawable, public sf::Transformable
{
public:


    void update(float, sf::Vector2f);
    void remover(int);
    void add(int);

    int getAmount() const;

    sf::FloatRect getRect(int) const;
    sf::Sprite getSprite(int) const;

    explicit Meteor(void);

private:
    std::vector<sf::FloatRect> rect;
    std::vector<sf::Sprite> meteor;

    sf::Texture texture[20];

    virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
};
