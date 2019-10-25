#include<DxLib.h>
#include"Load.h"
int Load::Initialize() {
	mHp = 0;		//�̗�
	mStr = 0;		//��(�����p)
	mDef = 0;		//�h��(�����p)
	mIntelli = 0;		//����(���@�p)
	mMnd = 0;		//���h(���@�p)
	mGrowthDex = 0;		//	����
	mAgi = 0;		//���
	mMove = 0;	//�ړ���

	mRangeMin = 0;
	mRangeMax = 0;

	mGrowthHp = 0;
	mGrowthStr = 0;
	mGrowthDef = 0;
	mGrowthIntelli = 0;
	mGrowthMnd = 0;
	mGrowthDex = 0;
	mGrowthAgi = 0;

	return 0;
}

int Load::LoadFile(int _fileHandle, char* _data) {
	DrawFormatString(100, 250, GetColor(255, 255, 255), "Load");
	for (int i = 0; i < 64; i++) {
		DrawFormatString(100, (i + 1) * 20 + 250, GetColor(255, 255, 255), "Load%d", i);
		_data[i] = FileRead_getc(_fileHandle);  //�t�@�C���ǂݍ���

		if (_data[i] == '/') { //�X���b�V��������� 
			if (i > 0 && _data[i - 1] == '/') {
				while (FileRead_getc(_fileHandle) != '\n');//���s�܂Ń��[�v
				i = -1;//�J�E���^���ŏ��ɖ߂���
				continue;
			}
		}

		if (_data[i] == EOF)return 0;  //�t�@�C���I�[�Ȃ炻���ŏI���

		if (_data[i] == ',' || _data[i] == '-' || _data[i] == '\n') {//�J���}�����s�̏ꍇ
			_data[i] = '\0';  //�����܂ł𕶎���Ƃ���
			break;
		}
	}
}

/******************************************************
�^:int
����:const char* _filePath�c�ǂݍ��ރt�@�C���̃p�X
�@�@ vector<Mass>& _mass�c�}�b�v�̒n�`�����i�[����@
*******************************************************/
int Load::LoadData(const char* _filePath, vector<Mass>& _mass, const char* _PosFilePath) {

	int stageHandle = FileRead_open(_filePath);  //�t�@�C���I�[�v��
	int posHandle = FileRead_open(_PosFilePath);

	int n = 0, nn = 0;

	char input[256];

	if (stageHandle == NULL)return -1;
	if (posHandle == NULL)return -1;

	while (FileRead_eof(stageHandle) == 0) {  //�t�@�C���̏I�[�܂�
		LoadFile(stageHandle, input);  //�f�[�^�ǂݍ���	
		_mass.emplace_back(Mass(0, atoi(input), INSTANCE->cul.SetCost(atoi(input))));
	}

	while (FileRead_eof(posHandle) == 0) {  //�t�@�C���̏I�[�܂�
		LoadFile(posHandle, input);  //�f�[�^�ǂݍ���	

		switch (n) {
		case 0: strstr(_PosFilePath, "Player") ? mInitPlayerPos[nn].x = atoi(input) : mInitEnemyPos[nn].x = atoi(input); break;
		case 1: strstr(_PosFilePath, "Player") ? mInitPlayerPos[nn].y = atoi(input) : mInitEnemyPos[nn].y = atoi(input); break;
		}
		n++;
		if (n == 2) {
			n = 0;
			if (strstr(_PosFilePath, "Player"))	INSTANCE->SetCharaPos(nn, mInitPlayerPos[nn]);
			else INSTANCE->SetEnemyPos(nn, mInitEnemyPos[nn]);
			nn++;
			if (strstr(_PosFilePath, "Player") && nn == INSTANCE->GetCharaDataSize() ||
				strstr(_PosFilePath, "Enemy") && nn == INSTANCE->GetEnemyDataSize())break;
		}
	}

	FileRead_close(stageHandle);
	FileRead_close(posHandle);

	return 0;
}

