//
// Created by hang-tran on 11/12/20.
//
#pragma once
#include "Entity.h"
#include "Animation.h"
#ifndef NEWGAME_VIRUS_H
#define NEWGAME_VIRUS_H


class Virus : public Entity{
private:
    Texture texture;
    Sprite vi;
    Animation currentAnimation;
public:
    Virus(string name);
    void Update() override;
    void Draw(RenderWindow& rd);
    bool isCollision(Entity other);
    //[[maybe_unused]] void Scale();
};


#endif //NEWGAME_VIRUS_H
