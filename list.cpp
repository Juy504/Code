#include <iostream>
#include <assert.h>
#include <stack>
using namespace std;

struct Node
{
	int _data;
	Node* next;
};
typedef Node* list;
void CreatList(list* Head)
{
	int item = 0;
	Node* p = NULL;
	cout<<"-1 to end"<<endl;
	while(cin>>item && item != -1)
	{
		if(!(*Head))
		{
			*Head = new Node;
			(*Head)->_data = item;
			(*Head)->next = NULL;
			p = *Head;
		}
		else
		{
			Node* s = new Node;
			s->_data = item;
			s->next = NULL;

			p->next = s;
			p = s;
		}
	}
}

Node* reverse(list* head)
{
	assert(head != NULL);
	Node* cur = *head;
	Node* newHead = NULL;
	Node* tmp = NULL;
	while(cur)
	{
		tmp = cur;
		cur = cur->next;
		
		tmp->next = newHead;
		newHead = tmp;
	}
	return newHead;
}

void printList(list head)//Rec
{
	if(head != NULL)
	{
		if(head->next != NULL)
		{
			printList(head->next);
		}
		cout<<head->_data<<" ";
	}
}
void printList1(list head)
{
	stack<Node*> st;
	Node* node = head;
	while(node)
	{
		st.push(node);
		node = node->next;
	}
	while(!st.empty())
	{
		node = st.top();
		cout<<node->_data<<" ";
		st.pop();
	}
	cout<<endl;
}
Node*  deleteNode(list* head,list curDelete)//delete in O(1)
{
	assert(*head != NULL && curDelete !=NULL);
	if(curDelete->next !=NULL)//not in list tail
	{
		Node* tmpNode = curDelete->next;
		curDelete->_data = tmpNode->_data;
		curDelete->next = tmpNode->next;

		delete tmpNode;
		tmpNode = NULL;
	}else if(*head == curDelete)//has a node
	{
		delete curDelete;
		curDelete = NULL;
		*head = NULL;
	}
	else
	{
		Node* tmpNode = *head;
		while(tmpNode->next != curDelete)
			tmpNode = tmpNode->next;

		tmpNode->next = NULL;
		delete curDelete;
		curDelete = NULL;
	}
	return *head;
}

Node* deleteNode_find(list* head,int key)//find the key in O(n)
{
	assert(head !=NULL);
	Node* cur = *head;
	Node* newHead = NULL;
	while(cur)
	{
		if(cur->_data == key)
		{
			newHead = deleteNode(head,cur);
			return newHead;
		}
		cur = cur->next;
	}
	return false;
}
//int main()
//{
//	list l = NULL;
//	CreatList(&l);
//	printList(l);
//	cout<<endl;
//	l = reverse(&l);
//	deleteNode_find(&l,3);
//	printList(l);
//	cout<<endl;
//	deleteNode_find(&l,0);
//	printList(l);
//	cout<<endl;
//	deleteNode_find(&l,4);
//	printList(l);
//	cout<<endl;
//	return 0;
//}

Node* printReverse_K(list head,unsigned int k)
{
	if(head == NULL || k == 0)
		return NULL;
	Node* nextK = head;
	Node* cur = head;
	int i=0;
	while(i<k-1)
	{
		if(nextK->next)//when k > total node counts
			nextK = nextK->next;
		else
			return NULL;
		i++;
	}
	while(nextK->next)
	{
		nextK = nextK->next;
		cur = cur->next;
	}
	return cur;
}
int main()
{
	list l = NULL;
	CreatList(&l);
	printList(l);
	cout<<endl;
	l = printReverse_K(l,2);
	cout<<l->_data<<endl;
	return 0;
}
