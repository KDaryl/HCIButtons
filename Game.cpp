/// <summary>
/// Basic Game loop 
/// </summary>
#include "Game.h"

Game::Game() :
	m_window(sf::VideoMode(1280, 720), "SWITCH"),
	m_currentState(GameState::Splash),
	m_previousState(GameState::Splash)
{

}

//If we use pointers they will be deleted in here
Game::~Game()
{
}

void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time timePerFrame = sf::seconds(1.0f / 60.0f);

	while (m_window.isOpen())
	{
		processEvents();
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			update(timePerFrame);
		}
		render();
	}
}

void Game::update(sf::Time dt)
{
	//Using switch statement to update each screen
	switch (m_currentState)
	{
	case GameState::Splash:
		//Simple check press to transition from screen to screen
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
		{
			setGameState(GameState::MainMenu);
		}
		break;
	case GameState::MainMenu:
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
		{
			setGameState(GameState::Options);
		}
		break;
	case GameState::Options:
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
		{
			setGameState(GameState::Game);
		}
		break;
	case GameState::Game:
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
		{
			setGameState(GameState::Pause);
		}
		break;
	case GameState::Pause:
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
		{
			setGameState(GameState::Splash);
		}
		break;
	}
}

void Game::render()
{
	//Using switch statement to draw each screen
	switch (m_currentState)
	{
	case GameState::Splash:
		//Simple colour displays for each screen
		m_window.clear(sf::Color(207, 18, 224));
		m_window.display();
		break;
	case GameState::MainMenu:
		m_window.clear(sf::Color(105, 90, 190));
		m_window.display();
		break;
	case GameState::Options:
		m_window.clear(sf::Color(15, 190, 90));
		m_window.display();
		break;
	case GameState::Game:
		m_window.clear(sf::Color(125, 30, 10));
		m_window.display();
		break;
	case GameState::Pause:
		m_window.clear(sf::Color(65, 120, 70));
		m_window.display();
		break;
	default:
		m_window.clear();
		m_window.display();
		break;
	}
}

void Game::processEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			m_window.close();
		}
	}
}

void Game::setGameState(GameState gameState)
{
	m_previousState = m_currentState; //Set the previous to the current state
	m_currentState = gameState; //set the current state to the new state
}