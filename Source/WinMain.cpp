#include "DxLib.h"
#include "Constant.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "SceneMgr.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	SetWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	SetGraphMode(WINDOW_WIDTH, WINDOW_HEIGHT, 32);
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK); //ウィンドウモード変更と初期化と裏画面設定

	//SceneMgr sceneMgr;
	

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {


		Keyboard::Instance()->Update();
		Mouse::Instance()->Update();

	//	sceneMgr.Update();


	//	sceneMgr.Draw();

	}

	DxLib_End(); // DXライブラリ終了処理
	return 0;
}