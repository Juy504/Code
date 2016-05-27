#include <iostream>
#include <assert.h>
using namespace std;

void Print1_To_n(char* str,int n)
{
	int i = 0;
	for (; i < n; i++)
	{
		if (str[i] != '0')
			break;
	}
	if (i == n)
		return;
	for (; i<n; i++)
		printf("%c", str[i]);
	printf(" ");
}
bool Increment(char* str)//此过程用于在字符串上模拟加法
{
	assert(str != NULL);
	bool isOverflow = false;
	int carry = 0;   //set carry bit and  initialize 0
	int Len = strlen(str);
	for (int i = Len - 1; i >= 0; i--)
	{
		int sum = str[i] - '0' + carry;
		if (i == Len - 1)
			sum++;
		if (sum  == 10)
		{
			if (i == 0)
				isOverflow = true;//the first bit is overflow
			else
			{
				sum = 0;
				str[i] = sum + '0';
				carry = 1;
			}
		}
		else
		{
			str[i] = sum + '0';//everytime print the number when number < 9
			break;
		}
	}
	return isOverflow;
}
void Print1ToMax(int n)
{
	if (n <= 0)
		return;
	char* str = new char[n + 1];
	memset(str, '0', n);
	str[n] = '\0';

	while (!(Increment(str)))
	{
		Print1_To_n(str,n);
	}
	delete[]str;
}
void NoIncrement_(char* str, int index, int len)
{
	assert(str != NULL);
	if (index == len - 1)//当下标为字符串长度时输出
	{
		Print1_To_n(str, len);
		return;
	}
	for (int i = 0; i < 10; ++i)//此循环用于输出除0下标之后剩下的位每一位都输出0-9
	{
		str[index + 1] = i + '0';
		NoIncrement_(str, index + 1, len);
	}
	
}
void Print1ToMax_(int n)
{
	if (n < 0)
		return;
	char *str = new char[n + 1];
	str[n] = '\0';
	for (int i = 0; i < 10; ++i)//此循环用于控制0下标的0-9
	{
		str[0] = i + '0';
		NoIncrement_(str, 0, n);
	}
	delete[]str;
}
//  bigData a + b
int *Sum(int a, int b)
{
	static int arr[300];
	int aa[200];
	int bb[200];
	int i = 0;
	int k = 0;
	int carry = 0;
	while (a > 0 || b > 0)
	{
		if (a > 0)
		{
			aa[i++] = a % 10;
			a /= 10;
		}
		if (b > 0)
		{
			bb[k++] = b % 10;
			b /= 10;
		}
	}
	int j = 0;
	while (i > 0 && k>0)
	{
		int tmp = aa[j] + bb[j]+carry;
		if (tmp > 9)
		{
			carry = 1;
			arr[j] = tmp % 10;
		}
		else
			arr[j] = tmp;
		i--,k--; j++;
	}
	while (k == 0 || i == 0)
	{
		if (k == 0 && i == 0)
			break;
		int tmp = 0;
		if (i == 0)
		{
			tmp = bb[j] + carry;
			k--;
		}
		else
		{
			tmp = aa[j] + carry;
			i--;
		}
		if (tmp > 9)
		{
			carry = 1;
			arr[j] = tmp % 10;
		}
		else
			arr[j] = tmp;
		j++;
	}
	while (--j >= 0)
	{
		cout << arr[j];
	}
	cout << endl;
	return arr;
}
int main()
{
	system("pause");
	return 0;
}
/*
void f(int* x, int* y, int*s)
{
	s = (int*)malloc(sizeof(int));
	*s = *x + *(y++);
}
int main()
{
	int a[2] = { 1, 2 };
	int b[2] = { 10, 20 };
	int*s = a;
	f(a, b, s);
	printf("%d\n", *s);
	system("pause");
	return 0;
}*/
