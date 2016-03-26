#include <SFML/Graphics.hpp>

class BitmaskManager
{
public:

    sf::Uint8 GetPixel (const sf::Uint8* mask, const sf::Texture* tex, unsigned int x, unsigned int y);
    sf::Uint8* CreateMask(const sf::Texture* tex, const sf::Image& img);
    sf::Uint8* GetMask (const sf::Texture* tex);

    ~BitmaskManager();

private:
    std::map<const sf::Texture*, sf::Uint8*> Bitmasks;
};
