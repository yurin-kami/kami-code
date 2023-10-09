#include"meta.h"
void revive(char borad[w][h], int W, int H) {
	for (int i = 0; i < w; i++)
	{
		for (int j = 0; j < h; j++) {
			borad[i][j]=' ';
		}
	}
}
void displayborad(char borad[w][h], int W, int H) {
	int i = 0;
	for (i = 0; i < w; i++)
	{
		int j = 0;
		for (j = 0; j < h; j++)
		{
			printf("%c", borad[i][j]);
			if (j < h - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		if (i < w - 1)
		{
			for (j = 0; j < h; j++)
			{
				printf("—");

				if (j < h - 1)
				{
					printf("|");
				}
			}
			printf("\n");
		}
	}
}
int ifFull(char borad[w][h], int W, int H) {
	for (int i = 0; i < W; i++)
	{
		for (int j = 0; j < H; j++)
		{
			if (borad[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}
void PlayerMove(char borad[w][h], int W, int H) {
	int x, y = 0;
	printf("来，下吧，看看你几斤几两\n");
	while (1)
	{
		printf("坐标:>");
		scanf_s("%d%d", &x, &y);
		if (x >= 1 && x <= W && y >= 1 && y <= H)
		{
			if (borad[x-1][y-1]== ' ')
			{
				borad[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("你不会真是笨蛋吧，还要下下过的地方？？？\n");
				
			}
		}
		else {
			printf("哈？你玩的啥，给我重新走！！！\n");
			break;
		}
	}
}
void computerGo(char borad[w][h], int W, int H) {
	int x, y = 0;
	printf("电脑走：>\n");
	while (1)
	{
		x = rand() % W;
		y = rand() % H;
		if (borad[x][y] == ' ')
		{
			borad[x][y] = '#';
			break;
		}
	}
}
char ifWin(char borad[w][h], int W, int H) {
	int i = 0;
	for ( i = 0; i < W; i++)
	{
		if (borad[i][0] == borad[i][1] && borad[i][1] == borad[i][2] && borad[i][1] != ' ') {
			return borad[i][1];
		}
	}
	for ( i = 0; i < H; i++)
	{
		if (borad[0][i] == borad[2][i] && borad[2][i] == borad[3][i] && borad[1][i] != ' ')
		{
			return borad[1][i];
		}
	}
	if (borad[0][0] == borad[1][1] && borad[1][1] == borad[2][2] && borad[1][1] != ' ')
	{
		return borad[1][1];
	}
	if (borad[2][0] == borad[1][1] && borad[1][1] == borad[0][2] && borad[1][1] != ' ')
	{
		return borad[1][1];
	}
	if (ifFull(borad,w,h))
	{
		return 'Q';
	}else{
		return 'C';
	}
}
