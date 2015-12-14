#include <PlayState.hpp>

PlayState::PlayState(StateManager *manager)
	:mySnakz(manager->window.getSize()), myFood(manager->window.getSize())
{
	this->manager = manager;
}

PlayState::~PlayState()
{

}

void PlayState::processEvents()
{

}

void PlayState::update(float delta)
{

	if(myFood.getHitbox().intersects(mySnakz.getGlobalBound()))
	{
		myFood.updatePosFood();
	}

}

void PlayState::draw(float delta)
{
	this->manager->window.draw(mySnakz);
	this->manager->window.draw(myFood);
}

void PlayState::handlePlayerInput()
{
	if((sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) && (mySnakz.getDirSnakz() != Direction::Down))
		mySnakz.setDirSnakz(Direction::Up);
	if((sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) && (mySnakz.getDirSnakz() != Direction::Up))
		mySnakz.setDirSnakz(Direction::Down);
	if((sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) && (mySnakz.getDirSnakz() != Direction::Right))
		mySnakz.setDirSnakz(Direction::Left);
	if((sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) && (mySnakz.getDirSnakz() != Direction::Left))
		mySnakz.setDirSnakz(Direction::Right);
}
