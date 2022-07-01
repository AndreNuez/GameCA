#include "PopUp.h"

PopUp::PopUp()
{
	// Cuadro Negro
	_cuadro.setSize(sf::Vector2f(400, 300));
	_cuadro.setOrigin(sf::Vector2f(_cuadro.getLocalBounds().width /2, _cuadro.getLocalBounds().height /2));
	_cuadro.setPosition(sf::Vector2f(300, 300));
	_cuadro.setFillColor(sf::Color::Black);

	// Establecemos fuente y tamaño
	_font.loadFromFile("8bit.ttf");
	

	//Texto 1
	_texto.setFont(_font);
	_texto.setCharacterSize(30);
	_texto.setPosition(sf::Vector2f(200,150));
	_texto.setString("¡FELICITACIONES!");

	//Texto PUNTOS
	_texto2.setFont(_font);
	_texto2.setCharacterSize(30);
	_texto2.setPosition(sf::Vector2f(110,250));
	_texto2.setString("PUNTOS ACUMULADOS: " + std::to_string(_puntos));

	// Texto VIDAS
	_texto3.setFont(_font);
	_texto3.setCharacterSize(30);
	_texto3.setPosition(sf::Vector2f(110, 300));
	_texto3.setString("VIDAS RESTANTES: " + std::to_string(_vidas));

	//Texto ENTER
	_texto4.setFont(_font);
	_texto4.setCharacterSize(25);
	_texto4.setPosition(sf::Vector2f(125, 400));
	_texto4.setString("PRESIONE ENTER PARA CONTINUAR");
}

void PopUp::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(_cuadro, states);
	target.draw(_texto, states);
	target.draw(_texto2, states);
	target.draw(_texto3, states);
	target.draw(_texto4, states);
}

void PopUp::update()
{
	_texto2.setString("PUNTOS ACUMULADOS: " + std::to_string(_puntos));
	_texto3.setString("VIDAS RESTANTES: " + std::to_string(_vidas));
}

void PopUp::setPuntos(int p)
{
	_puntos = p;
}

void PopUp::setVidas(int v)
{
	_vidas = v;
}
