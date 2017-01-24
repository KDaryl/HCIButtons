#pragma once
#include <string>
#include "sfeMovie\Movie.hpp" //our movie library

class Splash
{
public:
	Splash(unsigned int screenWidth, unsigned int screenHeight);
	~Splash();

	void update();
	void render(sf::RenderWindow& window);

	bool getFinished() const;
private:
	sfe::Movie m_introMovie; //our movie object, will be used to play a video
	bool m_finished; //bool to hold wheter the movie is over or not
};