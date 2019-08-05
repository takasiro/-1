#include"Button.h"
#include"DxLib.h"
#include"Mouse.h"
Button::Button() :BaseObj()
{
	mGrHandlesCount = 3;
	mGrHandles = new int[mGrHandlesCount];

	mGrHandles[0] = LoadGraph("../button1.png");
	mGrHandles[1] = LoadGraph("../button2.png");
	mGrHandles[2] = LoadGraph("../button3.png");
	GetGraphSize(mGrHandles[0], &imgw, &imgh);
	mPos.x = 50;
	mPos.y = 50;
}

Button::~Button()
{
}
int Button::Initialize() {
	return 0;
}

int Button::Update() {
	Mouse::Instance()->Update();

	int mx = Mouse::Instance()->GetPosX();
	int my = Mouse::Instance()->GetPosY();
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
	if (oldSteat == 1 && steat == 2 && clickFlag == 1) OnClick();
	if (!(GET_BUTTON() & MOUSE_INPUT_LEFT)) clickFlag = 0;

	oldSteat = steat;
	return 0;
}

int Button::Draw() {
	DrawGraph(mPos.x, mPos.y, mGrHandles[0], true);
	return 0;
}

int Button::Close() {
	return 0;
}

void Button::OnClick() {
	DrawBox(0, 0, 640, 480, GetColor(255, 255, 255), true);
}