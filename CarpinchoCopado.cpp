#include <stdlib.h>
#include "CarpinchoCopado.h"

CarpinchoCopado::CarpinchoCopado() 
{
	_texture.loadFromFile("carpinchocopado.png");
	_sprite.setTexture(_texture);
	_sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height / 2);
}

void CarpinchoCopado::update()
{
	_sprite.move(_velocity);
	if (_sprite.getPosition().y > 600) {
		respawn();
	}

}

void CarpinchoCopado::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(_sprite, states);
}

void CarpinchoCopado::respawn() 
{
	_sprite.setPosition((std::rand() % 200) + 150 + _sprite.getLocalBounds().width, -100);
}

sf::FloatRect CarpinchoCopado::getBounds() const
{
	return _sprite.getGlobalBounds();
}

void CarpinchoCopado::setVelocity(sf::Vector2f velocity)
{
	_velocity = velocity;
}
