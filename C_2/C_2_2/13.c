#include <stdio.h>
int main13 ()
{
	 /* ����һ�����е������ ��С�� �Ǽ� */
	int ds[]={10,30,43,43,43,23,12,40};
	int max = ds[0];
	int min = ds[0];
	int i;
	int length=sizeof(ds)/sizeof(ds[0]);
	//printf("%d",sizeof(ds)/sizeof(ds[0]));//��������ĳ�Ա����
	/* ��չ��������м��� */
	for(i=1;i<length;i++)
	{
		if (max<ds[i])
		{
			max = ds[i];
		}
		if (min>ds[i])
		{
			min = ds[i];
		}
	}
	printf("max=%d min=%d\n",max,min);
	/* ��չ���ڶ�����Ǽ� */

	return 0;
}