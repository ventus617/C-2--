#include <stdio.h>
int main02()
{
	//1 什么是指针变量：存储内存地址的变量为指针变量 
	//声明指针变量

	int age = 6;
	int* p = &age;

	//*是地址指向内存空间的操作，即指向目标地址（空间）的操作。

	printf("%d %d \n",age,*p);//p指向了age *p就代表age空间的“使用权”
	age += 5;
	*p += 5;
	printf("%d %d \n", age, *p);

	//在内存1中 其中的值就是存储的值 由于int型所以会分配给四个字节内容 cc表示回收地址，未分配的地址

	//2 指针变量的空间大小：根据操作系统的位数而不同。
	double d=2;
	double* pd=&d;
	printf("指针变量在内存中的字节数：%d\n",sizeof(p));
	printf("%d %d %d\n",sizeof(pd),sizeof(char*),sizeof(long long*));

	//在分配地址的时候是分配的首地址，即地址的编号
	//或者是指针保存的是内存地址的编号
	//因此任何指针数据类型在分配的时候，所占的长度是固定的，根据cpu的位数来确定地址字节数
	//32位是4字节 64位是8字节




	//3 指针的移动：根据数据类型不同，移动的步伐大小也不同
	//所加的常数1，是代表的该数据类型的下一个地址
	char c='1';
	char* pc=&c;
	printf("int* %d %d %d\n",p,p+1,p+2);
	printf("char* %d %d %d\n",pc,pc+1,pc+2);
	printf("double* %d %d %d\n",pd,pd+1,pd+2);

	//4 利用指针对存储值进行算术运算（注意运算符的优先级）。

	int q = 5;;
	int* k=&q;
	*k = 10;
	printf("%d\n", q);
	*k *= 5;
	printf("%d\n", q);
	(*k)++;
	printf("%d\n", q);
	//++等级高于*;


	//int* p;
	//double* pd;
	//long long* pll;
	//char* pc;
	//p = pd = pll = pc = NULL;
	//printf("%d %d %d\n", sizeof(p), sizeof(*p), p + 1); //4 4 4
	//	printf("%d %d %d \n", sizeof(pd), sizeof(*pd), pd + 1);	// 4 8 8  
	//	printf("%d %d %d \n", sizeof(pll), sizeof(*pll), pll + 1);  //4 8 8
	//	printf("%d %d %d \n", sizeof(pc), sizeof(*pc), pc + 1); //4 1 1
		//这里若是PC则是求PC指向的内存地址的格式size，由CPU决定的
		//若是* pc则是 指针指向的内存地址中存放的内容所占的size，由用户自己定义的数据类型决定的





	return 0;
}