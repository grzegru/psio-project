#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <vector>
#include <ctime>
#include "pipes.h"
#include "bird.h"
#include "ground.h"
#include "background.h"
#include "collisions.h"
#include "GameMenu.h"
#include "gameover.h"
#include "Points.h"


using namespace std;

sf::Vector2f windowsize(550,750);


//obiekty klas
Pipes pipe1(400,380,0);
Pipes pipe2(400,380,300);
Bird bird(50,400);
Ground ground(0,700);
Background background;
Collisions collision;
GameMenu gamemenu;
GameOver gameover;
Points points;







//zmienne
bool isGameStart=false;
bool BirdFlying=false;
bool isGameOver;

int amount_of_points=0;

bool addpoint=false;



int main()
{


    sf::RenderWindow window(sf::VideoMode(550,750), "Bird");
    window.setFramerateLimit(60);
    window.setActive(true);



    sf::Clock clock;


    while (window.isOpen()) {
        sf::Time elapsed=clock.restart();



            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            // clear the window with black color
            window.clear(sf::Color::Black);

            // draw everything here...



            background.draw(window);

            if(!isGameStart){
                gamemenu.Draw(window);
                if(event.type==sf::Event::MouseButtonPressed){
                    if(event.mouseButton.button==sf::Mouse::Left){
                        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                        if(gamemenu.PlayButtonSprite.getGlobalBounds().contains(mousePos.x,mousePos.y)){
                            isGameStart=true;
                        }
                    }
                }

            }else if(isGameStart){
                pipe1.Draw(window);            //rysowanie
                pipe2.Draw(window);
                bird.Draw(window);
                ground.Draw(window);

                if(pipe1.CheckPoints(bird.getPosition().x) || pipe2.CheckPoints(bird.getPosition().x)){
                    addpoint=true;
                    amount_of_points++;


                }else{
                   addpoint=false;
                  // std::cout<<amount_of_points;
                }

                //if(addpoint){
                //    amount_of_points++;
                //}else{
               //     std::cout<<amount_of_points<<std::endl;
               // }







                if(((!collision.CheckCollision(bird.GetSprite(), ground.GetSprite()))&&                      //kolizja ptaka z podlozem
                  (!collision.CheckCollision(bird.GetSprite(), pipe1.GetSprite(), pipe2.GetSprite())))&&    //kolizja ptaka z rura g
                  (!collision.CheckCollision(bird.GetSprite(), pipe1.GetSprite2(), pipe2.GetSprite2())))    //kolizja ptaka z rura d
                {

                    pipe1.animate(elapsed);         //poruszanie sie rur
                    pipe2.animate(elapsed);


                    ground.animate(elapsed);        //ruch podłoża


                    bird.animate();                          //ruch skrzydel ptaka
                    bird.Update(elapsed);                    //metoda odpowiadajaca za lot ptaka po kliknieciu(w osi OY oraz rotacja)
                    bird.click();                             //wylapywanie klikniecia

                }else{
                   // gameover.Draw(window);
                }
            }







            // end the current frame
            window.display();
        }



    return 0;
}
