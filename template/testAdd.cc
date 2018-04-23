 ///
 /// @file    testAdd.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-04-19 16:23:18
 ///
 
#include "add.h"//使用模板时，必须要知道其全部实现；仅仅有声明是不够的
#include <iostream>
using std::cout;
using std::endl;
 
int main(void)
{
	int a = 3, b = 4;
	cout << add(a, b) << endl;
}
