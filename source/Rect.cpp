#include "Rect.h"

Rect::~Rect() {
	printf("Destructor Rectangle\n");
	//delete(this);
}

void Rect::Render() {
	VideoDriver::VideoDriver();
	VideoDriver::GetInstance()->DrawRect((int)getX(), (int)getY(), (int)width, (int)height);
	//VideoDriver::GetInstance()->SetColor(110);
}
void Rect::setPosition(double x, double y, double w, double h) {
	setX(x);
	setY(y);
	width = w;
	height = h;
}
Rect::Rect(double x, double y, double w, double h) {
	setX(x);
	setY(y);
	height = h;
	width = w;
}
void Rect::Update(float frameTime) {
	setMass(getMass() + 1.5*frameTime);
	if (getVtMoveY() == 0)
		setX(getX() + (double)frameTime*getMass());
	else {
		if (coliBoundX) {
			setVtMoveX(-getVtMoveX());
		}
		if (fabs(getVtMoveX()) < fabs(getVtMoveY()))
			setX(getX() + (double)frameTime*getMass()*getVtMoveX() / fabs(getVtMoveY()));
		else
			setX(getX() + (double)frameTime*getMass()*getVtMoveX() / fabs(getVtMoveX()));
		if (coliBoundY) {
			setVtMoveY(-getVtMoveY());
		}
		else if (timeMove < 0 && getVtMoveY() < 0) {
			timeMove = 2;
			setVtMoveY(-getVtMoveY());
			//setY(getY() - (double)frameTime*getMass()*getVtMoveY() / fabs(getVtMoveY()));
		}
		if (fabs(getVtMoveX()) < fabs(getVtMoveY()))
			setY(getY() + (double)frameTime*getMass()*getVtMoveY() / fabs(getVtMoveY()));
		else
			setY(getY() + (double)frameTime*getMass()*getVtMoveY() / fabs(getVtMoveX()));
	}
}
double Rect::getHeight() {
	return height;
}
double Rect::getWidth() {
	return width;
}

bool Rect::checkInside(double x, double y) {
	if (x > getX() + width) return 0;
	if (x < getX()) return 0;
	if (y < getY()) return 0;
	if (y > getY() + height) return 0;
	return 1;
}