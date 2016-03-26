#include "Game.h"

void Game::runGame()
{
    while(state != END)
    {
        switch(state)
        {
		case ENTRANCE:
		{
			entrance();
			break;
		}

        case MENU:
        {
            menu();
            break;
        }
        case ENGINE:
        {
            start();
            break;
        }
        case OPTIONS:
        {
            options();
            break;
        }
        case ABOUT:
        {
            about();
            break;
        }

        }
    }
}

void Game::start()
{
    Engine engine(window, windowSize, audio, index, &score);
    engine.engine();

    state = MENU;
}
void Game::entrance()
{

}

void Game::menu()
{	
	sf::Event event;

    while(state == MENU)
    {
        sf::Vector2f mouse(sf::Mouse::getPosition(window));

        while(window.pollEvent(event))
        {
            for(int i=0; i<5; i++)
            {
                if(text[i].getGlobalBounds().contains(mouse))
                    text[i].setColor(sf::Color(26, 188, 156));
                else
                    text[i].setColor(sf::Color::White);

                if(event.type == sf::Event::Closed || i == 4 && text[i].getGlobalBounds().contains(mouse) && event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left)
                {
                    window.close();
                    state = END;
                }
            }
            if(text[1].getGlobalBounds().contains(mouse) && event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left)
                state = ENGINE;

            else if(text[2].getGlobalBounds().contains(mouse) && event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left)
                state = OPTIONS;

            else if(text[3].getGlobalBounds().contains(mouse) && event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left)
                state = ABOUT;

        }

        window.clear();
        window.draw(background);

        for(int i=0; i<5; i++)
            window.draw(text[i]);

        window.display();
    }
} 

