 ///
 /// @file    AutoReleaseSingleton2.cc
 /// @author  WildFiretobee(Danderous@email.com)
 /// @date    2018-04-19 21:39:42
 ///

#include <stdlib.h>
#include <pthread.h>

#include <iostream>
using std::cout;
using std::endl;

//单例对象自动释放方法之二：
//
//必须要在linux环境下使用，因为关联了POSIX的线程库
//  atexit + pthread_once
//

class Singleton
{
public:
	//多线程环境下是线程安全的
	static Singleton * getInstance()
	{
		pthread_once(&_once, init);
		return _pInstance;
	}

	//只会被执行一次
	static void init()
	{
		_pInstance = new Singleton;
		::atexit(destory);
	}

	static void destory()
	{
		if(_pInstance)
			delete _pInstance;
	}

private:
	Singleton(){ cout << "Singleton()" << endl; }
	~Singleton(){ cout << "~Singleton()" << endl; }

	static Singleton * _pInstance;
	static pthread_once_t _once;
};

Singleton * Singleton::_pInstance = NULL;//饿汉模式，懒汉模式（懒加载）

pthread_once_t Singleton::_once = PTHREAD_ONCE_INIT;

int main(void)
{
	Singleton * p1 = Singleton::getInstance();
	Singleton * p2 = Singleton::getInstance();
	cout << "p1 = " << p1 << endl;
	cout << "p2 = " << p2 << endl;

	return 0;
}
