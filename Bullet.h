#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>

#define M_PI 3.14159265359

class Bullet: public sf::Drawable, public sf::Transformable
{
public:

    void add(sf::Vector2f, float, float, int);
    void update(float);
    void remover(int);
    int getAmount()const;

    sf::FloatRect getRect(int) const;
    sf::Sprite getSprite(int) const;

    explicit Bullet(void);

private:
    sf::Texture texture[3];

    std::vector<sf::Vector2f> wektor;

    std::vector<sf::FloatRect> rect;
    std::vector<sf::Sprite> bullet;

    virtual void draw(sf::RenderTarget&, sf::RenderStates) const;

};
