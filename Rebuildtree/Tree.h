#pragma once
#include<queue>
#include <vector>
#include<stack>
#include <stdio.h>
#include <iostream>
using namespace std;
template<class T>
struct Node
{
	T data;
	Node* left;
	Node* right;
	Node(T value)
		:data(value), left(NULL), right(NULL)
	{}
	~Node()
	{}
};
template<class T>
class BinTree
{
public:
	BinTree()
		:root(NULL)
	{}
	~BinTree()
	{}
	void CreatTree(char* str)
	{
		CreatTree_(root,str);
	}
	void _CreatTree(char* VLR, char* LVR,int Len)
	{
		_CreatTree_(root, VLR, LVR,Len);
		cout << endl;
	}
	void RecPreOrder()
	{
		RecPreOrder_(root);
		cout << endl;
	}
	void RecInOrder()
	{
		RecInOrder_(root);
		cout << endl;
	}
	void RecPostOrder()
	{
		RecPostOrder_(root);
		cout << endl;
	}
	void zigzagLevelOrder()
	{
		zigzagLevelOrder_(root);
		cout << endl;
	}
	void LevelOrder()
	{
		LevelOrder_(root);
		cout << endl;
	}
	void PreOrder()
	{
		PreOrder_(root);
		cout << endl;
	}
	void InOrder()
	{
		InOrder_(root);
		cout << endl;
	}
	void PostOrder()
	{
		PostOrder_(root);
		cout << endl;
	}
protected:
	void PostOrder_(Node<T>* rt)
	{
		stack<Node<T>* > st;
		if (rt != NULL)
		{
			Node<T>* cur = rt;
			Node<T>* visited = NULL;
			while (!st.empty() || cur != NULL)
			{
				while (cur)
				{
					st.push(cur);
					cur = cur->left;
				}
				cur = st.top();
				if (cur->right == NULL || cur->right == visited)
				{
					st.pop();
					cout << cur->data << " ";
					visited = cur;
					cur = NULL;
				}
				else
					cur = cur->right;
			}
		}
	}
	void InOrder_(Node<T>* rt)
	{
		stack<Node<T>* > st;
		if (rt != NULL)
		{
			Node<T>* cur = rt;
			while (!st.empty() || cur !=NULL)
			{
				while (cur)
				{
					st.push(cur);
					cur = cur->left;
				}
				cur = st.top();
				st.pop();

				cout << cur->data << " ";

				cur = cur->right;
			}
			
		}
	}
	void PreOrder_(Node<T>* rt)
	{
		stack<Node<T>* > st;
		if (rt != NULL)
		{
			st.push(rt);
			while (!st.empty())
			{
				Node<T>* t = st.top();
				st.pop();
				cout << t->data << " ";
				if (t->right)
					st.push(t->right);
				if (t->left)
					st.push(t->left);
			}
		}
	}
	vector<vector<int>> zigzagLevelOrder_(Node<T>* rt)//¶þ²æÊ÷µÄÐý×ª
	{
		queue<Node<T>*> q;
		q.push(rt);
		q.push(nullptr);
		vector<vector<int>> result;
		vector<int> level;
		bool left_to_right = true;
		while (!q.empty())
		{
			Node<T>* cur = q.front();
			q.pop();
			if (cur)
			{
				level.push_back(cur->data);
				if (cur->left)q.push(cur->left);
				if (cur->right)q.push(cur->right);
			}
			else
			{
				if (left_to_right)
					result.push_back(level);
				else
				{
					reverse(level.begin(), level.end());
					result.push_back(level);
				}
				level.clear();
				left_to_right = !left_to_right;
				if (q.size() > 0)q.push(nullptr);
			}
		}
		return result;
	}
	void LevelOrder_(Node<T>* rt)
	{
		queue<Node<T>* > q;
		if (rt != NULL)
		{
			q.push(rt);
			while (!q.empty())
			{
				Node<T> *t = q.front();
				q.pop();
				cout << t->data << " ";
				if (t->left)
					q.push(t->left);
				if (t->right)
					q.push(t->right);
			}
		}
	}
	void RecPostOrder_(Node<T>* rt)
	{
		if (rt == NULL)
			return;
		if (rt->left)
			RecPostOrder_(rt->left);
		if (rt->right)
			RecPostOrder_(rt->right);
		cout << rt->data << " ";
	}
	void RecInOrder_(Node<T>* rt)
	{
		if (rt == NULL)
			return;
		if (rt->left)
			RecInOrder_(rt->left);
		cout << rt->data << " ";
		if (rt->right)
			RecInOrder_(rt->right);
	}
	void RecPreOrder_(Node<T>* rt)
	{
		if (rt == NULL)
			return;
		cout << rt->data << " ";
		if (rt->left)
			RecPreOrder_(rt->left);
		if (rt->right)
			RecPreOrder_(rt->right);
	}
	void _CreatTree_(Node<T>* &rt, char* VLR, char* LVR,int Len)
	{
		int k = 0; 
		if (Len != 0)
		{
			while (*VLR != LVR[k])
			{
				k++;
			}
			rt = new Node<T>(*VLR);
			_CreatTree_(rt->left, VLR+1, LVR, k);
			_CreatTree_(rt->right, VLR + k + 1, LVR + k + 1, Len-k-1);
		}
		//return rt;
	}
	void CreatTree_(Node<T>* &rt, char*& str)
	{
		if (*str == '#')
			return;
		rt = new Node<T>(*str);
		CreatTree_(rt->left,++str);
		CreatTree_(rt->right,++str);
	}

private:
	Node<T> *root;
};
