#include <stdio.h>

int Findkey(int arr[][5], const int wight, const int hight, int key)
{
	int i=0;
	int j=hight;
	while (i<=wight || j<=0)
	{
		if (arr[i][j] == key)
		    return 1;
		else if (arr[i][j] < key)
		{
			i++;
		}
		else 
		{
     		j--;
		}
	}
	return 0;

}

int main()
{
	int arr[5][5] ={ {1,3,4,5,7},
	                 {2,4,6,9,10},
	                 {4,6,7,10,13}
	};
	int wight = sizeof(arr[0])/sizeof(arr[0][0])-1;
	int hight = sizeof(arr)/sizeof(arr[0])-1;
	if (Findkey(arr,wight,hight,8))
	{
		printf("have key\n");
	}
	else 
	{
		printf("don't have key\n");
	}
	return 0;
}