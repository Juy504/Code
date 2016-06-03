#include <iostream>
using namespace std;

void strPer(char* str,char* start)
{
	if(str == NULL)
		return;
	if(*start == '\0')
	{
		cout<<str<<" ";
	}
	else
	{
		for(char* ch = start;*ch != '\0';++ch)
		{
			swap(*ch,*start);
			strPer(str,start+1);
			swap(*ch,*start);
		}
	}
}
int main()
{
	char str[] = "abc";
	char str1[] = "";
	//strPer(str,str);
	strPer(str1,str1);
	cout<<endl;
}
