#include "SceneMgr.h"
#include"TitleScene.h"
#include"InGameScene.h"

SceneMgr::SceneMgr(){
	//�����V�[���ݒ�
	AddScene((BaseScene*)new InGameScene(this));
}


SceneMgr::~SceneMgr(){

}
