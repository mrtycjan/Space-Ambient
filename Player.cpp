#include "Player.h"

void Player::slower()
{
    static sf::Clock clock;
    static sf::Time time;

    time += clock.getElapsedTime();

    index = 0;

    if(velocity > 0 && time > sf::seconds(0.5))
    {
        time = sf::Time::Zero;
		velocity -= 2;

        if(velocity < 0)
            velocity = 0;

        clock.restart();
    }
}

void Player::changeLife(int value)
{
    life += value;
}

void Player::accelerate(float speed)
{
    if(velocity < acceleration*speed)
        velocity += 5;

    index = 1;
}

void Player::faster()
{
	if (acceleration < 3)
		acceleration += 0.05;
}

void Player::rotate(float angle)
{	
    player[0].rotate(angle);
    player[1].rotate(angle);
}

void Player::update(float delta)
{	
	sf::Vector2f wektor;
	float radian;

    radian = (player[index].getRotation()*M_PI)/180.f;

	wektor.x = sin(radian) * delta * velocity;
    wektor.y = -cos(radian) * delta * velocity;
    
	player[0].move(wektor);
    player[1].move(wektor);

    rect = player[0].getGlobalBounds();
}
sf::FloatRect Player::getRect() const
{
    return rect;
}

sf::Sprite Player::getSprite() const
{
    return player[0];
}

float Player::getRotation() const
{
    return player[0].getRotation();
}

void Player::addLife()
{
	if (life < 3)
		life++;
}

float Player::getVelocity() const
{
    return velocity;
}

int Player::getLife() const
{
    return life;
}

sf::Vector2f Player::getPosition() const
{
    return player[0].getPosition();
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();

    target.draw(player[index], states);
}

Player::Player(const int index)
{	
    velocity = 0;
	acceleration = 2.8;
    life = 3;

    track[0] = "data/textures/playerShip1_blue.png";
    track[1] = "data/textures/playerShip1_green.png";
    track[2] = "data/textures/playerShip1_orange.png";
    track[3] = "data/textures/playerShip1_red.png";
    track[4] = "data/textures/playerShip2_blue.png";
    track[5] = "data/textures/playerShip2_green.png";
    track[6] = "data/textures/playerShip2_orange.png";
    track[7] = "data/textures/playerShip2_red.png";
    track[8] = "data/textures/playerShip3_blue.png";
    track[9] = "data/textures/playerShip3_green.png";
    track[10] = "data/textures/playerShip3_orange.png";
    track[11] = "data/textures/playerShip3_red.png";
    track[12] = "data/textures/jet0.png";
    track[13] = "data/textures/jet1.png";
    track[14] = "data/textures/jet2.png";
    track[15] = "data/textures/jet3.png";
    track[16] = "data/textures/jet4.png";
    track[17] = "data/textures/jet5.png";
    track[18] = "data/textures/jet6.png";
    track[19] = "data/textures/jet7.png";
    track[20] = "data/textures/jet8.png";
    track[21] = "data/textures/jet9.png";
    track[22] = "data/textures/jet10.png";
    track[23] = "data/textures/jet11.png";


    texture[0].loadFromFile(track[index]);
    texture[1].loadFromFile(track[index+12]);

    for(int i=0; i<2; i++)
    {
        texture[i].setSmooth(true);
        player[i].setTexture(texture[i]);
        player[i].setPosition((1280-player[0].getGlobalBounds().width)/2, 720/2);
    }

    rect = player[0].getGlobalBounds();
    player[0].setOrigin(rect.width/2, rect.height/2);
    player[1].setOrigin(rect.width/2, rect.height/2);

}

