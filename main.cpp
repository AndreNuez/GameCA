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

    int timer = 60*10; //Tiempo que tarda en volver a aparecer

    GamePlay gp;


    //Points
    int vidas = 3;
    int points = 0;



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

        gp.aceleracion();
        gp.juego();
        gp.setTextos();
        gp.pausa();
        gp.gameOver();
        gp.update();

        window.clear();

        //Draw
        window.draw(gp);

        if (timer == 0) {
            //window.draw(camarada);
        }

        //Display - Fli
        window.display();
    }
       
    //Liberación del juego
    return 0;
}