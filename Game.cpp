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
		break;
	case GameState::MainMenu:
		break;
	case GameState::Options:
		break;
	case GameState::Game:
		break;
	case GameState::Pause:
		break;
	}
}

void Game::render()
{
	//Using switch statement to draw each screen
	switch (m_currentState)
	{
	case GameState::Splash:
		break;
	case GameState::MainMenu:
		break;
	case GameState::Options:
		break;
	case GameState::Game:
		break;
	case GameState::Pause:
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