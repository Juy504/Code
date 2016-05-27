#include<iostream>
//#include<string.h>
#include"Tree.h"
using namespace std;

int main()
{
	char* str = "123##4##56###";
	BinTree<char> mytree;
//	char* VLR = "123456";
//	char* LVR = "324165";
//	int len = strlen(VLR);
	mytree.CreatTree(str);
	mytree.zigzagLevelOrder();
//	mytree.RecPreOrder();
//	mytree.RecInOrder();
//	mytree.RecPostOrder();
//	mytree.LevelOrder();
//	mytree.PreOrder();
//	mytree.InOrder();
//	mytree.PostOrder();
//	mytree._CreatTree(VLR, LVR,len);
	system("pause");
	return 0;
}
