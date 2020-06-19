#include "bird.h"
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include "pipes.h"
#include "ground.h"



Bird::Bird()
{

    sf::Context contex;


    if(!texture_bird1.loadFromFile("textures_fonts/ptak1.png")){std::cout<<"Fail bird1 load"<<std::endl;exit(0);}
    if(!texture_bird2.loadFromFile("textures_fonts/ptak2.png")){std::cout<<"Fail bird2 load"<<std::endl;exit(0);}
    if(!texture_bird3.loadFromFile("textures_fonts/ptak3.png")){std::cout<<"Fail bird3 load"<<std::endl;exit(0);}
    if(!texture_bird4.loadFromFile("textures_fonts/ptak4.png")){std::cout<<"Fail bird4 load"<<std::endl;exit(0);}

    if(!wingsoundBuffer.loadFromFile("sounds/wingsound.wav")){std::cout<<"Fail buffer load"<<std::endl;exit(0);}


    _animationBirdIterator=0;
    _animationBirdFrame.emplace_back(texture_bird1);
    _animationBirdFrame.emplace_back(texture_bird2);
    _animationBirdFrame.emplace_back(texture_bird3);
    _animationBirdFrame.emplace_back(texture_bird4);


    texture_bird1.setSmooth(true);
    texture_bird2.setSmooth(true);
    texture_bird3.setSmooth(true);
    texture_bird4.setSmooth(true);


    _birdSprite.setTextureRect(sf::IntRect(0,0,695,520));
    _birdSprite.setScale( 0.075 , 0.075 );
    _birdSprite.setPosition(PosX,PosY);
    _birdSprite.setTexture(_animationBirdFrame.at(_animationBirdIterator));

    wingsound.setBuffer(wingsoundBuffer);

    _birdSprite.setPosition(50,350);



}






      void Bird::animate(){                                    // ruch skrzydel ptaka
        if(_clock.getElapsedTime().asSeconds()>0.1){
            if(_animationBirdIterator<_animationBirdFrame.size()-1){
               _animationBirdIterator++;
            }
            else{
                _animationBirdIterator = 0;
            }
            _birdSprite.setTexture(_animationBirdFrame.at(_animationBirdIterator));
            _clock.restart();
        }
    }




    void Bird::Update(sf::Time &elapsed)                     // status ptaka(lot w gore, spadanie)
        {
            switch ( birdState ) {
            case FALLING:
                _birdSprite.move(0, gravitation * elapsed.asSeconds());

                angle += 100 * elapsed.asSeconds();
                if (angle > 25.0f)
                    angle = 25.0f;
                _birdSprite.setRotation(angle);
                break;
            case FLYING:
                _birdSprite.move(0, fly * elapsed.asSeconds());

                angle -= 100 * elapsed.asSeconds();
                if (angle < -25.0f)
                    angle = -25.0f;
                _birdSprite.setRotation(angle);
                break;

            default:
                break;
            }

            if (_moveClock.getElapsedTime().asSeconds() > 0.3)
            {
                _moveClock.restart();
                birdState = FALLING;

            }

        }



    void Bird::click(){                                    //wylapywanie klikniecia do lotu ptaka
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            _moveClock.restart();
            birdState=FLYING;
            wingsound.play();
        }

    }


    void Bird::birdfalling(sf::Time &elapsed){                            //spadek ptaka po uderzeniu w rure az do dotkniecia podloza
        if(_birdSprite.getPosition().y < _ground_height ){
            _birdSprite.move(0, fall_speed*elapsed.asSeconds());
            angle+=100*elapsed.asSeconds();
            if (angle > 50)
                angle = 50;
            _birdSprite.setRotation(angle);
        }
    }




    void Bird::Draw(sf::RenderWindow &window){

        window.draw(_birdSprite);
    }


    const sf::Sprite &Bird::GetSprite( ) const{
        return _birdSprite;
    }


    void Bird::setposition(){                            //ustawianie pozycji ptaka na poczatku nowej gry w pozycji startowej
        _birdSprite.setPosition(50,350);
        _birdSprite.setRotation(0);
    }
