#include "SceneMgr.h"



SceneMgr::SceneMgr(){
	//�����V�[���ݒ�
	AddScene((BaseScene*)new TitleScene(this));
}


SceneMgr::~SceneMgr(){

}
