/*
 *find min in rotate array
 *
 */

#include <iostream>
using namespace std;
int MinResult(int *arr,int left,int right)
{
	int res = arr[left];
	int i = 0;
	for(i = left;i<right;i++)
	{
		if(result > arr[i])
			result = arr[i];
	}
	return res;
}
int Min(int *arr, int n)
{
	if(arr ==NULL || n<=0)
		return -1;
	int left = 0;
	int right = n;
	int mid = 0;
	while(right - left > 1)
	{
		mid = (left+right)/2;
		if(arr[left] < arr[right])
			return arr[left];
		if(arr[left] == arr[right] && arr[left] == arr[mid])
			return MinResult(arr,left,right);
		if(arr[left] <= arr[mid])
		{
			left = mid;
			continue;
		}
		if(arr[left] >= arr[mid])
		{
			last = mid;
			continue;
		}
	}
	return arr[right];
}
int main()
{
	int i=0;
	int arr[100];
	while(i<5)
	{
		cin>>arr[i];
	}
	int Min(arr,i-1);
	return 0;
}
