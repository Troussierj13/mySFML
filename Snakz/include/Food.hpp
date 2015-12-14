#ifndef FOOD_HPP
#define FOOD_HPP

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <cstdlib>
#include <ctime>

class Food : public sf::Drawable, sf::Transformable
{
public:
	Food(sf::Vector2u);
	void updatePosFood();
	sf::FloatRect getHitbox()const;

private:
	sf::RectangleShape	food;
	sf::FloatRect		rect;
	sf::Vector2u		sizeWind;

	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

};

#endif // FOOD_HPP
