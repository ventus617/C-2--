
#include<stdio.h>
#include<stdlib.h>
int main17 ()
{
	int ds[20],ns[20]  ;
	int i,j;
	int len=sizeof(ds)/sizeof(ds[0]);
	
	for(i=0;i<len;i++)
	{
		ds[i]=rand()%100;
		ds[i] = ds[i]*(ds[i]%3==0 ? -1 :1);
		printf("%d,",ds[i]);
	}
	printf("\n");
	/*��������ɵ������Ա��С��������ַŵ�һ��������ns��*/

	j = 0;
	for (i = 0; i < len; i++)
	{
		if (ds[i] < 0)
		{

			ns[j] = ds[i];
			j++;
	/*		printf("%d ", ds[i]);*/
		}
	}
	for (i = 0; i < j; i++)
	{
		printf("%d ",ns[i]);
	}

	return 0;
}