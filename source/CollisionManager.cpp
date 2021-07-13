#include "CollisionManager.h"

bool CollisionManager::ObjNObj(Object* o1, Object* o2) {
	if ((strncmp(o1->shape, "Rectangle", 9) == 0) && strncmp(o2->shape, "Rectangle", 9) == 0) {
		Rect* rect1 = (Rect*)o1;
		Rect* rect2 = (Rect*)o2;
		return RectNRect(rect1, rect2);
	}
	if ((strncmp(o1->shape, "Circle", 6) == 0) && strncmp(o2->shape, "Circle", 6) == 0) {
		Cir* cir1 = (Cir*)o1;
		Cir* cir2 = (Cir*)o2;
		return CirNCir(cir1, cir2);
	}
	if ((strncmp(o1->shape, "Rectangle", 9) == 0) && strncmp(o2->shape, "Circle", 6) == 0) {
		Rect* rect1 = (Rect*)o1;
		Cir* cir1 = (Cir*)o2;
		return RectNCir(rect1, cir1);
	}
	if ((strncmp(o1->shape, "Circle", 6) == 0) && strncmp(o2->shape, "Rectangle", 9) == 0) {
		Cir* cir1 = (Cir*)o1;
		Rect* rect1 = (Rect*)o2;
		return RectNCir(rect1, cir1);
	}
	if ((strncmp(o1->shape, "Rectangle", 9) == 0) && strncmp(o2->shape, "Plane", 5) == 0) {
		Rect* rect1 = (Rect*)o1;
		Plane* plane1 = (Plane*)o2;
		return RectNPlane(rect1, plane1);
	}
	if ((strncmp(o1->shape, "Plane", 5) == 0 && strncmp(o2->shape, "Rectangle", 9) == 0)) {
		Rect* rect1 = (Rect*)o2;
		Plane* plane1 = (Plane*)o1;
		return RectNPlane(rect1, plane1);
	}
	if ((strncmp(o1->shape, "Plane", 5) == 0 && strncmp(o2->shape, "Circle", 6) == 0)) {
		Cir* cir1 = (Cir*)o2;
		Plane* plane1 = (Plane*)o1;
		return CirNPlane(cir1, plane1);
	}
	if ((strncmp(o1->shape, "Circle", 6) == 0 && strncmp(o2->shape, "Plane", 5) == 0)) {
		Cir* cir1 = (Cir*)o1;
		Plane* plane1 = (Plane*)o2;
		return CirNPlane(cir1, plane1);
	}
	return 1;
}
bool CollisionManager::RectNPlane(Rect* rect1, Plane* plane1) {
	double x1 = rect1->getX();
	double y1 = rect1->getY();
	double w1 = rect1->getWidth();
	double h1 = rect1->getHeight();
	double xp1 = plane1->getX();
	double xp2 = plane1->getX2();
	double yp1 = plane1->getY();
	double yp2 = plane1->getY2();
	////cout << (int)xp1 << " " << (int)yp1 << " ";
	if ((int)xp1 == (int)xp2) {
		if (xp1 <= x1 + w1 && xp1 >= x1) {
			if (yp1 <= y1 && y1 <= yp2) return 0;
			if (yp1 <= y1 + h1 && y1 + h1 <= yp2) return 0;
		}
	}
	//cout << (int)xp2 << " " << (int)yp2 << endl;
	if ((int)yp1 == (int)yp2) {
		if (yp1 <= y1 + h1 && yp1 >= y1) {
			if (xp1 <= x1 && x1 <= xp2) return 0;
			if (xp1 <= x1 + w1 && x1 + w1 <= xp2) return 0;
		}
	}
	//cout << endl;
	return 1;
}
bool CollisionManager::CirNPlane(Cir* cir1, Plane* plane1) {
	double xp1 = plane1->getX();
	double xp2 = plane1->getX2();
	double yp1 = plane1->getY();
	double yp2 = plane1->getY2();
	double xc = cir1->getX();
	double yc = cir1->getY();
	double rad = cir1->getRadian();
	if ((int)xp1 == (int)xp2) {
		if (fabs(xc - xp1) <= rad) return 0;
	}
	if ((int)yp1 == (int)yp2) {
		if (fabs(yc - yp1) <= rad) return 0;
	}
	return 1;
}

