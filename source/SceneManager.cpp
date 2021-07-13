#include "Object.h"
#include "SceneManager.h"
#include "CollisionManager.h"

SceneManager* SceneManager::s_Instance = NULL;

SceneManager::SceneManager(void)
{
	this->Init();
}

SceneManager::~SceneManager(void) {
	
	printf("Destructor Scenemanager\n");
}

SceneManager* SceneManager::GetInstance()
{
	if (!s_Instance)
		s_Instance = new SceneManager();
	return s_Instance;
}

void SceneManager::Update(float frameTime) {
	CollisionManager *col = new CollisionManager();
	//col->ObjNObj(obj[1], obj[4]);
	for (int i = 0; i < obj.size() - 1; i++) {
		//cout << obj[i]->shape << endl;
		for (int j = i + 1; j < obj.size(); j++) {
			if (col->ObjNObj(obj[i], obj[j]) == 0 ){
				//Xet giua plane va doi tuong khac
				if (strncmp(obj[i]->shape, "Plane", 5) == 0){
					Plane* plane = (Plane*)obj[i];
					if ((int)plane->getX() == (int)plane->getX2()) {
						obj[j]->coliBoundX = 1;
						if (strncmp(obj[j]->shape, "Rectangle", 9) == 0) {
							Rect* rect = (Rect*)obj[j];
							if (obj[j]->getX() <= plane->getX()) {
								obj[j]->setX(plane->getX());
							}
							else if (rect->getX() + rect->getWidth() >= plane->getX()) {
								obj[j]->setX(plane->getX()-rect->getWidth());
							}
						}
						else {
							Cir* cir = (Cir*)obj[i];
							double rad = cir->getRadian();
							if (cir->getX() - rad <= plane->getX() && plane->getX() < 200) {
								obj[i]->setX(plane->getX() + rad);
							}
							else{
								obj[i]->setX(plane->getX() - rad);
							}
						}
					}
					
					else if ((int)plane->getY() == (int)plane->getY2()) {
						obj[j]->coliBoundY = 1;
						if (strncmp(obj[j]->shape, "Rectangle", 9) == 0) {
							Rect* rect = (Rect*)obj[j];
							if (obj[j]->getY() <= plane->getY() && plane->getY() < 200) {
								obj[j]->setY(plane->getY());
							}
							else {
								double tmp = plane->getY() - rect->getHeight();
								obj[j]->setY(tmp);
							}
						}
						else {
							Cir* cir = (Cir*)obj[j];
							double rad = cir->getRadian();
							if (cir->getY() - rad <= plane->getY() && plane->getY() < 200) {
								obj[j]->setY(plane->getY() + rad);
							}
							else {
								obj[j]->setY(plane->getY() - rad);
							}
						}
					}
					/*obj[i]->setStop(true);
					obj[j]->setStop(true);*/
				}
				//xet giua doi tuong khac va plane
				else if (strncmp(obj[j]->shape, "Plane", 5) == 0) {
					Plane* plane = (Plane*)obj[j];
					if ((int)plane->getX() == (int)plane->getX2()) {
						obj[i]->coliBoundX = 1;
						if (strncmp(obj[i]->shape, "Rectangle", 9) == 0) {
							Rect* rect = (Rect*)obj[i];
							if (obj[i]->getX() <= plane->getX() && plane->getX() < 200) {
								obj[i]->setX(plane->getX());
							}
							else {
								double tmp = plane->getX() - rect->getWidth();
								obj[i]->setX(tmp);
							}
						}
						else {
							Cir* cir = (Cir*)obj[i];
							double rad = cir->getRadian();
							if (cir->getX() - rad <= plane->getX() && plane->getX() < 200) {
								obj[i]->setX(plane->getX() + rad);
							}
							else{
								obj[i]->setX(plane->getX() - rad);
							}
						}

					}
					else if ((int)plane->getY() == (int)plane->getY2()) {
						obj[i]->coliBoundY = 1;
						if (strncmp(obj[i]->shape, "Rectangle", 9) == 0) {
							Rect* rect = (Rect*)obj[i];
							if (obj[i]->getY() <= plane->getY() && plane->getY() < 200) {
								obj[i]->setY(plane->getY());
							}
							else {
								double tmp = plane->getY() - rect->getHeight();
								obj[i]->setY(tmp);
							}
						}
						else {
							Cir* cir = (Cir*)obj[i];
							double rad = cir->getRadian();
							if (cir->getY() - rad <= plane->getY() && plane->getY() < 200) {
								obj[i]->setY(plane->getY() + rad);
							}
							else {
								obj[i]->setY(plane->getY() - rad);
							}
						}
					}
					/*obj[i]->setStop(true);
					obj[j]->setStop(true);*/
				}
				//Neu khong co cai nao la plane
				else {
					if (obj[i]->getVtMoveX()*obj[j]->getVtMoveX() <= 0) {
						obj[i]->setVtMoveX(-obj[i]->getVtMoveX());
						obj[j]->setVtMoveX(-obj[j]->getVtMoveX());
					}
					if (obj[i]->getVtMoveY()*obj[j]->getVtMoveY() <= 0) {
						obj[i]->setVtMoveY(-obj[i]->getVtMoveY());
						obj[j]->setVtMoveY(-obj[j]->getVtMoveY());
					}
					obj[i]->Update(frameTime);
					obj[j]->Update(frameTime);
				}
				cout << "Collision between " << obj[i]->shape << " " << i << " and " << obj[j]->shape << " " << j << endl;
			}
		}
	}
	for (int i = 0; i < obj.size(); i++) {
		if (obj[i]->getIsHold() == false && obj[i]->getStop() == false)
			obj[i]->Update(frameTime);
			obj[i]->timeMove -= frameTime;
			obj[i]->coliBoundX = 0;
			obj[i]->coliBoundY = 0;
			obj[i]->setStop(false);
	}
}
void SceneManager::Render() {
	for (int i = 0; i < obj.size(); i++) {
		obj[i]->Render();
	}
}

