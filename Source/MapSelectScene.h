#include "BaseScene.h"

class MapSelectScene : public BaseScene {

	MapSelectScene();
	MapSelectScene(ISceneChanger*);
	virtual	~MapSelectScene();
	int Initialize() { return 0; }	//����������
	int Update() { return 0; }		//�v�Z����
	int Draw() { return 0; }			//�`�揈��
	int Close() { return 0; }		//�I������


};