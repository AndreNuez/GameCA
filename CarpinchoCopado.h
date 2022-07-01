#pragma once
#include <SFML/Graphics.hpp>
#include "Carpincho.h"

class CarpinchoCopado: public Carpincho
{

public:
	CarpinchoCopado();
	void update();
	void draw(sf::RenderTarget&, sf::RenderStates) const override;
	void respawn();
	sf::FloatRect getBounds() const override;
};