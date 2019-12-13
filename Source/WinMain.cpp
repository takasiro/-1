#include "DxLib.h"
#include "Constant.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "SceneMgr.h"

#include "EffectMgr.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	SetWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	SetGraphMode(WINDOW_WIDTH, WINDOW_HEIGHT, 32);
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK); //�E�B���h�E���[�h�ύX�Ə������Ɨ���ʐݒ�

	SceneMgr sceneMgr;

	EffectMgr::Instance()->Initialize();
//	EffectMgr::Instance()->PlayEffect("Effect01",0, 0);


	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {

		//�C���^�[�t�F�[�X�X�V
		Keyboard::Instance()->Update();
		Mouse::Instance()->Update();


		sceneMgr.Update();
		EffectMgr::Instance()->Update();

		sceneMgr.Draw();
		EffectMgr::Instance()->Draw();
	}

	DxLib_End(); // DX���C�u�����I������
	return 0;
}