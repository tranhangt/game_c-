//
// Created by hang-tran on 11/12/20.
//
#pragma once
#ifndef NEWGAME_ARROW_H
#define NEWGAME_ARROW_H
#include <vector>
#include "Animation.h"
#include "Entity.h"

class Arrow : public Entity{
private:
    Texture texture;
    Sprite s;
    vector<Sprite> list;
    Animation currentAnimation;
    float currentTexture{};
    int stage;
    float angle = -0.1f;
    bool check, gameover;
public:
    explicit Arrow(string file_name);
    void Draw(RenderWindow& rd) override;
    void Update() override;
    bool isCollision(Entity* other) override;
    bool isCollision(Entity other) override;
    void Move(Vector2f velocity);
    void set_stage(int tmp) override;
    int get_stage() override;
    float okk_x(Entity* other, float ang) override;
    float okk_y(Entity* other, float ang) override;
    bool check_ck() override;
    void Update2() override;
    bool getgameover() override;

};


#endif //NEWGAME_ARROW_H
