#include "SceneMgr.h"
#include"TitleScene.h"
#include"InGameScene.h"
#include"CharacterMenu.h"

SceneMgr::SceneMgr(){
	//初期シーン設定
	AddScene((BaseScene*)new TitleScene(this));
}


SceneMgr::~SceneMgr(){

}
