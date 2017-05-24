#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

void PrintMaxN(char* num)
{
	int flag = 1;
	int len = strlen(num);
	for (int i = 0;i<len;i++)
	{
		if (!(num[i] - '0') && flag) 
		     continue ;
		else 
		{
            printf("%c",num[i]);
			flag = 0;
		}

	}
	printf("\t");	
}

bool increase(char* num)
{
	int conver=0;
	int len = strlen(num);
	num[i] += 1;
	for (int i = len -1;;i>=0;i--)
	{
		conver = num[i] - '0';
		if (conver >= 10)
		{
			if (i == 0)
				return false;
			num[i] = '0';
			num[i-1] += 1;
		}
		else 
			return true;
	}

}
void OneToMaxN(int n)
{
	if (n<=0)
        return;
	char* num = new char[n+1];
	memset(num,'0',n);
	num[n] = '\0';

	while (increase(num))
	{
		PrintMaxN(num);
	}

	delete []num;
}


int main()
{
	OneToMaxN(111);
	return 0 ;
}