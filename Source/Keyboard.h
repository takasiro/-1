#pragma once

#ifndef _INCLUDE_KEYBOARD_
#define _INCLUDE_KEYBOARD_

#include "Singleton.h"
#include "DxLib.h"

#define GET_KEY Keyboard::Instance()->Get	//キー獲得簡易化

class Keyboard :public Singleton <Keyboard>{
	Keyboard() {}
	friend Singleton <Keyboard>;
private:
	int Key[256];  // キーの入力状態格納用変数
public:
	void Update() {
		char tmpKey[256];             // 現在のキーの入力状態を格納する
		GetHitKeyStateAll(tmpKey);  // 全てのキーの入力状態を得る
		for (int i = 0; i<256; i++) {
			if (tmpKey[i] != 0) { // i番のキーコードに対応するキーが押されていたら
				Key[i]++;   // 加算
			}
			else {              // 押されていなければ
				Key[i] = 0; // 0にする
			}
		}
	}
	int Get(int KeyCode) {
		return Key[KeyCode]; // KeyCodeの入力状態を返す
	}

};


#endif