#ifndef __BINTREE_H__
#define __BINTREE_H__

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

char Stack[100];
int sum = 0;
int j = 0;
template<class T>
struct Node
{
	T _data;
	Node<T>* left;
	Node<T>* right;
	Node(T val)
		:_data(val),left(NULL),right(NULL)
	{}
	~Node()
	{}
};

template<class T>
class BinTree
{
public:
	BinTree()
		:_root(NULL)
	{}
	~BinTree()
	{}
public:
	void createTree(char* str)
	{
		createTree_(_root,str);	
	}
	void preOrder()
	{
		preOrder_(_root);
		cout<<endl;
	}
	void IsSontree(BinTree<T> tree)
	{
		cout<<isSontree_(_root,tree._root);
		cout<<endl;
	}
	void mirrorTree()
	{
		mirror(_root);
		preOrder_(_root);
	}

	void levelOrder()
	{
		levelOrder(_root);
	}

	void sumData(int data)
	{
		sumData_(_root,data);
	}
protected:
	void sumData_(Node<T>* root, int data)
	{
		if(root == NULL || data == 0)
			return;
		
		Stack[j++] = root->_data;  //data push array_Stack
		sum += root->_data-'0';   //sum and Stack are global vars;
		
		if(root->left == NULL && root->right == NULL && sum == data)
		{
			for(int i=0;i<j;i++)
				cout<<Stack[i]<<"->";
			cout<<"nul"<<endl;
			return;
		}
		if(root->left)
			sumData_(root->left,data);
		if(root->right)
			sumData_(root->right,data);
		sum -= root->_data-'0';
		j--;
	}

	void levelOrder(Node<T>* root)
	{
		if(root ==NULL)
			return;
		queue<Node<T>*> q; //use queue character FIFO
		q.push(root);

		while(!q.empty())
		{
			Node<T>* tmp = q.top();
			cout<<tmp->_data;

			q.pop();
			if(tmp->left)
				q.push(tmp->left);
			if(tmp->right)
				q.push(tmp->right);
		}
	}
	void mirror(Node<T>*& root)
	{
		if(root == NULL)
			return;
		if(root->left !=NULL || root->right !=NULL)
			swap(root->left,root->right);
		if(root->left !=NULL)
			mirror(root->left);
		if(root->right !=NULL)
			mirror(root->right);
	}
	bool isSontree1(Node<T>* rt1, Node<T>* rt2)
	{
		if(rt2 ==NULL)
			return true;
		if(rt1 == NULL) // rt2 != NULL  rt1 ==NULL
			return false;
		if(rt1->_data != rt2->_data) //tag of end
			return false;
		return isSontree1(rt1->left,rt2->left) 
			&& isSontree1(rt2->right,rt2->right);

	}
	bool isSontree_(Node<T>* rt1, Node<T>* rt2)
	{
		bool tag = false;  //global tag 
		if(rt1 !=NULL && rt2 !=NULL)
		{
			if(rt1->_data == rt2->_data)
			{
				tag = isSontree1(rt1,rt2);
			}
			if(!tag)
				tag = isSontree_(rt1->left,rt2);//tree2 node  can not move
			//	tag = isSontree_(rt1->left,rt2->left);
			if(!tag)
				tag = isSontree_(rt2->right,rt2);
			//	tag = isSontree_(rt2->right,rt2->right);
		}
		return tag;
	}
	void preOrder_(Node<T>* root)
	{
		if(root == NULL)
			return;
		cout<<root->_data;
		preOrder_(root->left);
		preOrder_(root->right);
	}
	void createTree_(Node<T>*&root, char*&str)
	{
		if(*str == '#')
			return;
		else
		{
			root = new Node<T>(*str);
			createTree_(root->left,++str);
			createTree_(root->right,++str);
		}
	}
private:
	Node<T>* _root;
};
#endif
