#pragma once
#include <iostream>
#include<vector>
using namespace std;
#include"BaseObj.h"

#define _FONT_H_INCLUDED

class Fontcall {
public:
private:
	int Font[10];
public:
	Fontcall();
	virtual ~Fontcall();
	int Initialize();
	int Update();
	int Update(int _b);	//�v�Z����

	int Draw();
	int Close();
	int FontNum(int Num);
};
