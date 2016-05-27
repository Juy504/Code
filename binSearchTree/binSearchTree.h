#pragma once
#include <string.h>
#include <iostream>
using namespace std;

template<class T>
struct Node
{
	T _data;
	Node<T>* left;
	Node<T>* right;
	Node(T val) :_data(val), left(NULL), right(NULL)
	{}
	~Node()
	{}
};
template<class T>
class BinSearchTree
{
public:
	BinSearchTree() :_root(0)
	{}
	void CreatTree(char* str)
	{
		int n = strlen(str);
		CreatTree_(_root,str,n);
	}
	void comFather(char a,char b)
	{
		return comFather_(_root,a,b);
	}

	bool isPost(int* arr,int len)//is or not we only need judge the rightree
	{
		int flag =0;
		int i=0;
		int tmp = arr[len-1]; //tmp is root node
		for(;i<len-1;i++)
		{
			if(arr[i] > tmp) //we get right subtree
				break;
		}
		int j = i;
		for(;j<len-1;j++)
		{
			if(arr[j] < tmp)  //error 
				return false;
		}
		bool left = true;
		if(i>0)
			left = isPost(arr,i);
		bool right = true;
		if(i<len-1)
			right = isPost(arr+i,len-i-1);
		return left&&right;
	}
protected:

	void comFather_(Node<T>* root,char a,char b)
	{
		if (root->_data > a && root->_data < b)
		{
			cout << root->_data << endl;
			return;
		}
		if (root->_data > a && root->_data > b)
			comFather_(root->left, a, b);
		if (root->_data < a && root->_data < b)
			comFather_(root->right, a, b);
	}
	void insertVal(Node<T>*& root, char ch)
	{
		if (root == NULL)
		{
			root = new Node<T>(ch);
			return;
		}
		if (ch < root->_data)
			insertVal(root->left, ch);
		if (ch > root->_data)
			insertVal(root->right, ch);
	}
	void CreatTree_(Node<T>*& root,char*& str,int n)
	{
		for (int i = 0; i < n;i++)
			insertVal(root, str[i]);
	}
private:
	Node<T>* _root;
};
