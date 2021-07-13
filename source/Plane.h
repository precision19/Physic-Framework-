#pragma once
#include "videoDriver.h"
#include "Object.h"

class Plane : public Object {
	private:
		double x2;
		double y2;
	public:
		void Render();
		void setPosition(double x, double y, double w, double h);
		Plane(double x, double y, double w, double h);
		double getX2();
		double getY2();
		virtual ~Plane();
};
