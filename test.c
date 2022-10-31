#include "game.h"
void menu()
{
	printf("*********************\n");
	printf("***1.play   0.exit***\n");
	printf("*********************\n");
}
void game()
{
	char ret;
	char board[ROW][COL] = { 0 };
	Initboard(board, ROW, COL);
	//��ӡ����
	DisplayBoard(board,ROW,COL);
	while (1)
	{
		PlayerMave(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("���Ӯ\n");
	}
	else if (ret == '#')
	{
		printf("����Ӯ\n");
	}
	else
	{
		printf("ƽ��\n");
	}
}
void test()
{
	int input;
	do
	{
		menu();
		printf("��ѡ��>:");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			printf("������\n");
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ���������������\n");
			break;
		}
	} while (input);
}
int main()
{
	srand((unsigned int)time(NULL));
	test();
	return 0;
}