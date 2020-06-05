#include "gameover.h"
#include "pipes.h"
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include "Points.h"



GameOver::GameOver()
{
 if(!texture_Game_Over.loadFromFile("C:/Users/Grzechu/Pictures/game_over.png")){std::cout<<"Fail game_over_tx load"<<std::endl;exit(0);}
 Game_over.setTexture(texture_Game_Over);
 texture_Game_Over.setSmooth(1);
 Game_over.setPosition(110,70);
 Game_over.setScale(1.2,1.2);

 if(!texture_ScoreBoard.loadFromFile("C:/Users/Grzechu/Pictures/ScoreBoardd.png")){std::cout<<"Fail score_board_tx load"<<std::endl;exit(0);}
 ScoreBoard.setTexture(texture_ScoreBoard);
 ScoreBoard.setPosition(85,150);
 ScoreBoard.setScale(1.2,1.2);
 texture_ScoreBoard.setSmooth(1);

 if(!texture_playAgain.loadFromFile("C:/Users/Grzechu/Pictures/playagain.png")){std::cout<<"Fail score_board_tx load"<<std::endl;exit(0);}
 PlayAgainButton.setTexture(texture_playAgain);
 PlayAgainButton.setPosition(100,340);
 PlayAgainButton.setScale(0.5,0.5);


 if(!texture_exit.loadFromFile("C:/Users/Grzechu/Pictures/exit_button.png")){std::cout<<"Fail score_board_tx load"<<std::endl;exit(0);}
 ExitButton.setTexture(texture_exit);
 ExitButton.setPosition(280,347);
 ExitButton.setScale(0.5,0.5);


 if(!texture_GoldMedal.loadFromFile("C:/Users/Grzechu/Pictures/gold_medal1.png")){std::cout<<"Fail gold_medal_tx load"<<std::endl;exit(0);}
 GoldMedal.setTexture(texture_GoldMedal);
 texture_GoldMedal.setSmooth(true);
 GoldMedal.setPosition(130,225);
 GoldMedal.setScale(1.5,1.5);


 if(!texture_SilverMedal.loadFromFile("C:/Users/Grzechu/Pictures/silver_medal1.png")){std::cout<<"Fail silver_medal_tx load"<<std::endl;exit(0);}
 SilverMedal.setTexture(texture_SilverMedal);
 texture_SilverMedal.setSmooth(1);
 SilverMedal.setPosition(125,220);
 SilverMedal.setScale(1.5,1.5);


 if(!texture_BronzeMedal.loadFromFile("C:/Users/Grzechu/Pictures/bronze_medal1.png")){std::cout<<"Fail bronze_medal_tx load"<<std::endl;exit(0);}
 BronzeMedal.setTexture(texture_BronzeMedal);
 texture_BronzeMedal.setSmooth(1);
 BronzeMedal.setPosition(125,223);
 BronzeMedal.setScale(1.5,1.5);


 if(!font.loadFromFile("C:/Users/Grzechu/Pictures/font.ttf")){std::cout<<"fail font loaded"<<std::endl; exit(0);}
 _scoreTx.setFont(font);
 _scoreTx.setString("0");
 _scoreTx.setCharacterSize(128);
 _scoreTx.setFillColor(sf::Color::White);
 _scoreTx.setPosition(370,210);
 _scoreTx.setScale(0.3,0.3);

}








void GameOver::Draw(sf::RenderWindow &window, int _points){
        window.draw(Game_over);
        window.draw(ScoreBoard);
        window.draw(PlayAgainButton);
        window.draw(ExitButton);
        _scoreTx.setString( std::to_string( _points ));
        window.draw( _scoreTx );
        if(_points>=10&&_points<=19){
            window.draw(BronzeMedal);
        }
        else if(_points>=20&&_points<=39){
            window.draw(SilverMedal);
        }
        else if(_points>=40){
            window.draw(GoldMedal);
        }

    }




