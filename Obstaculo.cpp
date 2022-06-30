#include "Obstaculo.h"

Obstaculo::Obstaculo()
{
	_textura.loadFromFile("barrera.png"); // asigno imagen a textura
	_sprite.setTexture(_textura); // asigno textura a personaje
	_sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height / 2);
	_sprite.setPosition(300, -50);
}

void Obstaculo::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(_sprite, states);
}


void Obstaculo::update()
{
	_sprite.move(_velocity);
}

void Obstaculo::setVelocity(sf::Vector2f velocity)
{
	_velocity = velocity;
}

sf::FloatRect Obstaculo::getBounds() const
{
	return _sprite.getGlobalBounds();
}