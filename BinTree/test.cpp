#include <iostream>
#include "BinTree.h"

using namespace std;
int main()
{
	char* str = "123##4##5#6###";
	char* str1 = "23##5###";
	char* str2 = "472##5##8##";
	BinTree<char> mytree;
	BinTree<char> rtree;
	mytree.createTree(str2);
//	rtree.createTree(str1);
	
//	mytree.mirrorTree();
	mytree.preOrder();
	mytree.sumData(12);
	return 0;
}
