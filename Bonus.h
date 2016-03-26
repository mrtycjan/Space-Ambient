#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdlib>


class Bonus: public sf::Drawable, public sf::Transformable
{
public:

    sf::Sprite getSprite(int);
    sf::FloatRect getRect(int);

    void add(int);
    void remover(int);
    int getAmount();
    void update(float delta, sf::Vector2f wektor);

    explicit Bonus(void);
private:

    std::vector<sf::FloatRect> rect;
    std::vector<sf::Sprite> bonus;

    sf::Texture texture[12];

    virtual void draw(sf::RenderTarget&, sf::RenderStates) const;

};
