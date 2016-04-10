#pragma once

#include "Bonus.h"

void Bonus::add(int amount)
{
    for(int i=0; i<amount; i++)
    {
        sf::Sprite sprite;
        sf::FloatRect rectangle;

        sprite.setTexture(texture);
        sprite.setPosition(rand()%3000, rand()%3000);

        rectangle = sprite.getGlobalBounds();

        bonus.push_back(sprite);
        rect.push_back(rectangle);
    }

}

void Bonus::remover(int index)
{
    for(int i=index; i<bonus.size()-1; i++)
    {
        std::swap(bonus[i], bonus[i+1]);
        std::swap(rect[i], rect[i+1]);
    }
    bonus.resize(bonus.size()-1);
    rect.resize(bonus.size());
}

void Bonus::update(float delta, sf::Vector2f wektor)
{
    for(int i=0; i<bonus.size(); i++)
    {
        bonus[i].move(wektor.x*delta, wektor.y*delta);
        rect[i] = bonus[i].getGlobalBounds();
    }

}

int Bonus::getAmount()
{
    return bonus.size();
}

sf::Sprite Bonus::getSprite(int index)
{
    return bonus[index];
}

sf::FloatRect Bonus::getRect(int index)
{
    return rect[index];
}

void Bonus::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();

    for(int i=0; i<bonus.size(); i++)
        target.draw(bonus[i], states);

}

Bonus::Bonus(void)
{
    srand(time(NULL));
	texture.loadFromFile("data/textures/things_gold.png");
}
