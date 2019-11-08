#include "BaseScene.h"
#include <iostream>
#include <vector>

class MapSelectScene : public BaseScene {

public:

	int state = 0;

	const int direction[4][2]{
		{0,1},
		{1,0},
		{0,-1},
		{-1,0}
	};

	typedef struct MAP {
		int x, y, r;
		int connection[9];

		vector<int>next;//�q�����Ă���}�b�v�̏�������(�O��)
		vector<int> prev;//�q�����Ă���}�b�v�̏�������(���)
	};

	//�}�E�X���W�p�ϐ�
	int MouseX = 0, MouseY = 0;

	MAP map[9] = {
		{100,100,20,{1,1,-1,-1,-1}},
		{200,400,20,{0,2,-1,-1,-1}},
		{300,100,20,{1,3,-1,-1,-1}},
		{400,200,20,{2,4,-1,-1,-1}},
		{500,600,20,{3,5,-1,-1,-1}},
		{650,650,20,{4,6,-1,-1,-1}},
		{750,800,20,{5,7,-1,-1,-1}},
		{850,200,20,{6,8,-1,-1,-1}},
		{1200,500,20,{7,8,-1,-1,-1}}
	};

	MapSelectScene();
	MapSelectScene(ISceneChanger*);
	virtual	~MapSelectScene();
	int Initialize();	//����������
	int Update();	//�v�Z����
	int Draw();		//�`�揈��
	int Close();	//�I������
};