#include"EquipDataBase.h"

int EquipDataBase::Initialize() {
	//�f�o�b�O�p�ɉ��f�[�^�����Ă��܂�
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
�֐����Fint EquipDataBase::GetEqCount(eClass _unitType,int _unitId) 
�����FeClass _unitType�c���j�b�g���� eChara�Ȃ�L�����̑����f�[�^�AeEnemy�Ȃ�G�̑����f�[�^�ɐ؂�ւ���
�@�@�@int _unitId�c���j�b�gID
�߂�l:int idCount�c�������Ă��镐��̐�
�@�\�����F�w��L�����N�^�[�̑������Ă��镐��̐����擾����Ƃ��Ɏg�p���Ă��������B
		�@��)�L�����N�^�[�N���X�̃^���N(ID�c1)����������𑕔����Ă��邩�m�肽���ꍇ
			 int hoge=GetEqCount(eChara,1);
			 ���^���N�������2�������Ă�����hoge��2���������܂��B
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
�֐����Fint EquipDataBase::GetEq(eClass _unitType,int _unitId, int _eqNum)
�����FeClass _unitType�c���j�b�g���� eChara�Ȃ�L�����̑����f�[�^�AeEnemy�Ȃ�G�̑����f�[�^�ɐ؂�ւ���
�@�@�@int _unitId�c���j�b�gID
	  int _eqNum�c���ڂ̑�����
�߂�l:int eqID�c����ID
�@�\�����F�w��L�����N�^�[���w��ڂɑ������Ă��镐���ID���擾����Ƃ��Ɏg�p���Ă�������
		�@��)�L�����N�^�[�N���X�̃^���N(ID�c1)��3����𑕔����Ă��āA2�ڂɑ������Ă��镐���ID��m�肽���ꍇ
			 int hoge=GetEq(eChara,1,2);
			 ���^���N������(ID:99)�𑕔����Ă�����hoge��99���������܂��B
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
�֐����Fint EquipDataBase::SetEquipData(eClass _unitType,int _unitId, int _equipId) 
�����FeClass _unitType�c���j�b�g���� eChara�Ȃ�L�����̑����f�[�^�AeEnemy�Ȃ�G�̑����f�[�^�ɐ؂�ւ���
�@�@�@int _unitId�c���j�b�gID
	�@int _equipId�c����ID
�߂�l:�Ȃ�
�@�\�����F�V�����L�����N�^�[�ɕ���𑕔�������Ƃ��Ɏg�p���Ă��������B
		�@��)�L�����N�^�[�N���X�̃^���N(ID�c1)�ɕ���(ID:99)�𑕔����������ꍇ
			 int hoge=SetEquipData(eChara,1,99);
			 ���f�[�^�x�[�X��Ƀ^���N������ID(99)�̕���𑕔����Ă����񂪒ǉ�����܂��B
*****************************************************************************************/
void EquipDataBase::SetEquipData(eClass _unitType, short _unitId, short _equipId) {
	if(_unitType==eChara)charaEqData.emplace_back(new EquipData(charaEqData.size() + 1, _unitId, _equipId));
	else if(_unitType==eEnemy)enemyEqData.emplace_back(new EquipData(enemyEqData.size() + 1, _unitId, _equipId));
}


/************************************************************************************
�֐����Fint EquipDataBase::DeleteEq(eClass _unitType,int _unitId, int _eqId)
�����FeClass _unitType�c���j�b�g���� eChara�Ȃ�L�����̑����f�[�^�AeEnemy�Ȃ�G�̑����f�[�^�ɐ؂�ւ���
�@�@�@int _unitId�c���j�b�gID
�߂�l:�Ȃ�
�@�\�����F�w��L�����N�^�[�̑������Ă��镐��f�[�^����������Ƃ��Ɏg�p���Ă��������B
		�@��)�L�����N�^�[�N���X�̃^���N(ID�c1)���������̕���(ID:99)���O�������ꍇ
			 int hoge=GetEqCount(eChara,1);
			 ���f�[�^�x�[�X�ォ��^���N������(ID:99)�������Ă����񂪏�������܂��B
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