#pragma once
#include <SFML/Graphics.hpp>

class Collisionable
{
public:
	virtual sf::FloatRect getBounds() const = 0;
	bool isCollision(Collisionable& col) const;
};



