#include "BaseScene.h"

class MapSelectScene : public BaseScene {

	MapSelectScene();
	MapSelectScene(ISceneChanger*);
	virtual	~MapSelectScene();
	int Initialize();	//初期化処理
	int Update();	//計算処理
	int Draw();		//描画処理
	int Close();	//終了処理


};