/**************************************************************************
�^:int
����:const char* _baseFilePath�c�ǂݍ��ރt�@�C���̃p�X
	 const char* _growthFilePath�c�ǂݍ��ރt�@�C���̃p�X
�@�@ vector<Mass>& _unit�c��b�X�e�[�^�X�Ɛ�����X�e�[�^�X���i�[����
***************************************************************************/
//int LoadData(const char* _baseFilePath, const char* _growthFilePath){
//int Load::LoadData(const char* _baseFilePath, const char* _growthFilePath, vector<Unit>& _unit) {
int Load::LoadData(const char* _baseFilePath, const char* _growthFilePath) {
	//�t�@�C���I�[�v��
	mBaseHandle = FileRead_open(_baseFilePath);
	mGrowthHandle = FileRead_open(_growthFilePath);

	int n = 0;
	int nn = 0;

	if (mBaseHandle == NULL)return -1;
	if (mGrowthHandle == NULL)return -1;

	while (FileRead_eof(mBaseHandle) == 0) {
		while (FileRead_eof(mBaseHandle) == 0) {  //�t�@�C���̏I�[�܂�

			if (strstr(_baseFilePath, "Player") && FileRead_eof(mBaseHandle) == 0) {
				LoadChara(mBaseHandle, mGrowthHandle, eChara);
			}
			else if (strstr(_baseFilePath, "Enemy") && FileRead_eof(mBaseHandle) == 0) {
				LoadChara(mBaseHandle, mGrowthHandle, eEnemy);
			}
			else if (strstr(_baseFilePath, "Fairy") && FileRead_eof(mBaseHandle) == 0) {
				LoadWeapon(mBaseHandle, mGrowthHandle);
			}

		}
	}

	FileRead_close(mBaseHandle);
	FileRead_close(mGrowthHandle);
	return 0;
}


/**************************************************************************
�^:int
����:const char* _baseHandle�c�ǂݍ��ރt�@�C���̃n���h��
	 const char* _growthHandle�c�ǂݍ��ރt�@�C���̃n���h��
�@�@ int _type�c�ǂݍ��ރf�[�^�^�C�v
***************************************************************************/
//int Load::LoadChara(int _baseHandle, int _growthHandle, vector<Unit>& _unit) {
int Load::LoadChara(int _baseHandle, int _growthHandle, int _type) {
	int n = 0;
	int nn = 0;
	static int count = 0;
	//	int dataSize = INSTANCE->GetCharaDataSize();

	while (FileRead_eof(mBaseHandle) == 0) {
		while (FileRead_eof(mBaseHandle) == 0) {  //�t�@�C���̏I�[�܂�

			LoadFile(mBaseHandle, input);  //�f�[�^�ǂݍ���

			switch (n) {
			case 0:mName = input; break;
			case 1:mRole = eRole(atoi(input)); break;
			case 2:mHp = atoi(input); break;
			case 3:mStr = atoi(input); break;
			case 4:mDef = atoi(input); break;
			case 5:mIntelli = atoi(input); break;
			case 6:mMnd = atoi(input); break;
			case 7:mDex = atoi(input); break;
			case 8:mAgi = atoi(input); break;
			case 9:mMove = atoi(input); break;
			case 10:
				if (strstr(input, "/") == NULL) {
					break;
				}
				else {
					strcpy(mFilePath, input); break;
				}
			}

			n++;
			if (n == 11) {  //new���Ȃ��Ƃ����Ȃ��Ƃ�����Ȃ��Ƃ���܂��H
				INSTANCE->SetCharaData(Chara(mName, mRole, mHp, mStr, mDef, mIntelli, mMnd, mDex, mAgi, mMove, 0, 1));
				count++;
				n = 0;
				break;
			}
		}
		while (FileRead_eof(mGrowthHandle) == 0) {  //�t�@�C���̏I�[�܂�

			LoadFile(mGrowthHandle, input);  //�f�[�^�ǂݍ���	
			int tmp;
			//for (int i = 0;   tmp = INSTANCE->GetCharaDataSize(); i++) {
			switch (nn) {
			case 0:mGrowthHp = atof(input); break;
			case 1:mGrowthStr = atof(input); break;
			case 2:mGrowthDef = atof(input); break;
			case 3:mGrowthIntelli = atof(input); break;
			case 4:mGrowthMnd = atof(input); break;
			case 5:mGrowthDex = atof(input); break;
			case 6:mGrowthAgi = atof(input); break;

			}
			nn++;
			if (nn == 7) {
				INSTANCE->SetCharaGrowth(count-1, mGrowthHp, mGrowthStr, mGrowthDef, mGrowthIntelli, mGrowthMnd, mGrowthDex, mGrowthAgi);
				//_unit[_unit.size() - 1].SetGrowth(mGrowthHp, mGrowthStr, mGrowthDef, mGrowthIntelli, mGrowthMnd, mGrowthDex, mGrowthAgi);
				nn = 0;
				break;
			}
		}
	}
	count = 0;
	return 0;
}

