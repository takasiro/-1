#pragma once
class BaseTask
{
public:
	BaseTask() {}
	virtual ~BaseTask() {}

	virtual int Initialize() = 0;	//����������
	virtual int Update() = 0;		//�v�Z����
	virtual int Draw() = 0;			//�`�揈��
	virtual int Close() = 0;		//�I������

};
