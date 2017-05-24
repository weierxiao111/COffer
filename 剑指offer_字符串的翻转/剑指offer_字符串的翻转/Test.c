#include <stdio.h>
#include <assert.h>

char* Strrev(char* start, char* end)
{
	char* ret = start;
	assert(start && end);
	while (start < end)
	{
		char temp = *start;
		*start = *end;
		*end = temp;
		start ++;
		end --;
	}
	return ret;
}

char* Wordrev(char* src)
{
	char* start;
	char* begin;
	assert(src);
	start = src;
	begin = src;
	while (*src)
	{
		while (*src && !isspace(*(++src)))  //���ո�ǰ�����ĸ��ת
			;
		Strrev(start, src-1);
		while (*src && isspace(*(++src))) //�����ո�����
			;
		start = src;
	}
	Strrev(begin, src-1);  //���ַ���ȫ����ת����
	return begin;
}

int main()
{
	char str[] = "happy  are  we";
	Wordrev(str);
	printf("%s",str);
	return 0;
}