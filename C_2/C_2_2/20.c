#include <stdio.h>
int main20()
{
	/*��һ������������У�Ѱ��һ��ָ�����������ڵ��±�*/
	int d[] = {1,5,8,12,23,44,56,78,99,200};
	int find=12;
	int len = sizeof(d) / sizeof(d[0]);
	//�۰���ң�����������������У�
	int begin = 0;//��ʼ��
	int middle = 0;//�м��
	int end = len-1;//ĩβ��
	do
	{
		middle = (begin + end)>>1;
		if (d[middle] == find)
		{
			printf("�±���%2d\n",middle);
			break;
		}
		else if (d[middle] < find)//������middle�±���ұ�
		{
			begin = middle + 1;
		}
		else if (d[middle] > find)//������middle�±�����
		{
			end = middle - 1;
		}

	} while (begin <= end);
	if (!(begin <= end))
	{
		printf("�޷��ҵ���Ӧ�±�");
	}

	return 0;

}