#include <iostream>
using namespace std;

/*
int Num_1(int n)
{
	int flag = 1;
	int cnt = 0;
	while(flag)//flag need << 32bit
	{
		if(n & flag)
			cnt++;
		flag = flag << 1;
	}
	return cnt;
}*/
int Num_1(int n)
{
	int cnt = 0;
	while(n)
	{
		n = n & (n-1);//7   6=7&6 4=6&5 0=4&3
		cnt++;
	}
	return cnt;
}
bool pow_2(int n)
{
	if(n & n-1)
		return false;
	return true;
}
int changeNum(int m,int n)
{
	unsigned int tmp = m ^ n;
	return Num_1(tmp);
}
int main()
{
//	cout<<Num_1(15)<<endl;
//	cout<<Num_1(0x7fffffff)<<endl;
//	cout<<Num_1(0x80000000)<<endl;
	cout<<changeNum(10,13)<<endl;	
	return 0;
}
