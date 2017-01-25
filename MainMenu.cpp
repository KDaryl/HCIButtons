#include "MainMenu.h"

MainMenu::MainMenu(unsigned int screenWidth, unsigned int screenHeight) :
	m_isStartUp(true)
{
	m_whiteBox.setSize(sf::Vector2f(screenWidth / 2.0, screenHeight));
	m_whiteBox.setFillColor(sf::Color::White);
	m_whiteBox.setPosition(screenWidth / 2.0, screenHeight); //set the position to the right hand side under the screen 
	m_whiteBox.setPosition(m_whiteBox.getPosition().x, -m_whiteBox.getPosition().y);
}

void MainMenu::update()
{
	switchScreen();
}

void MainMenu::render(sf::RenderWindow& window)
{
	window.draw(m_whiteBox);
}

void MainMenu::switchScreen()
{
	if (m_isStartUp)
	{
		if (m_whiteBox.getPosition().y < 0)
			m_whiteBox.setPosition(sf::Vector2f(m_whiteBox.getPosition().x, m_whiteBox.getPosition().y + m_animationSpeed));
		
		if (m_whiteBox.getPosition().y >= 0)
		{
			m_whiteBox.setPosition(sf::Vector2f(m_whiteBox.getPosition().x, 0));
			m_isStartUp = false;
		}
	}
}