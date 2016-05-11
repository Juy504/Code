#include <iostream>
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
	while(item != -1 && cin>>item)
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
	while(node->next)
	{
		st.push(node);
	}
	while(!st.empty())
	{
		node = st.top();
		cout<<node->_data<<" ";
		st.pop();
	}
}
int main()
{
	list l = NULL;
	CreatList(&l);
	printList(l);
}
