#include "SceneMgr.h"
#include"TitleScene.h"
#include"InGameScene.h"

SceneMgr::SceneMgr(){
	//‰ŠúƒV[ƒ“İ’è
	AddScene((BaseScene*)new InGameScene(this));
}


SceneMgr::~SceneMgr(){

}
