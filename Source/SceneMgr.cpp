#include "SceneMgr.h"
#include"TitleScene.h"


SceneMgr::SceneMgr(){
	//�����V�[���ݒ�
	AddScene((BaseScene*)new TitleScene(this));
}


SceneMgr::~SceneMgr(){

}
