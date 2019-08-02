#pragma once
#include "BaseScene.h"

class LoadScene : public BaseScene {

	LoadScene();
	LoadScene(ISceneChanger*);
	virtual	~LoadScene();
	int Initialize();	//‰Šú‰»ˆ—
	int Update();		//ŒvZˆ—
	int Draw();		//•`‰æˆ—
	int Close();		//I—¹ˆ—


};