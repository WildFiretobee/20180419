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
	//�������� �ڽ����˳�����Զ������Ѿ�ע��ĺ�����һ����������ע����
	//ע�Ἰ�ξ�ִ�м���
	::atexit(test);
	::atexit(test);
	::atexit(test);
	cout << "main end() " << endl;
	return 0;
}