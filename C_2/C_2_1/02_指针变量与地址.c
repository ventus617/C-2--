#include <stdio.h>
int main02()
{
	//1 ʲô��ָ��������洢�ڴ��ַ�ı���Ϊָ����� 
	//����ָ�����

	int age = 6;
	int* p = &age;

	//*�ǵ�ַָ���ڴ�ռ�Ĳ�������ָ��Ŀ���ַ���ռ䣩�Ĳ�����

	printf("%d %d \n",age,*p);//pָ����age *p�ʹ���age�ռ�ġ�ʹ��Ȩ��
	age += 5;
	*p += 5;
	printf("%d %d \n", age, *p);

	//���ڴ�1�� ���е�ֵ���Ǵ洢��ֵ ����int�����Ի������ĸ��ֽ����� cc��ʾ���յ�ַ��δ����ĵ�ַ

	//2 ָ������Ŀռ��С�����ݲ���ϵͳ��λ������ͬ��
	double d=2;
	double* pd=&d;
	printf("ָ��������ڴ��е��ֽ�����%d\n",sizeof(p));
	printf("%d %d %d\n",sizeof(pd),sizeof(char*),sizeof(long long*));

	//�ڷ����ַ��ʱ���Ƿ�����׵�ַ������ַ�ı��
	//������ָ�뱣������ڴ��ַ�ı��
	//����κ�ָ�����������ڷ����ʱ����ռ�ĳ����ǹ̶��ģ�����cpu��λ����ȷ����ַ�ֽ���
	//32λ��4�ֽ� 64λ��8�ֽ�




	//3 ָ����ƶ��������������Ͳ�ͬ���ƶ��Ĳ�����СҲ��ͬ
	//���ӵĳ���1���Ǵ���ĸ��������͵���һ����ַ
	char c='1';
	char* pc=&c;
	printf("int* %d %d %d\n",p,p+1,p+2);
	printf("char* %d %d %d\n",pc,pc+1,pc+2);
	printf("double* %d %d %d\n",pd,pd+1,pd+2);

	//4 ����ָ��Դ洢ֵ�����������㣨ע������������ȼ�����

	int q = 5;;
	int* k=&q;
	*k = 10;
	printf("%d\n", q);
	*k *= 5;
	printf("%d\n", q);
	(*k)++;
	printf("%d\n", q);
	//++�ȼ�����*;


	//int* p;
	//double* pd;
	//long long* pll;
	//char* pc;
	//p = pd = pll = pc = NULL;
	//printf("%d %d %d\n", sizeof(p), sizeof(*p), p + 1); //4 4 4
	//	printf("%d %d %d \n", sizeof(pd), sizeof(*pd), pd + 1);	// 4 8 8  
	//	printf("%d %d %d \n", sizeof(pll), sizeof(*pll), pll + 1);  //4 8 8
	//	printf("%d %d %d \n", sizeof(pc), sizeof(*pc), pc + 1); //4 1 1
		//��������PC������PCָ����ڴ��ַ�ĸ�ʽsize����CPU������
		//����* pc���� ָ��ָ����ڴ��ַ�д�ŵ�������ռ��size�����û��Լ�������������;�����





	return 0;
}