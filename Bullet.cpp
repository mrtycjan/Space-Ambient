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
    texture[0].loadFromFile("data/textures/laserBlue01.png");
    texture[1].loadFromFile("data/textures/laserBlue02.png");
    texture[2].loadFromFile("data/textures/laserBlue03.png");
    texture[3].loadFromFile("data/textures/laserBlue04.png");
    texture[4].loadFromFile("data/textures/laserBlue05.png");
    texture[5].loadFromFile("data/textures/laserBlue06.png");
    texture[6].loadFromFile("data/textures/laserBlue07.png");
    texture[7].loadFromFile("data/textures/laserBlue12.png");
    texture[8].loadFromFile("data/textures/laserBlue13.png");
    texture[9].loadFromFile("data/textures/laserBlue14.png");
    texture[10].loadFromFile("data/textures/laserGreen02.png");
    texture[11].loadFromFile("data/textures/laserGreen03.png");
    texture[12].loadFromFile("data/textures/laserGreen04.png");
    texture[13].loadFromFile("data/textures/laserGreen05.png");
    texture[14].loadFromFile("data/textures/laserGreen06.png");
    texture[15].loadFromFile("data/textures/laserGreen07.png");
    texture[16].loadFromFile("data/textures/laserGreen08.png");
    texture[17].loadFromFile("data/textures/laserGreen09.png");
    texture[18].loadFromFile("data/textures/laserGreen10.png");
    texture[19].loadFromFile("data/textures/laserGreen11.png");
    texture[20].loadFromFile("data/textures/laserGreen12.png");
    texture[21].loadFromFile("data/textures/laserGreen13.png");
    texture[22].loadFromFile("data/textures/laserRed01.png");
    texture[23].loadFromFile("data/textures/laserRed02.png");
    texture[24].loadFromFile("data/textures/laserRed03.png");
    texture[25].loadFromFile("data/textures/laserRed04.png");
    texture[26].loadFromFile("data/textures/laserRed05.png");
    texture[27].loadFromFile("data/textures/laserRed06.png");
    texture[28].loadFromFile("data/textures/laserRed07.png");
    texture[29].loadFromFile("data/textures/laserRed12.png");
    texture[30].loadFromFile("data/textures/laserRed13.png");
    texture[31].loadFromFile("data/textures/laserRed14.png");
}
