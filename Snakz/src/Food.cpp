#include <Food.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <cstdlib>
#include <ctime>

Food::Food(sf::Vector2u sizeWin)
	:food(sf::Vector2f(10, 10)), rect(0, 0, 0, 0), sizeWind(sizeWin)
{
	std::srand(time(nullptr));

	food.setFillColor(sf::Color::Cyan);
	setPosition({std::rand() % sizeWind.x, std::rand() % sizeWind.y});
	rect = {getPosition(), food.getSize()};
}

void Food::updatePosFood()
{
	setPosition({std::rand() % sizeWind.x, std::rand() % sizeWind.y});
	rect = {getPosition(), food.getSize()};
}

sf::FloatRect Food::getHitbox()const
{
	return rect;
}

void Food::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(food, states);
}
