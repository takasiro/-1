#include "SceneMgr.h"
#include"TitleScene.h"
#include"InGameScene.h"
#include"CharacterMenu.h"

SceneMgr::SceneMgr(){
	//�����V�[���ݒ�
	AddScene((BaseScene*)new InGameScene(this));
}


SceneMgr::~SceneMgr(){

}
