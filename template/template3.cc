 ///
 /// @file    template3.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-04-19 16:43:37
 ///
 
#include <iostream>
using std::cout;
using std::endl;


//普通类中也可以将成员函数定义为函数模板
//
//成员函数模板
class Example
{
public:
	template <typename T>
	T add(T x, T y)
	{
		cout << "T add(T, T)" << endl;
		return x + y;
	}

	int add(int x, int y)
	{
		cout << "int add(int, int)" << endl;
		return x + y;
	}
};
 
int main(void)
{
	int a = 3, b = 4;
	double d1 = 3.3, d2 = 4.4;
	Example e;
	cout << "a + b = " << e.add(a, b) << endl;
	cout << "d1 + d2 = " << e.add(d1, d2) << endl;

	return 0;
}
