#include"Button.h"
#include"DxLib.h"
#include"Mouse.h"
Button::Button() :BaseObj()
{
	//mGrHandlesCount = 3;
	//mGrHandles = new int[mGrHandlesCount];

	//mGrHandles[0] = LoadGraph("../Resource/Image/button1.png");
	////mGrHandles[1] = LoadGraph("../Resource/Image/button2.png");
	//mGrHandles[2] = LoadGraph("../Resource/Image/button3.png");
	//GetGraphSize(mGrHandles[0], &imgw, &imgh);
	//mPos.x = 50;
	//mPos.y = 50;
}

Button::Button(int _x,int _y) :BaseObj()
{
	/*mGrHandlesCount = 3;
	mGrHandles = new int[mGrHandlesCount];

	mGrHandles[0] = LoadGraph("../Resource/Image/button1.png");
	mGrHandles[1] = LoadGraph("../Resource/Image/button2.png");
	mGrHandles[2] = LoadGraph("../Resource/Image/button3.png");
	GetGraphSize(mGrHandles[0], &imgw, &imgh);
	mPos.x = _x;
	mPos.y = _y;
	*/
}

Button::~Button()
{
	for (int i = 0; i < 3; i++) {
		DeleteGraph(mGrHandles[i]);
	}
	delete[] mGrHandles;
}
int Button::Initialize() {
	return 0;
}

int Button::Update() {
	sPos tmp = GET_POSITION();

	int mx = tmp.x;
	int my = tmp.y;
	if (mx >= imgx && mx <= imgx + imgw && my >= imgy && my <= imgy + imgh && GET_BUTTON() & MOUSE_INPUT_LEFT) {
		steat = 1;
	}
	else if (mx >= imgx && mx <= imgx + imgw && my >= imgy && my <= imgy + imgh) {
		steat = 2;
	}

	else {
		steat = 0;
	}
	if (GET_BUTTON() & MOUSE_INPUT_LEFT && oldSteat == 2 && steat == 1) clickFlag = 1;
	if (oldSteat == 1 && steat == 2 && clickFlag == 1)
		OnClick(myNum);
	if (!(GET_BUTTON() & MOUSE_INPUT_LEFT)) clickFlag = 0;

	oldSteat = steat;
	return 0;
}

int Button::Draw() {
	DrawGraph(mPos.x, mPos.y, mGrHandles[steat], true);
	return 0;
}

int Button::Close() {
	return 0;
}

