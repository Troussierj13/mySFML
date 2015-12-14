#include <StateManager.hpp>
#include <PlayState.hpp>

int main()
{
	StateManager manager;

	manager.pushState(new PlayState(&manager));
	manager.gameLoop();

	return 0;
}

