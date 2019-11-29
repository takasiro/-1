#pragma once
#include "BaseScene.h"
#include "BaseObj.h"
#include "ISceneChanger.h"
#include"InGameScene.h"
#include"MapSelectScene.h"
#include"CharacterMenu.h"
#include"Load.h"
#include"Chara.h"
#include"Enemy.h"
#include "Map.h"
#include"Button.h"
#include<vector>
class TitleScene : public BaseScene {

	Load load;  //Load
	Button button[3];  //ボタン(0:初期画像 1:押し込み差分 2:マウスオーバー差分)

	int mTitleGraphHandle;  //タイトル画像ハンドル
	static ISceneChanger* mStaticISceneChanger;

public:
	TitleScene();
	TitleScene(ISceneChanger*);
	~TitleScene();

	int Initialize();
	int Update();
	int Draw();
	int Close();

	static int ChangeScene(int _buttonNumber);
	
};

