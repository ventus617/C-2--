#include<stdio.h>
#include<stdlib.h>
int main18 ()
{
	int ds[20];
	int i,j;
	int len=sizeof(ds)/sizeof(ds[0]);
	for(i=0;i<len;i++)
	{
		ds[i]=rand()%100;
		printf("%d,",ds[i]);
	}
	printf("\n");
	/*�������Ա �� ��С�����˳���������*/
	//ð�����������������ţ������Ǵ�����һ����
	int temp = 0;
	for (int suo = 0; suo < len-1; suo++)//����һ�������ͺ�������һȦ���������ĸ������������һ��
	{
		for (int bijiao=suo+1;bijiao<len;bijiao++)//�������ĺ�һ�����Ƚϣ����һ�Ƚϵ����һ���������ҵ���С��
		{
			if (ds[suo] > ds[bijiao])
			{
				temp = ds[suo];
				ds[suo] = ds[bijiao];
				ds[bijiao] = temp;
			}
		}
	}
	for (i = 0; i < len; i++)
	{
		printf("%d ",ds[i]);
	}

	return 0;
}