#pragma once
#include <SFML/Graphics.hpp>
#include "Carpincho.h"

class CarpinchoCopado: public Carpincho
{
private:
	//sf::Sprite _sprite;

public:
	CarpinchoCopado();
	void update();
	void draw(sf::RenderTarget&, sf::RenderStates) const override;
	void respawn();
	sf::FloatRect getBounds() const override;
};

