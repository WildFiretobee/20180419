 ///
 /// @file    COWString.cc
 /// @author  WildFiretobee(Danderous@email.com)
 /// @date    2018-04-19 17:20:31
 ///

#include <stdio.h>
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class String
{
	class CharProxy
	{
	public:
		CharProxy(size_t idx, String & self)
		: _idx(idx)
		, _self(self)
		{}

		operator char(){
			return _self._pstr[_idx];
		}

		char & operator=(const char & ch);
	private:
		size_t _idx;
		String & _self;
	};

public:
	String();
	String(const char*);
	String(const String &rhs);
	String & operator=(const String &rhs);
	~String();

	size_t size(){ return strlen(_pstr); }
	const char * c_str() const {  return _pstr; }

	size_t refcount() const
	{	return ((int*)(_pstr-4))[0];	}

	friend std::ostream & operator<<(std::ostream &os,const String &rhs);
	const char & operator[](size_t idx) const
	{
		return _pstr[idx];
	}

	CharProxy operator[](size_t idx);

private:
	void initRefcount()
	{	((int*)( _pstr - 4))[0]=1;	}

	void increaseRefcount()
	{
		++(((int*)(_pstr-4))[0]);
	}
	
	void decreaseRefcount()
	{
		--(((int*)(_pstr-4))[0]);
	}

	void release()
	{
		decreaseRefcount();
		if(refcount() == 0)
		{
			delete [] (_pstr-4);
			cout << "release data" << endl;
		}
	}

private:
	char * _pstr;
};

std::ostream & operator<<(std::ostream &os,const String &rhs)
{
	os << rhs._pstr;
	return os;
}

String::String()
: _pstr(new char[5]())
{
	cout << "String()" << endl;
	_pstr+=4;
	initRefcount();
}
	
String::String(const char* pstr)
: _pstr(new char[strlen(pstr) + 5]())
{
	cout << "String(const char *) " << endl;
	_pstr += 4;
	initRefcount();
	strcpy(_pstr, pstr);
}

String::String(const String &rhs)
: _pstr(rhs._pstr)
{
	increaseRefcount();
}

String & String::operator=(const String &rhs)
{
	if(this != &rhs)
	{
		release();//	先释放左操作数开辟的空间
		_pstr = rhs._pstr;
		increaseRefcount();
	}
	return *this;
}

String::CharProxy String::operator[](size_t idx)
{
	return CharProxy(idx,*this);
}

String::~String()
{
	release();
	cout << "~String()" << endl;
}

char & String::CharProxy::operator=(const char & ch)
{
	if(_self.refcount() > 1)
	{
		_self.decreaseRefcount();
		//深拷贝
		char * ptmp = new char[_self.size() + 5]();
		strcpy(ptmp + 4, _self._pstr);
		_self._pstr = ptmp + 4;
		_self.initRefcount();
	}
	_self._pstr[_idx] = ch;
	return _self._pstr[_idx];
}

int main(void)
{
	String s1("hello,mote");
	String s2(s1);
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	cout << "s1.refcount = " << s1.refcount() << endl;
	cout << "s2.refcount = " << s2.refcount() << endl;

	printf("s1` addr = %p\n",s1.c_str());
	printf("s2` addr = %p\n",s2.c_str());

	String s3("world");
	cout << "s3 = " << s3 << endl;
	cout << endl << "执行s3 = s1" << endl;
	s3=s1;
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	cout << "s3 = " << s3 << endl;
	cout << "s1.refcount = " << s1.refcount() << endl;
	cout << "s2.refcount = " << s2.refcount() << endl;
	cout << "s3.refcount = " << s3.refcount() << endl;
	
	printf("s1` addr = %p\n",s1.c_str());
	printf("s2` addr = %p\n",s2.c_str());
	printf("s3` addr = %p\n",s3.c_str());

	s3[0]='O';
	cout << endl << "执行s3[0] = 'O' 后：" << endl;
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	cout << "s3 = " << s3 << endl;
	cout << "s1.refcount = " << s1.refcount() << endl;
	cout << "s2.refcount = " << s2.refcount() << endl;
	cout << "s3.refcount = " << s3.refcount() << endl;

	printf("s1` addr = %p\n",s1.c_str());
	printf("s2` addr = %p\n",s2.c_str());
	printf("s3` addr = %p\n",s3.c_str());

	cout << endl << "执行读操作s1[0] = " << s1[0] << endl;
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	cout << "s3 = " << s3 << endl;
	cout << "s1.refcount = " << s1.refcount() << endl;
	cout << "s2.refcount = " << s2.refcount() << endl;
	cout << "s3.refcount = " << s3.refcount() << endl;

	printf("s1` addr = %p\n",s1.c_str());
	printf("s2` addr = %p\n",s2.c_str());
	printf("s3` addr = %p\n",s3.c_str());


	return 0;
}
