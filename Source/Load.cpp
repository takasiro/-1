#include<DxLib.h>
#include"Load.h"
#include"Calculator.h"
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
	
	mPos = { 0,0 };
	mLevel = 0;

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

	if (_mass.size() < 1) {
		while (FileRead_eof(stageHandle) == 0) {  //�t�@�C���̏I�[�܂�
			LoadFile(stageHandle, input);  //�f�[�^�ǂݍ���	
			_mass.emplace_back(Mass(0, atoi(input), Calculator::Instance()->SetCost(atoi(input))));
		}
	}

	while (FileRead_eof(posHandle) == 0) {  //�t�@�C���̏I�[�܂�
		LoadFile(posHandle, input);  //�f�[�^�ǂݍ���	

		switch (n) {
		case 0: mInitPlayerPos[nn].x = atoi(input); break;
		case 1: mInitPlayerPos[nn].y = atoi(input); break;
		}
		n++;
		if (n == 2) {
			n = 0;
			int tmp = INSTANCE->GetEnemyDataSize();
			if (strstr(_PosFilePath, "Player") != NULL && nn == INSTANCE->GetCharaDataSize())break;
			if (strstr(_PosFilePath, "Player") != NULL)	INSTANCE->SetCharaPos(nn, mInitPlayerPos[nn]);
			//else INSTANCE->SetEnemyPos(nn, mInitEnemyPos[nn]);
			nn++;


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
				LoadChara(mBaseHandle, mGrowthHandle);
			}
			else if (strstr(_baseFilePath, "Enemy") && FileRead_eof(mBaseHandle) == 0) {
				LoadEnemy(mBaseHandle, mGrowthHandle);
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
int Load::LoadChara(int _baseHandle, int _growthHandle) {
	int n = 0;
	int nn = 0;
	static int count = 0;

	while (FileRead_eof(mBaseHandle) == 0) {
		while (FileRead_eof(mBaseHandle) == 0) {  //�t�@�C���̏I�[�܂�

			LoadFile(mBaseHandle, input);  //�f�[�^�ǂݍ���

			switch (n) {
			case 0:mId = short(atoi(input)); break;
			case 1:mName = input; break;
			case 2:mRole = eRole(atoi(input)); break;
			case 3:mWeapon = eWeapon(atoi(input)); break;
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
					char* tmp = strstr(input, "\r");
					if (*tmp != NULL) {
						*tmp = 0x00;
						strcpy(mFilePath, input); break;
					}
				}
			}

			n++;
			if (n == 13) {
				INSTANCE->SetCharaData(Chara(mId, mName, mRole, mWeapon, mHp, mStr, mDef, mIntelli, mMnd, mDex, mAgi, mMove, 0, 1, mFilePath));
				count++;
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
				INSTANCE->SetCharaGrowth(count - 1, mGrowthHp, mGrowthStr, mGrowthDef, mGrowthIntelli, mGrowthMnd, mGrowthDex, mGrowthAgi);
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
	static	int count = 0;
	while (FileRead_eof(mBaseHandle) == 0) {
		while (FileRead_eof(mBaseHandle) == 0) {  //�t�@�C���̏I�[�܂�

			LoadFile(mBaseHandle, input);  //�f�[�^�ǂݍ���

			switch (n) {
			case 0:mId = short(atoi(input)); break;
			case 1:mName = input; break;
			case 2:mRole = eRole(atoi(input)); break;
			case 3:mWeapon = eWeapon(atoi(input)); break;
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
					char* tmp = strstr(input, "\r");
					if (*tmp != NULL) {
						*tmp = 0x00;
						strcpy(mFilePath, input); break;
					}
				}
			}

			n++;
			if (n == 13) {
				mEnemyMasterData.emplace_back(mId, mName, mRole, mWeapon, mHp, mStr, mDef, mIntelli, mMnd, mDex, mAgi, mMove, 0, 1, mFilePath);
				//INSTANCE->SetEnemyData(Enemy(mId, mName, mRole, mWeapon, mHp, mStr, mDef, mIntelli, mMnd, mDex, mAgi, mMove, 0, 1, mFilePath));
				count++;
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
				mEnemyMasterData.at(count - 1).SetGrowth(mGrowthHp, mGrowthStr, mGrowthDef, mGrowthIntelli, mGrowthMnd, mGrowthDex, mGrowthAgi);
				//INSTANCE->SetEnemyGrowth(count - 1, mGrowthHp, mGrowthStr, mGrowthDef, mGrowthIntelli, mGrowthMnd, mGrowthDex, mGrowthAgi);
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
�@�@ int type�c�ǂݍ��ރf�[�^�^�C�v
***************************************************************************/
int Load::LoadWeapon(int _baseHandle, int _growthHandles) {
	//int Load::LoadWeapon(int _baseHandle, int _growthHandle, vector<Unit>& _unit) {
	int n = 0, nn = 0;
	static	int count = 0;

	while (FileRead_eof(mBaseHandle) == 0) {
		while (FileRead_eof(mBaseHandle) == 0) {  //�t�@�C���̏I�[�܂�
			LoadFile(mBaseHandle, input);  //�f�[�^�ǂݍ���

			switch (n) {
			case 0:mId = short(atoi(input)); break;
			case 1:mName = input; break;
			case 2:mRangeMin = atoi(input); break;
			case 3:mRangeMax = atoi(input); break;
			case 4:mRole = eRole(atoi(input)); break;
			case 5:mWeapon = eWeapon(atoi(input)); break;
			case 6:mHp = atoi(input); break;
			case 7:mStr = atoi(input); break;
			case 8:mDef = atoi(input); break;
			case 9:mIntelli = atoi(input); break;
			case 10:mMnd = atoi(input); break;
			case 11:mDex = atoi(input); break;
			case 12:mAgi = atoi(input); break;
			case 13:mMove = atoi(input); break;
			case 14:
				if (strstr(input, "/") == NULL) {
					break;
				}
				else {
					char* tmp = strstr(input, "\r");
					if (*tmp != NULL) {
						*tmp = 0x00;
						strcpy(mFilePath, input); break;
					}
				}
			}
			n++;
			if (n == 15) {
				//	INSTANCE->SetFairyDate(Unit(mName, mRole, mHp, mStr, mDef, mIntelli, mMnd, mDex, mAgi, mMove, 0, 0)); break;
				INSTANCE->SetFairyDate(Fairy(mId, mName, mRole, mWeapon, mHp, mStr, mDef, mIntelli, mMnd, mDex, mAgi, mMove, 0, 1, mFilePath, mRangeMin, mRangeMax));
				count++;
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
				INSTANCE->SetFairyGrowth(count - 1, mGrowthHp, mGrowthStr, mGrowthDef, mGrowthIntelli, mGrowthMnd, mGrowthDex, mGrowthAgi);
				nn = 0;
				break;
			}
		}
	}
	return 0;
}

int Load::LoadEnemyData(const char* _FilePath) {
	//�ǂݍ���
	int n = 0;

	mBaseHandle = FileRead_open(_FilePath);

	while (FileRead_eof(mBaseHandle) == 0) {  //�t�@�C���̏I�[�܂�
		LoadFile(mBaseHandle, input);  //�f�[�^�ǂݍ���

		switch (n) {
		case 0:mPos.x = double(atof(input)); break;
		case 1:mPos.y= double(atof(input)); break;
		case 2:mRole = eRole(atoi(input)); break;
		case 3:mLevel = atoi(input); break;

		}
		n++;
		if (n == 4) {
			INSTANCE->SetEnemyData(mEnemyMasterData[mRole]);
			INSTANCE->GetEnemyDate(INSTANCE->GetEnemyDataSize() - 1).SetLv(mLevel);  //���x���ݒ�
			INSTANCE->GetEnemyDate(INSTANCE->GetEnemyDataSize() - 1).AdjustStatus();  //���x���V���N
			INSTANCE->GetEnemyDate(INSTANCE->GetEnemyDataSize() - 1).SetPos(mPos);  //�������W�ݒ�
			n = 0;
			
		}
	}

	return 0;
}


int Load::LoadEffect(const char* _FilePath, map<string,Effect>& _Effect) {
	FILE *p;
	p = fopen(_FilePath, "r");
	if (p == NULL)return -1;//err
	char str[256],Name[256],FileName[256];
	int AllNum, XNum, YNum, XSize, YSize;
	while (fgets(str,255,p) != NULL) {
		if (sscanf(str, "%[^,],%d,%d,%d,%d,%d,%s", Name, &AllNum, &XNum, &YNum, &XSize, &YSize, FileName) == 7);
		if (Name[0] == '/' && Name[1] == '/')continue;
		_Effect[Name].SetAll(Name, AllNum, XNum, YNum, XSize, YSize, FileName);
	}
	fclose(p);
	return 0;
}