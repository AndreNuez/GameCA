#pragma once
#include <SFML/Graphics.hpp>
#include "Collisionable.h"
#include "Obstaculo.h"


class Carpincho : public Obstaculo
{
private:
	sf::Sprite _sprite;
public:
	Carpincho();
	void updateRandom();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void respawn(); 
	void setSprite(int); //Borrar si no uso
	sf::FloatRect getBounds() const override;
};


