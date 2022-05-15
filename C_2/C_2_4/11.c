#include <stdio.h>
int main11 ()
{
	/* Ñî»ÔÈı½Ç
		1
		11
		121
		1331
		14641
	*/
	int a[10][10]={{1},{1,1}};
	for (int h=2;h<10 ;h++ )
	{
		a[h][0] = a[h][h] = 1;
		for (int l=1;l<h;l++)
		{
			a[h][l] = a[h - 1][l] + a[h - 1][l - 1];
		}
	}
	for (int h = 0; h < 10; h++)
	{
		for (int k = 0; k <=h; k++)
		{
			printf("%-d ",a[h][k]);
		}
		printf("\n");
	}

	 

	return 0;
}