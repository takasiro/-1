#pragma once
#include "BaseScene.h"

class LoadScene : public BaseScene {

	LoadScene();
	LoadScene(ISceneChanger*);
	virtual	~LoadScene();
	int Initialize();	//初期化処理
	int Update();		//計算処理
	int Draw();		//描画処理
	int Close();		//終了処理


};