#pragma once
#include "BaseScene.h"

class TitleScene : public BaseScene {
	
public:
	TitleScene();
	~TitleScene();
	int Initialize();
	int Update();
	int Draw();
	int Close();


};