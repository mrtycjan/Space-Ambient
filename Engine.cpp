#include "Engine.h"

void Engine::engine()
{	
	while(!menu)
    {
        sf::Clock clock;

		gamePlay();
        draw();
        control();
        delta = clock.getElapsedTime().asSeconds();
        update(delta);
        collision();

        clock.restart();
    }
}

void Engine::control()
{
    sf::Event event;

    while(window->pollEvent(event))
    {
        if(event.key.code == sf::Keyboard::Escape)
            menu = true;
		else if (event.type == sf::Event::Closed)
		{
			menu = true;
			window->close();
		}
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        player.accelerate(speed);

    else
        player.slower();

    if(player.getVelocity() > 0)
        setView();
    else
        view = sf::Vector2f(0,0);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        player.rotate(-4* speed*delta);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        player.rotate(4*speed*delta);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
    {
        static sf::Clock clock;
        static sf::Time time;

        time += clock.restart();

        if(time >= sf::seconds(0.7))
        {
			audio->play(0);
			playerBullet.add(player.getPosition(), player.getRotation(), 4.2*speed, 0);
            time = sf::Time::Zero;
        }
    }
}

void Engine::gamePlay()
{
    static sf::Clock clock;
    static sf::Time time;
	
	

	if (player.getLife() < 0)
	{
		menu = true;
	}
		
	if (meteor.getAmount() <= 10)
	{
		meteor.add(47);
	}
        
    if(ufo.getAmount() <= 1 && rand()%2)
        ufo.add(player.getPosition(), rand()%4);

    if(bonus.getAmount() <= 0)
        bonus.add(20);

    time += clock.restart();

    if(time >= sf::seconds(seconds))
    {	
		if (speed < 85)
			speed += 2;

		if (ufo.getAmount())
		{	
			int index = rand() % ufo.getAmount();
			ufoBullet.add(ufo.getPosition(index), ufo.getRotation(index), 2.5*speed, rand()%2+1);
		}
			
        time = sf::Time::Zero;
    }

	ui.setScore(*score);
}

void Engine::randomize()
{
	int id = rand() % 3;

	switch (id)
	{
	case 0:
		if (seconds > 1.5)
			seconds -= 0.3;
		break;

	case 1:
		player.addLife();
		break;

	case 2:
		player.faster();
			break;

	}
}

void Engine::setView()
{
    if(player.getPosition().x > 1180)
        view = sf::Vector2f(-player.getVelocity(), 0);

    else if(player.getPosition().x < 100 && background.getPosition().x < 0)
        view = sf::Vector2f(player.getVelocity(), 0);

    else if(player.getPosition().y > 620)
        view = sf::Vector2f(0, -player.getVelocity());

    else if(player.getPosition().y < 100 && background.getPosition().y < 0)
        view = sf::Vector2f(0, player.getVelocity());
    else
        view = sf::Vector2f(0,0);
}

void Engine::collision()
{
    for(int i=0; i<playerBullet.getAmount(); i++)
    {
        for(int j=0; j<meteor.getAmount(); j++)
        {
            if(meteor.getRect(j).intersects(playerBullet.getRect(i)))
            {
				if (Collision::pixelPerfect(meteor.getSprite(j), playerBullet.getSprite(i)))
				{
					meteor.remover(j);
					*score += 20;
				}   
            }
        }
        for(int j=0; j<ufo.getAmount(); j++)
        {
            if(ufo.getRect(j).intersects(playerBullet.getRect(i)))
            {
				if (Collision::pixelPerfect(ufo.getSprite(j), playerBullet.getSprite(i)))
				{	
					ufo.remover(j);
					*score += 30;
				}
                   
            }
        }
    }
    for(int i=0; i<meteor.getAmount(); i++)
    {
        if(meteor.getRect(i).intersects(player.getRect()))
        {
            if(Collision::pixelPerfect(meteor.getSprite(i), player.getSprite()))
            {
                meteor.remover(i);
                player.changeLife(-1);
                ui.change(player.getLife());
            }
        }
    }
    for(int i=0; i<ufo.getAmount(); i++)
    {
        if(ufo.getRect(i).intersects(player.getRect()))
        {
            if(Collision::pixelPerfect(ufo.getSprite(i), player.getSprite()))
            {	
                ufo.remover(i);
                player.changeLife(-1);
                ui.change(player.getLife());
            }
        }
    }

    for(int i=0; i<ufoBullet.getAmount(); i++)
    {
        if(ufoBullet.getRect(i).intersects(player.getRect()))
        {
            if(Collision::pixelPerfect(ufoBullet.getSprite(i),  player.getSprite()))
            {
                player.changeLife(-1);
                ufoBullet.remover(i);
				ui.change(player.getLife());
            }
        }
    }

    for(int i=0; i<bonus.getAmount(); i++)
    {
        if(bonus.getRect(i).intersects(player.getRect()))
        {
            if(Collision::pixelPerfect(bonus.getSprite(i), player.getSprite()))
                bonus.remover(i);
			randomize();
			ui.change(player.getLife());
        }
    }
}


void Engine::draw()
{
    
	window->clear();
    window->draw(background);
    window->draw(bonus);
    window->draw(playerBullet);
    window->draw(ufoBullet);
    window->draw(meteor);
    window->draw(player);
    window->draw(ufo);
    window->draw(ui);
    window->display();
	
}

void Engine::update(float delta)
{
    player.update(delta);
    bonus.update(delta, view);
    playerBullet.update(delta);
    ufoBullet.update(delta);
    background.move(view.x*delta, view.y*delta);
    meteor.update(delta, view);
    ufo.update(player.getPosition(), delta, speed);
}
Engine::Engine(sf::RenderWindow &win, sf::Vector2f &win_size,  Audio &sound, int index, int &points): id(index)
{	
	score = &points;
    delta = 0;
	speed = 50;
	seconds = 2;

    menu = false;

    texture.setRepeated(true);
    texture.loadFromFile("data/textures/darkPurple.png");
    background.setTexture(texture);
    background.setTextureRect(sf::IntRect(0,0,5000, 5000));

    audio = &sound;
    window = &win;
    windowSize = &win_size;
}
