#include <iostream>
using namespace std;
#include <stack>

bool IsStacck(int *push, int *pop, int sz)
{
	if (push == NULL || pop == NULL || sz < 1)
		return false;
	stack<int> st;
	int *pushstart = push;
	int *popstart = pop;
	while (pop - popstart < sz )
	{
		while (st.empty() || st.top() != *pop)
		{
			if (push - pushstart == sz)
				break;
			st.push(*push);
			push++;
		}
		if (*pop == st.top())
		{
			st.pop();
			pop++;
		}
		else
			break;
	}
	if (pop - popstart == sz && st.empty())
		return true;
	else
		return false;
}

//int main()
//{
//	int push[] = { 1,2,3,4,5 };
//	int pop[] = {4,3,5,1,2};
//	cout << IsStacck(push, pop,5);
//	return 0;
//}