#include <SFML/Graphics.hpp>
#include <sstream>

class UI: public sf::Drawable, public sf::Transformable
{
public:
    void change(int);
	void setScore(int);

    UI(int);
private:

    sf::Text score;
    sf::Font font;
    sf::Texture texture[6];
    sf::Sprite sprite[3];

	std::string toString(int);
    std::string track[17];

    virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
};
