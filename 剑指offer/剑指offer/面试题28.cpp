#include <iostream>
using namespace std;

void _AllOrder(char *str, int index ,int len)
{
	if (index == len-1)
		cout <<str<<endl;
	else
	{
		for (int i = index; i < len; ++i)
		{
			swap(str[index],str[i] );
			_AllOrder(str, index + 1,len);
			swap(str[index], str[i]);
		}
	}

}

void AllOrder(char *str)
{
	if (NULL == str)
		return;
	int len = strlen(str);
	_AllOrder(str, 0,len);
}

//int main()
//{
//	char str[] = "ABCD";
//	AllOrder(str);
//	return 0;
//}