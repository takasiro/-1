#include "SceneMgr.h"
#include"TitleScene.h"
#include"InGameScene.h"
#include"ResultScene.h"
#include"CharacterMenu.h"
#include"GameOverScene.h"

SceneMgr::SceneMgr(){
	//‰ŠúƒV[ƒ“İ’è
	AddScene((BaseScene*)new TitleScene(this));
	//AddScene((BaseScene*)new MapSelectScene(this));
}


SceneMgr::~SceneMgr(){

}
