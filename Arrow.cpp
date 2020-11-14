//
// Created by hang-tran on 11/12/20.
//
#include <cmath>
#include "Arrow.h"
Arrow::Arrow(string name) {
    currentAnimation = Animation(name, 1.f/60);
    currentAnimation.setTexture(s);
    s.setPosition(300.0f, 730.0f);
    s.setOrigin(s.getTexture()->getSize().x * 0.5f, 200.0f);
    this->body.setSize((Vector2f)s.getTexture()->getSize());
    this->body.setOrigin(s.getTexture()->getSize().x * 0.5f, 200.0f);
    this->body.setPosition(300.0f, 730.0f);
    this->check = true;
    this->gameover = false;
    this->angle = 7.0f;
}
void Arrow::Draw(RenderWindow &rd) {
    Entity::Draw(rd);
    rd.draw(s);
}
void Arrow::Update() {
    //this->currentAnimation.setTexture(s);
    //s.setPosition(body.getPosition());
    if(Keyboard::isKeyPressed(Keyboard::Space)){
        //this->Velocity.y = -0.5f;
        //this->Velocity.x = 0;
        s.rotate(angle);
    }
    this->angle += 7.f;
    Move(this->Velocity);
}
void Arrow::Update2() {
    this->currentAnimation.setTexture(s);
}
void Arrow::Move(Vector2f velocity) {
    s.move(velocity);
    body.setPosition(s.getPosition());
}
bool Arrow::isCollision(Entity* other) {
    if(other->getBody().getGlobalBounds().intersects(s.getGlobalBounds())){
        check = false;
        body.rotate(angle);
        s.rotate(angle);
        //s.setPosition(body.getPosition().x, body.getPosition().y);
        //body.setPosition((Vector2f)s.getPosition());
        return true;
    }
    return false;
}
bool Arrow::isCollision(Entity other) {
    if(other.getBody().getGlobalBounds().intersects(s.getGlobalBounds())){
        gameover = true;
        return true;
    }
    return false;
}
void Arrow::set_stage(int tmp) {
    this->stage = tmp;
}
int Arrow::get_stage() {
    return stage;
}
bool Arrow::check_ck() {
    return check;
}
bool Arrow::getgameover() {
    return this->gameover;
}
float Arrow::okk_x(Entity* other, float ang){
    return other->getBody().getSize().x * 0.5 * cos(ang);
}
float Arrow::okk_y(Entity *other, float ang) {
    return  other->getBody().getSize().y * 0.5 * sin(ang);
}