void Game::options()
{
	sf::Event event;

	arrow[0].setPosition(540, 220);
	arrow[1].setPosition(740, 220);

	while (state == OPTIONS)
	{
		sf::Vector2f mouse(sf::Mouse::getPosition(window));

		while (window.pollEvent(event))
		{

			if (event.type == sf::Event::Closed)
			{
				window.close();
				state = END;
			}

			for (int i = 5; i < 10; i++)
			{
				if (text[i].getGlobalBounds().contains(mouse))
					text[i].setColor(sf::Color(26, 188, 156));
				else
					text[i].setColor(sf::Color::White);
			}

			if (text[5].getGlobalBounds().contains(mouse) && event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				state = MENU;

			if (text[7].getGlobalBounds().contains(mouse) && event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left)
			{
				if (text[7].getString() == "On")
				{
					audio.mute(true);
					text[7].setString("Off");
					text[7].setOrigin(text[7].getGlobalBounds().width / 2, text[7].getGlobalBounds().height / 2);
					text[7].setPosition(640.f, 350.f);
				}
				else if (text[7].getString() == "Off")
				{
					audio.mute(true);
					text[7].setString("On");
					text[7].setOrigin(text[7].getGlobalBounds().width / 2, text[7].getGlobalBounds().height / 2);
					text[7].setPosition(640.f, 350.f);
				}

			}			

			if (text[9].getGlobalBounds().contains(mouse) && event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left)
			{
				level += 10;

				if (level == 110)
					level = 0;

				audio.setVol(level);

				text[9].setString(toString(level));
			}
			std::cout << level << std::endl;
			for (int i = 0; i < 2; i++)
			{
				if (arrow[i].getGlobalBounds().contains(mouse))
				{
					arrow[i].setTexture(texture[2]);
					arrow[i].setColor(sf::Color::Cyan);

					if (i == 0 && event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left)
					{
						if (index == 0)
							index = 11;
						else
							index--;
					}
					else if (i == 1 && event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left)
					{
						if (index == 11)
							index = 0;
						else
							index++;
					}
				}

				else
				{
					arrow[i].setTexture(texture[1]);
					arrow[i].setColor(sf::Color::White);
				}
			}
			
		}
        window.clear();
        window.draw(background);
		window.draw(player[index]);
		window.draw(arrow[0]);
		window.draw(arrow[1]);
		for (int i = 5; i < 10; i++)
			window.draw(text[i]);
        window.display();
    }
}

void Game::about()
{
	sf::Event event;

	arrow[0].setPosition(140, 340);
	arrow[1].setPosition(1140, 340);

    while(state == ABOUT)
    {
        sf::Vector2f mouse(sf::Mouse::getPosition(window));

        while(window.pollEvent(event))
        {
            if(text[5].getGlobalBounds().contains(mouse))
                text[5].setColor(sf::Color(26, 188, 156));
            else
                text[5].setColor(sf::Color::White);

            if(event.type == sf::Event::Closed)
            {
                window.close();
                state = END;
            }

            if(text[5].getGlobalBounds().contains(mouse) && event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                state = MENU;
			
			for (int i = 0; i < 2; i++)
			{
				if (arrow[i].getGlobalBounds().contains(mouse))
				{
					arrow[i].setTexture(texture[2]);
					arrow[i].setColor(sf::Color::Cyan);
				}
				else
				{
					arrow[i].setTexture(texture[1]);
					arrow[i].setColor(sf::Color::White);
				}

			}
		}
        window.clear();
        window.draw(background);
		window.draw(arrow[0]);
		window.draw(arrow[1]);
        window.draw(text[5]);
        window.display();
    }
}

std::string Game::toString(int number)
{
	std::stringstream integer;
	integer << number;

	return integer.str();
}

Game::Game(void)
{	
    context.antialiasingLevel = 4;
    windowSize = sf::Vector2f(1280, 720);

    window.create(sf::VideoMode(windowSize.x, windowSize.y), "Space Ambient", sf::Style::Close, context);
    window.setFramerateLimit(60);

    font[0].loadFromFile("data/fonts/kenvector_future.ttf");
	font[1].loadFromFile("data/fonts/kenvector_future_thin.ttf");

    texture[0].setRepeated(true);
    texture[0].loadFromFile("data/textures/ambient.png");
	texture[1].loadFromFile("data/textures/arrow.png");
	texture[2].loadFromFile("data/textures/arrows.png");

	arrow[0].setTexture(texture[1]);
	arrow[1].setTexture(texture[1]);

	arrow[0].setOrigin(arrow[0].getGlobalBounds().width / 2, arrow[0].getGlobalBounds().height / 2);
	arrow[1].setOrigin(arrow[1].getGlobalBounds().width / 2, arrow[1].getGlobalBounds().height / 2);

	arrow[0].setRotation(-180);

    background.setTexture(texture[0]);
    background.setTextureRect(sf::IntRect(0,0, 1280, 720));

    strings[0] = "Space Ambient";
    strings[1] = "Start";
    strings[2] = "Options";
    strings[3] = "About";
    strings[4] = "Exit";
    strings[5] = "Back";
	strings[6] = "Audio";
	strings[7] = "On";
	strings[8] = "Audio Level";
	strings[9] = "80";

	textures[0].loadFromFile("data/textures/playerShip1_blue.png");
	textures[1].loadFromFile("data/textures/playerShip1_green.png");
	textures[2].loadFromFile("data/textures/playerShip1_orange.png");
	textures[3].loadFromFile("data/textures/playerShip1_red.png");
	textures[4].loadFromFile("data/textures/playerShip2_blue.png");
	textures[5].loadFromFile("data/textures/playerShip2_green.png");
	textures[6].loadFromFile("data/textures/playerShip2_orange.png");
	textures[7].loadFromFile("data/textures/playerShip2_red.png");
	textures[8].loadFromFile("data/textures/playerShip3_blue.png");
	textures[9].loadFromFile("data/textures/playerShip3_green.png");
	textures[10].loadFromFile("data/textures/playerShip3_orange.png");
	textures[11].loadFromFile("data/textures/playerShip3_red.png");

    state = MENU;
	score = 0;
	index = 0;
	level = 80;

    for(int i=0; i<5; i++)
    {
        text[i].setString(strings[i]);
      
        if(i>0)
        {	
			text[i].setFont(font[1]);
            text[i].setCharacterSize(30);
            text[i].setPosition((windowSize.x-text[i].getGlobalBounds().width)/2, 220+i*80);
        }

        else
        {
			text[i].setFont(font[0]);
			text[i].setCharacterSize(80);
            text[i].setPosition((windowSize.x-text[i].getGlobalBounds().width)/2, 70);

            text[i+5].setString(strings[i+5]);
            text[i+5].setFont(font[1]);
            text[i+5].setCharacterSize(25);
            text[i+5].setPosition((windowSize.x-text[i+5].getGlobalBounds().width)/2, 630);
        }
    }

	for (int i = 0; i < 12; i++)
	{
		player[i].setTexture(textures[i]);
		player[i].setOrigin(player[i].getGlobalBounds().width / 2, player[i].getGlobalBounds().height / 2);
		player[i].setPosition(640.f, 215.f);
	}

	for (int i = 6; i < 10; i++)
	{	
		text[i].setFont(font[1]);
		text[i].setString(strings[i]);
	}

	text[6].setCharacterSize(25);
	text[6].setOrigin(text[6].getGlobalBounds().width/ 2, text[6].getGlobalBounds().height / 2);
	text[6].setPosition(640.f, 320.f);

	text[7].setCharacterSize(19);
	text[7].setOrigin(text[7].getGlobalBounds().width / 2, text[7].getGlobalBounds().height / 2);
	text[7].setPosition(640.f, 350.f);

	text[8].setCharacterSize(24);
	text[8].setOrigin(text[8].getGlobalBounds().width / 2, text[8].getGlobalBounds().height / 2);
	text[8].setPosition(640.f, 430.f);
	
	text[9].setCharacterSize(19);
	text[9].setOrigin(text[9].getGlobalBounds().width / 2, text[9].getGlobalBounds().height / 2);
	text[9].setPosition(640.f, 460.f);
}
