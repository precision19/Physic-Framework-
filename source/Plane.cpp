#include "Plane.h"

void Plane::Render() {
	VideoDriver::GetInstance()->DrawLine(getX(), getY(), x2, y2);
	//VideoDriver::GetInstance()->SetColor(1213);
}

Plane::~Plane() {
	printf("Destructor plane\n");
	//delete(this);
}
void Plane::setPosition(double x, double y, double w, double h) {
	setX(x);
	setY(y);
	x2 = w;
	y2 = h;
}
double Plane::getX2() {
	return x2;
}
double Plane::getY2() {
	return y2;
}
Plane::Plane(double x, double y, double w, double h) {
	setX(x);
	setY(y);
	x2 = w;
	y2 = h;
}