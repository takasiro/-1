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
public:
	Button();
	Button(int ,int);
	virtual ~Button();
	int Initialize();
	int Update();
	int Draw();
	int Close();
	void	OnClick();


};

