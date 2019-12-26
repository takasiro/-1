#include "TitleScene.h"
#include "Load.h"
#include"Map.h"

ISceneChanger* TitleScene::mStaticISceneChanger;

int TitleScene::ChangeScene(int _buttonNumber) {
	switch (_buttonNumber) {
	case 0:
		//InGameScene�ڍs
		mStaticISceneChanger->AddScene((BaseScene*)new InGameScene(mStaticISceneChanger));
		break;
	case 1:
		//�Ȃ񂩂�Scene�Ɉڍs
		//mStaticISceneChanger->AddScene((BaseScene*)new CharacterMenu(mStaticISceneChanger));
		break;
	case 2:
		//�Q�[���I���Ƃ�����Ȃ�
		DxLib_End() ; 
		break;
	default:
		//�G���[�����Ƃ�
		break;
	}
	return 0;
}

TitleScene::TitleScene() {
	Initialize();
}

TitleScene::TitleScene(ISceneChanger* _Changer) :BaseScene(_Changer) {

	mTitleGraphHandle = LoadGraph("../Resource/Image/Title.png");  //�^�C�g���摜�ǂݍ���

	for (int i = 0; i < 3; i++) {  //�{�^���摜�ǂݍ���
		button[i].SetGrHandleCount(3);
		button[i].SetGrHandles(new int[button[i].GetGrHandleCount() ]);
		button[i].GetGrHandles()[0] = LoadGraph("../Resource/Image/Button/StartButton01.png");
		button[i].GetGrHandles()[1] = LoadGraph("../Resource/Image/Button/StartButton02.png");
		button[i].GetGrHandles()[2] = LoadGraph("../Resource/Image/Button/StartButton03.png");
		button[i].SetPosX(475);
		button[i].SetPosY(625+i * 100);
		button[i].SetOnClick(&ChangeScene);
		button[i].SetMyNum(i);
		button[i].Initialize();
	}

	//�������V�[���ւ̃{�^���͊D�F�\���ɂ��Ă��܂�
		//�������V�[���ւ̃{�^���͊D�F�\���ɂ��Ă��܂�
	button[1].GetGrHandles()[0] = LoadGraph("../Resource/Image/Button/CharaMenuButton02.png");
	button[1].GetGrHandles()[1] = LoadGraph("../Resource/Image/Button/CharaMenuButton02.png");
	button[1].GetGrHandles()[2] = LoadGraph("../Resource/Image/Button/CharaMenuButton02.png");

	button[2].GetGrHandles()[0] = LoadGraph("../Resource/Image/Button/QuitButton01.png");
	button[2].GetGrHandles()[1] = LoadGraph("../Resource/Image/Button/QuitButton02.png");
	button[2].GetGrHandles()[2] = LoadGraph("../Resource/Image/Button/QuitButton03.png");


	mStaticISceneChanger = mISceneChanger;

}

TitleScene::~TitleScene() {

	for (int i = 0; i < 3; i++) {  //�{�^���摜�̃��������
		for (int j = 0; j < 3; j++) {
			DeleteGraph(button[i].GetGrHandles()[j]);
		}
		delete[] button[i].GetGrHandles();
	}

	DeleteGraph(mTitleGraphHandle);  //�^�C�g���摜�̃��������
}

int TitleScene::Initialize() {

	mTitleGraphHandle = LoadGraph("../Resource/Image/Title.png");
	return 0;
}
int TitleScene::Update() {
	for (int i = 0; i < 3; i++)button[i].Update();
	return 0;
}
int TitleScene::Draw() {

	DrawGraph(0, 0, mTitleGraphHandle, FALSE);
	for(int i=0;i<3;i++)button[i].Draw();

	return 0;
}


int TitleScene::Close() {
	return 0;
}



