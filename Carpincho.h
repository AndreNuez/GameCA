﻿#pragma once
#include <SFML/Graphics.hpp>
#include "Collisionable.h"

class Carpincho : public sf::Drawable, public Collisionable
{
<<<<<<< Updated upstream
<<<<<<< Updated upstream
protected:
	sf::Sprite _sprite;
	sf::Texture _textura;
	sf::Vector2f _velocity;
=======

>>>>>>> Stashed changes
=======

>>>>>>> Stashed changes
public:
	Carpincho();
	void update();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void respawn(); // Para que aparezca item en posici�n random.
	sf::FloatRect getBounds() const override;
	void setVelocity(sf::Vector2f);
};


