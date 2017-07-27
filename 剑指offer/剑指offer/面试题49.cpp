#include <iostream>
using namespace std;

bool status = false;

//注：num 取long long  可以判断是否超过int范围
//最小的int 1000 0000 0000 0000 （原码 -0 避免与0重叠， 规定为最小的负数）
//最大的int 0111 1111 1111 1111
int strtoint(const char *str, int falg)
{
	long long num = 0; 
	while (*str)
	{
		if (*str <= '9' && *str >= '0')
		{
			num = num * 10 + falg * (*str - '0');
			if ((falg == -1 && num < (signed int)0x80000000)
				|| (falg == 1 && num > 0x7FFFFFFF))
			{
				num = 0;
				return (int)num;
			}
			str++;
		}
		else
		{
			num = 0;
			return (int)num;
		}
	}
	status = true;
	return (int)num;

}

int Atoi(const char* str)
{
	status = false;
	int flag = 1;
	if (str == NULL)
		return 0;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			flag = -1;
		str++;
	}
	return strtoint(str, flag);
}

//int main()
//{
//	int a = Atoi("2343849");
//	cout << a<<endl;
//	return  0;
//}