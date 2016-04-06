#pragma once

#include "UI.h"

void UI::change(int life)
{
    if(life > -1 && life < 4)
        sprite[0].setTexture(texture[life]);
   
}

void UI::setScore(int points)
{
	score.setString(toString(points));
}

void UI::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();

    target.draw(sprite[0]);
    target.draw(sprite[1]);
    target.draw(sprite[2]);
    target.draw(score);

}

std::string UI::toString(int number)
{
	std::stringstream integer;
	integer << number;

	return integer.str();
}

UI::UI(int index)
{
    track[0] = "data/textures/playerLife1_blue.png";
    track[1] = "data/textures/playerLife1_green.png";
    track[2] = "data/textures/playerLife1_orange.png";
    track[3] = "data/textures/playerLife1_red.png";
    track[4] = "data/textures/playerLife2_blue.png";
    track[5] = "data/textures/playerLife2_green.png";
    track[6] = "data/textures/playerLife2_orange.png";
    track[7] = "data/textures/playerLife2_red.png";
    track[8] = "data/textures/playerLife3_blue.png";
    track[9] = "data/textures/playerLife3_green.png";
    track[10] = "data/textures/playerLife3_orange.png";
    track[11] = "data/textures/playerLife3_red.png";
    track[12] = "data/textures/numeral0.png";
    track[13] = "data/textures/numeral1.png";
    track[14] = "data/textures/numeral2.png";
    track[15] = "data/textures/numeral3.png";
    track[16] = "data/textures/numeralX.png";

    texture[0].loadFromFile(track[12]);
	texture[1].loadFromFile(track[13]);
	texture[2].loadFromFile(track[14]);
	texture[3].loadFromFile(track[15]);
    texture[4].loadFromFile(track[16]);
    texture[5].loadFromFile(track[index]);

    sprite[0].setTexture(texture[3]);
	sprite[1].setTexture(texture[4]);
	sprite[2].setTexture(texture[5]);

    font.loadFromFile("data/fonts/kenvector_future_thin.ttf");
    score.setFont(font);
    score.setString("0");
    score.setPosition(15, 10);
    score.setCharacterSize(19);

    sprite[2].setPosition(1190, 9);
    sprite[1].setPosition(1230, 11);
    sprite[0].setPosition(1250, 11);
}
