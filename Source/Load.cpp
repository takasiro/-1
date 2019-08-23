#include<DxLib.h>
#include"Load.h"
int Load::LoadFile(int _fileHandle, char* _data) {
	DrawFormatString(100, 250, GetColor(255, 255, 255), "Load");
	for (int i = 0; i < 64; i++) {
		DrawFormatString(100, (i + 1) * 20 + 250, GetColor(255, 255, 255), "Load%d", i);
		_data[i] = FileRead_getc(_fileHandle);  //�t�@�C���ǂݍ���

		if (_data[i] == '/') {//�X���b�V���������
			while (FileRead_getc(_fileHandle) != '\n');//���s�܂Ń��[�v
			i = -1;//�J�E���^���ŏ��ɖ߂���
			continue;
		}

		if (_data[i] == EOF)return 0;  //�t�@�C���I�[�Ȃ炻���ŏI���

		if (_data[i] == ',' || _data[i] == '\n') {//�J���}�����s�̏ꍇ
			_data[i] = '\0';  //�����܂ł𕶎���Ƃ���
			break;
		}
	}
}

/******************************************************
�^:void
����:const char* file_Path�c�ǂݍ��ރt�@�C���̃p�X
�@�@ vector<Mass>& _mass�c�}�b�v�̒n�`�����i�[����@
*******************************************************/
int Load::LoadData(const char* _filePath, vector<Mass>& _mass) {

	int stageHandle = FileRead_open(_filePath);  //�t�@�C���I�[�v��

	char input[256];

	if (stageHandle == NULL)return -1;

	while (FileRead_eof(stageHandle) == 0) {  //�t�@�C���̏I�[�܂�
		LoadFile(stageHandle, input);  //�f�[�^�ǂݍ���	
		_mass.emplace_back(Mass(0, atoi(input), 0));  //Mass�z��ɑ��		
	}

	FileRead_close(stageHandle);

	return 0;
}


int Load::LoadData(char* _filePath, vector<Unit>& _unit) {
	//�t�@�C���I�[�v��
	int stageHandle = FileRead_open(_filePath);

	char input[256];

	char name[256];	//���O
	eRole	role;	//���̃L�����̐E��(�����l�ɕ΂���o�����邽��)
	int hp = 0;		//�̗�
	int str = 0;		//��(�����p)
	int def = 0;		//�h��(�����p)
	int intelli = 0;		//����(���@�p)
	int mnd = 0;		//���h(���@�p)
	int dex = 0;		//	����
	int agi = 0;		//���
	int move = 0;	//�ړ���

	int n = 0;


	if (stageHandle == NULL)return -1;

	while (FileRead_eof(stageHandle) == 0) {  //�t�@�C���̏I�[�܂�
		LoadFile(stageHandle, input);  //�f�[�^�ǂݍ���	

		switch (n) {
		case 0:strcpy(name, input); break;
		case 1:role = eRole(atoi(input)); break;
		case 2:hp = atoi(input); break;
		case 3:str = atoi(input); break;
		case 4:def = atoi(input); break;
		case 5:intelli = atoi(input); break;
		case 6:mnd = atoi(input); break;
		case 7:dex = atoi(input); break;
		case 8:agi = atoi(input); break;
		case 9:move = atoi(input); break;
		}

		n++;

		if (n == 10) {
			_unit.emplace_back(Unit(name, role, hp, str, def, intelli, mnd, dex, agi, move, 0, 0));
			n = 0;
		}

	}

	FileRead_close(stageHandle);

	return 0;

}