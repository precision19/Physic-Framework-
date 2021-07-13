#pragma once
#include <math.h>
#include "Object.h"
class Cir : public Object {
	private:
		double rad;
	public:
		void setPosition(double x, double y, double r);
		Cir(double x, double y, double r);
		void Render();
		void Update(float frameTime);
		double getRadian();
		bool checkInside(double x, double y);
		virtual ~Cir();
};

