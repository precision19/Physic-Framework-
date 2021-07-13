#pragma once
#include "videoDriver.h"
#include <string>
class Object {
	private: 
		bool stop;
		bool isHold;
		double posX;
		double posY;
		double mass;
		double velocity;
		double moveX; //vector giua tam va diem nhan chuot theo x	
		double moveY; //vector giua tam va diem nhan chuot theo y
		double vtMoveX; //vector di chuyen theo x
		double vtMoveY; // vector obj di chuyen theo y
		double mouseX; //diem nhan chuot(x)
		double mouseY; //diem nhan chuot(y)
	public:
		double timeMove;
		bool coliBoundX;
		bool coliBoundY;
		char shape[10];
		virtual void Render();
		virtual void Update(float frameTime);
		double getX();
		void setX(double m);
		double getY();
		void setY(double y);
		double getMass();
		void setMass(double m);
		double getVelocity();
		void setVelocity(double velo);
		bool getIsHold();
		void setIsHold(bool hold);
		//virtual bool Collision(Object* o);
		virtual bool checkInside(double x, double y);
		void Move(double x, double y);
		void setMoveX(double x);
		void setMoveY(double y);
		double getMoveX();
		double getMoveY();
		virtual bool getStop();
		virtual void setStop(bool st);
		void setVtMoveX(double x);
		double getVtMoveX();
		void setVtMoveY(double);
		double getVtMoveY();
		double getMouseX();
		double getMouseY();
		void setMouseX(double);
		void setMouseY(double);
		virtual ~Object();
		Object();
};
