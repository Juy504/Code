#include <iostream>
using namespace std;

int partition(int* arr,int len,int left,int right)
{
	int tmp = arr[left];
	while(left < right)
	{
		while(left < right && arr[right] >= tmp)
			right--;
		arr[left] = arr[right];
		while(left < right && arr[left] <= tmp)
			left++;
		arr[right] = arr[left];
	}
	arr[left] = tmp;
	return left;
}
bool input = true;
bool judgeMoreThanHalf(int* arr, int len,int res)
{
	int times = 0;
	for(int i=0;i<len-1;i++)
	{
		if(arr[i] == res)
			times++;
	}
	bool isMoreHalf = false;
	if(times > (len>>2))
	{
		input = true;
		isMoreHalf = true;
	}
	return isMoreHalf;
}

int MoreHalf1(int* arr, int len) //record times of every number
{
	if(arr == NULL || len < 0)
	{
		input = false;
		return 0;
	}
	int times = 0;
	int res = arr[0];
	for(int i=1;i<len;i++)
	{
		if(arr[i] == res)
		{
			times+=1;
		}else if(times == 0)
		{
			res = arr[i];
			times = 1;
		}else
		{
			times--;
		}
	}
	if(!judgeMoreThanHalf(arr,len,res))
		res = 0;
	return res;
}

int MoreHalf1(int* arr, int len)
{
	if(arr == NULL || len <= 0)
	{
		input = false;
		return 0;
	}
	int mid = len>>1;
	int left = 0;
	int right = len-1;
	int index = partition(arr,len,left,right);
	while(index != mid)
	{
		if(index < mid)
		{
			left = index +1;
			index = partition(arr,len,left,right);
		}else
		{
			right = index -1;
			index = partition(arr,len,left,right);
		}
	}
	int res = arr[mid]; //judge res with request
	if(!judgeMoreThanHalf(arr,len,res))
		res = 0;
	return res;
}

int main()
{
	int arr[] = {1,2,3,2,2,2,5,4,2};
	int len = sizeof(arr)/sizeof(int);
	cout<<MoreHalf1(arr,len)<<endl;
	return 0;
}
