#include "Meteor.h"

void Meteor::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();

    for(int i=0; i<meteor.size(); i++)
        target.draw(meteor[i], states);
}

void Meteor::update(float delta, sf::Vector2f wektor)
{
    for(int i=0; i<meteor.size(); i++)
    {
        meteor[i].move(wektor.x*delta, wektor.y*delta);
        rect[i] = meteor[i].getGlobalBounds();
    }

}
sf::FloatRect Meteor::getRect(int index) const
{
    return rect[index];
}

sf::Sprite Meteor::getSprite(int index) const
{
    return meteor[index];
}

int Meteor::getAmount() const
{
    return meteor.size();
}

void Meteor::add(int amount)
{
    for(int i=0; i<amount; i++)
    {
        int index = rand()%20;

        sf::Sprite sprite;
        sf::FloatRect rectangle;

        sprite.setTexture(texture[index]);

        rectangle = sprite.getGlobalBounds();
        sprite.setOrigin(rectangle.width/2, rectangle.height/2);

        sprite.setPosition(rand()%5000, rand()%5000);

        rect.push_back(rectangle);
        meteor.push_back(sprite);

    }
}

void Meteor::remover(int index)
{
    for(int i=index; i<meteor.size()-1; i++)
    {
        std::swap(meteor[i], meteor[i+1]);
        std::swap(rect[i], rect[i+1]);
    }
    meteor.resize(meteor.size()-1);
    rect.resize(meteor.size());
}

Meteor::Meteor()
{
    srand(time(NULL));

    texture[0].loadFromFile("data/textures/meteorBrown_big1.png");
    texture[1].loadFromFile("data/textures/meteorBrown_big2.png");
    texture[2].loadFromFile("data/textures/meteorBrown_big3.png");
    texture[3].loadFromFile("data/textures/meteorBrown_big4.png");
    texture[4].loadFromFile("data/textures/meteorBrown_med1.png");
    texture[5].loadFromFile("data/textures/meteorBrown_med3.png");
    texture[6].loadFromFile("data/textures/meteorBrown_small1.png");
    texture[7].loadFromFile("data/textures/meteorBrown_small2.png");
    texture[8].loadFromFile("data/textures/meteorBrown_tiny1.png");
    texture[9].loadFromFile("data/textures/meteorBrown_tiny2.png");
    texture[10].loadFromFile("data/textures/meteorGrey_big1.png");
    texture[11].loadFromFile("data/textures/meteorGrey_big2.png");
    texture[12].loadFromFile("data/textures/meteorGrey_big3.png");
    texture[13].loadFromFile("data/textures/meteorGrey_big4.png");
    texture[14].loadFromFile("data/textures/meteorGrey_med1.png");
    texture[15].loadFromFile("data/textures/meteorGrey_med2.png");
    texture[16].loadFromFile("data/textures/meteorGrey_small1.png");
    texture[17].loadFromFile("data/textures/meteorGrey_small2.png");
    texture[18].loadFromFile("data/textures/meteorGrey_tiny1.png");
    texture[19].loadFromFile("data/textures/meteorGrey_tiny2.png");
}
