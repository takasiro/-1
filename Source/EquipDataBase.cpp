#include"EquipDataBase.h"

int EquipDataBase::Initialize() {
	//�f�o�b�O�p�ɉ��f�[�^�����Ă��܂�
	for (int i = 0; i = 8; i++) {
		eqData.emplace_back(new EquipData(i,i+1,i+2));
	}
	return 0;
}

/************************************************************************************
�֐����Fint EquipDataBase::GetEqCount(int _charaId) 
�����Fint _charaId�c�L�����N�^�[ID
�߂�l:int idCount�c�������Ă��镐��̐�
�@�\�����F�w��L�����N�^�[�̑������Ă��镐��̐����擾����Ƃ��Ɏg�p���Ă��������B
		�@��)�^���N(ID�c1)����������𑕔����Ă��邩�m�肽���ꍇ
			 int hoge=GetEqCount(1);
			 ���^���N�������2�������Ă�����hoge��2���������܂��B
************************************************************************************/
int EquipDataBase::GetEqCount(int _charaId) {
	int idCount;
	for (int i = 0; i < eqData.size(); i++) {
		if(eqData[i]->GetCharaId()==_charaId)idCount++;
	}
	return idCount;
}

/*****************************************************************************************
�֐����Fint EquipDataBase::GetEq(int _charaId, int _eqNum)
�����Fint _charaId�c�L�����N�^�[ID
	  int _eqNum�c���ڂ̑�����
�߂�l:int eqID�c����ID
�@�\�����F�w��L�����N�^�[���w��ڂɑ������Ă��镐���ID���擾����Ƃ��Ɏg�p���Ă�������
		�@��)�^���N(ID�c1)��3����𑕔����Ă��āA2�ڂɑ������Ă��镐���ID��m�肽���ꍇ
			 int hoge=GetEq(1,2);
			 ���^���N������(ID:99)�𑕔����Ă�����hoge��99���������܂��B
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
�֐����Fint EquipDataBase::SetEquipData(int _charaId, int _equipId) 
�����Fint _charaId�c�L�����N�^�[ID
	�@int _equipId�c����ID
�߂�l:�Ȃ�
�@�\�����F�V�����L�����N�^�[�ɕ���𑕔�������Ƃ��Ɏg�p���Ă��������B
		�@��)�^���N(ID�c1)�ɕ���(ID:99)�𑕔����������ꍇ
			 int hoge=SetEquipData(1,99);
			 ���f�[�^�x�[�X��Ƀ^���N������ID(99)�̕���𑕔����Ă����񂪒ǉ�����܂��B
*****************************************************************************************/
void EquipDataBase::SetEquipData(int _charaId, int _equipId) {
	eqData.emplace_back(new EquipData(eqData.size() + 1, _charaId, _equipId));
}


/************************************************************************************
�֐����Fint EquipDataBase::DeleteEq(int _charaId, int _eqId)
�����Fint _charaId�c�L�����N�^�[ID
�߂�l:�Ȃ�
�@�\�����F�w��L�����N�^�[�̑������Ă��镐��f�[�^����������Ƃ��Ɏg�p���Ă��������B
		�@��)�^���N(ID�c1)���������̕���(ID:99)���O�������ꍇ
			 int hoge=GetEqCount(1);
			 ���f�[�^�x�[�X�ォ��^���N������(ID:99)�������Ă����񂪏�������܂��B
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