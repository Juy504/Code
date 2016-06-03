#include <iostream>
#include <stack>
using namespace std;

bool isPopOrder(const int* push,const int* pop,int len)
{
	bool IsOrder = false;
	if(push == NULL || pop == NULL || len<0)
		return false;
	else
	{
		const int* npop = pop;
		const int* npush = push;
		stack<int> st;
		while(npop - pop < len)
		{
			while(st.empty() || st.top() != *npop)
			{
				if(npush - push == len)
					break;
				st.push(*npush);
				npush++;
			}
			if(st.top() != *npop)  //the order is wrong
				break;
			st.pop();
			npop++;
		}
		if(st.empty() && npop-pop == len)
			IsOrder = true;
	}
	return IsOrder;
}
int main()
{
	const int push[] = {1,2,3,4,5};
	const int pop[] = {4,3,5,1,2};
	const int _pop[] = {4,5,3,2,1};
	int len = sizeof(_pop)/sizeof(int);
	cout<<isPopOrder(push,_pop,len)<<endl;
	return 0;
}
