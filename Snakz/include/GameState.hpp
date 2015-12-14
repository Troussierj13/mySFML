#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include <StateManager.hpp>

class GameState
{
public:

	StateManager 	 *manager;

	virtual void			processEvents		() = 0;
	virtual void 			draw				(float delta) = 0;
	virtual void 			update				(float delta) = 0;
	virtual void 			handlePlayerInput	() = 0;

};
#endif //GAMESTATE_HPP
