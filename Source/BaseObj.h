#pragma once
#include "BaseTask.h"
class BaseObj : public BaseTask
{
public:
	typedef struct {
		double x, y;
	}sPos;

protected:
	sPos mPos;	//�W�����W
	sPos mV;	//�x�N�g��
	sPos mC;	//�������W
	double mWidth;	//��
	double mHeight;	//����
	double mAngle;	//�p�x
	double mSpeed;	//���x
	double mR;	//���a
	bool mOnActive;	//�A�N�e�B�u
	int mGrHandle;	//�O���t�B�b�N�n���h��
	int* mGrHandles;	//�O���t�B�b�N�n���h����������ꍇ
	int mGrHandlesCount;	//��������ꍇ�̌�

	//���������甼�a�𐶐�
	void RUpdate() {
		mR = mWidth < mHeight ? mWidth / 2 : mHeight / 2;
	}

	//��{���W�����ɒ������W�̍X�V
	void CUpdate() {
		mC.x = (mWidth / 2) + mPos.x;
		mC.y = (mHeight / 2) + mPos.y;
	}

public:

	//�l�̊l��
	double GetPosX() { return mPos.x; }
	double GetPosY() { return mPos.y; }
	sPos GetmPos() { return mPos; }
	double GetVX() { return mV.x; }
	double GetVY() { return mV.y; }
	sPos GetV() { return mV; }
	double GetCX() { return mC.x; }
	double GetCY() { return mC.y; }
	sPos GetC() { return mC; }
	double GetWidth() { return mWidth; }
	double GetHight() { return mHeight; }
	double GetAngle() { return mAngle; }
	double GetSpeed() { return mSpeed; }
	double GetR() { return mR; }
	int GetOnActive() { return mOnActive; }
	int GetGrHandle() { return mGrHandle; }
	int* GetGrHandles() { return mGrHandles; }
	int GetGrHandleCount() { return mGrHandlesCount; }

	void AddPos(double _vx) { mPos.x += _vx; }

	/*
	//�l�̐ݒ�i���g�p
	void SetPosX(double x) { mPos.x = x; }
	void SetPosY(double y) { mPos.y = y; }
	void SetPos(sPos pos) { mPos = pos; }
	void SetVX(double vx) { mV.x = vx; }
	void SetVY(double vy) { mV.y = vy; }
	void SetV(sPos v) { v = mV; }
	void SetCX(double cx) { mC.x = cx; }
	void SetCY(double cy) { mC.y = cy; }
	void SetC(sPos c) { mC = c; }
	void SetWidth(double width) { mWidth = width; }
	void SetHight(double hight) { mHeight = hight; }
	void SetAngle(double angle) { mAngle = angle; }
	void SetSpeed(double speed) { mSpeed = speed; }
	void SetR(double r) { mR = r; }
	void SetOnActive(int onactive) { mOnActive = onactive; }
	void SetGrHandle(int grhandle) { mGrHandle = grhandle; }
	void SetGrHandles(int* grhandles) { mGrHandles = grhandles; }
	void SetGrHandleCount(int grhandlescount) { mGrHandlesCount = grhandlescount; }
	*/
};
