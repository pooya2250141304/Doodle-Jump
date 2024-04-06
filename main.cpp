#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <time.h>
#include <iostream>
#include <sstream>
#include <windows.h>
#include "stru.h"
#include "populatePlats.h"
#include "movePlats.h"
#include "generatePlats.h"
#include "overlapnig_detector.h"

using namespace sf;

void drawPlat(RenderWindow &app, int n, Sprite sPlat, point plat[]){
    for (int i=0;i<n;i++){
        sPlat.setPosition(plat[i].x,plat[i].y);
        app.draw(sPlat);
    }
}

void setcaract_text(Text &text, const Font& font, const std::ostringstream& ss, const int font_size, const float x, const float y){
    text.setFont(font);
    text.setString(ss.str());
    text.setCharacterSize(font_size);
    text.setPosition(x, y);
}

int highScore=0, score=0;
int hardness = 1 ;
bool Menu(RenderWindow &app){

    Texture t1,t2,t3,t4,t5,t6;
    t1.loadFromFile("C:\\Users\\Lenovo\\Desktop\\New folder (7)\\fine7\\images\\menu_background.png");
    t2.loadFromFile("C:\\Users\\Lenovo\\Desktop\\New folder (7)\\fine7\\images\\play.png");
    t3.loadFromFile("C:\\Users\\Lenovo\\Desktop\\New folder (7)\\fine7\\images\\quit.png");
    t4.loadFromFile("C:\\Users\\Lenovo\\Desktop\\New folder (7)\\fine7\\images\\play.png");
    t5.loadFromFile("C:\\Users\\Lenovo\\Desktop\\New folder (7)\\fine7\\images\\hard.jpg");
    t6.loadFromFile("C:\\Users\\Lenovo\\Desktop\\New folder (7)\\fine7\\images\\easy.jpg");


    Sprite sBackground(t1), sPlay(t2),  sQuit(t3), sPlayh(t4), sHard(t5), sEasy(t6);
    sPlay.setPosition(220, 320);
    sQuit.setPosition(150, 480);
    sPlayh.setPosition(220,360);
    sHard.setPosition(322,365);
    sEasy.setPosition(142,324);

    app.draw(sBackground);
    app.draw(sPlay);
    app.draw(sPlayh);
    app.draw(sQuit);
    app.draw(sHard);
    app.draw(sEasy);
    app.display();
    app.setFramerateLimit(0);

    while(app.isOpen()){
        Event e;

        while (app.pollEvent(e)){
            if (e.type == Event::Closed)
                return false;
        }

        if(Mouse::isButtonPressed(Mouse::Left)){
            Vector2f mouse = app.mapPixelToCoords(Mouse::getPosition(app));
            FloatRect bounds1 = sPlay.getGlobalBounds(), bounds2 = sQuit.getGlobalBounds(), bounds3 = sPlayh.getGlobalBounds();
            if (bounds1.contains(mouse)){
                return true;
            }
            else if (bounds3.contains(mouse)){
                hardness = 2;
                return true;
            }
            else if (bounds2.contains(mouse)){
                return false;
            }
        }
        Sleep(1);
    }
    return false;
}

