#include<DxLib.h>
#include"Load.h"
/*******
�^:void
����:const char* file_Path�c�ǂݍ��ރt�@�C���̃p�X
�@�@ vector<Mass>& _mass�c�}�b�v�̒n�`�����i�[����@
*****/
void Load::LoadMap(char* _filePath, vector<Mass>& _mass) {
	//�񎟌��z��̑���@�����̌^�@
	int stageHandle=FileRead_open(_filePath); 
	char input[256];  //�t�@�C���ǂݍ��ݗp(char)

	while (FileRead_eof(stageHandle) == 0) {  //�t�@�C���̏I�[�ɂȂ�܂�
		for (int i = 0; i < 64; i++) {
			input[i] = FileRead_getc(stageHandle);
			if (input[i] == ',' || input[i] == '\n') {//�J���}�����s�̏ꍇ
				input[i] = '\0';  //�����܂ł𕶎���Ƃ���
				break;
			}
		}
		_mass.emplace_back(atoi(input));  //Mass�z��ɑ��
	}
}		