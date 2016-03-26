#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdlib>

class Explosion: public sf::Drawable, public sf::Transformable
{
public:

	void update();
	void add(sf::Vector2f);

    explicit Explosion(void);
	
private:
	
	sf::Clock clock;
	sf::Time time;
	sf::Texture texture[5];

	std::vector<sf::Sprite> explosion;
	std::vector<int> nodes;

	void remover(int);

	virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
	
};
