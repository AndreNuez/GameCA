#include <stdlib.h>
#include <iostream>
#include "GamePlay.h"

GamePlay::GamePlay()
{
    vidas = 3;
    tiempojugado = 60 * 5;
    points = 0;
    //	int timer = 60 * 10;
    time_inmunidad = 0;
    juego_pausa = false;
    game_over = false;
    llegada = false;

    vPosicionEjeX[0] = 50;
    vPosicionEjeX[1] = 50;
    vPosicionEjeX[2] = 50;
    vPosicionEjeX[3] = 50;

    texture_fondo.loadFromFile("ruta.png");
    image.setTexture(texture_fondo);

    font.loadFromFile("8bit.ttf");
    
    text.setFont(font);
    text_vida.setFont(font);
    text_game_over.setFont(font);
    text_pausa.setFont(font);

    carpincho.respawn();
    camarada.respawn();
}

void GamePlay::update()
{
    if (!game_over && !llegada) {
        repartidor.update();
        carpincho.updateRandom();
        camarada.update();
        if (tiempojugado <= 5) {
            barrera.update();
        }
    }
}

void GamePlay::draw(sf::RenderTarget& target, sf::RenderStates states) const
{   
    target.draw(image, states);
    target.draw(repartidor, states);
    target.draw(carpincho, states);
    target.draw(camarada, states);
    target.draw(text,states);
    target.draw(text_vida,states);

    if (tiempojugado < 5) {
        target.draw(barrera, states);
    }

    if (game_over) {
        target.draw(text_game_over, states);
    }
    
    if (juego_pausa) {
        target.draw(text_pausa, states);
    }
}

void GamePlay::aceleracion()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        if (repartidor.getAceleracion() < 12)
        {
            repartidor.setAceleracion(0.05);
        }
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        if (repartidor.getAceleracion() > 6)
        {
            repartidor.setAceleracion(-0.05);
        }
    }
}

void GamePlay::juego()
{
    if (!juego_pausa && !game_over && !llegada) {

        int velocidad = repartidor.getAceleracion();
        image.move(0, velocidad);
        
        if (image.getPosition().y > 0) {
            image.setPosition(image.getPosition().x, -600);
        }
        
        carpincho.setVelocity(sf::Vector2f(0, velocidad));
        camarada.setVelocity(sf::Vector2f(0, velocidad));
        barrera.setVelocity(sf::Vector2f(0, velocidad));

        if (repartidor.getInmunidad()) {
            time_inmunidad++;
        }
        if (repartidor.getInmunidad() && time_inmunidad == 60 * 5) {
            repartidor.setInmunidad(false);
        }
        if (repartidor.isCollision(carpincho)) {
            carpincho.respawn();
            //carpincho.setSprite(vPosicionEjeX[(std::rand() % 4) - 1]);
            if (!repartidor.getInmunidad()) {
                vidas--;
            }
        }
        if (repartidor.isCollision(camarada)) {
            repartidor.setInmunidad(true);
            time_inmunidad = 0;
            camarada.respawn();
            points += 100;
        }
        repartidor.setTransparencia(repartidor.getInmunidad());
        
        if (repartidor.isCollision(barrera)) {
            llegada = true;
        }

        tiempojugado--;
    }
    else {
        image.move(0, 0);
        carpincho.setVelocity(sf::Vector2f(0, 0));
        camarada.setVelocity(sf::Vector2f(0, 0));
        repartidor.setAceleracion(0);
    }
}

void GamePlay::setTextos()
{
    text.setPosition(602, 0);
    text.setString("PUNTOS: " + std::to_string(points));

    text_vida.setPosition(602, 20);
    text_vida.setString("VIDAS: " + std::to_string(vidas));

    text_game_over.setPosition(250, 300);
    text_game_over.setString("GAME OVER");

    text_pausa.setPosition(250, 300);
    text_pausa.setString("PAUSA");
}

void GamePlay::pausa()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        if (!juego_pausa) {
            juego_pausa = true;
        } 
        else if (juego_pausa) {
            juego_pausa = false;
        }
    }
    //std::cout << juego_pausa;
}


void GamePlay::gameOver()
{
    if (vidas < 1) {
        game_over = true;
    }
}
