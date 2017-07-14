//ÖµÔËËã·ûº¯Êı
#include <string>
class mystring {
public:
	mystring(const char* str = "")
		:_str(new char[strlen(str)+1])
	{
		if (NULL == str)
		{
			_str = new char[1];
			_str[0] = '\0';
		}
		else
		{
			strcpy(_str, str);
		}		  
	}
	mystring(const mystring& string)
		:_str(new char[strlen(string._str)+1])
	{
		strcpy(_str, string._str);
	}

	mystring& operator= (const mystring& string)
	{
		if (this != &string)
		{
			delete[]_str;
			_str = new char[strlen(string._str) + 1];
			strcpy(_str, string._str);
		}
		return (*this);
	}
	/*
	mystring& operator= (const mystring& string)
	{
		if (this != &string)
		{
			mystring temp(string);
			swap(temp._str,_str);
		}
		return (*this);
	}
	*/

	~mystring()
	{
		if (_str != NULL)
		{
			delete[]_str;
		}
	}
private:
	char *_str;
};

//int main()
//{
//	mystring str1("str");
//	mystring str2(str1);
//	mystring str3;
//	str3 = str2;
//}