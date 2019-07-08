#pragma once

#ifndef _SINGLETON_INCLUDE_
#define _SINGLETON_INCLUDE_

template <typename _T>
class Singleton {

protected:
	Singleton() {}
	virtual ~Singleton() {}
	Singleton(const Singleton& r) {}
	Singleton& operator=(const Singleton& r) {}

public:
	//オブジェクトインスタンスの獲得
	static _T* Instance() {
		static _T inst;
		return &inst;
	};
};

#endif