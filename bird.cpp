#include "bird.h"
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include "pipes.h"
#include "ground.h"



Bird::Bird(int PosX, int PosY)
{


    if(!texture_bird1.loadFromFile("C:/Users/Grzechu/Pictures/ptak1.png")){std::cout<<"Fail bird1 load"<<std::endl;exit(0);}
    if(!texture_bird2.loadFromFile("C:/Users/Grzechu/Pictures/ptak2.png")){std::cout<<"Fail bird2 load"<<std::endl;exit(0);}
    if(!texture_bird3.loadFromFile("C:/Users/Grzechu/Pictures/ptak3.png")){std::cout<<"Fail bird3 load"<<std::endl;exit(0);}
    if(!texture_bird4.loadFromFile("C:/Users/Grzechu/Pictures/ptak4.png")){std::cout<<"Fail bird4 load"<<std::endl;exit(0);}


    /* _animationBirdFrame[0].loadFromFile("C:/Users/Grzechu/Pictures/ptak1.png");
     _animationBirdFrame[1].loadFromFile("C:/Users/Grzechu/Pictures/ptak1.png");
     _animationBirdFrame[2].loadFromFile("C:/Users/Grzechu/Pictures/ptak1.png");
     _animationBirdFrame[3].loadFromFile("C:/Users/Grzechu/Pictures/ptak1.png");*/



    _animationBirdIterator=0;
    _animationBirdFrame.emplace_back(texture_bird1);
    _animationBirdFrame.emplace_back(texture_bird2);
    _animationBirdFrame.emplace_back(texture_bird3);
    _animationBirdFrame.emplace_back(texture_bird4);


    texture_bird1.setSmooth(true);
    texture_bird2.setSmooth(true);
    texture_bird3.setSmooth(true);
    texture_bird4.setSmooth(true);



    bird.setScale( 0.075 , 0.075 );
    bird.setPosition(PosX,PosY);
    bird.setTexture(_animationBirdFrame.at(_animationBirdIterator));



}






      void Bird::animate(){
        if(_clock.getElapsedTime().asSeconds()>0.1){
            if(_animationBirdIterator<_animationBirdFrame.size()-1){
               _animationBirdIterator++;
            }
            else{
                _animationBirdIterator = 0;
            }
            bird.setTexture(_animationBirdFrame.at(_animationBirdIterator));
            _clock.restart();
        }
    }




    void Bird::Update(sf::Time &elapsed)
        {
            // Update state.
            switch ( birdState ) {
            case FALLING:
                bird.move(0, gravitation * elapsed.asSeconds());

                angle += 100 * elapsed.asSeconds();
                if (angle > 25.0f)
                    angle = 25.0f;
                bird.setRotation(angle);
                 //std::cout<<"falling"<<std::endl;
                break;
            case FLYING:
                bird.move(0, fly * elapsed.asSeconds());

                angle -= 100 * elapsed.asSeconds();
                if (angle < -25.0f)
                    angle = -25.0f;
                bird.setRotation(angle);
                //std::cout<<"flying"<<std::endl;
                break;
           /* case STILL:
                bird.move(0,0);

                angle-=50*elapsed.asSeconds();
                if(angle < 0)
                    angle=0;
                bird.setRotation(angle);
                std::cout<<"still";
                break;*/
            default:
                break;
            }

            if (_moveClock.getElapsedTime().asSeconds() > 0.3)
            {
                _moveClock.restart();
                birdState = FALLING;
                /*if(0.3<_moveClock.getElapsedTime().asSeconds() > 0.35){
                   _moveClock.restart();
                    birdState = FALLING; //STILL;
                }*/
            }

        }



    void Bird::click(){
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            _moveClock.restart();
            _move2Clock.restart();
            birdState=FLYING;
        }

    }


    void Bird::birdfalling(sf::Time &elapsed){
        if(bird.getPosition().y < _ground_height ){
            bird.move(0, fall_speed*elapsed.asSeconds());
            angle+=100*elapsed.asSeconds();
            if (angle > 50)
                angle = 50;
            bird.setRotation(angle);
        }
    }




    void Bird::Draw(sf::RenderWindow &window){

        window.draw(bird);
    }


    const sf::Sprite &Bird::GetSprite( ) const{
        return bird;
    }
