#include <SFML/Graphics.hpp>

#include "BitmaskManager.h"
class Collision
{
public:

    static bool pixelPerfect(const sf::Sprite& Object1,const sf::Sprite& Object2, sf::Uint8 AlphaLimit = 0);
};
