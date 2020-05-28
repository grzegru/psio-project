#include "gameover.h"
#include "pipes.h"
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include "Points.h"



GameOver::GameOver()
{
 if(!texture_Game_Over.loadFromFile("C:/Users/Grzechu/Pictures/ptak1.png")){std::cout<<"Fail game_over_tx load"<<std::endl;exit(0);}
 Game_over.setTexture(texture_Game_Over);
 Game_over.setPosition(50,120);
 Game_over.setScale(1,1);

 if(!texture_ScoreBoard.loadFromFile("C:/Users/Grzechu/Pictures/scoreboard.png")){std::cout<<"Fail score_board_tx load"<<std::endl;exit(0);}
 ScoreBoard.setTexture(texture_ScoreBoard);
 ScoreBoard.setPosition(35,150);
 ScoreBoard.setScale(0.7,0.7);

 if(!texture_GoldMedal.loadFromFile("C:/Users/Grzechu/Pictures/gold_medal1.png")){std::cout<<"Fail gold_medal_tx load"<<std::endl;exit(0);}
 GoldMedal.setTexture(texture_GoldMedal);
 texture_GoldMedal.setSmooth(true);
 GoldMedal.setPosition(98,250);
 GoldMedal.setScale(1.5,1.5);


 if(!texture_SilverMedal.loadFromFile("C:/Users/Grzechu/Pictures/silver_medal1.png")){std::cout<<"Fail silver_medal_tx load"<<std::endl;exit(0);}
 SilverMedal.setTexture(texture_SilverMedal);
 texture_SilverMedal.setSmooth(1);
 SilverMedal.setPosition(98,250);
 SilverMedal.setScale(1.5,1.5);


 if(!texture_BronzeMedal.loadFromFile("C:/Users/Grzechu/Pictures/bronze_medal1.png")){std::cout<<"Fail bronze_medal_tx load"<<std::endl;exit(0);}
 BronzeMedal.setTexture(texture_BronzeMedal);
 texture_BronzeMedal.setSmooth(1);
 BronzeMedal.setPosition(98,250);
 BronzeMedal.setScale(1.5,1.5);

}




void GameOver::Draw(sf::RenderWindow &window){
    window.draw(ScoreBoard);
    window.draw(BronzeMedal);

}




void GameOver::PipeCollision(sf::RenderWindow &window, bool isGameOver, int points){
    if(isGameOver){
        window.draw(Game_over);
        window.draw(ScoreBoard);
        if(points>=10&&points<=19){
            window.draw(BronzeMedal);
        }
        else if(points>=20&&points<=39){
            window.draw(SilverMedal);
        }
        else if(points>=40){
            window.draw(GoldMedal);
        }

    }
}
