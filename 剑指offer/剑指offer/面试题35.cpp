#include <iostream>
using namespace std;

char FindOnlyOne(const char *str)
{
	if (NULL == str)
		return '\0';
	const char *start = str;
	const int SIZE = 256;
	int *hashTable = new int[SIZE];
	memset(hashTable, 0, 256 * sizeof(int));
	while (*start)
	{
		hashTable[*start]++;
		++start;
	}
	char  c = '\0';
	while (*str)
	{
		if (hashTable[*str] == 1)
		{ 
		    c = *str;
			break;
		}
		str++;
	}

	delete[]hashTable;
	return c;
}

//int main()
//{
//	cout<<FindOnlyOne("aafaaaregrgrwgvavwwhtehavaegeg");
//	return 0;
//}