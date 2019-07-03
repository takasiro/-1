#pragma once

#define WINDOW_WIDTH 1280	//画面の幅
#define WINDOW_HEIGHT 960	//画面の高さ


#define DEBUG

//DxLibの表示系関数のxy座標は全て引数がintの為doubleで指定すると警告がでるので例外処理
#pragma warning(disable: 4244)

//vectorのsize()関数を使ったfor文において
//size()の戻り値がunsigned intになりsigned int型と比較すると警告が出るので例外処理
#pragma warning(disable: 4018)