#include <stdio.h>




int One(int n)
{
	int count = 0;

	while (n)
	{
		++ count;
		n = (n - 1)&n;
	}

	return count;
}
    

int main()
{
	int ret = One(-1);
	printf("%d\n",ret);
	return 0;
}


/*  1101 0011   1101 0010
    1101 0010   1101 0001
	1101 0000   1100 0001
	1100 0000   1000 0001
	1000 0000   0000 0001
	0000 0000
	*/