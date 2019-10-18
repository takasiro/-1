#define  _FONT_H_INCLUDED
#include "DxLib.h"

//#include "Font.h"
//int Font[10];

//Fontload.cpp
extern void Fontload();
//_FONT_H_INCLUDED

#ifndef  _GLOBAL_INSTANCE_

int Font[10];
int Fontsize[10];
extern void Fontload();

#else

extern int Font[10];
extern int Fontsize[10];

#endif //_GLOBAL_INSTANCE_