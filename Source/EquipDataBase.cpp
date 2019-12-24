#include"EquipDataBase.h"

int EquipDataBase::Initialize() {
	//デバッグ用に仮データを入れています
	/*for (int i = 0; i = 8; i++) {
		charaEqData.emplace_back(new EquipData(i,i+1,i+2));
	}
	*/
	return 0;
}

int EquipDataBase::GetDataCount(eClass _unitType){
	if (_unitType == eChara)return charaEqData.size();
	if (_unitType == eEnemy)return enemyEqData.size();
}


/********************************************************************************************************
関数名：int EquipDataBase::GetEqCount(eClass _unitType,int _unitId) 
引数：eClass _unitType…ユニット識別 eCharaならキャラの装備データ、eEnemyなら敵の装備データに切り替える
　　　int _unitId…ユニットID
戻り値:int idCount…装備している武器の数
機能説明：指定キャラクターの装備している武器の数を取得するときに使用してください。
		　例)キャラクタークラスのタンク(ID…1)がいくつ武器を装備しているか知りたい場合
			 int hoge=GetEqCount(eChara,1);
			 →タンクが武器を2つ装備していたらhogeに2が代入されます。
*********************************************************************************************************/
int EquipDataBase::GetEqCount(eClass _unitType, short _unitId) {
	int idCount = 0;
	
	if (_unitType == eChara) {
		for (int i = 0; i < charaEqData.size(); i++) {
			if (charaEqData[i]->GetUnitId() == _unitId)idCount++;
		}
	}

	else if (_unitType == eEnemy) {
		for (int i = 0; i < enemyEqData.size(); i++) {
			if (enemyEqData[i]->GetUnitId() == _unitId)idCount++;
		}
	}

	return idCount;
}

/*****************************************************************************************
関数名：int EquipDataBase::GetEq(eClass _unitType,int _unitId, int _eqNum)
引数：eClass _unitType…ユニット識別 eCharaならキャラの装備データ、eEnemyなら敵の装備データに切り替える
　　　int _unitId…ユニットID
	  int _eqNum…何個目の装備か
戻り値:int eqID…武器ID
機能説明：指定キャラクターが指定個目に装備している武器のIDを取得するときに使用してください
		　例)キャラクタークラスのタンク(ID…1)が3つ武器を装備していて、2つ目に装備している武器のIDを知りたい場合
			 int hoge=GetEq(eChara,1,2);
			 →タンクが武器(ID:99)を装備していたらhogeに99が代入されます。
*********************************************************************************************/
int EquipDataBase::GetEq(eClass _unitType, short _unitId, short _eqNum) {
	int tmpNum = 0,eqId = 0;

	if (_unitType == eChara) {
		for (int i = 0; i < charaEqData.size(); i++) {
			if (charaEqData[i]->GetUnitId() == _unitId)tmpNum++;
			if (tmpNum == _eqNum) {
				eqId = charaEqData[i]->GetEquipId();
				break;
			}
		}
	}
	else if (_unitType == eEnemy) {
		for (int i = 0; i < enemyEqData.size(); i++) {
			if (enemyEqData[i]->GetUnitId() == _unitId)tmpNum++;
			if (tmpNum == _eqNum) {
				eqId = enemyEqData[i]->GetEquipId();
				break;
			}
		}
	}
	return eqId;
}


/*****************************************************************************************
関数名：int EquipDataBase::SetEquipData(eClass _unitType,int _unitId, int _equipId) 
引数：eClass _unitType…ユニット識別 eCharaならキャラの装備データ、eEnemyなら敵の装備データに切り替える
　　　int _unitId…ユニットID
	　int _equipId…武器ID
戻り値:なし
機能説明：新しくキャラクターに武器を装備させるときに使用してください。
		　例)キャラクタークラスのタンク(ID…1)に武器(ID:99)を装備させたい場合
			 int hoge=SetEquipData(eChara,1,99);
			 →データベース上にタンクが武器ID(99)の武器を装備している情報が追加されます。
*****************************************************************************************/
void EquipDataBase::SetEquipData(eClass _unitType, short _unitId, short _equipId) {
	if(_unitType==eChara)charaEqData.emplace_back(new EquipData(charaEqData.size() + 1, _unitId, _equipId));
	else if(_unitType==eEnemy)enemyEqData.emplace_back(new EquipData(enemyEqData.size() + 1, _unitId, _equipId));
}


/************************************************************************************
関数名：int EquipDataBase::DeleteEq(eClass _unitType,int _unitId, int _eqId)
引数：eClass _unitType…ユニット識別 eCharaならキャラの装備データ、eEnemyなら敵の装備データに切り替える
　　　int _unitId…ユニットID
戻り値:なし
機能説明：指定キャラクターの装備している武器データを消去するときに使用してください。
		　例)キャラクタークラスのタンク(ID…1)が装備中の武器(ID:99)を外したい場合
			 int hoge=GetEqCount(eChara,1);
			 →データベース上からタンクが武器(ID:99)装備している情報が消去されます。
************************************************************************************/
void EquipDataBase::DeleteEq(eClass _unitType, short _unitId, short _eqId) {
	int dataId = 0;
	
	if (_unitType == eChara) {
		for (int i = 0; i < charaEqData.size(); i++) {
			if (charaEqData[i]->GetUnitId() == _unitId && charaEqData[i]->GetEquipId() == _eqId) {
				dataId = charaEqData[i]->GetId();
			}
		}
		charaEqData.erase(charaEqData.begin() + (dataId - 1));
	}
	else if (_unitType == eEnemy) {
		for (int i = 0; i < charaEqData.size(); i++) {
			if (enemyEqData[i]->GetUnitId() == _unitId && enemyEqData[i]->GetEquipId() == _eqId) {
				dataId = enemyEqData[i]->GetId();
			}
		}
		enemyEqData.erase(enemyEqData.begin() + (dataId - 1));
	}

}