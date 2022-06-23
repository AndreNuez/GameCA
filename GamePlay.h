#pragma once
#include <SFML\Graphics.hpp>
#include "Personaje.h"
#include "Carpincho.h"
#include "CarpinchoCopado.h"

class GamePlay: public sf::Drawable
{
private:
	Personaje repartidor;
	Carpincho carpincho;
	CarpinchoCopado camarada;
	sf::Sprite image;
	sf::Texture texture_fondo;
	sf::Font font;
	sf::Text text, text_vida, game_over;

	int vidas = 3;
	int tiempojugado = 60*30;
	int points = 0;
//	int timer = 60 * 10;
	int time_inmunidad = 0;

public:
	GamePlay();
	void update();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void aceleracion();
//	void respawn();
	void juego();
	void setTextos();
};

