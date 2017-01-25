#include "Splash.h"

Splash::Splash(unsigned int screenWidth, unsigned int screenHeight) :
	m_finished(false)
{
	//Setting up video parameters
	m_introMovie.openFromFile("./resources/SplashAnimation.mov");
	m_introMovie.fit(0, 0, screenWidth, screenHeight); //fit our movie onto the screen
	m_introMovie.play(); //play our intro video
}

Splash::~Splash()
{

}

void Splash::update()
{
	m_introMovie.update(); //update our movie

	if (m_introMovie.getStatus() == false) //if the movie is over
	{
		m_finished = true;
	}
}

void Splash::render(sf::RenderWindow& window)
{
	window.clear();
	window.draw(m_introMovie);
	window.display();
}

bool Splash::getFinished() const
{
	return m_finished;
}