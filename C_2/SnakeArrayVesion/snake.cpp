#include"snake.h"
#include<stdlib.h>
//只要涉及调用，就得有前置声明

//外部的（链接的作用）变量声明
extern int snakeLength;
extern int snakeLie[100];
extern int snakeHang[100];
extern int appleHang;
extern int appleLie;
extern int fangXiang;


/* 蛇 爬行 */
void snakemove(void)
{
	for (int jie = snakeLength - 1; jie >= 1; jie--)
	{
		snakeHang[jie] = snakeHang[jie - 1];
		snakeLie[jie] = snakeLie[jie - 1];
	}

	//蛇头爬
	switch (fangXiang)
	{
	case 0:
		snakeLie[0]++;
		break;
	case 1:
		snakeHang[0]--;
		break;
	case 2:
		snakeLie[0]--;
		break;
	case 3:
		snakeHang[0]++;
		break;
	}
}
/* 能吃 */
int haveit()
{

		return appleHang == snakeHang[0]
			&& appleLie == snakeLie[0];
	
}
/* 蛇 变长 */
void grow()
{
	snakeLength++;
}
/* 生成新苹果 */
void creatnewone()
{
	appleHang = rand() % 16 + 2;
	appleLie = rand() % 16 + 2;
}
/* 出界 */
int outofit()
{

	return (snakeHang[0] == 0 || snakeHang[0] == 19|| snakeLie[0] == 0 || snakeLie[19]);
}
		 
/* 咬自己 */
int biteit()
{
	
	for (int j = 1; j < snakeLength; j++)
	{
		if (snakeHang[0] == snakeHang[j]&& 
			snakeLie[0] == snakeLie[j])
		{
			return 1;
		}
	}
	return 0;
}
/* 结束游戏 */
void gameover()
{
	extern int stop;
	stop = 1;
}

/* 蛇转向 */
void turnup()
{
	if (fangXiang != 3)
		{
			fangXiang = 1;
		}
}
void turndown()
{
		if (fangXiang!=1)
		{
			fangXiang = 3;
		}
}
void turnleft()
{
		if (fangXiang != 0)
		{
			fangXiang = 2;
		}
}
void turnright()
{
	if (fangXiang != 2)
	{
		fangXiang = 0;
	}
}
