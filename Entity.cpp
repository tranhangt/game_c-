//
// Created by hang-tran on 11/6/20.
//

#include "Entity.h"
Entity::Entity() {
    body.setFillColor(Color(0, 0, 0, 0));
    body.setOutlineThickness(3.0f);
    body.setOutlineColor(Color::White);
    name = "Default";
    Velocity.x = Velocity.y = 0;
}
void Entity::Draw(RenderWindow &rd) {
    rd.draw(body);
}
void Entity::Update() {

}
void Entity::setPosition(Vector2f Position) {
    body.setPosition(Position);
}
Vector2f Entity::getPosition() {
    return body.getPosition();
}
RectangleShape Entity::getBody() {
    return body;
}
void Entity::resize(Vector2f size) {
    body.setSize(size);
}
bool Entity::isCollision(Entity other) {

}
bool Entity::isCollision(Entity* other){

}
void Entity::Draw(RenderWindow &rd, int i) {

}
int Entity::get_stage() {

}
void Entity::set_stage(int tmp) {

}
float Entity::okk_x(Entity* other, float angle) {

}
float Entity::okk_y(Entity *other, float angle) {

}
bool Entity::check_ck() {

}
void Entity::Update2() {

}
bool Entity::getgameover() {

}