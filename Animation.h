//
// Created by hang-tran on 11/6/20.
//
#pragma once
#ifndef MAZE_GAME_ANIMATION_H
#define MAZE_GAME_ANIMATION_H
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

class Animation {
private:
    //vector<Texture> listTexture;
    Texture tex;
    float currentFrame;
    float deltaTime;
public:
    Animation();
    //Animation(int countImg, string file_name, float deltaTime);
    Animation(string file_name, float deltaTime);
    void Update();
    void setTexture(Sprite& s);
    void Scale();
};


#endif //MAZE_GAME_ANIMATION_H
