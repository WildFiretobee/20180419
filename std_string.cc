 ///
 /// @file    std_string.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-04-19 10:58:42
 ///
 
#include <stdio.h>
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;
 
int main(void)
{
	string s0 = "f;lasjfljsdf;ljsdlkfjsadl;kfjl;ksdajf lkjsf;l jfdlj ;lasdjf l;sjdf;l jasl;f ja;lj ;aj";
	string s1("hello,world");
	string s2(s1);
	string s3(s1);
	cout << "sizeof(string) = " << sizeof(string) << endl;
	cout << "sizeof(s1) = " << sizeof(s1) << endl;
	cout << "sizeof(s0) = " << sizeof(s0) << endl;

	cout << "s1' c_str = " << s1.c_str() << endl;
	cout << "s2' c_str = " << s2.c_str() << endl;
	cout << "s3' c_str = " << s3.c_str() << endl;
	printf("s1' c_str addr = %p\n", s1.c_str());
	printf("s2' c_str addr = %p\n", s2.c_str());
	printf("s3' c_str addr = %p\n", s3.c_str());
	
	s3[0] = 'X';
	cout << "发生修改之后: " << endl;
	cout << "s1' c_str = " << s1.c_str() << endl;
	cout << "s2' c_str = " << s2.c_str() << endl;
	cout << "s3' c_str = " << s3.c_str() << endl;
	printf("s1' c_str addr = %p\n", s1.c_str());
	printf("s2' c_str addr = %p\n", s2.c_str());
	printf("s3' c_str addr = %p\n", s3.c_str());


	return 0;
 
}