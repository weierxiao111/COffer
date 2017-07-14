//Ìæ»»¿Õ¸ñ
#include <string>
void  ReplaceBlank(char *str, int len)
{
	if (NULL == str || len < 1)
		return;
	char *start = str;
	int blanknum = 0;
	while (*start != '\0')
	{
		if (isspace(*start++))
			blanknum++;
	}
	int oldend = len-1;
	int newend = oldend + 2 * blanknum;

	str[newend+1] = '\0';
	while (oldend >= 0)
	{
		if (isspace(str[oldend]))
		{
			str[newend ] = '0';
			str[newend - 1] = '2';
			str[newend - 2] = '%';
			newend -= 3;
		}
		else
		{
			str[newend] = str[oldend];
			newend--;
		}
		oldend--;
	}
}

//int main()
//{
//	char str[20] = "ni hao a";
//	ReplaceBlank(str, strlen(str));
//	return 0;
//}