#pragma once
class BaseTask
{
public:
	BaseTask() {}
	virtual ~BaseTask() {}

	virtual int Initialize() = 0;	//‰Šú‰»ˆ—
	virtual int Update() = 0;		//ŒvZˆ—
	virtual int Draw() = 0;			//•`‰æˆ—
	virtual int Close() = 0;		//I—¹ˆ—

};
