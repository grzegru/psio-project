#include "pipes.h"
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>



Pipes::Pipes(int PosX, int PosY, int Distance)
{
    if(!texture_pipe_down.loadFromFile("C:/Users/Grzechu/Pictures/pipe_down.png")){std::cout<<"Fail pipe_down load"<<std::endl;exit(0);}
    if(!texture_pipe_up.loadFromFile("C:/Users/Grzechu/Pictures/pipe_up1.png")){std::cout<<"Fail pipe_up load"<<std::endl;exit(0);}


    pipe_up.setTexture( texture_pipe_up );
    pipe_up.setScale( 1 , 1 );
    pipe_up.setPosition(PosX+Distance , PosY-800);
    pipe_up.setTextureRect(sf::IntRect(0,0,52,600));

    pipe_down.setTexture( texture_pipe_down );
    pipe_down.setScale( 1 , 1 );
    pipe_down.setPosition(PosX+Distance,  PosY);                     // posY=700 , rura znika przy wartosci 1000 /  aby gra byla w miare<900,550>
    pipe_down.setTextureRect(sf::IntRect(0,0,52,100000));

 }





     Pipes::~Pipes(){}


     void Pipes::animate(sf::Time &elapsed){
         pipe_up.move(speed*elapsed.asSeconds(),0);
         pipe_down.move(speed*elapsed.asSeconds(),0);
         if(pipe_up.getPosition().x <= -50&&pipe_down.getPosition().x <= -50){                 //wylapywanie rur ktore sa poza ekranem

             int down = rand()%350+300;                            //losowane polozenie rur
             int up = down-800;           //odsetep miedzy rurami jest okej 730

             pipe_up.setPosition( 550 , up );
             pipe_down.setPosition( 550 , down );

         }


     }

     const sf::Sprite &Pipes::GetSprite( ) const{
         return pipe_up;


     }

     const sf::Sprite &Pipes::GetSprite2( ) const{
         return pipe_down;

     }




     void Pipes::Draw(sf::RenderWindow &window){
         window.draw(pipe_up);
         window.draw(pipe_down);
     }


     bool Pipes::CheckPoints(float BirdPos){

         int leftside=BirdPos;
         int rightside=BirdPos+25;

         int leftside_pipeup=pipe_up.getPosition().x;
         int rightside_pipeup=pipe_up.getPosition().x+pipe_up.getGlobalBounds().width;

         int leftside_pipedown=pipe_down.getPosition().x;
         int rightside_pipedown=pipe_down.getPosition().x+pipe_down.getGlobalBounds().width;


         if((rightside >= leftside_pipeup&&leftside <= rightside_pipeup) || (rightside >= leftside_pipedown && leftside <= rightside_pipedown)){
              return true;

          }else{
              return false;
          }





        /* if((rightside>=leftside_pipeup&&leftside<=rightside_pipeup) || (rightside >= leftside_pipedown && leftside <= rightside_pipedown)){
             return true;

         }else{
             return false;
         }*/
     }
