#include "SceneMgr.h"
#include"TitleScene.h"
#include"InGameScene.h"
#include"CharacterMenu.h"

SceneMgr::SceneMgr(){
	//�����V�[���ݒ�
	AddScene((BaseScene*)new TitleScene(this));
	//AddScene((BaseScene*)new MapSelectScene(this));
}


SceneMgr::~SceneMgr(){

}
