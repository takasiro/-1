#include<DxLib.h>
#include"Load.h"
/*******
型:void
引数:const char* file_Path…読み込むファイルのパス
　　 vector<Mass>& _mass…マップの地形情報を格納する　
*****/
void Load::LoadMap(char* _filePath, vector<Mass>& _mass) {
	//二次元配列の代入　引数の型　
	int stageHandle=FileRead_open(_filePath); 
	char input[256];  //ファイル読み込み用(char)

	while (FileRead_eof(stageHandle) == 0) {  //ファイルの終端になるまで
		for (int i = 0; i < 64; i++) {
			input[i] = FileRead_getc(stageHandle);
			if (input[i] == ',' || input[i] == '\n') {//カンマか改行の場合
				input[i] = '\0';  //そこまでを文字列とする
				break;
			}
		}
		_mass.emplace_back(atoi(input));  //Mass配列に代入
	}
}		