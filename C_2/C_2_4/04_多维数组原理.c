#include <stdio.h>
int main ()
{
	/* 1 ��ά���������  */
	int arr[3][4][5];//��������+ά��
	/* 2 ��ά����ĳ�ʼ��  */
	int arr1[3][4][5] = { 1,2,3,4 };
	int arr2[3][4][5] = { {1,2},{3,4} };
	int arr3[3][4][5] = { {{1},{2} }, { {3},{4} }};
	/* 3.1 ��ά����ı���:��ά������+�±�  */


	printf("%d %d %d\n",arr3,arr3+1,arr3+2);//�����arr�����ַ��arr�ǻ������������׵�ַ
	printf("%d %d %d\n",sizeof(*arr3),sizeof(*(arr3+1)),sizeof(*(arr3+2)));
	printf("%d %d %d\n", sizeof(arr3[0]), sizeof(arr3[1]), sizeof(arr3[2]));


	printf("%d %d %d\n",arr3[0]+0,arr3[0]+1,arr3[0]+2);//�õ��е�ַ
	printf("%d %d %d\n",sizeof(*(arr3[0]+0)),sizeof(*(arr3[0]+1)),sizeof(*(arr3[0]+2)));
	printf("%d %d %d\n", sizeof(arr3[0][0]), sizeof(arr3[0][1]), sizeof(arr3[0][2]));
	//����* �൱�����ַ���ֽڴ�С��32λ����4�ֽڣ���*�൱������ռ��С

	for (int m = 0; m < 3; m++)
	{
		for (int h = 0; h < 4; h++)
		{
			for (int i = 0; i < 5; i++)
			{
				printf("%d", arr3[m][h][i]);
			}
			printf("\n");
		}
		printf("\n");
	 }


	/* 3.2 ��ά����ı���:��int�ͱ�����ָ��(��ָ��)  */
	int* plie = &arr3[1][0][0];
	printf("%d\n", *plie);
	int* pp = &arr3[1][1][1];
	printf("%d\n", *pp);
	//�������*plie ��Ϊ�����plie���Ǹ�����ַ

	/* 3.3 ��ά����ı���:��int��ָ��һά�����ָ�루��ָ�룩  */
	int(* poor)[5] = (arr3[1]+1);//*(arr+1)+1 ָ��4ʱ
	printf("%d\n", (*poor)[0]);
	int(*ppp)[5] = *arr3[1] + 1;
	printf("%d\n", (*ppp)[2]);
	/* 3.4 ��ά����ı���:��int��ָ���ά�����ָ�루ƽ��ָ�룩  */
	int(*pmian)[4][5] = arr3 + 1;
	printf("%d\n",(*pmian)[1][0]);

	int(*pppp)[4][5] = arr3;
	printf("%d\n",*(pppp)[2][3] );
	/* 3.5 ��ά����ı���:��int��ָ����ά�����ָ�루����ָ�룩  */
	int(*pli)[3][4][5] = &arr3;//arr��ָ�������������ά�ȵĵ�ַ����&arr�����壬�����ָ����������ά�ȵĵ�ַ
	printf("%d\n",(*pli)[1][1][0]);

	int(*ppppp)[3][4][5] = &arr;
	printf("%d\n", (*ppppp)[2][3][3]);
	//�ο���ַ[����]=*���ο���ַ+������


	//ָ��ʵ�ʾ��Ǵ洢�ĵ�ַ
	 
	return 0;
}