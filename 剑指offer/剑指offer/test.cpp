#include <iostream>
using namespace std;
#include <stack>
#include <stdlib.h>

template <class T>
class SQueue {
public:
	void Push(const T& value);
	T Pop();
private:
	stack<T>  st1;
	stack<T>  st2;
};

template <class T>
T SQueue<T>::Pop()
{
	if (st2.size() <= 0)
	{
		if (st1.size() == 0)
		{
			exit(1);
		}
		while ((st1.size() > 0))
		{
			T& top = st1.top();
			st2.push(top);
			st1.pop();
		}
	}

	T head = st2.top();
	st2.pop();
	return head;

}

template <class T>
void SQueue<T>::Push(const T& value)
{
	st1.push(value);
}

int main()
{
	SQueue<int> sq;
	for (int i = 0; i < 10; ++i)
	{
		sq.Push(i);
	}
	for (int i = 0; i < 5; ++i)
	{
		cout << sq.Pop() << " ";
	}

	for (int i = 0; i < 5; ++i)
	{
		cout << sq.Pop() << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}
