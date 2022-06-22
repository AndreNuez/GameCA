#include <stdlib.h>
#include "Carpincho.h"

Carpincho::Carpincho()
{
	_textura.loadFromFile("carpincho.png"); // asigno imagen a textura
	_sprite.setTexture(_textura); // asigno textura a personaje
	_sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height / 2);
	_velocity = { 0,0 };
}

void Carpincho::update()
{
	_sprite.move(_velocity);
	if (_sprite.getPosition().y > 600) {
		respawn();
	}
}

void Carpincho::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(_sprite, states);
}

void Carpincho::respawn()
{
	//Acá se tiene que llamar al objeto, no a la propiedad. La clase tiene que ser transformable.
	_sprite.setPosition((std::rand() % 200) + 150 + _sprite.getLocalBounds().width, -100);
}

sf::FloatRect Carpincho::getBounds() const
{
	return _sprite.getGlobalBounds();
}

void Carpincho::setVelocity(sf::Vector2f velocity)
{
	_velocity = velocity;
}
