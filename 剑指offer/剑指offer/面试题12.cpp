#include <iostream>
using namespace std;

bool MaxN(char *num, int n)
{
	bool flag = true;
	int i = n - 1;
	for (; i >= 0; --i)
	{
	    int temp = num[i]- '0'+1;
		if (temp == 10)
		{
			num[i] = '0';
		}
		else
		{
			flag = false;
			num[i] = temp + '0';
			break;
		}
	}
	
	return (i == -1 && flag);
}

void PrintNum(char *num)
{
	if (NULL == num)
		return;
	while ( *num == '0')
		num++;
	cout << num << " ";
}

void PrintMaxN_Nor(int n)
{
	if (n <= 0)
		return;
	char *num = new char[n + 1];
	memset(num,'0', (n + 1)*sizeof(char));
	num[n] = '\0';
	while (!MaxN(num,n))
	{
		PrintNum(num);
	}
	delete []num;
}


void _PrintMaxN(char *num, int n, int index)
{
	if (NULL == num)
		return;
	if ( index == n )
	{
		PrintNum(num);
	}
	else
	{
		for (int i = 0; i <= 9; ++i)
		{
			num[index] = i + '0';
			_PrintMaxN(num, n, index + 1);
		}
	}
}

void PrintMaxN(int n)
{
	if (n <= 0)
		return;
	char *num = new char[n+1];
	num[n] = '\0';
	_PrintMaxN(num, n, 0);

	delete []num;
}

//int main()
//{
//	PrintMaxN(2);
//	return 0;
//}