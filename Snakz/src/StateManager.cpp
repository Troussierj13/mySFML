#include <StateManager.hpp>
#include <GameState.hpp>
#include <PlayState.hpp>

StateManager::StateManager()
{
     this->window.create(sf::VideoMode(800, 600), "Snakz");
     this->window.setFramerateLimit(60);

}

StateManager::~StateManager()
{
     while (!this->states.empty())
	     popState();
}

void StateManager::pushState(GameState* state)
{
     this->states.push(state);
}

void StateManager::popState()
{
     delete this->states.top();
     this->states.pop();
}

void StateManager::changeState(GameState* state)
{
     if(!this->states.empty())
     popState();
     pushState(state);

}

GameState* StateManager::peekState()
{
     if (this->states.empty())
	     return nullptr;
     return this->states.top();

}

void StateManager::gameLoop()
{
     sf::Clock clock;

     while (this->window.isOpen())
     {
	     sf::Time elapsed = clock.restart();
	     float delta = elapsed.asSeconds();

	     if(peekState() != nullptr)
	     {
	     peekState()->processEvents();
	     peekState()->update(delta);
	     this->window.clear(sf::Color::White);
	     peekState()->draw(delta);
	     this->window.display();
	     }
	     else
	     {
		     //pushState(new MenuState(&manager));
	     }
     }
}
