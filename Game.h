#include <SFML/Graphics.hpp>

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

	//Member variables
	GameState m_currentState;
	GameState m_previousState;
	

	sf::RenderWindow m_window;
};