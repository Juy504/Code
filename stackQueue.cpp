
#pragma once
#include<stack>
#include<queue>
#include<iostream>
using namespace std;
template<class T>
class Stack//��������ʵ��һ��ջ��
{
private:
	queue<T> q1;
	queue<T> q2;     //q2����Ϊһ����תվ ʵ��ջ�ĳ�ջ��ջ����q1��ʵ��
public:
	Stack()
	{}
	void Push(const T& item)
	{
		q1.push(item);
	}

	void Pop()
	{
		if (!q2.empty())
			q2.pop();
		else
		{
			while (q1.front() != q1.back())
			{
				q2.push(q1.front());
				q1.pop();
			}
			q1.pop();
			while (!q2.empty())
			{
				q1.push(q2.front());
				q2.pop();
			}
		}
	}
};
/*
template<class T>
class Queue
{
private:
	stack<T> st1;
	stack<T> st2;        //st1ʵ�����   st2ʵ�ֳ���
	queue<T> q;
public:
	Queue()
	{}
	void Push(const T& item)    
	{
		st1.push(item);
	}
	void Pop()
	{
		if (!st2.empty())
			st2.pop();
		else
		{
			while (!st1.empty())
			{
				st2.push(st1.top());
				st1.pop();
			}
			st2.pop();
		}
	}
};*/
/*
template<class T>    //ʵ��һ��ջ  push() pop() min()��ʱ�临�Ӷ�Ϊ1��
class Stack
{
private:
	stack<T> _stack;
	stack<T> _minStack;
public:
	Stack()
	{}
	~Stack()
	{}
	void Push(const T& item)
	{
		_stack.push(item);
		if (_minStack.empty())
			_minStack.push(item);
		else
			_minStack.push(_minStack.top() > item ? item : _minStack.top());
	}
	void Pop()
	{
		_stack.pop();
		_minStack.pop();
	}
	T Min()
	{
		cout << _minStack.top() << endl;
		return _minStack.top();
	}
};
*/
/*
template<class T>
class Stack
{
private:
	int maxsize;
	int top;
	T* element;
public:
	Stack(int s)
		:maxsize(s), top(-1) 
	{
		element = new T[maxsize];
		assert(element != NULL);
	}
	~Stack()
	{}
	bool IsFull()
	{
		return top == maxsize - 1;
	}
	bool IsEmpty()
	{
		return top == -1;
	}
	void Push(const T& item)
	{
		if (IsFull())
			return;
		top++;
		element[top] = item;
	}
	T Pop()
	{
		if (IsEmpty())
			return;
		return element[top--];
	}
	T top()
	{
		if (IsEmpty())
			return;
		return element[top];
	}
	};*/
