#pragma once
#include"BaseTask.h"
#include<vector>
using namespace std;
class MapSelect :public BaseTask {
private:
	//�}�b�v�\���p�̍��W
	vector<vector<int>>mPos;
	int nowMap;

	virtual int Initialize() { ; }	//����������
	virtual int Update() { ; }		//�v�Z����
	virtual int Draw() { ; }			//�`�揈��
	virtual int Close() { ; }		//�I������
	int Select();//�N���b�N���ꂽ�Ƃ��ɋN��
	int ChangeMap(int _num);

};