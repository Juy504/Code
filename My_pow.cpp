#include <iostream>
#include <vector>
#include <string>
#include <assert.h>
using namespace std;

/*
char* SubString(char* s1, char* s2,char* Mtmp)//暴力法
{
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	int pos = -1;
	int Mcount = 0;
	for (int i = 0; i<len1; i++)
	{
		for (int j=0; j < len2; j++)
		{
			if (s1[i] == s2[j])
			{
				int k;
				for (k = 1; (s1[i + k] == s2[j + k]) && (s1[i + k] != '\0'); k++)
					;
				if (k>Mcount)
				{
					pos = i;
					Mcount = k;
				}
			}
			if (pos == -1)
				Mtmp[0] = '\0';
			else
			{
				memcpy(Mtmp, s1 + pos, Mcount);
				Mtmp[Mcount] = '\0';
			}
		}
	}
	return Mtmp;
}
char* SubString1(char* s1, char* s2, char*Mtmp)//动态规划
{											//两个字符串之间每一项都需进行比较，则可建立		
	int i, j,x,y;							//二维数组
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	int**c = new int*[len1 + 1];
	for (i = 0; i < len1+1; i++)
	{
		c[i] = new int[len2 + 1];
	}
	for (i = 0; i < len1 + 1; i++)
	{
		c[i][0] = 0;
	}
	for (j = 0; j < len2 + 1; j++)
	{
		c[0][j] = 0;
	}
	 int count = -1;
	for (i = 1; i < len1+1; i++)
	{
		for (j = 1; j < len2+1; j++)
		{
			if (s1[i - 1] == s2[j - 1])
				c[i][j] = c[i - 1][j - 1] + 1;
			else 
				c[i][j] = 0;
			if (count < c[i][j])
			{
				count = c[i][j];
				x = i;
				y = j;
			}
		}
	}
	char ch[100];
	int k = count;
	ch[k--] = '\0';
	i = x - 1;
	j = y - 1;
	while(i>=0 && j>=0)
	{
		if (s1[i] == s2[j])
		{
			ch[k--] = s1[i];
			i--; j--;
		}
		else
			break;
	}
	for (i = 0; i < count; i++)
	{
		cout << ch[i];
	}
	ch[count] = '\0';
	cout << endl;
	for (i = 0; i < len1 + 1; i++)
		delete[] c[i];            //先释放每行的一维数组
	delete c;					  //再释放二维数组
	return ch;
}*/

//int partition(int arr[], int n,int left,int right)
//{
//	assert(arr != NULL);
//	int tmp = arr[left];
//	while (left < right)
//	{
//		while (left < right &&arr[right] >= tmp)
//			right--;
//		arr[right] = arr[left];
//		while (left < right && arr[left] <= tmp)
//			left++;
//		arr[left] = arr[right];
//	}
//	arr[left] = tmp;
//	return left;
//}
//int MorethanHalfNum(int arr[], int n, int left, int right)
//{
//	int tmp = partition(arr, n, 0, n);
//	if (tmp == n / 2)
//	{
//		return arr[tmp];
//	}
//	if (tmp > n / 2)
//		tmp = partition(arr, n, left, tmp - 1);
//	else
//		tmp = partition(arr, n, tmp + 1, right);
//	return arr[tmp];
//}
//int MorethanHalfNum1(int arr[], int n, int left, int right)
//{										//因为此数超过数组大小的一半，则最后一次将
//	assert(arr != NULL);			     //times设为1的数即为要找的数
//	int tmp;
//	int times = 0;
//	tmp = arr[0];
//	times = 1;
//	int index;
//	for (int i = 1; i < n; i++)
//	{
//		if (tmp != arr[i])
//		{
//			times--;
//		}
//		if (times == 0)
//		{
//			tmp = arr[i];
//			times = 1;
//			index = i;
//		}
//		if (tmp == arr[i])
//			times++;
//	}
//	return arr[index];
//}
//int main()
//{
//	int arr[] = { 1, 2, 3, 2, 2, 2, 5, 4, 2 };
//	int n = sizeof(arr) / sizeof(int)-1;
//	system("pause");
//	return 0;
//}
bool isEqual(double num1, double num2)//two double numbers can not campare
{
	if (num1 - num2 > -0.0000001 && num1 - num2 < 0.0000001)
	{
		return true;
	}
	return false;
}
double My_pow(double base, int exp)//maybe exp<0 or base == 0
{								    //
	bool flag = false;      //different from return error and return because
	double result = 1.0;	//of base == 0
	if (isEqual(base, 0.0) && exp < 0)
	{
		flag = true;
		return 0;
	}
	int tmpExp = exp;
	if (exp < 0)
	{
		tmpExp = (-1)*exp;//
	}
	else if (exp == 0)
	{
		return 1;
	}
	for (int i = 0; i < tmpExp; i++)
	{
		result *= base;
	}
	if (exp < 0)
		result = 1 / result;
	return result;
}
int main()
{
	cout<<My_pow(0,0)<<endl;//base == 0,exp == 0 result == 1 flag == true
	cout<<My_pow(1,0)<<endl;//result == 1,flag == false
	cout<<My_pow(2,-3)<<endl;// result == 0.125
	return 0;
}

