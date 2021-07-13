#pragma once
#include "Object.h"
#include "Rect.h"
#include "Plane.h"
#include "Cir.h"
class CollisionManager {
	public:
		bool ObjNObj(Object*, Object*);
		bool RectNRect(Rect*, Rect*);
		bool RectNPlane(Rect*, Plane*);
		bool CirNPlane(Cir*, Plane*);
		bool CirNCir(Cir*, Cir*);
		bool RectNCir(Rect*, Cir*);
};