bool CollisionManager::RectNRect(Rect* rect1, Rect* rect2) {
	double x1 = rect1->getX();
	double x2 = rect2->getX();
	double y1 = rect1->getY();
	double y2 = rect2->getY();
	double w1 = rect1->getWidth();
	double w2 = rect2->getWidth();
	double h1 = rect1->getHeight();
	double h2 = rect2->getHeight();
	if (x1 >= x2 && x1 <= x2 + w2 && y1 >= y2 && y1 <= y2 + h2) {
		return 0;
	}
	if (x2 >= x1 && x2 <= x1 + w1 && y2 >= y1 && y2 <= y1 + h1) {
		return 0;
	}
	if (x1 + w1 >= x2 && x1 + w1 <= x2 + w2 && y1 >= y2 && y1 <= y2 + h2) {
		return 0;
	}
	if (x2 + w2 >= x1 && x2 + w2 <= x1 + w1 && y2 >= y1 && y2 <= y1 + h1) {
		return 0;
	}
	if (x1 + w1 >= x2 && x1 + w1 <= x2 + w2 && y1 + h1 >= y2 && y1 + h1 <= y2 + h2) {
		return 0;
	}
	if (x2 + w2 >= x1 && x2 + w2 <= x1 + w1 && y2 + h2 >= y1 && y2 + h2 <= y1 + h1) {
		return 0;
	}
	if (x1 >= x2 && x1 <= x2 + w2 && y1 + h1 >= y2 && y1 + h1 <= y2 + h2) {
		return 0;
	}
	if (x2 >= x1 && x2 <= x1 + w1 && y2 + h2 >= y1 && y2 + h2 <= y1 + h1) {
		return 0;
	}
	return 1;
}
double distance(double x1, double x2, double y1, double y2) {
	double pow2 = (x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1);
	return sqrt(pow2);
}
//distance point to line
double distancePTL(double xc, double yc, double a, double b, double c) {
	return sqrt(fabs(a*xc + b*yc + c) / (sqrt(a*a + b*b)));
}


bool CollisionManager::RectNCir(Rect* rect1, Cir* cir1) {
	double x1 = rect1->getX();
	double y1 = rect1->getY();
	double xc = cir1->getX();
	double yc = cir1->getY();
	double w1 = rect1->getWidth();
	double h1 = rect1->getHeight();
	double rad = cir1->getRadian();
	if (fabs(xc - x1) <= rad) {
		double tmpY = yc - sqrt(rad*rad - (xc - x1)*(xc - x1));
		double tmpY1 = yc + sqrt(rad*rad - (xc - x1)*(xc - x1));
		if (y1 <= tmpY && y1 + h1 >= tmpY) return 0;
		if (y1 <= tmpY1 && y1 + h1 >= tmpY1) return 0;
	}
	if (fabs(xc - x1 - w1) <= rad) {
		double tmpy = yc - sqrt(rad*rad - (xc - x1 - w1)*(xc - x1 - w1));
		double tmpy1 = yc + sqrt(rad*rad - (xc - x1 - w1)*(xc - x1 - w1));
		if (y1 <= tmpy && y1 + h1 >= tmpy) return 0;
		if (y1 <= tmpy1 && y1 + h1 >= tmpy1) return 0;
	}
	if (fabs(yc - y1) <= rad) {
		double tmpX = xc - sqrt(rad*rad - (yc - y1)*(yc - y1));
		double tmpX1 = xc + sqrt(rad*rad - (yc - y1)*(yc - y1));
		if (x1 <= tmpX && x1 + w1 >= tmpX) return 0;
		if (x1 <= tmpX1 && x1 + w1 >= tmpX1) return 0;
	}
	if (distancePTL(xc, yc, 0, 1, -y1 - h1) <= rad) {
		double tmpX = xc - sqrt(rad*rad - (yc - y1 - h1)*(yc - y1 - h1));
		double tmpX1 = xc + sqrt(rad*rad - (yc - y1 - h1)*(yc - y1 - h1));
		if (x1 <= tmpX && x1 + w1 >= tmpX) return 0;
		if (x1 <= tmpX1 && x1 + w1 >= tmpX1) return 0;
	}

	if (xc - x1 <= rad && x1 + w1 - xc <= rad && yc - y1 <= rad && y1 + h1 - yc <= rad) {
		return 0;
	}
	return 1;
}

bool CollisionManager::CirNCir(Cir* cir1, Cir* cir2) {
	double x1 = cir1->getX();
	double y1 = cir1->getY();
	double x2 = cir2->getX();
	double y2 = cir2->getY();
	double rad1 = cir1->getRadian();
	double rad2 = cir2->getRadian();
	if (distance(x1, y1, x2, y2) <= rad1 + rad2) {
		return 0;
	}
	return 1;
}