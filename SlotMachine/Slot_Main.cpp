#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include <time.h>
#pragma warning(disable:4996)

const int grid_size = 3;
int machine[grid_size][grid_size];
float cash = 100.0;
float bet = 10.0;
int winnings = 0;
int hor_line_count = 0;
int vert_line_count = 0;
int right_dia_line_count = 0;
int left_dia_line_count = 0;
float totalWinnings = 0;


void draw_machine()
{
	for (int row = 0; row < grid_size; row++)
	{
		for (int col = 0; col < grid_size; col++)
		{


			machine[row][col] = rand() % 10;
			printf("|%d|", machine[row][col]);


		}
		printf("\n");
	}
}

void hor_lines()
{

	for (int row = 0; row < grid_size; row++)
	{

		int hor_match = 1;
		for (int col = 1; col < grid_size; col++)
		{
			if (machine[row][0] != machine[row][col])
			{
				hor_match = 0;
				break;
			}
		}
		if (hor_match == 1)
		{

			hor_line_count += 1;

		}

	}

	printf("Horizontal matches: %d\n", hor_line_count);
	
}

void vert_lines()
{
	for (int col = 0; col < grid_size; col++)
	{

		int vert_match = 1;
		for (int row = 1; row < grid_size; row++)
		{
			if (machine[0][col] != machine[row][col])
			{
				vert_match = 0;
				break;
			}

		}
		if (vert_match == 1)
		{
			vert_line_count += 1;
		}
	}
	printf("Vertical matches: %d\n", vert_line_count);
	
}

void right_dia_lines()
{
	int dia_match = 1;

	for (int row = 1; row < grid_size; row++)
	{
		int col = row;

		if (machine[row][col] != machine[0][0])
		{
			dia_match = 0;
			break;
		}
	}

	if (dia_match == 1)
	{
		right_dia_line_count += 1;
	}
	printf("Right diagonal matches: %d\n", right_dia_line_count);
	
}

void left_dia()
{
	int dia_match = 1;

	for (int row = 1; row < grid_size; row++)
	{
		int col = 2 - row;

		if (machine[row][col] != machine[0][2])
		{
			dia_match = 0;
			break;
		}
	}
	if (dia_match == 1)
	{
		left_dia_line_count += 1;
	}
	printf("Left diagonal matches: %d\n", left_dia_line_count);
	
}

void payout()
{
	winnings += (hor_line_count + vert_line_count)* 1.2 * bet;
	winnings += (right_dia_line_count + left_dia_line_count) * 3 * bet;
}

	int main()
	{
		srand(time(0));
		printf("	Welcome to Casino Royale! Please press enter to spin the slot.\n\n");

		getchar();
		for (;;)
		{
			printf("You have $%.2f			Current bet : $ % .2f.\n\n		Total Winnings : %.2f\n", cash, bet, totalWinnings);

			getchar();

			cash -= bet;

			if (cash > 0)
			{
				draw_machine();
				hor_lines();
				vert_lines();
				right_dia_lines();
				left_dia();
				payout();
				cash += winnings;
				vert_line_count = 0;
				hor_line_count = 0;
				left_dia_line_count = 0;
				right_dia_line_count = 0;


				printf("Your winnings are $%d\n", winnings);
				totalWinnings += winnings;
				winnings = 0;
				getchar();
			}
			else
			{
				printf("You dont have enough cash for bet, Thank you for playing");
				printf("\nGoodBye!");
				getchar();
				return 0;
			}
			
			
		}
		getchar();
		return 0;
	}
