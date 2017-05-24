#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

char* replaceSpace(const char* str)
{
	int count = 0;
	int len = 0;
	char* oldstr = str;
	char* newstr = NULL;
     assert(str);
	 while (*oldstr++)
	 {
		 if (isspace(*oldstr))
			 count++;
	 }
	 len = strlen (str);
	 newstr = (char* )malloc((len+2*count)*sizeof(char));
	 if (NULL == newstr)
	 {
		 return;
	 }
	 while (oldstr != str)
	 {
		 if (isspace(*oldstr))
		 {
			 *newstr-- = '0';
			 *newstr-- = '2';
			 *newstr-- = '%';
             *oldstr -- ;
		 }
		 else 
		 {
			 *newstr-- = *oldstr--;
		 }
	 }
	 *newstr = *oldstr;
	 return newstr;

}
int main()
{
	char* _str ="we are happy";
	
	printf("%s\n",replaceSpace(_str));

	return 0;
}