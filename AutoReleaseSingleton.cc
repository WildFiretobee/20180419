 ///
 /// @file    AutoReleaseSingleton.cc
 /// @author  WildFiretobee(Danderous@email.com)
 /// @date    2018-04-19 22:23:06
 ///
 
#include <iostream>
using std::cout;
using std::endl;

//单例对象自动释放方法之一:
//
// 嵌套类 + 静态对象
//

class Singleton
{
	class AutoRelease
	{
	public:
		AutoRelease(){ cout << "AutoRelease()" << endl; }
		~AutoRelease(){
			if(_pInstance)
			{
				delete _pInstance;
				cout << "~AutoRelease()" << endl;
			}
		}
	};

public:
	//多线程环境下是 非线程安全的
	static Singleton * getInstance()
	{
		if(NULL == _pInstance)
		{
			_pInstance = new Singleton;
		}
		return _pInstance;
	}

private:
	Singleton(){ cout << "Singleton()" << endl; }
	~Singleton(){ cout << "~Singleton()" << endl; }

	static Singleton * _pInstance;
	static AutoRelease _auto;

};

//Singleton * Singleton::_pInstance=NULL;//饿汉模式，懒汉模式（懒加载），如使用它，就必须加锁
Singleton * Singleton::_pInstance = getInstance();//线程安全的，饱汉模式

Singleton::AutoRelease Singleton::_auto;

int main(void)
{
	Singleton * p1 = Singleton::getInstance();
	Singleton * p2 = Singleton::getInstance();
	cout << "p1 = " << p1 << endl;
	cout << "p2 = " << p2 << endl;

	return 0;
}
