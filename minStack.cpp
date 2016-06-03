#include <iostream>
#include <stack>
using namespace std;
template<class T>
class Stack
{
public:
	void pop()
	{
		if(data_st.size() > 0 && min_st.size() > 0)
		{
			data_st.pop();	
			min_st.pop();
		}
	}
	void push(T _data)
	{
		data_st.push(_data);//push data stack
		if(min_st.size() == 0 || _data < min_st.top())
			min_st.push(_data);
		else
			min_st.push(min_st.top());//min_st.size() == data_st.size()
	}

	T Get_min()
	{
		if(data_st.size()>0 && min_st.size()>0)
			return min_st.top();
	}
private:
	stack<T> data_st;
	stack<T> min_st;
};
int main()
{
	Stack<int> st;
	st.push(3);
	st.push(4);
	st.push(2);
	st.push(1);
	st.push(5);
	st.push(0);
	cout<<st.Get_min()<<endl;
	st.pop();
	cout<<st.Get_min()<<endl;
	st.pop();
	cout<<st.Get_min()<<endl;
	st.pop();
	cout<<st.Get_min()<<endl;
	return 0;
}
