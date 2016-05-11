/***************************
 A string class
 ***************************/
#include <iostream>
#include <string.h>
using namespace std;

class My_string
{
public:
	My_string(char* _data = NULL)
		:m_data(_data)
	{
		if(m_data == NULL)
		{
			m_data = new char[0];
			m_data[0] = '\0';
		}
		else
		{
			m_data = new char[strlen(m_data)+1];
			strcpy(m_data,_data);
		}
	}
	My_string(const My_string& str)
	{
		m_data = new char[strlen(str.m_data)+1];
		strcpy(m_data,str.m_data);
	}
//	My_string& operator=(const My_string& str)
//	{
//		if(this != &str)
//		{
//			delete []m_data;
//			m_data = NULL;
//			m_data = new char[strlen(str.m_data)+1];//maybe throw bad_alloc
//			strcpy(m_data,str.m_data);
//		}
//		return *this;
//	}
	My_string& operator=(const My_string& str)
	{
		My_string tmp(str.m_data);
		if(this != &str)
		{
			swap(tmp.m_data,m_data);
		}
	}
	~My_string()
	{
		delete []m_data;
		m_data = NULL;
	}
private:
	char* m_data;
};
int main()
{
	My_string st("hello");
	My_string st1(st);
	My_string st2("world");
	st2 = st1;
	return 0;
}
