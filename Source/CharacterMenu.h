#pragma once
#include "BaseScene.h"
#include "Button.h"
#include "Chara.h"
#include "UnitMgr.h"
#include "Load.h"

class CharacterMenu : public BaseScene{
private:
	Button test[8];
	static Chara chara ;
public:
	CharacterMenu();
	CharacterMenu(ISceneChanger*);
	~CharacterMenu();
	int Initialize();
	int Update();
	int Draw();
	int Close();
	static void SetCharaData(Chara _c) { chara = _c; }

};


int SelectChara(int _num);