/*********************
 *Fibonacci
 *
 *********************/
#include <stdio.h>
/*
int Fib(int n)
{
	if(n <= 0)
		return 0;
	if(n <= 1)
		return 1;
	return Fib(n-1)+Fib(n-2);
}
*/
int Fib1(int n)
{
	int sum = 0;
	int i = 0;
	int Fib1 = 1,Fib2 = 0;
	while(i<=n)
	{
		if(i<2)
		{
			sum = 1;
		}
		else
		{
			sum = Fib1 + Fib2;
			Fib2 = Fib1;
			Fib1 = sum;
		}
		i++;
	}
	return sum;
}
int Floor(int n)
{
	int result[3] = {0,1,2};
	if(n<2)
		return result[n];
	else
	{
		return Floor(n-1)+Floor(n-2);
	}
}

int main()
{
	printf("%d\n",Fib1(7));
	return 0;
}