void SceneManager::TouchMove(int x, int y) {
	//cout << x << " " << y << endl;
	for (int i = 0; i < obj.size(); i++) {
		//cout << obj[i]->getIsHold();
		if (obj[i]->getIsHold()) {
			obj[i]->Move(x, y);
			obj[i]->setVtMoveX(x - obj[i]->getMouseX());
			//cout << x - obj[i]->getMoveX() - obj[i]->getX() << endl;
			obj[i]->setVtMoveY(y - obj[i]->getMouseY());
		}
	}
}
void  SceneManager::TouchDown(int x, int y) {
	for (int i = 0; i < obj.size(); i++) {
		//cout << x << " " << y << " " << obj[i]->getX() << " " << obj[i]->getY() << " " << i << " " << obj[i]->checkInside(x, y) << endl;
		if (obj[i]->checkInside(x, y)) {
			obj[i]->timeMove = 2;
			obj[i]->setIsHold(true);
			obj[i]->setMoveX(x - obj[i]->getX());
			obj[i]->setMoveY(y - obj[i]->getY());
			obj[i]->setMouseX(x);
			obj[i]->setMouseY(y);
			/*cout << obj[i]->getMoveX();
			cout << obj[i]->getMoveY();*/
			break;
		}
	}
}
void SceneManager::TouchUp(int x, int y) {
	for (int i = 0; i < obj.size(); i++) {
		obj[i]->setIsHold(false);
	}
}
void SceneManager::Init() {
	FILE* f;
	int bufferLength = 255;
	char buffer[255];

	f = fopen("source/SceneManager.txt", "r");
	if (f == NULL) {
		printf("Can't open file\n");
	}
	fgets(buffer, 255, f);
	char useless[255];
	int numObject;
	sscanf(buffer, "%s %d", useless, &numObject);
	int pos = -1;
	while (fgets(buffer, bufferLength, f)) {
		//printf("%s\n", buffer);
		if (strncmp(buffer, "#ID", 3) == 0) {
			if (pos > -1) {
				cout << pos << " " << obj[pos]->shape << endl;
			}
			pos++;
		}
		char type[10];
		if (strncmp(buffer, "TYPE", 4) == 0) {
			char t[10];
			memset(type, 0, sizeof(type));
			sscanf(buffer, "%s %s", t, type);
			//printf("%d %s\n", pos , type);
		}
		double x, y, z, w;
		if (strncmp(buffer, "position", 8) == 0) {
			char t[20];
			if (strcmp(type, "Rectangle") == 0) {
				sscanf(buffer, "%s %lf %s %lf %s %lf %s %lf", t, &x, t, &y, t, &z, t, &w);
				obj.push_back(new Rect(x, y, z, w));
				sprintf(obj[pos]->shape, "%s", "Rectangle");
				obj[pos]->setIsHold(false);
				obj[pos]->setStop(false);
				obj[pos]->setVtMoveX(0);
				obj[pos]->setVtMoveY(1);
				obj[pos]->timeMove = 4;
			}
			if (strcmp(type, "Plane") == 0) {
				sscanf(buffer, "%s %lf %s %lf %s %lf %s %lf", t, &x, t, &y, t, &z, t, &w);
				obj.push_back(new Plane(x, y, z, w));
				sprintf(obj[pos]->shape, "%s", "Plane");
				obj[pos]->setIsHold(false);
				obj[pos]->setStop(false);
			}
			if (strcmp(type, "Circle") == 0) {
				sscanf(buffer, "%s %lf %s %lf %s %lf %s %lf", t, &x, t, &y, t, &z, t, &w);
				obj.push_back(new Cir(x, y, z));
				sprintf(obj[pos]->shape, "%s", "Circle");
				obj[pos]->setIsHold(false);
				obj[pos]->setStop(false);
				obj[pos]->setVtMoveX(0);
				obj[pos]->setVtMoveY(1);
				obj[pos]->timeMove = 4;
			}
			//printf("%s", obj[pos]->shape);
		}
		if (strncmp(buffer, "velocity", 8) == 0) {
			double vt;
			char t[20];
			sscanf(buffer, "%s %lf", t, &vt);
			obj[pos]->setVelocity(vt);
		}
		if (strncmp(buffer, "mass", 4) == 0) {
			double vt;
			char t[20];
			sscanf(buffer, "%s %lf", t, &vt);
			obj[pos]->setMass(vt);
		}

		memset(buffer, 0, sizeof(buffer));
	}

	fclose(f);
	/*		delete[]obj;*/
}