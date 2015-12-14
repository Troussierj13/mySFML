#ifndef PLAYSTATE_HPP
#define PLAYSTATE_HPP

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <Snakz.hpp>
#include <Food.hpp>
#include <GameState.hpp>

class PlayState : public GameState
{
public:
	PlayState		(StateManager* manager);
	~PlayState		();

	void	processEvents		();
	void	update			(float delta);
	void	draw				(float delta);
	void	handlePlayerInput		();

private:
	Snakz mySnakz;
	Food myFood;

};

#endif // PLAYSTATE_HPP
