#pragma once
#include <SFML\Graphics.hpp>
#include "Collisionable.h"

class Personaje: public sf::Drawable, public Collisionable, public sf::Transformable
{
private: 
	sf::Sprite _sprite;
	sf::Texture _texture;
	sf::Vector2f _velocity;
	bool _inmunidad;
	float _aceleracion;
public: 
	Personaje();
	void update();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	sf::FloatRect getBounds() const override;
	void setInmunidad(bool inmunidad);
	bool getInmunidad();
	void setAceleracion(float aceleracion);
	float getAceleracion();
	void setTransparencia(bool);
};

