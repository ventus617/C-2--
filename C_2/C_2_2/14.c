#include<stdio.h>
int main14 ()
{
	//��ת����
	/*
	* 987654321
	* 123456789
	* �ǵ����ǻ���Ի����Ƿ�ת
	*/
	 /* ��һ����������β�Ե� */
	int ds[] = {0,1,2,3,4,5,6,7,8,9};
	int i,j,t;
	int len=sizeof(ds)/sizeof(ds[0]);
	for(i=0,j=len-1;i<j;i++,j--)
	{
		t = ds[i];
		ds[i]=ds[j];
		ds[j] = t;
	}
	for(i=0;i<len;i++)
	{
		printf("%d ",ds[i]);
	}
	return 0;
}