// CaiShuZi.cpp : 定义控制台应用程序的入口点。
//By Baka

#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#define num 4 //一共有几个数需要猜。
struct suijishu
{
	int pt[num];
	//pt是需要输入进去数。
	int jiance[num];
	//jiance是开关。
}pnum;
//随机数结构体。

int main()
{
	printf("==========================================\n");
	printf("=   小游戏，猜%d个数字，分别回车确认。   =\n", num);
	printf("==========================================\n");
	int rtime,rnum[num];
	/*
	定义两个整形变量。
	rtime代表生成随机数的循环次数，
	数组rnum代表生成的随机数，
	结构体中数组pnum代表需要输入的数。
	*/
	int yy, xx;
	/*
	定义两个整形变量。
	yy代表数对位置也对的个数，
	xx代表数对位置不对的个数。
	每次输入要猜的数，返回的就是yy和xx的值。
	*/
	int yytime, xxtime1, xxtime2, xxjump;
	/*
	yytime是检测数对位置也对的循环次数。
	xxtime1和2是检测数对但是位置错误的循环次数。
	xxjump是开关，跳出循环用。
	*/
	int pnumtime;
	//pnumtime是输入数字的次数，由num决定。
	int i=0;
	//i用来死循环，直到猜对所有数字跳出循环。
	int guesstime=0;
	//猜的次数有多少次，每猜一轮自身加上一。
	srand(time(0));
	//初始化随机数种子。
	for (rtime = 0; rtime < num; rtime++)
	{
		rnum[rtime] = rand() % 10;
		//printf("\n%d", rnum[rtime]);
		//分别对rnum[0]~rum[num-1]赋值个随机数。
	}
	while (i==0)
		//死循环
	{
		for (pnumtime = 0; pnumtime < num; pnumtime++)
		{
			printf("请输入第%d个数：", pnumtime+1);
			scanf("%d", &pnum.pt[pnumtime]);
			//从1开始输入num个数。
		}
		guesstime++;
		//猜的次数，每次输入完毕后都会加上1次。
		yy = 0;
		xx = 0;
		/*
		初始化yy和xx的值。
		也就是说，每次输入完毕要猜的数字后，
		yy和xx的值都会重置。
		*/

		for (yytime = 0; yytime < num; yytime++)
		{
			if (pnum.pt[yytime] == rnum[yytime])
			{
				yy++;
				/*
				如果位置对数也对，那么yy自身加上1。
				如果没有，则进入else。
				*/
				pnum.jiance[yytime] = 1;
				/*
				开关，用于对xx的计算。
				作用是：如果这个数字数对位置也对，
				那么他就不参与数对位置错误的检测。
				举个例子就是：
				答案是101
				如果猜的是123，那么返回的应该是1，0而不是1，1。
				*/
			}
			else
			{
				pnum.jiance[yytime] = 0;
				//开关，同上，用于xx。
			}
		}
	
		for (xxtime1 = 0; xxtime1 < num; xxtime1++)
		{
			xxjump = 0;
			//开关，见下。
			for (xxtime2 = 0; xxtime2 < num; xxtime2++)
			{
				if (pnum.jiance[xxtime1] == 0 && xxjump == 0 && pnum.pt[xxtime1]==rnum[xxtime2])
					/*
					这里是进行不同位置的比较，检测是否有数对但是不同位置的数。
					分别检测了：
					1.在yy中的开关，如果有开关是1的数字，那么不进入xx中比较。
					2.是否已经比较过一次并且让xx自增过的数字，如果有则不进入比较。
					例如：答案是101，如果猜213，那么返回的结果是0 1而不是0 2。
					*/
				{
					xx++;
					//满足以上条件后，并且检测的两个数相等，那么xx自加1。
					xxjump = 1;
					//开关赋值为1，也就是说满足条件后让xx自增的数字不再进入检测。
				}
			}
		}
		if (yy == num)
		{
			i = 1;
		}
		//如果全部猜对，那么跳出循环，输出结果。
		printf("位置对数也对的个数：%d\n位置不对但是数对的个数：%d\n这是你猜的第%d次。\n\n", yy, xx,guesstime);
	}
	printf("==========================================\n");
	printf("=   恭喜你，你猜对了所有的数字！！！！   =\n");
	printf("==========================================\n");
	return 0;
}