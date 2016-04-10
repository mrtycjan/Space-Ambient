#pragma once

#include "Ufo.h"

#define M_PI 3.14159265359

void Ufo::add(sf::Vector2f to, int amount)
{
    for(int i=0; i<amount; i++)
    {
        int index = rand()%24;
        int number = rand()%4;

        float radian, degree;

        sf::FloatRect rectangle;
        sf::Sprite sprite;
        sf::Vector2f vect;

        if(number == 3)
            sprite.setPosition(rand()%1280, -50);

        else if(number == 2)
            sprite.setPosition(-50, rand()%720);

        else if(number == 1)
            sprite.setPosition(rand()%1280, 770);

        else
            sprite.setPosition(1330, rand()%720);

        sprite.setTexture(texture[index]);
        rectangle = sprite.getGlobalBounds();
        sprite.setOrigin(rectangle.width/2, rectangle.height/2);

        radian = atan2(to.x-sprite.getPosition().x, to.y-sprite.getPosition().y);

        vect.x = sin(radian);
        vect.y = -cos(radian);

        degree = (radian * 180)/M_PI;

        sprite.setRotation(degree);

        ufo.push_back(sprite);
        angle.push_back(degree);
        wektor.push_back(vect);
        rect.push_back(rectangle);
    }
}

void Ufo::update(sf::Vector2f to, float delta, float speed)
{
    for(int i=0; i<ufo.size(); i++)
    {
        float radian = atan2(to.x-ufo[i].getPosition().x, to.y-ufo[i].getPosition().y);

        wektor[i].x = sin(radian)*acceleration*speed*delta;
        wektor[i].y = cos(radian)*acceleration*speed*delta;

        angle[i] = (radian*180)/M_PI;
        ufo[i].move(wektor[i]);
        ufo[i].setRotation(-angle[i]);
        rect[i] = ufo[i].getGlobalBounds();
    }
}

sf::Vector2f Ufo::getPosition(int index) const
{
    return ufo[index].getPosition();
}

sf::Sprite Ufo::getSprite(int index) const
{
    return ufo[index];
}

sf::FloatRect Ufo::getRect(int index) const
{
    return rect[index];
}

int Ufo::getAmount() const
{
    return ufo.size();
}

float Ufo::getRotation(int index) const
{
    return ufo[index].getRotation()*2;
}

void Ufo::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();

    for(int i=0; i<ufo.size(); i++)
        target.draw(ufo[i]);
}

void Ufo::remover(int index)
{
    for(int i=index; i<ufo.size()-1; i++)
    {
        std::swap(ufo[i], ufo[i+1]);
        std::swap(angle[i], angle[i+1]);
        std::swap(wektor[i], wektor[i+1]);
        std::swap(rect[i], rect[i+1]);
    }
    ufo.resize(ufo.size()-1);
    angle.resize(ufo.size());
    wektor.resize(angle.size());
    rect.resize(wektor.size());
}

Ufo::Ufo(void)
{	
	acceleration = 1.5f;

    srand(time(NULL));

    texture[0].loadFromFile("data/textures/enemyBlack1.png");
    texture[1].loadFromFile("data/textures/enemyBlack2.png");
    texture[2].loadFromFile("data/textures/enemyBlack3.png");
    texture[3].loadFromFile("data/textures/enemyBlack4.png");
    texture[4].loadFromFile("data/textures/enemyBlack5.png");
    texture[5].loadFromFile("data/textures/enemyBlue1.png");
    texture[6].loadFromFile("data/textures/enemyBlue2.png");
    texture[7].loadFromFile("data/textures/enemyBlue3.png");
    texture[8].loadFromFile("data/textures/enemyBlue4.png");
    texture[9].loadFromFile("data/textures/enemyBlue5.png");
    texture[10].loadFromFile("data/textures/enemyGreen1.png");
    texture[11].loadFromFile("data/textures/enemyGreen2.png");
    texture[12].loadFromFile("data/textures/enemyGreen3.png");
    texture[13].loadFromFile("data/textures/enemyGreen4.png");
    texture[14].loadFromFile("data/textures/enemyGreen5.png");
    texture[15].loadFromFile("data/textures/enemyRed1.png");
    texture[16].loadFromFile("data/textures/enemyRed2.png");
    texture[17].loadFromFile("data/textures/enemyRed3.png");
    texture[18].loadFromFile("data/textures/enemyRed4.png");
    texture[19].loadFromFile("data/textures/enemyRed5.png");
    texture[20].loadFromFile("data/textures/ufoGreen.png");
    texture[21].loadFromFile("data/textures/ufoYellow.png");
    texture[22].loadFromFile("data/textures/ufoRed.png");
    texture[23].loadFromFile("data/textures/ufoBlue.png");

    for(int i=0; i<24; i++)
        texture[i].setSmooth(true);
}

