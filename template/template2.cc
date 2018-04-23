 ///
 /// @file    template2.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-04-19 16:38:49
 ///
 
#include <iostream>
using std::cout;
using std::endl;

//模板参数的形式有两种：
//1. 类型参数
//2. 非类型参数,就是整型(bool, char, short, int, long), 代表的是常量表达式
template <typename T, int number>
T add(T x, T y)
{
	return x * y * number;
}
 
int main(void)
{
	int a = 10, b = 3;
	cout << add<int, 4>(a, b) << endl;
	return 0;
}
