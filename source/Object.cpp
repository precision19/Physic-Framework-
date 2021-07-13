#include "Object.h"

Object::Object() {
	coliBoundX = 0;
	coliBoundY = 0;
}

void Object::setStop(bool st) {
	stop = st;
}

bool Object::getStop() {
	return stop;
}
Object::~Object() {
	printf("Destructor Object\n");
	//delete(this);
}

void Object::setVtMoveX(double x) {
	vtMoveX = x;
}
double Object::getVtMoveX() {
	return vtMoveX;
}
void Object::setVtMoveY(double y) {
	vtMoveY = y;
}
double Object::getVtMoveY() {
	return vtMoveY;
}
double Object::getMouseX() {
	return mouseX;
}
double Object::getMouseY() {
	return mouseY;
}
void Object::setMouseX(double x) {
	mouseX = x;
}
void Object::setMouseY(double y) {
	mouseY = y;
}
void Object::setMoveX(double x) {
	moveX = x;
}
void Object::setMoveY(double y) {
	moveY = y;
}
double Object::getMoveX() {
	return moveX;
}
double Object::getMoveY() {
	return moveY;
}
void Object::Render() {

}
void Object::Update(float frameTime) {
	
}
bool Object::checkInside(double x, double y) {
	return 0;
}
bool Object::getIsHold() {
	return isHold;
}
void Object::Move(double x, double y) {
	setX(x-moveX);
	setY(y-moveY);
}
void Object::setIsHold(bool hold) {
	isHold = hold;
}
double Object::getX() {
	return posX;
}
void Object::setX(double m) {
	posX = m;
}
double Object::getY() {
	return posY;
}
void Object::setY(double y) {
	posY = y;
}
double Object::getMass() {
	return mass;
}
void Object::setMass(double m) {
	mass = m;
}
double Object::getVelocity() {
	return velocity;
}
void Object::setVelocity(double velo) {
	velocity = velo;
}


