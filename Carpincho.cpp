#include <stdlib.h>
#include "Carpincho.h"

Carpincho::Carpincho()
{
	_body.setSize(sf::Vector2f(50, 100));
	_textura.loadFromFile("carpincho.png"); // asigno imagen a textura
	_sprite.setTexture(_textura); // asigno textura a personaje
	_sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height / 2);
}

void Carpincho::updateRandom()
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
	_sprite.setPosition((std::rand() % 200) + 150 + _sprite.getLocalBounds().width, -100 - (std::rand() % 300));
}


sf::FloatRect Carpincho::getBounds() const
{
	return _sprite.getGlobalBounds();
}


///BORRAR
void Carpincho::setSprite(int random)
{
	_sprite.setPosition(random, -100 - (std::rand() % 300));
}
