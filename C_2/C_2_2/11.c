#include <stdio.h>
int main11()
{
	/*����5��ѧ�����䣬���������*/ 
	int hs[5];
	int i;
	for(i=0;i<5;i++)
	{
		scanf("%d",&hs[i]);
	}

	for(i=5-1;i>=0;i--)
	{
		printf("%d ,",hs[i]);
	}
	return 0;
}