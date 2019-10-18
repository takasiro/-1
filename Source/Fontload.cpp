#include "DxLib.h"
#include "Fontcall.h"

void Fontload(){

	Font[0]= CreateFontToHandle("HG丸ｺﾞｼｯｸM-PRO", Fontsize[0], 3, DX_FONTTYPE_ANTIALIASING_EDGE);
	Font[1] = CreateFontToHandle("メイリオ", Fontsize[1], 3, DX_FONTTYPE_ANTIALIASING_EDGE);
	/*Font[2] = CreateFontToHandle("HG丸ｺﾞｼｯｸM-PRO", 30, 3, DX_FONTTYPE_ANTIALIASING_EDGE);
	Font[3] = CreateFontToHandle("メイリオ", 30, 3, DX_FONTTYPE_ANTIALIASING_EDGE);
	Font[4] = CreateFontToHandle("HG丸ｺﾞｼｯｸM-PRO", 30, 3, DX_FONTTYPE_ANTIALIASING_EDGE);
	Font[5] = CreateFontToHandle("メイリオ", 30, 3, DX_FONTTYPE_ANTIALIASING_EDGE);*/

}