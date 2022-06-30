#pragma once
#include <SFML\Graphics.hpp>
#include "Personaje.h"
#include "Obstaculo.h"
#include "Carpincho.h"
#include "CarpinchoCopado.h"

class GamePlay: public sf::Drawable
{
private:
	Personaje repartidor;
	Carpincho carpincho;
	CarpinchoCopado camarada;
	Obstaculo barrera;
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
	bool llegada;
	int vPosicionEjeX[4];


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

