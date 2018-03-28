#include "game.hpp"

using namespace std;
using namespace sf;

Game::Game()
{
	title = "Unknown Game";
	resolution = Vector2u(600, 600);
	window = NULL;
}

Game::Game(Vector2u res, string ttitle)
{
	window = NULL;
	resolution = res;
	title = ttitle;
}

Game::~Game()
{

}

void Game::delay(unsigned int ms)
{
	delayClock.restart();
	while(delayClock.getElapsedTime().asMilliseconds() < ms);
}

int Game::start()
{
	srand(time(NULL));
	window = new RenderWindow(VideoMode(resolution.x, resolution.y), title);
	
	bool spaceBlocking = false;
	bool rblocking = false;
	unsigned int steps = 1;
	bool running = false;
	
	pad.setSize(resolution);
	
	while(window->isOpen())
	{
		while(window->pollEvent(event))
		{
			if(event.type == Event::Closed)
				window->close();
		}
		
		if(Keyboard::isKeyPressed(Keyboard::Space))
		{
			if(!spaceBlocking)
			{
				spaceBlocking = true;
				pad.shiftRow();
				pad.addBallsRandomly(14);
				//pad.spawnTest();
			}
		}
		else
			spaceBlocking = false;
			
		delay(8);
		
		if(Keyboard::isKeyPressed(Keyboard::R))
		{
			if(!rblocking)
			{
				rblocking = true;
				running = !running;
			}
		}
		else
			rblocking = false;
		
		if(Keyboard::isKeyPressed(Keyboard::A))
			steps++;
		
		if(Keyboard::isKeyPressed(Keyboard::S))
		{
			if(steps > 1)
				steps--;
		}
		
		if(Keyboard::isKeyPressed(Keyboard::Num0))
			steps = 1;
		
		if(Keyboard::isKeyPressed(Keyboard::K) || running)
			for(size_t stepsNow = 0; stepsNow < steps; stepsNow++)
				pad.update();
		
		window->clear(Color::White);
		pad.display(window);
		window->display();
	}
	
	return 0;
}
