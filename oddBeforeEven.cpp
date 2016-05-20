#include <iostream>
#include <assert.h>

//void oddBeforeEven(int* arr, int n)
//{						// two pointers point the leftArray and righAarray
//	assert(arr !=NULL);
//	int left = 0;
//	int right = n-1;
//	while(left < right)
//	{
//		if(arr[left]%2 != 0 && arr[right]%2 !=0)
//		{
//			left++;
//		}else if(arr[left] %2 == 0 && arr[right]%2 ==0){
//			right--;
//		}else if(arr[left]%2 != 0 && arr[right]%2 == 0)
//		{
//			left++;
//			right--;
//		}
//		else
//		{
//			std::swap(arr[left],arr[right]);
//		}
//	}
//	int *left = arr;
//	int *right = arr+n-1;
//	while(left < right)
//	{
//		while(left < right && (*left & 0x1) !=0)//*left is odd
//			left++;
//		while(left < right && (*right & 0x1) == 0)//*right is even
//			right--;
//		std::swap(*left,*right);
//	}
//}

bool Isbool(n)
{
	return (n & 0x1) == 0;
}
void Order(int arr, int n, bool (*func)(int))
{
	int *left = arr;
	int *right = arr+n-1;
	while(left < right)
	{
		while(left < right && Isbool(*left))//*left is odd
			left++;
		while(left < right && Isbool(*right))//*right is even
			right--;
		std::swap(*left,*right);
	}
}
void oddBeforeEven(int* arr, int n)
{
	Order(arr,n,)
}
int main()
{
	int arr[] = {1,2,3,4,5,6,7};
	int len  = sizeof(arr)/sizeof(int);
	oddBeforeEven(arr,len);
	for(int i=0; i<len; i++)
	{
		std::cout<<arr[i]<<" ";
	}
	std::cout<<std::endl;
	return 0;
}
