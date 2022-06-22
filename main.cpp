#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <ctime>
#include "Personaje.h"
#include "Carpincho.h"
#include "CarpinchoCopado.h"
#include "GamePlay.h"

int main()
{
    std::srand((unsigned)std::time(0)); //Planto la semilla para poder usar random con ctime

    //Inicialización de la ventana:
    sf::RenderWindow window(sf::VideoMode(800, 600), "Carpincho's Attack"); //Píxeles tamaño de ventana + nombre
    window.setFramerateLimit(60); //Forzamos a que corra a 60 frames per second

    //Fuente
    //sf::Font font;
    //sf::Text text, text_vida, game_over;

    //font.loadFromFile("8bit.ttf");
    //text.setFont(font);

   // text_vida.setFont(font);
    //game_over.setFont(font);

    //Personaje repartidor;
    //int time_inmunidad = 0;
        
    //Carpincho carpincho;
    //carpincho.respawn();

   //CarpinchoCopado camarada;
    //camarada.respawn();
    int timer = 60*10; //Tiempo que tarda en volver a aparecer

    GamePlay gp;


    //Points
    int vidas = 3;
    int points = 0;


    //Fondo
    /*sf::Sprite image;
    sf::Texture texture_fondo;
    texture_fondo.loadFromFile("ruta.png");
    image.setTexture(texture_fondo);*/

    //GameLoop
    while (window.isOpen())
    {
        //ReadInput
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //if (vidas > 0) {

            gp.aceleracion();

            gp.juego();

            
            /*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
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

            int velocidad = repartidor.getAceleracion();

            image.move(0, velocidad);
            if (image.getPosition().y > 0) {
                image.setPosition(image.getPosition().x, -600);
            }*/

            /*if (timer > 0) {
                timer--;
            }*/

            //repartidor.update();
            //carpincho.setVelocity(sf::Vector2f( 0,velocidad));
            //carpincho.update();
            //camarada.setVelocity(sf::Vector2f(0, velocidad));
            //camarada.update();

            /*if (repartidor.getInmunidad()) {
                time_inmunidad++;
            }

            if (repartidor.getInmunidad() && time_inmunidad == 60 * 5) {
                repartidor.setInmunidad(false);
            }

            if (repartidor.isCollision(carpincho)) {
                carpincho.respawn();
                if (!repartidor.getInmunidad()) {
                    vidas --;
                }
            }

            if (timer == 0 && repartidor.isCollision(camarada)) {
                // Repartidor.GetInmunidad() - Agregar condicion de que si choco obst�culos no pase nada.
                repartidor.setInmunidad(true);
                time_inmunidad = 0;
                timer = 60 * 5;
                camarada.respawn();
                points += 100;
            }
        }*/

        
        //text.setPosition(602, 0);
        //text.setString("PUNTOS: " + std::to_string(points));

        //text_vida.setPosition(602, 20);
        //text_vida.setString("VIDAS: " + std::to_string(vidas));

        //game_over.setPosition(250, 300);
        //game_over.setString("GAME OVER");
        
        gp.setTextos();
        gp.update();
        
        window.clear();

        //Draw
        window.draw(gp);
        //window.draw(repartidor);
        //window.draw(carpincho);
        //window.draw(text);
        //window.draw(text_vida);

        //if (vidas == 0) {
        //    window.draw(game_over);
        //}

        if (timer == 0) {
            //window.draw(camarada);
        }

        //Display - Fli
        window.display();
    }
       
    //Liberación del juego
    return 0;
}