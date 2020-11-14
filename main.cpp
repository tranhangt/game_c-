#include <iostream>
#include "Virus.h"
#include "Arrow.h"
#include "Animation.h"
#include <vector>
#include <algorithm>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;
int main() {
    RenderWindow window(VideoMode(600.0f, 800.0f), "hello");
    Entity* virus = new Virus("mybia");
    Arrow arrow = Arrow("my");
    Arrow new_arrow = Arrow("my");

    Texture play, background;
    play.loadFromFile("../playbutton.png");
    background.loadFromFile("../backgrr.png");
    Sprite play_bt, back_ground;

    play_bt.scale(0.3f, 0.3f);
    play_bt.setTexture(play);
    play_bt.setOrigin((Vector2f)play_bt.getTexture()->getSize() * 0.5f);
    play_bt.setPosition(300.0f, 400.0f);

    back_ground.setTexture(background);
    back_ground.scale(1.7f, 1.7f);
    back_ground.setOrigin((Vector2f)back_ground.getTexture()->getSize() * 0.5f);
    back_ground.setPosition(250.0f, 350.0f);
    bool pressed_play = false;

    vector<Arrow> arr;
    arr.push_back(arrow);
    int stage_tmp = 0;
    while(window.isOpen()){
        Event event;
        while(window.pollEvent(event)){
            if(event.type == Event::Closed)
                window.close();
            if(Keyboard::isKeyPressed(Keyboard::Space)){
                stage_tmp++;
                stage_tmp = min(2, stage_tmp);
                new_arrow.set_stage(stage_tmp);
                arr.push_back(new_arrow);
            }
        }

        window.clear(Color(255, 255, 255));
        //window.draw(back_ground);
        if(!pressed_play) {

            if(Mouse::getPosition().x < play_bt.getOrigin().x + 115.0f && Mouse::getPosition().x > play_bt.getOrigin().x - 115.0f && Mouse::getPosition().y < play_bt.getOrigin().y + 43.0f && Mouse::getPosition().y > play_bt.getOrigin().y - 43.0f){
                play_bt.scale(0.7f, 0.7f);
            }
            if (Mouse::isButtonPressed(sf::Mouse::Left)) {
                pressed_play = true;
            }window.draw(play_bt);
        }
        if(pressed_play) {
            window.draw(back_ground);
            virus->Update();
            for(int i = 0; i < arr.size(); i++){
                for(int j = 0; j < arr.size(); j++){
                    arr[i].isCollision(arr[j]);
                    if(arr[i].getgameover()){
                        //pressed_play = false;
                    }
                }
            }

            for (int i = 0; i < arr.size(); i++) {
                arr[i].isCollision(virus);
            }
            for (int i = 0; i < arr.size(); i++) {
                arr[i].Update2();
                if (arr[i].get_stage() == 2 && arr[i].check_ck())
                    arr[i].Update();
            }
            virus->Draw(window);
            for (int i = 0; i < arr.size(); i++) {
                arr[i].Draw(window);
            }
        }
            window.display();
    }
    return 0;
}
