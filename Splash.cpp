#include "Splash.h"

Splash::Splash(unsigned int screenWidth, unsigned int screenHeight) :
	m_finished(false),
	m_screenFinished(false)
{
	//Setting up video parameters
	m_introMovie.openFromFile("./resources/SplashAnimation.mov");
	m_introMovie.fit(0, 0, screenWidth, screenHeight, false); //fit our movie onto the screen
	m_introMovie.play(); //play our intro video

	//Setting up our background image parameters 
	if (!m_texture.loadFromFile("./resources/SplashBG.png"))
	{
		std::cout << "Error loading 'SplashBG.png'" << std::endl;
	}

	//Resize our background image
	resize(screenWidth, screenHeight);

	m_leftSide.setTexture(m_texture);
	m_leftSide.setTextureRect(sf::IntRect(0, 0, screenWidth / 2.0, screenHeight));
	m_leftSide.setScale(m_scalar);
	m_leftSide.setPosition(sf::Vector2f(0, 0));

	m_rightSide.setTexture(m_texture);
	m_rightSide.setTextureRect(sf::IntRect(screenWidth / 2.0, 0, screenWidth / 2.0, screenHeight));
	m_rightSide.setScale(m_scalar);
	m_rightSide.setPosition(sf::Vector2f(screenWidth / 2.0, 0));
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
		if (m_leftSide.getPosition().y > -m_leftSide.getTextureRect().height)
		{
			m_leftSide.setPosition(m_leftSide.getPosition().x, m_leftSide.getPosition().y - m_animationSpeed);
		}
		if (m_leftSide.getPosition().y <= -m_leftSide.getTextureRect().height)
		{
			m_leftSide.setPosition(m_leftSide.getPosition().x, -m_leftSide.getTextureRect().height);
			m_screenFinished = true;
		}
	}
}

//Determining the scalar for our picture so it is displayed at any resolution
void Splash::resize(double width, double height)
{
	if (m_texture.getSize().x < width)
	{
		m_scalar.x = m_texture.getSize().x / width;
	}
	if (m_texture.getSize().x > width)
	{
		m_scalar.x = width / m_texture.getSize().x;
	}
	if (m_texture.getSize().y < height)
	{
		m_scalar.y = m_texture.getSize().y / height;

	}
	if (m_texture.getSize().y > height)
	{
		m_scalar.y = height / m_texture.getSize().y;
	}
	else
	{
		m_scalar.x = 1;
		m_scalar.y = 1;
	}
}

void Splash::render(sf::RenderWindow& window)
{
	if (m_finished == false) //if the movie is still playing draw it
		window.draw(m_introMovie);

	else
	{
		window.draw(m_leftSide);
		window.draw(m_rightSide);
	}
}

bool Splash::getFinished() const
{
	return m_finished;
}
bool Splash::getScreenFinished() const
{
	return m_screenFinished;
}