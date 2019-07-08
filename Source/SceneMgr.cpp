#include "SceneMgr.h"



SceneMgr::SceneMgr(){
	//‰ŠúƒV[ƒ“İ’è
	AddScene((BaseScene*)new TitleScene(this));
}


SceneMgr::~SceneMgr(){

}
