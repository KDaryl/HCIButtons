#pragma once
#include "SFML\Graphics.hpp" //need to fix circular reference

class MainMenu
{
public:
	MainMenu(unsigned int screenWidth, unsigned int screenHeight);

	void update();

	void render(sf::RenderWindow& window);
	
	//our switch screen method takes a bool so it can determine if this is the first time the user is seing this screen
	void switchScreen(); 

private:
	sf::RectangleShape m_whiteBox;
	const float m_animationSpeed = 12.0f;
	bool m_isStartUp;
};