#include<stdio.h>
int main15()
{
	 /* ��һ�����ĵ�һ�����ŵ����������������ǰ�� */
	int ds[] = {1,2,3,4,5,6,7,8,9};
	int i,j,t;
	int len=sizeof(ds)/sizeof(ds[0]);
	/* ����1 */
	//t = ds[0];
	//for (i = 1; i < len; i++)
	//{	
	//	ds[i - 1] = ds[i];
	//}
	//ds[len - 1] = t;
	//for (i = 0; i < len; i++)
	//{
	//	printf("%d ",ds[i]);
	//}

	/* ����2 �ӵ�0����ʼ ���κͺ���������н��� */
	/*t = ds[0];
	for (i=0;i<len;i++)
	{
		ds[i] = ds[i + 1];
	}
	ds[len - 1] = t;*/
	for (i = 0; i < len - 1; i++)//ttaabb.t=a,a=b,b=t
	{
		t = ds[i];
		ds[i] = ds[i + 1];
		ds[i + 1] = t;
	}
	for (i = 0; i < len; i++)
	{
		printf("%d ",ds[i]);
	}
	return 0;
}