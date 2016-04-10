#include "Bullet.h"

void Bullet::add(sf::Vector2f position, float angle, float velocity, int index)
{
    sf::Sprite sprite;
    sf::Vector2f vect;
    sf::FloatRect rectangle;

    sprite.setTexture(texture[index]);
    sprite.setPosition(position);
    sprite.setOrigin(sprite.getGlobalBounds().width/2, sprite.getGlobalBounds().height/2);
    sprite.setRotation(angle);

    rectangle = sprite.getGlobalBounds();

    vect.x = velocity*(sin(2*M_PI*angle/360));
    vect.y = velocity*(-cos(2*M_PI*angle/360));

    wektor.push_back(vect);
    bullet.push_back(sprite);
    rect.push_back(rectangle);

}
sf::FloatRect Bullet::getRect(int index) const
{
    return rect[index];
}

sf::Sprite Bullet::getSprite(int index) const
{
    return bullet[index];
}

int Bullet::getAmount() const
{
    return bullet.size();
}

void Bullet::update(float delta)
{

    for(int i=0; i<wektor.size(); i++)
    {
        bullet[i].move(wektor[i].x * delta, wektor[i].y * delta);

        if(bullet[i].getPosition().x > 1280 || bullet[i].getPosition().x < 0 ||
                bullet[i].getPosition().y > 720 || bullet[i].getPosition().y < 0)
        {
            remover(i);
        }
        rect[i] = bullet[i].getGlobalBounds();
    }
}

void Bullet::remover(int index)
{
    for(int i=index; i<wektor.size()-1; i++)
    {
        std::swap(wektor[i],wektor[i+1]);
        std::swap(bullet[i],bullet[i+1]);
        std::swap(rect[i], rect[i+1]);
    }

    wektor.resize(wektor.size()-1);
    bullet.resize(wektor.size());
    rect.resize(bullet.size());
}

void Bullet::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();

    for(int i=0; i<bullet.size(); i++)
        target.draw(bullet[i], states);

}

Bullet::Bullet(void)
{
    texture[0].loadFromFile("data/textures/laserGreen10.png");
    texture[1].loadFromFile("data/textures/laserRed06.png");
	texture[2].loadFromFile("data/textures/laserRed07.png");
}
