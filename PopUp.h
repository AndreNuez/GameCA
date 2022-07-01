#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>


class PopUp: public sf::Drawable
{
private:
	sf::RectangleShape _cuadro;
	sf::Text _texto,_texto2,_texto3, _texto4;
	sf::Font _font;
	int _puntos, _vidas;

public:
	PopUp();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void update();

	void setPuntos(int p);
	void setVidas(int v);
};

