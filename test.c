#include<stdio.h>
#include"meta.h"

void menu() {
	printf("============���ˣ�������Trimoku��������ϷŶ=============\n");
	printf("============����ѡ������Ҫ�İ�~=========================\n");
	printf("============1��link start������0.��link out=============\n");
}
void game() {
	char ret = 0;
	char borad[w][h] = { 0 };
	revive(borad, w, h);
	displayborad(borad, w, h);
	//����
	while (1) {
		//�������
		PlayerMove(borad, w, h);
		displayborad(borad, w, h);
		//�ж���Ӯ
		ret = ifWin(borad, w, h);
		if (ret != 'C')
		{
			break;
		}
		//��������
		computerGo(borad, w, h);
		displayborad(borad, w, h);
		ret = ifWin(borad, w, h);
		if (ret != 'C')
		{
			break;
		}
	    if (ret == '*')
		{
			printf("��Ӯ��~���������\n");
		}
		
		else if (ret == '#')
		{
			printf("������ҵ�ʤ��Ӵ~��--- ��~\n");
		}
		else if(ret=='Q')
		{
			printf("���������Ҳ������£�������һ���ӵ���ҫ�ɣ���~\n");
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
				printf("��~����뿪�ˣ�����������~\n");
				break;

			default:
				printf("���Ǳ�����ⶼѡ���ԣ����ˣ���ǿ������ѡһ��Ŷ~\n");
				break;
			}
		} while (input);
		return 0;
	}
