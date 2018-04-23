 ///
 /// @file    atexit.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-04-19 10:10:00
 ///
 
#include <stdlib.h>
#include <iostream>
using std::cout;
using std::endl;

void test(void)
{
	cout << "test()" << endl;
}
 
int main(void)
{
	cout << "main start ()" << endl;
	//其作用是 在进程退出后会自动调用已经注册的函数，一个函数可以注册多次
	//注册几次就执行几次
	::atexit(test);
	::atexit(test);
	::atexit(test);
	cout << "main end() " << endl;
	return 0;
}