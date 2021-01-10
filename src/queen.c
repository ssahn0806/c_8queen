#include "queen.h"

void setBoard(char board[][SIZE], const int size)
{
	int width = size / SIZE;
	int height = size / SIZE;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			board[i][j] = '.';
		}
	}
}

void printBoard(const char board[][SIZE], const int size)
{
	int width = size / SIZE;
	int height = size / SIZE;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}

char printMenu(int* num)
{
	char input;

	printf("\n(A)dd, (M)ove, or (D)elete? ");
	scanf_s("%c%*c", &input, sizeof(input));
	(*num)++;
	while (input != 'A' && input != 'M' && input != 'D')
	{
		printf("ERROR: It is not a valid option!\n");
		printf("\n(A)dd, (M)ove, or (D)elete? ");
		scanf_s("%c%*c", &input, sizeof(input));
		(*num)++;
	}
	return input;
}

int isExist(const char board[][SIZE], const Point p)
{
	if (board[p.x - 1][p.y - 1] == 'Q')
		return 1;

	return 0;
}
int canExist(const char board[][SIZE], const Point p, char flag)
{
	if (flag == 'D' || flag == 'O')
	{
		if (p.x < 1 || p.x > 8 || p.y < 1 || p.y > 8)
			return 0;
	}
	else
	{
		if (p.x < 1 || p.x > 8 || p.y < 1 || p.y > 8)
			return 0;

		int cx = p.x - 1, cy = p.y - 1;

		for (int i = 0; i < SIZE; i++)
		{
			if (i == cx)
				continue;
			if (board[i][cy] == 'Q')
				return 0;
		}

		for (int j = 0; j < SIZE; j++)
		{
			if (j == cy)
				continue;
			if (board[cx][j] == 'Q')
				return 0;
		}


		// p.x - 1 , p.y - 1
		for (int k = 0; k < SIZE; k++)
		{
			for (int l = 0; l < SIZE; l++)
			{
				if (k == cx && l == cy)
					continue;
				if (k + l == cx + cy && board[k][l] == 'Q')
				{
					//printf("+ %d %d\n", k, l);
					return 0;
				}
				if (k - l == cx - cy && board[k][l] == 'Q')
				{
					//printf("- %d %d\n", k, l);
					return 0;
				}
			}
		}
	}

	return 1;
}
void addQueen(char board[][SIZE], const Point p)
{
	board[p.x - 1][p.y - 1] = 'Q';
	return;
}

void moveQueen(char board[][SIZE], const Point before, const Point after)
{
	board[before.x - 1][before.y - 1] = '.';
	board[after.x - 1][after.y - 1] = 'Q';
	return;
}
void deleteQueen(char board[][SIZE], const Point p)
{
	board[p.x - 1][p.y - 1] = '.';
	return;
}