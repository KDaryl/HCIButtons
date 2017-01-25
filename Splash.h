#pragma once
#include <string>
#include <iostream>
#include "sfeMovie\Movie.hpp" //our movie library

class Splash
{
public:
	Splash(unsigned int screenWidth, unsigned int screenHeight);
	~Splash();

	void update();
	void render(sf::RenderWindow& window);

	void resize(double width, double height);

	bool getFinished() const;
	bool getScreenFinished() const;
private:
	sfe::Movie m_introMovie; //our movie object, will be used to play a video
	bool m_finished; //bool to hold wheter the movie si over or not
	bool m_screenFinished; //Bool to hold if the screen is finished transitioning out or not

	const float m_animationSpeed = 12.0f;

	sf::Texture m_texture;
	sf::Sprite m_leftSide;
	sf::Sprite m_rightSide;
	sf::Vector2f m_scalar;
};