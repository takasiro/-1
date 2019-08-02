#include "BaseScene.h"

class MapSelectScene : public BaseScene {

	MapSelectScene();
	MapSelectScene(ISceneChanger*);
	virtual	~MapSelectScene();
	int Initialize();	//‰Šú‰»ˆ—
	int Update();	//ŒvZˆ—
	int Draw();		//•`‰æˆ—
	int Close();	//I—¹ˆ—


};