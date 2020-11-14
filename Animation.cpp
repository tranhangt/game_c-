//
// Created by hang-tran on 11/6/20.
//

#include "Animation.h"
Animation::Animation() {

}
/*Animation::Animation(int countImg, string file_name, float deltaTime) {
    /*for(int i = 1; i <= countImg; i++){
        Texture tmpImg;
        tmpImg.loadFromFile("../" + file_name + ".png");
        listTexture.push_back(tmpImg);
    }

    this->deltaTime = deltaTime;
}*/
Animation::Animation(string file_name, float deltaTime){
    tex.loadFromFile("../" + file_name + ".png");
    this->deltaTime = deltaTime;
}
void Animation::Update() {
    currentFrame += deltaTime;
    if(currentFrame > 1){
        currentFrame = 0;
    }
}
void Animation::setTexture(Sprite &s) {
    s.setTexture(tex);
    s.setTextureRect(IntRect(0, 0, tex.getSize().x, tex.getSize().y));
    s.setOrigin((Vector2f)tex.getSize() * 0.5f);
}