#pragma once
#include <SFML/Graphics.hpp>
#include "Collisionable.h"

class Obstaculo: public sf::Drawable, public Collisionable
{
protected:
	sf::Sprite _sprite;
	sf::Texture _textura;
	sf::Vector2f _velocity;
	sf::RectangleShape _body;
public: 
	Obstaculo();
	void setVelocity(sf::Vector2f);
	void update();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	sf::FloatRect getBounds() const override;


};

