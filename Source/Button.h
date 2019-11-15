#pragma once
#include"BaseObj.h"

class Button : public BaseObj
{
private:
	int imgw, imgh;
	int imgx = 20;
	int imgy = 120;
	int steat = 0;
	int oldSteat = 0;
	int clickFlag = 0;

	int(*OnClick)(int) = NULL;

public:
	Button();
	Button(int ,int);
	virtual ~Button();
	int Initialize();
	int Update();
	int Draw();
	int Close();
	void SetOnClick(int(*_fnc)(int _num)) { OnClick = _fnc; }
	void SetPosX(double _x) { imgx = mPos.x = _x; }
	void SetPosY(double _y) { imgy = mPos.y = _y; }


	

};



