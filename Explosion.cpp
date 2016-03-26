#include "Explosion.h"


void Explosion::update()
{
	for (int i = 0; i < explosion.size(); i++)
	{
		if (clock.getElapsedTime() >= time)
		{
			clock.restart();
			if (nodes[i] < 4)
			{
				nodes[i]++;
				explosion[i].setTexture(texture[nodes[i]]);
			}
			else
				remover(i);
		}
	}
}


void Explosion::add(sf::Vector2f position)
{
	sf::Sprite sprite;

	sprite.setTexture(texture[0]);

	sprite.setOrigin(50.f, 50.f);
	sprite.setPosition(position);
	
	explosion.push_back(sprite);
	nodes.push_back(1);
}

void Explosion::remover(int index)
{
	for (int i = index; i<explosion.size() - 1; i++)
	{
		std::swap(explosion[i], explosion[i + 1]);
		std::swap(nodes[i], nodes[i + 1]);
	}
	explosion.resize(explosion.size() - 1);
	nodes.resize(explosion.size());
}

void Explosion::draw(sf::RenderTarget& target, sf::RenderStates states) const
{	
	states.transform *= getTransform();

	for (int i = 0; i < explosion.size(); i++)
		target.draw(explosion[i], states);

}

Explosion::Explosion(void)
{
	texture[0].loadFromFile("data/textures/exp0.png");
	texture[1].loadFromFile("data/textures/exp1.png");
	texture[2].loadFromFile("data/textures/exp2.png");
	texture[3].loadFromFile("data/textures/exp3.png");
	texture[4].loadFromFile("data/textures/exp4.png");


	time = sf::seconds(0.025);
}