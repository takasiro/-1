#include<DxLib.h>
#include"Load.h"
int Load::LoadFile(int _fileHandle, char* _data) {
	DrawFormatString(100, 250, GetColor(255, 255, 255), "Load");
	for (int i = 0; i < 64; i++) {
		DrawFormatString(100, (i + 1) * 20 + 250, GetColor(255, 255, 255), "Load%d", i);
		_data[i] = FileRead_getc(_fileHandle);  //�t�@�C���ǂݍ���
		if (_data[i] == EOF)return 0;
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
	//�t�@�C���I�[�v��
	int stageHandle = FileRead_open(_filePath);
	DrawFormatString(20, 20, GetColor(255, 255, 255), "open");

	char input[256];

	if (stageHandle == NULL)return -1;

	while (FileRead_eof(stageHandle) == 0) {  //�t�@�C���̏I�[�܂�
		LoadFile(stageHandle, input);  //�f�[�^�ǂݍ���	
		_mass.emplace_back(Mass(0, atoi(input), 0));  //Mass�z��ɑ��		
	}

	DrawFormatString(200, 100, GetColor(255, 255, 255), "%d", _mass.size());  //�v�f���m�F

	FileRead_close(stageHandle);

	return 0;
}

/*
void Load::PlayerBase(char* _filePath, vector<Unit>& _unit) {
	int stageHandle = FileRead_open(_filePath);
	int n=0,num=0;
	//�ŏ��̓�s�@�ǂݔ�΂��@�����@
	for (int i = 0; i < 2; i++)while (FileRead_getc(stageHandle) != '\n');
	char input[64];
	//�t�@�C���̓ǂݎ�菈��(break��while���𔲂��鏈���Ȃ̂ŏ�������1�ɐݒ肳��Ă���)
	while (FileRead_eof(stageHandle) == 0) {

		for (int i = 0; i < 64; i++) {
			input[i] = FileRead_getc(stageHandle);//1�����擾����
			if (input[i] == '/') {//�X���b�V���������
				while (FileRead_getc(stageHandle) != '\n');//���s�܂Ń��[�v
				i = -1;//�J�E���^���ŏ��ɖ߂���
				continue;
			}
			if (input[i] == ',' || input[i] == '\n') {//�J���}�����s�Ȃ�
				input[i] = '\0';//�����܂ł𕶎���Ƃ�
				break;
			}
		}
	}

}*/