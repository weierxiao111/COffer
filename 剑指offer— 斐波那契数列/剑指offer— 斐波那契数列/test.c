#include <stdio.h>
#include <time.h>

int fbonaqie_1(int k)
{
	int lasttwo = 0;
	int lastone = 1;
	int now = 0;
	if (k<=0)
		return 0;
	if (k == 1)
		return 1;
	else 
	{
		while ( k-->1)
		{
		now = lastone + lasttwo;
		lasttwo = lastone;
		lastone = now;
		}
		return now;
	}
}

int fbonaqie_2(int k)
{

	if (k<=0)
		return 0;
	if (k==1)
		return 1;
	else 
		return fbonaqie_2(k-1) +fbonaqie_2(k-2);

}

int main()
{
	int ret1 = 0;
	int ret2 = 0;
	clock_t start1,end1,start2,end2;
	start1 = clock();
	ret1 = fbonaqie_1(35);
	end1 =clock();
	start2 = clock();
	ret2 = fbonaqie_2(50);
	end2 =clock();
	printf("%d   fbonaqie_1() use time is %f\n",ret1,difftime(end1,start1));
	printf("%d   fbonaqie_2() use time is %f\n",ret2,difftime(end2,start2));
	return 0;
}