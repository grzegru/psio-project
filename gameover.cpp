#include "gameover.h"
#include "pipes.h"
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include "Points.h"
#include <fstream>



GameOver::GameOver()
{
 if(!texture_Game_Over.loadFromFile("textures_fonts/gameover.png")){std::cout<<"Fail game_over load"<<std::endl;exit(0);}
 Game_over.setTexture(texture_Game_Over);
 texture_Game_Over.setSmooth(1);
 Game_over.setPosition(55,40);
 Game_over.setScale(0.7,0.7);

 if(!texture_ScoreBoard.loadFromFile("textures_fonts/scoreboard2.png")){std::cout<<"Fail score_board load"<<std::endl;exit(0);}
 ScoreBoard.setTexture(texture_ScoreBoard);
 ScoreBoard.setPosition(70,120);
 ScoreBoard.setScale(0.7,0.7);
 texture_ScoreBoard.setSmooth(1);

 if(!texture_playAgain.loadFromFile("textures_fonts/playagain.png")){std::cout<<"Fail playAgain load"<<std::endl;exit(0);}
 PlayAgainButton.setTexture(texture_playAgain);
 PlayAgainButton.setPosition(100,340);
 PlayAgainButton.setScale(0.5,0.5);


 if(!texture_exit.loadFromFile("textures_fonts/exit_button.png")){std::cout<<"Fail exit load"<<std::endl;exit(0);}
 ExitButton.setTexture(texture_exit);
 ExitButton.setPosition(280,347);
 ExitButton.setScale(0.5,0.5);


 if(!texture_GoldMedal.loadFromFile("textures_fonts/gold_medal1.png")){std::cout<<"Fail gold_medal load"<<std::endl;exit(0);}
 GoldMedal.setTexture(texture_GoldMedal);
 texture_GoldMedal.setSmooth(true);
 GoldMedal.setPosition(130,200);
 GoldMedal.setScale(1.5,1.5);


 if(!texture_SilverMedal.loadFromFile("textures_fonts/silver_medal1.png")){std::cout<<"Fail silver_medal load"<<std::endl;exit(0);}
 SilverMedal.setTexture(texture_SilverMedal);
 texture_SilverMedal.setSmooth(1);
 SilverMedal.setPosition(125,200);
 SilverMedal.setScale(1.5,1.5);


 if(!texture_BronzeMedal.loadFromFile("textures_fonts/bronze_medal1.png")){std::cout<<"Fail bronze_medal load"<<std::endl;exit(0);}
 BronzeMedal.setTexture(texture_BronzeMedal);
 texture_BronzeMedal.setSmooth(1);
 BronzeMedal.setPosition(125,200);
 BronzeMedal.setScale(1.5,1.5);


 if(!font.loadFromFile("textures_fonts/font.ttf")){std::cout<<"fail font loaded"<<std::endl; exit(0);}
 _scoreTx.setFont(font);
 _scoreTx.setString("0");
 _scoreTx.setCharacterSize(128);
 _scoreTx.setFillColor(sf::Color::White);
 _scoreTx.setPosition(370,195);
 _scoreTx.setScale(0.3,0.3);


 _highscoreTx.setFont(font);
 _highscoreTx.setString("0");
 _highscoreTx.setCharacterSize(128);
 _highscoreTx.setFillColor(sf::Color::White);
 _highscoreTx.setPosition(370,280);
 _highscoreTx.setScale(0.3,0.3);






}








void GameOver::Draw(sf::RenderWindow &window, int _points){       //rysowanie game over , medalu oraz punktow
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

void GameOver::HighScore(sf::RenderWindow &window, int _points){       //zczytywanie highscora
    std::ifstream highScoreReadFile;
    highScoreReadFile.open("textures_fonts/highscore.txt");

    if(highScoreReadFile.is_open()){
        while(!highScoreReadFile.eof()){
            highScoreReadFile>>_highscore;
        }
    }

    highScoreReadFile.close();

    std::ofstream highScoreWriteFile("textures_fonts/highscore.txt");

    if(highScoreWriteFile.is_open()){                         //zapisywanie nowego najlepszego wyniku(jesli jest lepszy)
        if(_points > _highscore){
            _highscore= _points;
        }
        highScoreWriteFile << _highscore;
    }
    highScoreWriteFile.close();

    _highscoreTx.setString( std::to_string( _highscore ));
    window.draw( _highscoreTx );


}


