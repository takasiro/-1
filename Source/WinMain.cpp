#include "DxLib.h"
#include "Constant.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "SceneMgr.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	SetWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	SetGraphMode(WINDOW_WIDTH, WINDOW_HEIGHT, 32);
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK); //�E�B���h�E���[�h�ύX�Ə������Ɨ���ʐݒ�

	//SceneMgr sceneMgr;
	

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {


		Keyboard::Instance()->Update();
		Mouse::Instance()->Update();

	//	sceneMgr.Update();


	//	sceneMgr.Draw();

	}

	DxLib_End(); // DX���C�u�����I������
	return 0;
}