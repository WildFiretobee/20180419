 ///
 /// @file    templateAdd.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-04-19 16:10:24
 ///
 
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

		//实参传递时类型
//函数模板 ------------> 模板函数 --> 模板参数推导
//		     实例化
//相当于代码生成器
//

#if 1
template <typename T>
T add(T x, T y);//函数模板的声明
#endif

//函数模板之间可以进行重载
template <typename T>
T add(T x, T y, T z)
{
	return x + y + z;
}

//模板的特化, 可以出现多个
template <>
const char * add<const char *>(const char * p1, const char * p2)
{
	char * ptmp = new char[strlen(p1) + strlen(p2) + 1]();
	strcpy(ptmp, p1);
	strcat(ptmp, p2);
	return ptmp;
}


#if 0
const char * add(const char * p1, const char * p2)
{
	char * ptmp = new char[strlen(p1) + strlen(p2) + 1]();
	strcpy(ptmp, p1);
	strcat(ptmp, p2);
	return ptmp;
}
#endif

//函数模板可以与普通函数进行重载
//普通函数会优先于模板的调用
#if 0
int add(int x, int y)
{
	cout << "int add(int, int)" << endl;
	return x + y;
}

double add(double x, double y)
{
	return x + y;
}

char add(char x, char y)
{
	return x + y;
}
#endif
 
#if 0
int test0(void)
{
	int a = 3, b = 4, c = 5;
	double d1 = 3.3, d2 = 4.4;
	char c1 = 'A', c2 = 2;
	cout << add(a, b) << endl;//隐式实例化
	cout << add<double>(d1, d2) << endl;//显式实例化
	cout << add(c1, c2) << endl;
	cout << add(a, b, c) << endl;
	//cout << add(a, d1) << endl;//error,不会进行强制转换
}
#endif
void test1(void)
{
	const char * p1 = "hello";
	const char * p2 = "world";
	cout << add(p1, p2) << endl;
}

int main(void)
{
	test1();
	return 0;
}

//通用形式
template <typename T>
T add(T x, T y) // 函数模板的实现
{
	cout << "T add(T,T)" << endl;
	return  x + y;
}
