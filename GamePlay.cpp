#include <stdlib.h>
#include "GamePlay.h"

GamePlay::GamePlay()
{
    texture_fondo.loadFromFile("ruta.png");
    image.setTexture(texture_fondo);

    font.loadFromFile("8bit.ttf");
    text.setFont(font);

    text_vida.setFont(font);
    game_over.setFont(font);

}

void GamePlay::update()
{
    repartidor.update();
    carpincho.update();
    camarada.update();
}

void GamePlay::draw(sf::RenderTarget& target, sf::RenderStates states) const
{   
    target.draw(image, states);
    target.draw(repartidor, states);
    target.draw(carpincho, states);
    target.draw(camarada, states);
    target.draw(text,states);
    target.draw(text_vida,states);

    if (tiempojugado == 0 || vidas == 0) {
        target.draw(game_over, states);
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

    /*int velocidad = repartidor.getAceleracion();
    
    image.move(0, velocidad);
    if (image.getPosition().y > 0) {
        image.setPosition(image.getPosition().x, -600);
    }

    carpincho.setVelocity(sf::Vector2f(0, velocidad));
    camarada.setVelocity(sf::Vector2f(0, velocidad));*/

}

void GamePlay::juego()
{
    if (tiempojugado > 0 && vidas > 0) {

        if (repartidor.getInmunidad()) {
            time_inmunidad++;
        }
        if (repartidor.getInmunidad() && time_inmunidad == 60 * 5) {
            repartidor.setInmunidad(false);
        }
        if (repartidor.isCollision(carpincho)) {
            carpincho.respawn();
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
        tiempojugado--;
    }
}

void GamePlay::setTextos()
{
    text.setPosition(602, 0);
    text.setString("PUNTOS: " + std::to_string(points));

    text_vida.setPosition(602, 20);
    text_vida.setString("VIDAS: " + std::to_string(vidas));

    game_over.setPosition(250, 300);
    game_over.setString("GAME OVER");
}

void GamePlay::pausa()
{
    int velocidad = repartidor.getAceleracion();
 

    if (vidas == 0 || sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
    
        image.move(0, 0);
        carpincho.setVelocity(sf::Vector2f(0, 0));
        camarada.setVelocity(sf::Vector2f(0, 0));
    }

    else {

        image.move(0, velocidad);
        if (image.getPosition().y > 0) {
            image.setPosition(image.getPosition().x, -600);
        }

        carpincho.setVelocity(sf::Vector2f(0, velocidad));
        camarada.setVelocity(sf::Vector2f(0, velocidad));
  
    }
}
