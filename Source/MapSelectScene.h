#include "BaseScene.h"

class MapSelectScene : public BaseScene {

	MapSelectScene();
	MapSelectScene(ISceneChanger*);
	virtual	~MapSelectScene();
	int Initialize();	//����������
	int Update();	//�v�Z����
	int Draw();		//�`�揈��
	int Close();	//�I������


};