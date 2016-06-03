#include <iostream>
using namespace std;

void cirArr(int(*arr)[4], int row,int col)//row 1 col 4
{
	if(arr == NULL || row<0 || col<0)
		return;
	int begin = 0;
	for(;row>begin*2&&col>begin*2;begin++)//attention to border
	{
		int rowNew = begin;
		int colNew = begin;
		for(;colNew < col-begin;colNew++)//print left to right
		{
			cout<<arr[rowNew][colNew]<<" ";
		}
		colNew = colNew-1;//3
		rowNew = rowNew+1;//1
		for(;rowNew < row-begin;rowNew++)//print top to bottom
		{
			cout<<arr[rowNew][colNew]<<" ";
		}//rowNew == 3 colNew == 3
		rowNew = rowNew-1;//3
		colNew = colNew-1;//2
		
		for(;colNew >= begin;colNew--)//print right to left
		{
			cout<<arr[rowNew][colNew]<<" ";
		}
		rowNew = rowNew-1;//2
		colNew = colNew+1;//0
		for(;rowNew > begin;rowNew--)//print bottom to top
		{
			cout<<arr[rowNew][colNew]<<" ";
		}
	}
	cout<<endl;
}
void cirArr1(int(*arr)[4], int row,int col)//row 1 col 4
{
	if(arr == NULL || row<0 || col<0)
		return;
	int begin = 0;
	for(;row>begin*2&&col>begin*2;begin++)//attention to border
	{
		int rowNew = begin;
		int colNew = begin;
		for(;colNew < col-begin;colNew++)//print left to right
		{
			cout<<arr[rowNew][colNew]<<" ";
		}
		cout<<endl;
		colNew = colNew-1;//0
		rowNew = rowNew+1;//1
		if(begin < rowNew)
		{
			for(;rowNew < row-begin;rowNew++)//print top to bottom
			{
				cout<<arr[rowNew][colNew]<<" ";
			}//rowNew == 3 colNew == 3
		}
		rowNew = rowNew-1;//0
		colNew = colNew-1;//2
		if(begin < rowNew && begin < colNew)
		{
			for(;colNew >= begin;colNew--)//print right to left
			{
				cout<<arr[rowNew][colNew]<<" ";
			}
		}
		rowNew = rowNew-1;//2
		colNew = colNew+1;//0
		if(begin < colNew && begin < rowNew-1)
		{
			for(;rowNew > begin;rowNew--)//print bottom to top
			{
				cout<<arr[rowNew][colNew]<<" ";
			}
		}
	}
	cout<<endl;
}

int main()
{
//	int arr[][4] = {1,2,3,4,
//				   5,6,7,8,
//	               9,10,11,12,
//				   13,14,15,16};
	int arr[][4] = {1,2,3,4};
	int row = sizeof(arr[0])/sizeof(int);
	int col = sizeof(arr)/sizeof(arr[0]);
	cout<<row<<endl;
	cout<<col<<endl;
	cirArr1(arr,row,col);
	return 0;
}
