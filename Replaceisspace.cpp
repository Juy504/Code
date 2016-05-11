/*
 *1.search a key in two-dimension array
 *2.merge two sort array
 *3.replace isspace use a string
 */


#include<iostream>
#include<string.h>
#include<assert.h>
using namespace std;

int* Merge(int arr1[], int arr2[],int len1,int len2)
{
	assert(arr1 != NULL&&arr2 != NULL);
	
//	arr1 += len1-1; arr2 += len2-1;
	int len3 = len1 + len2;
	while (len1 > 0)
	{
		if (arr2[len2-1] > arr1[len1-1])
		{
			arr1[len3-1] = arr2[len2-1];
			len2--;
		}
		else
		{
			arr1[len3-1] = arr1[len1-1];
			len1--;
		}
		len3--;
	}
	while (len1 == 0 && len2 != 0)
	{
		arr1[len3--] = arr2[len2--];
	}
	return arr1;
}
int main()
{
	int arr1[] = { 1, 3, 5, 7 };
	int arr2[4] = { 2, 4, 6, 8 };
	int len1 = sizeof(arr1) / sizeof(int);
	int len2 = sizeof(arr2) / sizeof(int);
	Merge(arr1, arr2,len1,len2);
	return 0;
}
/*void Replace(char* str1, char* str2)
{
	assert(str1 != NULL &&str2 != NULL);
	int i = 0;
	int OriLength = 0;
	
	int count = 0;
	while (str1[i] != '\0')
	{
		if (str1[i] == ' ')
			count++;
		OriLength++;
		i++;
	}
	int NewLength = OriLength+count*2;
	while (OriLength>=0 && NewLength>OriLength)
	{
		if (str1[OriLength] == ' ') //we are very happy
		{							//we are very happhappy
			str1[NewLength--] = '0';
			str1[NewLength--] = '2';
			str1[NewLength--] = '%';
		}
		else
		{
			str1[NewLength--] = str1[OriLength];
		}
		OriLength--;
	}
}
int main()
{
	char str1[] = "we ";
	char *str2 = "%20";
	Replace(str1, str2);
	system("pause");
	return 0;
}*/
/*int main()
{
	char str1[] = "hello world";
	char str2[] = "hello world";

	char *str3 = "hello world";
	char *str4 = "hello world";
	if (str1 == str2)
		printf("str1 and str2 are same\n");
	else
		printf("str1 and str2 are not same\n"); //
	if (str3 == str4)
		printf("str3 == str4\n");
	else
		printf("str3 != str4\n"); //
	return 0;
}*/
/*bool Search(int (*arr)[4],int row,int column,int x)
{
	int i = 0;
	int j = column-1;
	for (; i<row; ++i)
	{
		for (; j >= 0; --j)
		{
			if (arr[i][j] < x)
				break;
			else if (arr[i][j] == x)
				return true;
		}
	}
	return false;
}
int main()
{
	int arr[4][4] = { { 1, 2, 8, 9 },
					  { 2, 4, 9, 12 },
					  { 4, 7, 10, 13 },
					  { 6, 8, 11, 15 }
				    };
	int ret = Search(arr,4,4,5);
	cout << ret << endl;
	system("pause");
	return 0;
}
*/
