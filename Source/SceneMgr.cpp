#include "SceneMgr.h"
#include"TitleScene.h"
#include"InGameScene.h"

SceneMgr::SceneMgr(){
	//初期シーン設定
	AddScene((BaseScene*)new InGameScene(this));
}


SceneMgr::~SceneMgr(){

}
