#pragma once
#include "BaseTask.h"
class BaseObj : public BaseTask
{
public:
	typedef struct {
		double x, y;
	}sPos;

protected:
	sPos mPos;	//標準座標
	sPos mV;	//ベクトル
	sPos mC;	//中央座標
	double mWidth;	//幅
	double mHeight;	//高さ
	double mAngle;	//角度
	double mSpeed;	//速度
	double mR;	//半径
	bool mOnActive;	//アクティブ
	int mGrHandle;	//グラフィックハンドル
	int* mGrHandles;	//グラフィックハンドル複数ある場合
	int mGrHandlesCount;	//複数ある場合の個数

	//幅高さから半径を生成
	void RUpdate() {
		mR = mWidth < mHeight ? mWidth / 2 : mHeight / 2;
	}

	//基本座標を元に中央座標の更新
	void CUpdate() {
		mC.x = (mWidth / 2) + mPos.x;
		mC.y = (mHeight / 2) + mPos.y;
	}

public:

	//値の獲得
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
	//値の設定（未使用
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
