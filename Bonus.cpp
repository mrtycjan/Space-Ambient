#pragma once

#include "Bonus.h"

void Bonus::add(int amount)
{
    for(int i=0; i<amount; i++)
    {
        sf::Sprite sprite;
        sf::FloatRect rectangle;

        sprite.setTexture(texture[i]);
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

    texture[0].loadFromFile("data/textures/bolt_bronze.png");
    texture[1].loadFromFile("data/textures/bold_silver.png");
    texture[2].loadFromFile("data/textures/bolt_gold.png");
    texture[3].loadFromFile("data/textures/pill_red.png");
    texture[4].loadFromFile("data/textures/pill_green.png");
    texture[5].loadFromFile("data/textures/pill_yellow.png");
    texture[6].loadFromFile("data/textures/things_bronze.png");
    texture[7].loadFromFile("data/textures/things_silver.png");
    texture[8].loadFromFile("data/textures/things_gold.png");
    texture[9].loadFromFile("data/textures/shield_bronze.png");
    texture[10].loadFromFile("data/textures/shield_silver.png");
    texture[11].loadFromFile("data/textures/shield_gold.png");
}
