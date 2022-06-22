#pragma once
#include <SFML/Graphics.hpp>
#include "Collisionable.h"

class CarpinchoCopado : public sf::Drawable, public Collisionable
{
private:
	sf::Sprite _sprite;
	sf::Texture _texture;
	sf::Vector2f _velocity;
public:
	CarpinchoCopado();
	void update();
	void draw(sf::RenderTarget&, sf::RenderStates) const override;
	void respawn();
	sf::FloatRect getBounds() const override;
	void setVelocity(sf::Vector2f);
};

