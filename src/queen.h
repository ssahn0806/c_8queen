#include <stdio.h>

typedef struct {
	int x;
	int y;
}Point;

#define SIZE 8

void setBoard(char board[][SIZE], const int size);
void printBoard(const char board[][SIZE], const int size);
char printMenu(int* num);
int isExist(const char board[][SIZE], const Point p);
int canExist(const char board[][SIZE], const Point p, char flag);
void addQueen(char board[][SIZE], const Point p);
void moveQueen(char board[][SIZE], const Point before, const Point after);
void deleteQueen(char board[][SIZE], const Point p);