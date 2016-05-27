#include <iostream>
#include "binSearchTree.h"
using namespace std;

int main()
{
	char* str = "132056";
	int arr[] = {5,12,6,9,11,10,8};
	int len = sizeof(arr)/sizeof(int);
	BinSearchTree<char> mytree;
	mytree.CreatTree(str);
	mytree.comFather('2', '5');

	cout<<mytree.isPost(arr,len)<<endl;
	return 0;
}
