#include"EquipDataBase.h"

int EquipDataBase::Initialize() {
	//デバッグ用に仮データを入れています
	for (int i = 0; i = 8; i++) {
		eqData.emplace_back(new EquipData(i,i+1,i+2));
	}
	return 0;
}

/************************************************************************************
関数名：int EquipDataBase::GetEqCount(int _charaId) 
引数：int _charaId…キャラクターID
戻り値:int idCount…装備している武器の数
機能説明：指定キャラクターの装備している武器の数を取得するときに使用してください。
		　例)タンク(ID…1)がいくつ武器を装備しているか知りたい場合
			 int hoge=GetEqCount(1);
			 →タンクが武器を2つ装備していたらhogeに2が代入されます。
************************************************************************************/
int EquipDataBase::GetEqCount(int _charaId) {
	int idCount;
	for (int i = 0; i < eqData.size(); i++) {
		if(eqData[i]->GetCharaId()==_charaId)idCount++;
	}
	return idCount;
}

/*****************************************************************************************
関数名：int EquipDataBase::GetEq(int _charaId, int _eqNum)
引数：int _charaId…キャラクターID
	  int _eqNum…何個目の装備か
戻り値:int eqID…武器ID
機能説明：指定キャラクターが指定個目に装備している武器のIDを取得するときに使用してください
		　例)タンク(ID…1)が3つ武器を装備していて、2つ目に装備している武器のIDを知りたい場合
			 int hoge=GetEq(1,2);
			 →タンクが武器(ID:99)を装備していたらhogeに99が代入されます。
*********************************************************************************************/
int EquipDataBase::GetEq(int _charaId, int _eqNum) {
	int tmpNum = 0,eqId = 0;
	for (int i = 0; i < eqData.size(); i++) {
		if (eqData[i]->GetCharaId() == _charaId)tmpNum++;
		if (tmpNum == _eqNum) {
			eqId = eqData[i]->GetEquipId();
			break;
		}
	}
	return eqId;
}


/*****************************************************************************************
関数名：int EquipDataBase::SetEquipData(int _charaId, int _equipId) 
引数：int _charaId…キャラクターID
	　int _equipId…武器ID
戻り値:なし
機能説明：新しくキャラクターに武器を装備させるときに使用してください。
		　例)タンク(ID…1)に武器(ID:99)を装備させたい場合
			 int hoge=SetEquipData(1,99);
			 →データベース上にタンクが武器ID(99)の武器を装備している情報が追加されます。
*****************************************************************************************/
void EquipDataBase::SetEquipData(int _charaId, int _equipId) {
	eqData.emplace_back(new EquipData(eqData.size() + 1, _charaId, _equipId));
}


/************************************************************************************
関数名：int EquipDataBase::DeleteEq(int _charaId, int _eqId)
引数：int _charaId…キャラクターID
戻り値:なし
機能説明：指定キャラクターの装備している武器データを消去するときに使用してください。
		　例)タンク(ID…1)が装備中の武器(ID:99)を外したい場合
			 int hoge=GetEqCount(1);
			 →データベース上からタンクが武器(ID:99)装備している情報が消去されます。
************************************************************************************/
void EquipDataBase::DeleteEq(int _charaId, int _eqId) {
	int dataId = 0;
	
	for (int i = 0; i < eqData.size(); i++) {
		if (eqData[i]->GetCharaId() == _charaId && eqData[i]->GetEquipId() == _eqId) {
			dataId = eqData[i]->GetId();
		}
	}

	eqData.erase(eqData.begin() +(dataId-1));


}