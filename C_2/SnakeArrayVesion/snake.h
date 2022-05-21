#pragma once

/* 蛇 爬行 */
void snakemove(void);
/* 能吃 */
int haveit();
/* 变长 */
void grow();
/* 生成新苹果 */
void creatnewone();
/* 出界 */
int outofit();
/* 咬自己 */
int biteit();
/* 结束游戏 */
void gameover();

/* 蛇转向 */
void turnup();
void turndown();
void turnleft();
void turnright();
