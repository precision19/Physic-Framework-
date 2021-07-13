#pragma once
#include <math.h>
#include "Object.h"

class Rect : public Object {
	private: 
		double height;
		double width;
	public:
		void Render();
		void setPosition(double x, double y, double w, double h);
		Rect(double x, double y, double w, double h);
		void Update(float frameTime);
		double getWidth();
		double getHeight();
		bool checkInside(double x, double y) override;
		virtual ~Rect();
};

