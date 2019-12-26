#include "SceneMgr.h"
#include"TitleScene.h"
#include"InGameScene.h"
#include"CharacterMenu.h"

SceneMgr::SceneMgr(){
	//‰ŠúƒV[ƒ“İ’è
	AddScene((BaseScene*)new TitleScene(this));
	//AddScene((BaseScene*)new MapSelectScene(this));
}


SceneMgr::~SceneMgr(){

}