/**************************************************************************
�^:int
����:const char* _baseHandle�c�ǂݍ��ރt�@�C���̃n���h��
	 const char* _growthHandle�c�ǂݍ��ރt�@�C���̃n���h��
�@�@ int _type�c�ǂݍ��ރf�[�^�^�C�v
***************************************************************************/
int Load::LoadEnemy(int _baseHandle, int _growthHandle) {
	int n = 0;
	int nn = 0;

	while (FileRead_eof(mBaseHandle) == 0) {
		while (FileRead_eof(mBaseHandle) == 0) {  //�t�@�C���̏I�[�܂�

			LoadFile(mBaseHandle, input);  //�f�[�^�ǂݍ���

			switch (n) {
			case 0:mName = input; break;
			case 1:mRole = eRole(atoi(input)); break;
			case 2:mHp = atoi(input); break;
			case 3:mStr = atoi(input); break;
			case 4:mDef = atoi(input); break;
			case 5:mIntelli = atoi(input); break;
			case 6:mMnd = atoi(input); break;
			case 7:mDex = atoi(input); break;
			case 8:mAgi = atoi(input); break;
			case 9:mMove = atoi(input); break;
			case 10:
				if (strstr(input, "/") == NULL) {
					break;
				}
				else {
					strcpy(mFilePath, input); break;
				}
			}

			n++;
			if (n == 11) {
				mEnemyData.emplace_back(Enemy(mName, mRole, mHp, mStr, mDef, mIntelli, mMnd, mDex, mAgi, mMove, 0, 1));
				n = 0;
				break;
			}
		}
		while (FileRead_eof(mGrowthHandle) == 0) {  //�t�@�C���̏I�[�܂�

			LoadFile(mGrowthHandle, input);  //�f�[�^�ǂݍ���	

			switch (nn) {
			case 0:mName = input; break;
			case 1:mGrowthStr = atof(input); break;
			case 2:mGrowthDef = atof(input); break;
			case 3:mGrowthIntelli = atof(input); break;
			case 4:mGrowthMnd = atof(input); break;
			case 5:mGrowthDex = atof(input); break;
			case 6:mGrowthAgi = atof(input); break;
			}
			nn++;
			if (nn == 7) {
				//mEnemyData[mEnemyData.size() - 1].SetGrowth(mGrowthHp, mGrowthStr, mGrowthDef, mGrowthIntelli, mGrowthMnd, mGrowthDex, mGrowthAgi);
				nn = 0;
				break;
			}
		}
	}
	return 0;
}



/**************************************************************************
�^:int
����:const char* _baseHandle�c�ǂݍ��ރt�@�C���̃n���h��
	 const char* _growthHandle�c�ǂݍ��ރt�@�C���̃n���h��
�@�@ int type�c�ǂݍ��ރf�[�^�^�C�v
***************************************************************************/
int Load::LoadWeapon(int _baseHandle, int _growthHandles) {
	//int Load::LoadWeapon(int _baseHandle, int _growthHandle, vector<Unit>& _unit) {
	int n = 0, nn = 0;

	while (FileRead_eof(mBaseHandle) == 0) {
		while (FileRead_eof(mBaseHandle) == 0) {  //�t�@�C���̏I�[�܂�
			LoadFile(mBaseHandle, input);  //�f�[�^�ǂݍ���

			switch (n) {
			case 0:mName = input; break;
			case 1:mRangeMin = atoi(input); break;
			case 2:mRangeMax = atoi(input); break;
			case 3:mRole = eRole(atoi(input)); break;
			case 4:mHp = atoi(input); break;
			case 5:mStr = atoi(input); break;
			case 6:mDef = atoi(input); break;
			case 7:mIntelli = atoi(input); break;
			case 8:mMnd = atoi(input); break;
			case 9:mDex = atoi(input); break;
			case 10:mAgi = atoi(input); break;
			case 11:mMove = atoi(input); break;
			case 12:
				if (strstr(input, "/") == NULL) {
					break;
				}
				else {
					strcpy(mFilePath, input); break;
				}
			}

			n++;

			if (n == 13) {
				//	INSTANCE->SetFairyDate(Unit(mName, mRole, mHp, mStr, mDef, mIntelli, mMnd, mDex, mAgi, mMove, 0, 0)); break;
				INSTANCE->SetFairyDate(Fairy(mName, mRole, mHp, mStr, mDef, mIntelli, mMnd, mDex, mAgi, mMove, 0, 0, mRangeMin, mRangeMax)); break;

				n = 0;
				break;
			}
		}
		while (FileRead_eof(mGrowthHandle) == 0) {  //�t�@�C���̏I�[�܂�
			LoadFile(mGrowthHandle, input);  //�f�[�^�ǂݍ���	

			switch (nn) {
			case 0:mGrowthHp = atof(input); break;
			case 1:mGrowthStr = atof(input); break;
			case 2:mGrowthDef = atof(input); break;
			case 3:mGrowthIntelli = atof(input); break;
			case 4:mGrowthMnd = atof(input); break;
			case 5:mGrowthDex = atof(input); break;
			case 6:mGrowthAgi = atof(input); break;
			}
			nn++;
			if (nn == 7) {
				//_unit[_unit.size() - 1].SetGrowth(mGrowthHp, mGrowthStr, mGrowthDef, mGrowthIntelli, mGrowthMnd, mGrowthDex, mGrowthAgi);
				nn = 0;
				break;
			}
		}
	}
	return 0;
}