#pragma once
#include "BaseObj.h"
#include "Singleton.h"
#include "DxLib.h"

#define GET_BUTTON Mouse::Instance()->GetMouseButton	//キー獲得簡易化
#define GET_WHEEL Mouse::Instance()->GetMouseWheel	//キー獲得簡易化
#define GET_POSITION Mouse::Instance()->GetMouse_Pos	//キー獲得簡易化
#define RIGHTCLICK (Mouse::GET_BUTTON() & MOUSE_INPUT_RIGHT)//右クリックがされたか
#define LEFTCLICK (Mouse::GET_BUTTON() & MOUSE_INPUT_LEFT)//左クリックがされたか

class Mouse :public Singleton<Mouse> , public BaseObj{
	Mouse() { mButton=0, mWheel=0; }
	friend Singleton<Mouse>;
//protected:
	int mButton, mWheel;
public:
	int Update() {
		static int tmpx, tmpy;
		mButton = GetMouseInput();                //マウスの入力状態取得
		mWheel = GetMouseWheelRotVol();  //ホイールの回転量取得
		GetMousePoint(&tmpx, &tmpy);                //マウスの座標取得
		mPos.x = tmpx;
		mPos.y = tmpy;
		return 0;
	}
	int Draw() { return 0; }
	sPos GetMouse_Pos() { return mPos; }
	int GetMouseButton() { return mButton; }
	int GetMouseWheel(){ return mWheel; }

	int Initialize() { return 0; }
	int Close() { return 0; }

};
