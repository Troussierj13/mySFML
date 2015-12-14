#include <Snakz.hpp>

Snakz::Snakz(sf::Vector2u sizeWin)
	:shape(sf::Vector2f(25,25)), dir_Snakz(Direction::Right), sizeWind(sizeWin)
{
	shape.setFillColor(sf::Color::Magenta);
	shape.setPosition(sizeWind.x/2, sizeWind.y/2);
}

void Snakz::updatePosSnakz()
{
	switch(dir_Snakz)
	{
		case Direction::Up:
			shape.setPosition(shape.getPosition().x, shape.getPosition().y - SPEED);
			break;
		case Direction::Right:
			shape.setPosition(shape.getPosition().x + SPEED, shape.getPosition().y);
			break;
		case Direction::Down:
			shape.setPosition(shape.getPosition().x, shape.getPosition().y + SPEED);
			break;
		case Direction::Left:
			shape.setPosition(shape.getPosition().x - SPEED, shape.getPosition().y);
			break;
	}
	if (shape.getPosition().x > sizeWind.x)
		shape.setPosition(-shape.getSize().x, shape.getPosition().y);
	if (shape.getPosition().x < -shape.getSize().x)
		shape.setPosition(sizeWind.x , shape.getPosition().y);
	if (shape.getPosition().y > sizeWind.y)
		shape.setPosition(shape.getPosition().x, -shape.getSize().y);
	if (shape.getPosition().y < -shape.getSize().y)
		shape.setPosition(shape.getPosition().x, sizeWind.y);
}

Direction::Dir_Snakz Snakz::getDirSnakz()
{
	return dir_Snakz;
}

void Snakz::setDirSnakz(Direction::Dir_Snakz dir)
{
	dir_Snakz = dir;
}

sf::Vector2f Snakz::getPosition()const
{
	return shape.getPosition();
}

sf::FloatRect Snakz::getGlobalBound()const
{
	return sf::FloatRect(shape.getPosition(), sf::Vector2f(25, 25));
}

void Snakz::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	  //states.texture = &m_texture;

	  target.draw(shape, states);
}
