#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
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
#include "bonus.h"



using namespace std;

sf::Vector2f windowsize(550,750);
sf::Vector2f birdpos(50,400);


//obiekty klas
bonus bon;
Pipes pipe1;
Pipes pipe2;
Bird bird;
Ground ground(0,700);
Background background;
Collisions collision;
GameMenu gamemenu;
GameOver gameover;
Points points;




//zmienne
bool isGameStart=false;

bool isGameOver=false;

bool isTaped=false;

bool isBonus = false;

int amount_of_points=9;

int timer = 0;





int main()
{


    sf::RenderWindow window(sf::VideoMode(550,750), "Bird");
    window.setFramerateLimit(60);
    window.setActive(true);



    sf::Clock clock;
    sf::Clock _clock;


    while (window.isOpen()) {
        sf::Time elapsed=clock.restart();



            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            // clear the window with black color
            window.clear(sf::Color::Black);




            background.draw(window);


            if((isGameStart==false) && (isGameOver==false) && (isTaped==false)){
                gamemenu.Draw(window);                                          //      menu
                amount_of_points=0;
                bird.setposition();
                pipe1.setPipe1position();
                pipe2.setPipe2position();




                if(event.type==sf::Event::MouseButtonPressed){
                    if(event.mouseButton.button==sf::Mouse::Left){
                        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                        if(gamemenu.PlayButtonSprite.getGlobalBounds().contains(mousePos.x,mousePos.y)){
                            isGameStart=true;
                            gamemenu.clickPlay();
                            _clock.restart();
                        }
                    }
                }
            }else if((isGameStart==true) && (isGameOver==false) && (isTaped==false)){     //get_ready

                bird.animate();
                ground.animate(elapsed, isBonus);



                bird.Draw(window);
                gamemenu.Draw2(window);
                ground.Draw(window);

                if(_clock.getElapsedTime().asSeconds()>0.2){
                    if(event.type==sf::Event::MouseButtonPressed){
                       if(event.mouseButton.button==sf::Mouse::Left){
                          isGameStart=true;
                          isGameOver=false;
                         isTaped=true;
                        }
                    }
                }




            }else if((isGameStart==true) && (isGameOver==false) && (isTaped==true)){   // game

                if (event.mouseButton.button == sf::Mouse::Right) {
                    isBonus = !isBonus;
                    amount_of_points = 15;

                }
                if (isBonus) {

                    if (timer >= 300) { //3000
                        timer = 0;
                        isBonus = false;
                    }
                    else {

                        timer++;
                    }

                }
                bon.animate(window, elapsed.asSeconds(),pipe2.getPosition().x);
                gamemenu.Animate(isBonus);
                pipe1.animate(elapsed, isBonus, amount_of_points);
                pipe2.animate(elapsed, isBonus, amount_of_points);

                ground.animate(elapsed, isBonus);

                bird.animate();
                bird.Update(elapsed);                    //metoda odpowiadajaca za lot ptaka po kliknieciu(w osi OY oraz rotacja)
                bird.click();                             //wylapywanie klikniecia





                if(pipe1.CheckPoints(bird.getPosition().x) || pipe2.CheckPoints(bird.getPosition().x)){
                    amount_of_points=amount_of_points+1;
                    points.PointsSound();

                }
                   points.updateScore(amount_of_points);

                   if (collision.CheckCollision(bird.GetSprite(), bon.getSprite())){
                       isBonus = true;
                       bon.harvest();
                }


                if(((collision.CheckCollision(bird.GetSprite(), ground.GetSprite())) ||                     //kolizja ptaka z podlozem
                  (collision.CheckCollision(bird.GetSprite(), pipe1.GetSprite(), pipe2.GetSprite(), isBonus))) ||    //kolizja ptaka z rura g
                  (collision.CheckCollision(bird.GetSprite(), pipe1.GetSprite2(), pipe2.GetSprite2(), isBonus))){    //kolizja ptaka z rura d
                    isGameOver=true;
                    isGameStart=false;
                    collision.collisionSound();

                }




                pipe1.Draw(window);
                pipe2.Draw(window);
                bird.Draw(window);
                ground.Draw(window);
                points.Draw(window);


            }else if((isGameStart==false) && (isGameOver==true) && (isTaped==true)){ // game over

                bird.birdfalling(elapsed);

                if(event.type==sf::Event::MouseButtonPressed){
                    if(event.mouseButton.button==sf::Mouse::Left){
                        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                        if(gameover.PlayAgainButton.getGlobalBounds().contains(mousePos.x,mousePos.y)){
                            isGameOver=false;
                            isGameStart=false;
                            isTaped=false;
                            amount_of_points=0;



                        }else if(gameover.ExitButton.getGlobalBounds().contains(mousePos.x,mousePos.y)){
                            window.close();
                        }
                    }
                }
                pipe1.Draw(window);
                pipe2.Draw(window);
                bird.Draw(window);
                ground.Draw(window);
                gameover.Draw(window, amount_of_points);
                gameover.HighScore(window, amount_of_points);



            }






            // end the current frame
            window.display();
        }



    return 0;
}
