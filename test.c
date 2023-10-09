#include<stdio.h>
#include"meta.h"

void menu() {
	printf("============嗨嗨，这里是Trimoku三子棋游戏哦=============\n");
	printf("============来，选择你想要的吧~=========================\n");
	printf("============1：link start！！！0.：link out=============\n");
}
void game() {
	char ret = 0;
	char borad[w][h] = { 0 };
	revive(borad, w, h);
	displayborad(borad, w, h);
	//下棋
	while (1) {
		//玩家下棋
		PlayerMove(borad, w, h);
		displayborad(borad, w, h);
		//判断输赢
		ret = ifWin(borad, w, h);
		if (ret != 'C')
		{
			break;
		}
		//电脑下棋
		computerGo(borad, w, h);
		displayborad(borad, w, h);
		ret = ifWin(borad, w, h);
		if (ret != 'C')
		{
			break;
		}
	    if (ret == '*')
		{
			printf("你赢咯~让了你而已\n");
		}
		
		else if (ret == '#')
		{
			printf("这次是我的胜利哟~笨--- 蛋~\n");
		}
		else if(ret=='Q')
		{
			printf("能碰巧与我不相上下，当成你一辈子的荣耀吧，哼~\n");
		}
	}
}






	int main() {
		int input = 0;
		srand((unsigned int)time(NULL));
		do
		{

			menu();
			printf("select: ");
			scanf_s("%d", &input);
			switch (input)
			{
			case 1:
				game();
				break;
			case 0:
				printf("嘿~这就离开了？真是无聊呢~\n");
				break;

			default:
				printf("你是笨蛋嘛？这都选不对，算了，勉强让你再选一次哦~\n");
				break;
			}
		} while (input);
		return 0;
	}
