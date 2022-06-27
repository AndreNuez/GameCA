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
	sf::Text text, text_vida, text_game_over, text_pausa;

	int vidas;
	int tiempojugado;
	int points;
//	int timer = 60 * 10;
	int time_inmunidad;
	bool juego_pausa;
	bool game_over;

public:
	GamePlay();
	void update();
	void setTextos();

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void aceleracion();
//	void respawn();
	void juego();
	void pausa();
	void gameOver();
};

