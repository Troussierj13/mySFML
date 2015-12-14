#ifndef SNAKZ_HPP
#define SNAKZ_HPP

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

namespace Direction
{
	enum Dir_Snakz { Down, Up, Left, Right};
}

const float SPEED = 3.f;

class Snakz : public sf::Drawable, sf::Transformable
{
public:
	Snakz(sf::Vector2u);
	void updatePosSnakz();
	sf::Vector2f getPosition()const;
	sf::FloatRect getGlobalBound()const;
	Direction::Dir_Snakz getDirSnakz();
	void setDirSnakz(Direction::Dir_Snakz dir);

private:
	sf::RectangleShape	shape;
	Direction::Dir_Snakz	dir_Snakz;
	sf::Vector2u		sizeWind;

	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

};

#endif // SNAKZ_HPP
