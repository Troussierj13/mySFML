#ifndef STATEMANAGER_HPP
#define STATEMANAGER_HPP

#include <stack>
#include <iostream>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System.hpp>

class GameState;

class StateManager
{
public:

	StateManager();
	~StateManager();

	void pushState(GameState * state);
	void popState();
	void changeState(GameState * state);
	GameState* peekState();

	void gameLoop();

public:

	std::stack<GameState*> states;
	sf::RenderWindow window;

};

#endif //STATEMANAGER_HPP