int Game(RenderWindow &app){

    srand(time(0));

    app.setFramerateLimit(80);

    Texture t1,t2,t3,t4,t5,t6,t7,t8,t9;
    t1.loadFromFile("C:\\Users\\Lenovo\\Desktop\\New folder (7)\\fine7\\images\\background.jpg");
    t2.loadFromFile("C:\\Users\\Lenovo\\Desktop\\New folder (7)\\fine7\\images\\platform.png");
    t3.loadFromFile("C:\\Users\\Lenovo\\Desktop\\New folder (7)\\fine7\\images\\platform_destruct.png");
    t4.loadFromFile("C:\\Users\\Lenovo\\Desktop\\New folder (7)\\fine7\\images\\platform_floating.png");
    t5.loadFromFile("C:\\Users\\Lenovo\\Desktop\\New folder (7)\\fine7\\images\\platform_bounce.png");
    t6.loadFromFile("C:\\Users\\Lenovo\\Desktop\\New folder (7)\\fine7\\images\\doodle.png");
    t7.loadFromFile("C:\\Users\\Lenovo\\Desktop\\New folder (7)\\fine7\\images\\top_border.png");
    t8.loadFromFile("C:\\Users\\Lenovo\\Desktop\\New folder (7)\\fine7\\images\\border_border.png");
    t9.loadFromFile("C:\\Users\\Lenovo\\Desktop\\New folder (7)\\fine7\\images\\pause.png");

    Sprite sBackground(t1), sPlat1(t2), sPlat2(t3), sPlat3(t4), sPlat4(t5), sPers(t6), sBorder1(t7), sBorder2(t8), sPauseButton(t9);

    point plat1[14], plat2[6], plat3[4], plat4[2];

    if(hardness == 1) {
        populatePlats(plat1, 7);
        populatePlats(plat2, 3);
        populatePlats(plat3, 2);
        populatePlats(plat4, 1);
        overlaping_detector(plat1, plat2, plat3, plat4, 14, 6, 4, 2);
    }

    if(hardness == 2) {
        populatePlats(plat1, 2);
        populatePlats(plat2, 3);
        populatePlats(plat3, 1);
        populatePlats(plat4, 1);
        overlaping_detector(plat1, plat2, plat3, plat4, 14, 6, 4, 2);
    }

    int x=160, y=0, h=200, mx = 200;
    float dy=0;
    score=0;
    Text text;
    Font font;
    int isSpring = 0;
    int direction[3] = {0,0,0};
    std::ostringstream ss;
    if(!font.loadFromFile("C:\\Users\\Lenovo\\Desktop\\New folder (7)\\fine7\\res\\nanumgothic.ttf")){
        std::cout<<"Error loading file!"<<std::endl;
        app.close();
        return 0;
    }
    while (app.isOpen()){
        ss<<"Score : "<<score;

        setcaract_text(text, font, ss, 30, 5, 2);
        text.setFillColor(Color::White);
        text.setStyle(Text::Style::Italic);

        sPauseButton.setPosition(355, 5);

        Event e;
        while (app.pollEvent(e)){
            if (e.type == Event::Closed)
                return 0;
        }

        if(Mouse::isButtonPressed(Mouse::Left)){

            Vector2f mouse = app.mapPixelToCoords(Mouse::getPosition(app));

            FloatRect bounds = sPauseButton.getGlobalBounds();

            bounds.height -=5;
            bounds.width -=5;
            bounds.left +=5;
            bounds.top +=5;

            if (bounds.contains(mouse)){
                bool isPaused = true;

                std::ostringstream pauseoutput;
                pauseoutput<<"Paused\n(Right Click To Resume)";

                Texture t10;
                t10.loadFromFile("C:\\Users\\Lenovo\\Desktop\\New folder (7)\\fine7\\images\\resume.png");

                Sprite sResumeButton(t10);
                sResumeButton.setPosition(355, 5);

                Text text2;

                setcaract_text(text2, font, pauseoutput, 35, 0, 445);
                text2.setFillColor(Color::White);
                text2.setStyle(Text::Italic);

                app.draw(text2);
                app.draw(sResumeButton);
                app.display();

                app.setFramerateLimit(0);

                while (isPaused){
                    if(Mouse::isButtonPressed(Mouse::Right)){
                        mouse = app.mapPixelToCoords(Mouse::getPosition(app));

                        bounds = sResumeButton.getGlobalBounds();
                        bounds.height -=5;
                        bounds.width -=5;
                        bounds.left +=5;
                        bounds.top +=5;

                        if (bounds.contains(mouse)){
                            isPaused = false;
                        }
                    }
                    Event exit;
                    while (app.pollEvent(exit)){
                        if (exit.type == Event::Closed)
                            return 0;
                    }
                    Sleep(1);
                }
                app.setFramerateLimit(80);
                app.draw(sPauseButton);
                pauseoutput.str("");
                app.display();
            }
        }

        if (Keyboard::isKeyPressed(Keyboard::Right)){
            x+=5;
            t6.loadFromFile("C:\\Users\\Lenovo\\Desktop\\New folder (7)\\fine7\\images\\doodlereverse.png");
        }
        if (Keyboard::isKeyPressed(Keyboard::Left)){
            x-=5;
            t6.loadFromFile("C:\\Users\\Lenovo\\Desktop\\New folder (7)\\fine7\\images\\doodle.png");
        }

        int i;

        for(i=0;i<2;i++) movePlats(plat3, 4, direction, i, plat1, plat2, plat4, 14, 6, 2);

        dy+=0.2;
        y+=dy;

        if (y<h){
            y = h;

            generatePlats(plat1, 7, dy);
            generatePlats(plat2, 3, dy);
            generatePlats(plat3, 2, dy);
            generatePlats(plat4, 1, dy);
            overlaping_detector(plat1, plat2, plat3, plat4, 14, 6, 4, 2);
        }
        for (i=0;i<7;i++)
            if ((x+50>plat1[i].x)&&(x+20<plat1[i].x+68)&&(y+68>plat1[i].y)&&(y+68<plat1[i].y+14)&&(dy>0))
                dy=-10;
        for (i=0;i<3;i++)
            if ((x+50>plat2[i].x)&&(x+20<plat2[i].x+68)&&(y+68>plat2[i].y)&&(y+68<plat2[i].y+14)&&(dy>0))
                plat2[i].y=534;
        for (i=0;i<2;i++)
            if ((x+50>plat3[i].x)&&(x+20<plat3[i].x+68)&&(y+68>plat3[i].y)&&(y+68<plat3[i].y+14)&&(dy>0))
                dy=-10;


        if ((x+50>plat4[0].x)&&(x+20<plat4[0].x+68)&&(y+68>plat4[0].y)&&(y+68<plat4[0].y+14)&&(dy>0)){
            dy=-50;
            isSpring = 1;
        }

        sPers.setPosition(x,y);

        app.draw(sBackground);
        app.draw(sPers);
        app.draw(sPauseButton);

        drawPlat(app, 7, sPlat1, plat1);
        drawPlat(app, 3, sPlat2, plat2);
        drawPlat(app, 2, sPlat3, plat3);
        drawPlat(app, 1, sPlat4, plat4);

        app.draw(text);
        app.display();

        if(x<-40) x=390;
        else if (x>390) x=-40;

        if (dy>=10.76){
            if (score>highScore) highScore = score;
            return 1;
        }

        if (y < 240 && mx > y){
            if (mx > 240) mx = 240;
            if (isSpring == 1) score+=5*(mx-y);
            else score+=mx-y;
            mx = y;
        }
        else if (y == 200){
            if (isSpring == 1) score+=5;
            else score+=1;
            mx = 200;
        }
        else if (mx == 200 && y > 200){
            isSpring = 0;
            mx = y;
        }

        ss.str("");
    }
    return 1;
}

