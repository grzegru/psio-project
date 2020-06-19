#include "pipes.h"
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdlib>
#include <ctime>



Pipes::Pipes()
{
    if(!texture_pipe_down.loadFromFile("textures_fonts/pipe_down.png")){std::cout<<"Fail pipe_down load"<<std::endl;exit(0);}
    if(!texture_pipe_up.loadFromFile("textures_fonts/pipe_up.png")){std::cout<<"Fail pipe_up load"<<std::endl;exit(0);}


    pipe_upSprite.setTexture( texture_pipe_up );
    pipe_upSprite.setScale( 1 , 1 );
    pipe_upSprite.setTextureRect(sf::IntRect(0,0,52,600));

    pipe_downSprite.setTexture( texture_pipe_down );
    pipe_downSprite.setScale( 1 , 1 );
    pipe_downSprite.setTextureRect(sf::IntRect(0,0,52,100000));

 }





     Pipes::~Pipes(){}


     void Pipes::animate(sf::Time &elapsed){

         pipe_upSprite.move(speed*elapsed.asSeconds(),0);
         pipe_downSprite.move(speed*elapsed.asSeconds(),0);
         if(pipe_upSprite.getPosition().x <= -50&&pipe_downSprite.getPosition().x <= -50){    //wylapywanie rur ktore sa poza ekranem
             int down = rand()%350+300;                                                      //losowane polozenie rur
             int up = down-770;                                                             // regulowanie odstepu miedzy rurami
             pipe_upSprite.setPosition( 550 , up );
             pipe_downSprite.setPosition( 550 , down );

         }


     }

     const sf::Sprite &Pipes::GetSprite( ) const{
         return pipe_upSprite;


     }

     const sf::Sprite &Pipes::GetSprite2( ) const{
         return pipe_downSprite;

     }




     void Pipes::Draw(sf::RenderWindow &window){
         window.draw(pipe_upSprite);
         window.draw(pipe_downSprite);
     }


     bool Pipes::CheckPoints(float BirdPos){                 //funkcja do liczenia punktow

         int leftside=BirdPos;
         int rightside=BirdPos+2;


         float leftside_pipeup=pipe_upSprite.getPosition().x+15;
         float rightside_pipeup=pipe_upSprite.getPosition().x+15.5;
         float leftside_pipedown=pipe_downSprite.getPosition().x+15;
         float rightside_pipedown=pipe_downSprite.getPosition().x+15.5;



         if (((rightside >= leftside_pipeup) && (leftside <= rightside_pipeup)) || ((rightside >= leftside_pipedown) && (leftside <= rightside_pipedown))){
             return true;
         }else{
             return false;
         }


     }


     void Pipes::setPipe1position(){                  //ustawianie rur w pozycji startowej na poczatku nowej gry
         pipe_upSprite.setPosition(_posX , _posY-_difference);
         pipe_downSprite.setPosition(_posX , _posY );

     }

     void Pipes::setPipe2position(){
         pipe_upSprite.setPosition(_posX+_distance , _posY-_difference);
         pipe_downSprite.setPosition(_posX+_distance , _posY);

     }
