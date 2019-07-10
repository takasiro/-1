#include "BaseScene.h"

class MapSelectScene : public BaseScene {

	MapSelectScene();
	MapSelectScene(ISceneChanger*);
	virtual	~MapSelectScene();
	int Initialize() { return 0; }	//‰Šú‰»ˆ—
	int Update() { return 0; }		//ŒvZˆ—
	int Draw() { return 0; }			//•`‰æˆ—
	int Close() { return 0; }		//I—¹ˆ—


};