#include <SFML/Graphics.hpp>
#include "Splash.h"
#include "MainMenu.h"
//Our enum for gamestate, will be used for updating and drawing
enum class GameState
{
	Splash,
	MainMenu,
	Options,
	Game,
	Pause
};

class Game
{
public:
	Game();
	~Game();
	void run();
	//Will be used to set the current & previous states
	void setGameState(GameState gameState);

private:
	//Functions
	void processEvents();
	void update(sf::Time);
	void render();

	//Our window size variables
	const unsigned int m_screenWidth = 1280;
	const unsigned int m_screenHeight = 720;

	//Member variables
	GameState m_currentState;
	GameState m_previousState;
	
	//SFML objects
	sf::Font m_font; //will be used for displaying text
	sf::RenderWindow m_window;

	//Our screen objects
	Splash m_splash;
	MainMenu m_mainMenu;
};