#include <iostream>
using namespace std;

void Resver(char *start, char *end)  //注：最好用两个指标
{
	if (start == NULL || end == NULL)
		return ;
	while (start < end)
	{
		swap(*start, *end);
		start++;
		end--;
	}
}

char *ResverStr(char *str)
{
	if (str == NULL)
		return NULL;
	char *start = str;
	char *end = str;
	while (*end)
	{
		if (isspace(*end))
		{
			Resver(start, end - 1);
			start = end;
			while (*start && isspace(*start))
				++start;
			end = start;
		}
		else
			end++;
	}
    Resver(str, end - 1);
	return str;
}
//左旋n位  相当于旋转3次
char* LeftResverStr(char *str, int n)
{
	if (NULL == str)
		return NULL;
	if (n == 0)
		return str;
	int len = strlen(str);
	n %= len;
	char* start = str;
	char* end = str;
	while (--n > 0)
		end++;
	Resver(start, end);
	Resver(end + 1, start + len - 1);
	Resver(start, start + len - 1);
	return str;
}

//int main()
//{
//	char str[] = "abcdefgh";
//	cout<< LeftResverStr(str,-3)<<endl;
//	return 0;
//}