/*
struct T {
	char c1 : 1;
	char c2 : 3;
	unsigned short s2 : 13;
	unsigned long i : 3;

};
class A{
public:
	virtual void func(){
		cout << "A::func" << endl;
	}
	virtual void funcA(){
		cout << "A::funcA" << endl;
	}
private:
	int a;
};
class B{
public:
	virtual void func(){
		cout << "B::func" << endl;
	}
	virtual void funcB(){
		cout << "B::funcB" << endl;
	}
private:
	int b;
};
class C :public A, public B{
public:
	virtual void func(){
		cout << "C::func" << endl;
	}
	virtual void funcC(){
		cout << "C::funcC" << endl;
	}
private:
	int c;
};

void test()
{
	typedef void(*Fun)(void);
	C c;
	A a;
	B b;
	A *pa = &c;
	B *pb = &c;
	C *pc = &c;
	int** Vfptr = NULL;
	Vfptr = (int**)&c;
	Fun pfun = NULL;
	cout << "c::A::vfptr->" << endl;
	pfun = (Fun)Vfptr[0][0];
	cout << "[0]"; pfun();
	cout << (int*)pfun << endl;//
	pfun = (Fun)Vfptr[0][1];
	cout << "[0]"; pfun();
	cout << (int*)pfun << endl;//
	pfun = (Fun)Vfptr[0][2];
	cout << "[0]"; pfun();
	cout << (int*)pfun << endl;//

	int s = sizeof(A) / 4;
	pfun = (Fun)Vfptr[s][0];
	cout << "[1]"; pfun();
	cout << (int*)pfun << endl;
	pfun = (Fun)Vfptr[s][1];

	cout << "[1]"; pfun();
	cout << (int*)pfun << endl; //
	
	pa = reinterpret_cast<A *>(pb);
	Vfptr = (int**)&pa;
	pfun = (Fun)Vfptr[0][0];
	cout << (int*)pfun << endl;
	pfun = (Fun)Vfptr[0][1]; 
	cout << (int*)pfun << endl;
	pfun = (Fun)Vfptr[0][2]; 
	cout << (int*)pfun << endl;
	pa->func();
	pa->funcA();

	//pb = reinterpret_cast<B *>(pc);
	//pb->func();
	//pb->funcB();
	
}
int main()
{
	test();
	system("pause");
	return 0;
}
*/
/*
void shape(int a_i, int val, int* tmp, vector<string>& aa)
{	
	int tmp1 = 0;
	tmp1 = *tmp;
	if (a_i == int('1' - '0'))
		*tmp += val;
	if (a_i == int('2' - '0'))
		*tmp -= val;
	if (tmp1 > val && *tmp >= 3)
		aa.push_back("Yes");
	else
		aa.push_back("No");
}*/
