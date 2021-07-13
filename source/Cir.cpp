#include "Cir.h"

Cir::~Cir() {
	printf("Destructor Circle\n");
	//delete(this);
}
void Cir::Render() {
	VideoDriver::GetInstance()->DrawCircle(getX(), getY(), rad);
}
void Cir::Update(float frameTime) {
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
Cir::Cir(double x, double y, double r) {
	setX(x);
	setY(y);
	rad = r;
}
void Cir::setPosition(double x, double y, double r) {
	setX(x);
	setY(y);
	rad = r;
}
double Cir::getRadian() {
	return rad;
}
double dist(double x1, double y1, double x2, double y2) {
	double pow2 = (x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1);
	return sqrt(pow2);
}
bool Cir::checkInside(double x, double y) {
	if (dist(x, y, getX(), getY()) <= rad)
		return 1;
	return 0;
}
