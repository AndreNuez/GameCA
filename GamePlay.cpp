#include <stdlib.h>
#include "GamePlay.h"

GamePlay::GamePlay()
{
    vidas = 3;
    tiempojugado = 60 * 30;
    points = 0;
    time_inmunidad = 0;

    texture_fondo.loadFromFile("ruta.png");
    image.setTexture(texture_fondo);

    font.loadFromFile("8bit.ttf");
    text.setFont(font);

    text_vida.setFont(font);
    game_over.setFont(font);

    carpincho.respawn();
    camarada.respawn();
}

void GamePlay::update()
{
<<<<<<< Updated upstream
    repartidor.update();
    carpincho.update();
    camarada.update();
=======
    if (!game_over && !llegada) {
        repartidor.update();
        carpincho.updateRandom();
        camarada.update();
        if (tiempojugado <= 5) {
            barrera.update();
        }
    }

    if (llegada) {
        popup.update();
    }
<<<<<<< Updated upstream
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
}

void GamePlay::draw(sf::RenderTarget& target, sf::RenderStates states) const
{   
    target.draw(image, states);
    target.draw(repartidor, states);
    target.draw(carpincho, states);
    target.draw(camarada, states);
    target.draw(text,states);
    target.draw(text_vida,states);

    if (vidas == 0) {
        target.draw(game_over, states);
    }

    if (llegada) {
        target.draw(popup, states);
    }

    if (llegada) {
        target.draw(popup, states);
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
<<<<<<< Updated upstream
=======
    else {
        image.move(0, 0);
        carpincho.setVelocity(sf::Vector2f(0, 0));
        camarada.setVelocity(sf::Vector2f(0, 0));
        repartidor.setAceleracion(0);
    }

    if (llegada) {
        popup.setPuntos(points);
        popup.setVidas(vidas);
    }
    
<<<<<<< Updated upstream
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
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
    bool pausa = false;
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        
        if (!pausa) {
            pausa = true;
        }
        
        else if(pausa) {
            pausa = false;
        }
    }
    

    if (vidas == 0 || pausa || tiempojugado==0) {
    
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

int GamePlay::getVidas()
{
    return vidas;
}

int GamePlay::getPuntos()
{
    return points;
}

int GamePlay::getVidas()
{
    return vidas;
}

int GamePlay::getPuntos()
{
    return points;
}
