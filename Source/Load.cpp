#include<DxLib.h>
#include"Load.h"
int Load::LoadFile(int _fileHandle, char* _data) {
	DrawFormatString(100, 250, GetColor(255, 255, 255), "Load");
	for (int i = 0; i < 64; i++) {
		DrawFormatString(100, (i + 1) * 20 + 250, GetColor(255, 255, 255), "Load%d", i);
		_data[i] = FileRead_getc(_fileHandle);  //ファイル読み込み
		if (_data[i] == EOF)return 0;
		if (_data[i] == ',' || _data[i] == '\n') {//カンマか改行の場合
			_data[i] = '\0';  //そこまでを文字列とする
			break;
		}
	}
}

/******************************************************
型:void
引数:const char* file_Path…読み込むファイルのパス
　　 vector<Mass>& _mass…マップの地形情報を格納する　
*******************************************************/
int Load::LoadData(const char* _filePath, vector<Mass>& _mass) {
	//ファイルオープン
	int stageHandle = FileRead_open(_filePath);
	DrawFormatString(20, 20, GetColor(255, 255, 255), "open");

	char input[256];

	if (stageHandle == NULL)return -1;

	while (FileRead_eof(stageHandle) == 0) {  //ファイルの終端まで
		LoadFile(stageHandle, input);  //データ読み込み	
		_mass.emplace_back(Mass(0, atoi(input), 0));  //Mass配列に代入		
	}

	DrawFormatString(200, 100, GetColor(255, 255, 255), "%d", _mass.size());  //要素数確認

	FileRead_close(stageHandle);

	return 0;
}

/*
void Load::PlayerBase(char* _filePath, vector<Unit>& _unit) {
	int stageHandle = FileRead_open(_filePath);
	int n=0,num=0;
	//最初の二行　読み飛ばす　処理　
	for (int i = 0; i < 2; i++)while (FileRead_getc(stageHandle) != '\n');
	char input[64];
	//ファイルの読み取り処理(breakでwhile文を抜ける処理なので条件式は1に設定されている)
	while (FileRead_eof(stageHandle) == 0) {

		for (int i = 0; i < 64; i++) {
			input[i] = FileRead_getc(stageHandle);//1文字取得する
			if (input[i] == '/') {//スラッシュがあれば
				while (FileRead_getc(stageHandle) != '\n');//改行までループ
				i = -1;//カウンタを最初に戻して
				continue;
			}
			if (input[i] == ',' || input[i] == '\n') {//カンマか改行なら
				input[i] = '\0';//そこまでを文字列とし
				break;
			}
		}
	}

}*/