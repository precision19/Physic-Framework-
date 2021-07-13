#pragma once
#include <fstream>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include "CollisionManager.h"
using namespace std;
class SceneManager {

public:
	static SceneManager* s_Instance;
	static SceneManager* GetInstance();
	// Constructor
	SceneManager(void);

	// Destructor
	~SceneManager(void);
	vector<Object*> obj;
	void Update(float frameTime);
	virtual void Render();
	void TouchMove(int x, int y);
	void TouchDown(int x, int y);
	void TouchUp(int x, int y);
	void Init();
};