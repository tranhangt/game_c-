//
// Created by hang-tran on 11/6/20.
//
#pragma once
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#ifndef MAZE_GAME_ENTITY_H
#define MAZE_GAME_ENTITY_H
using namespace sf;
using namespace std;

class Entity {
protected:
    Vector2f Size;
    string name;
    Vector2f Velocity;
    RectangleShape body;
public:
    Entity();
    virtual void Update();
    virtual void Draw(RenderWindow& rd);
    virtual void Draw(RenderWindow& rd, int i);
    void resize(Vector2f size);
    void setPosition(Vector2f Position);
    RectangleShape getBody();
    Vector2f getPosition();
    virtual bool isCollision(Entity other);
    virtual bool isCollision(Entity* other);
    virtual void set_stage(int tmp);
    virtual int get_stage();
    virtual float okk_x(Entity* other, float angle);
    virtual float okk_y(Entity* other, float angle);
    virtual bool check_ck();
    virtual void Update2();
    virtual bool getgameover();

};


#endif //MAZE_GAME_ENTITY_H
