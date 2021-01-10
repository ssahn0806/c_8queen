#include "queen.h"

int main(void)
{
	char chessboard[SIZE][SIZE];
	while (1)
	{
		char input, again;
		int tries = 0, count = 0, can_exist, is_exist;
		Point point_old, point_new, point_del;
		setBoard(chessboard, sizeof(chessboard));
		printBoard(chessboard, sizeof(chessboard));
		do
		{
			input = printMenu(&tries);
			switch (input)
			{
			case 'A':
				printf("Input new queen's position (x,y): ");
				scanf_s("%d %d%*c", &point_new.x, &point_new.y);
				can_exist = canExist(chessboard, point_new, 'A');
				is_exist = isExist(chessboard, point_new);
				if (can_exist && !is_exist)
				{
					addQueen(chessboard, point_new);
					count++;
				}
				else if (is_exist)
				{
					printf("ERROR: There is already queen!\n");
				}
				else
					printf("ERROR: It is not a valid position!\n");
				break;
			case 'M':
				printf("Input old queen's position (x,y): ");
				scanf_s("%d %d%*c", &point_old.x, &point_old.y);
				fflush(stdin);
				can_exist = canExist(chessboard, point_old, 'O');
				is_exist = isExist(chessboard, point_old);
				if (can_exist && is_exist)
				{
					deleteQueen(chessboard, point_old);
					printf("Input new queen's position (x,y): ");
					scanf_s("%d %d%*c", &point_new.x, &point_new.y);
					can_exist = canExist(chessboard, point_new, 'N');
					is_exist = isExist(chessboard, point_new);
					if (can_exist && !is_exist)
					{
						//moveQueen(chessboard, point_old, point_new);
						addQueen(chessboard, point_new);
					}
					else if (is_exist)
					{
						printf("ERROR: There is already queen!\n");
						addQueen(chessboard, point_old);
					}
					else
					{
						printf("ERROR: It is not a valid position!\n");
						addQueen(chessboard, point_old);
					}
				}
				else if (!can_exist)
				{
					printf("ERROR: It is not a valid position!\n");
				}
				else
				{
					printf("ERROR: No queen at the position!\n");
				}
				break;
			case 'D':
				printf("Input delete queen's position (x,y): ");
				scanf_s("%d %d%*c", &point_del.x, &point_del.y);
				can_exist = canExist(chessboard, point_del, 'D');
				is_exist = isExist(chessboard, point_del);
				if (can_exist && is_exist)
				{
					deleteQueen(chessboard, point_del);
					count--;
				}
				else if (!can_exist)
				{
					printf("ERROR: It is not a valid position!\n");
				}
				else
				{
					printf("ERROR: No queen at the position!\n");
				}
				break;
			}
			printf("\n");
			printBoard(chessboard, sizeof(chessboard));
		} while (count < 8);

		printf("\nCongratulation!!!\nYou solved 8-queen puzzle by %d moves!\n", tries);

		printf("Press (R) to retry :");
		scanf_s("%c%*c", &again, sizeof(again));
		if (again != 'R')
			break;
	}
	return 0;
}

