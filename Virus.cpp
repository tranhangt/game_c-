//
// Created by hang-tran on 11/12/20.
//
#include "Arrow.h"
#include "Virus.h"
Virus::Virus(string name) {
    currentAnimation = Animation(name, 1.f/60);
    currentAnimation.setTexture(vi);
    vi.setPosition(300.0f, 300.0f);
    //vi.scale(0.7f, 0.7f);
    this->body.setSize((Vector2f)vi.getTexture()->getSize());
    this->body.setOrigin((Vector2f)vi.getTexture()->getSize() * 0.5f);

    this->body.setPosition(vi.getPosition());


}
void Virus::Update() {
    Entity::Update();
//    currentAnimation.Update();
    currentAnimation.setTexture(vi);
    //s.setPosition(body.getPosition());
    vi.rotate(0.1f);
}

bool Virus::isCollision(Entity other) {
    //if(other.getBody().getGlobalBounds().intersects(vi.getGlobalBounds())){
        if(vi.getGlobalBounds().intersects(other.getBody().getGlobalBounds())){
        other.getBody().setOrigin((Vector2f)vi.getTexture()->getSize() * 0.5f);
        other.getBody().rotate(0.6f);
        other.setPosition(other.getBody().getPosition());
        return true;
    }
    return false;
}
void Virus::Draw(RenderWindow& rd) {
    Entity::Draw(rd);
    rd.draw(vi);
}