bool DeathScreen(RenderWindow &app){
    Texture t1,t2,t3;
    t1.loadFromFile("C:\\Users\\Lenovo\\Desktop\\New folder (7)\\fine7\\images\\death_background.jpg");
    t2.loadFromFile("C:\\Users\\Lenovo\\Desktop\\New folder (7)\\fine7\\images\\play.png");
    t3.loadFromFile("C:\\Users\\Lenovo\\Desktop\\New folder (7)\\fine7\\images\\quit.png");

    Sprite sBackground(t1), sReplay(t2), sQuit(t3);
    sReplay.setPosition(230, 400);
    sQuit.setPosition(230, 440);

    Text text_score, text_highscore, text_title;
    std::ostringstream print_score, print_highscore, print_title;

    print_score<<"Score: "<<score;
    print_highscore<<"Highscore: "<<highScore;
    print_title<<"GAME OVER!";

    Font font, font_title;
    if(!font.loadFromFile("C:\\Users\\Lenovo\\Desktop\\New folder (7)\\fine7\\res\\times-new-roman.ttf")){
        std::cout<<"Error loading file!"<<std::endl;
        app.close();
        return 0;
    }
    if(!font_title.loadFromFile("C:\\Users\\Lenovo\\Desktop\\New folder (7)\\fine7\\res\\BarkingCatDEMO.otf")){
        std::cout<<"Error loading file!"<<std::endl;
        app.close();
        return 0;
    }

    setcaract_text(text_score, font, print_score, 30, 50, 200);
    text_score.setFillColor(Color::Black);
    text_score.setStyle(Text::Bold);

    setcaract_text(text_highscore, font, print_highscore, 30, 40, 240);
    text_highscore.setFillColor(Color::Black);
    text_highscore.setStyle(Text::Bold);

    setcaract_text(text_title, font_title, print_title, 47, 33, 47);
    text_title.setFillColor(Color::Black);
    text_title.setStyle(Text::Bold);

    app.draw(sBackground);
    app.draw(sReplay);
    app.draw(sQuit);
    app.draw(text_title);
    app.draw(text_score);
    app.draw(text_highscore);
    app.display();

    print_title.str("");
    print_score.str("");
    print_highscore.str("");
    app.setFramerateLimit(0);

    while(app.isOpen()){

        Event e;
        while (app.pollEvent(e)){
            if (e.type == Event::Closed)
                return false;
        }

        if(Mouse::isButtonPressed(Mouse::Left)){
            Vector2f mouse = app.mapPixelToCoords(Mouse::getPosition(app));
            FloatRect bounds1 = sReplay.getGlobalBounds(), bounds2 = sQuit.getGlobalBounds();
            if (bounds1.contains(mouse)){
                return true;
            }
            if(bounds2.contains(mouse)){
                return false;
            }
        }
        Sleep(1);
    }
    return false;
}

int main()
{

    RenderWindow app(VideoMode(400, 533), "Doodle jumpagne",Style::Close);

    sf::Image icon;
    icon.loadFromFile("C:\\Users\\Lenovo\\Desktop\\New folder (7)\\fine7\\images\\icoon.png");
    app.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

//    sf::Music music;
//    if (!music.openFromFile("C:\\Users\\Lenovo\\Desktop\\New folder (6)\\fine6\\music\\Central-Cee.wav"))
//    {
//        std::cout << "music failed" << std::endl;
//    }
//    else
//    {
//        music.setLoop(true);
//        music.play();
//    }

    app.setFramerateLimit(60);
    if (!Menu(app)){
        app.close();
        return 0;
    }
    else {
        int ok=1;
        while (ok)
            if (Game(app)){
                if (!DeathScreen(app)) ok=0;
            }
            else ok=0;
    }
    app.close();
    return 0;
}