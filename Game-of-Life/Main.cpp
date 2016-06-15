/****************************************************************************
**Program Filename:  Main.cpp
**Author:  Jason Fisher
**Date:  1/7/2016
**Description:  Main File for Assignment 1 - Game of Life
**Input:
**Output:
****************************************************************************/

#include <iostream>
#include <cstring>

int main()
{
	/*create 2 arrays large enough to hold the viewable window*/
	int array1[200][200];
	int array2[200][200];
	int choice, xTemp, yTemp, x, y;

	/*initialize array1 so that all cells are empty*/
	for (int i = 0; i < 200; i++) 
	{
		for (int j = 0; j < 200; j++) 
		{
			array1[i][j] = 0; 
		}
	}


	/*initialize array2 so that all cells are empty*/
	for (int i = 0; i < 200; i++) 
	{
		for (int j = 0; j < 200; j++) 
		{
			array2[i][j] = 0; 
		}
	}


	/*prompt the user to enter a starting position*/
	std::cout << "Choose a starting coordinate in a grid with 20 rows and 40 columns.";
	std::cout << std::endl;
	std::cout << "This coordinate will be the leftmost point of the starting pattern.";
	std::cout << std::endl;
	std::cout << "Pick a row betweein 1 and 20: ";
	std::cin >> xTemp; //starting row

	while ((xTemp < 1) || (xTemp > 20))//row data validation
	{
		std::cout << "Input not valid.  Re-enter Row.";
		std::cout << "Pick a row betweein 1 and 20: ";
		std::cin >> xTemp;
	}
	std::cout << "Pick a column between 1 and 40: ";
	std::cin >> yTemp;//starting column

	while ((yTemp < 1) || (yTemp > 40))//column data validation
	{
		std::cout << "Input not valid.  Re-enter Column.";
		std::cout << "Pick a column between 1 and 40: ";
		std::cin >> yTemp;
	}


	/*Adjust the entered coordinates for the viewable window*/
	x = xTemp+99;
	y = yTemp+99;

	
	/*prompt the user to choose a starting pattern*/
	std::cout << "Please choose the starting shape" << std::endl;
	std::cout << "Type 1 for oscillator" << std::endl;
	std::cout << "Type 2 for glider" << std::endl;
	std::cout << "Type 3 for glider gun" << std::endl;

	std::cin >> choice;

	
	/*set the oscillator*/
	if (choice == 1)
	{
		array1[x][y] = 1;
		array1[x][y+1] = 1;
		array1[x][y+2] = 1;
	}


	/*set the glider*/
	if (choice == 2)
	{
		array1[x][y] = 1;
		array1[x][y+1] = 1;
		array1[x][y+2] = 1;
		array1[x-1][y+2] = 1;
		array1[x-2][y+1] = 1;
	}


	/*set the glider gun*/
	if (choice == 3)
	{
		array1[x][y] = 1;
		array1[x][y+1] = 1;
		array1[x+1][y] = 1;
		array1[x+1][y+1] = 1;
		array1[x][y+10] = 1;
		array1[x+1][y+10] = 1;
		array1[x+2][y+10] = 1;
		array1[x-1][y+11] = 1;
		array1[x+3][y+11] = 1;
		array1[x-2][y+12] = 1;
		array1[x+4][y+12] = 1;
		array1[x-2][y+13] = 1;
		array1[x+4][y+13] = 1;
		array1[x+1][y+14] = 1;
		array1[x-1][y+15] = 1;
		array1[x+3][y+15] = 1;
		array1[x][y+16] = 1;
		array1[x+1][y+16] = 1;
		array1[x+2][y+16] = 1;
		array1[x+1][y+17] = 1;
		array1[x-2][y+20] = 1;
		array1[x-1][y+20] = 1;
		array1[x][y+20] = 1;
		array1[x-2][y+21] = 1;
		array1[x-1][y+21] = 1;
		array1[x][y+21] = 1;
		array1[x-3][y+22] = 1;
		array1[x+1][y+22] = 1;
		array1[x-4][y+24] = 1;
		array1[x-3][y+24] = 1;
		array1[x+1][y+24] = 1;
		array1[x+2][y+24] = 1;
		array1[x-2][y+34] = 1;
		array1[x-1][y+34] = 1;
		array1[x-2][y+35] = 1;
		array1[x-1][y+35] = 1;
	}


	/*copy array1 to array2*/
		for (int i = 0; i < 200; i++)
		{
			for (int j = 0; j < 200; j++) 
			{
				array2[i][j] = array1[i][j];
			}
		}


	/*Display the viewable window*/
	for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 40; j++)
			{
				if (array1[i+100][j+100] == 1)
					std::cout << "#";
				else
					std::cout << ".";
			}
			std::cout << std::endl;
		}
	std::cout << std::endl;//space between gens


	/*run cell comparison, cell set, and array assignment*/
	for (int index = 0; index < 2; index++)
	{
		for (int i = 1; i < 199; i++)//ignores left and right edge
		{
			for (int j = 1; j < 199; j++) //ignores top and bottom edge
			{
				int count = 0;//resets to 0 each loop
				
				/*check 8 surrounding cells*/
				if (array1[i-1][j-1] == 1)
					count++;
				if (array1[i-1][j] == 1)
					count++;
				if (array1[i-1][j+1] == 1)
					count++;
				if (array1[i][j+1] == 1)
					count++;
				if (array1[i+1][j+1] == 1)
					count++;
				if (array1[i+1][j] == 1)
					count++;
				if (array1[i+1][j-1] == 1)
					count++;
				if (array1[i][j-1] == 1)
					count++;
				
				
				/*change cell status based on conditions*/
				if ((array1[i][j] == 1) && (count < 2))
					array2[i][j] = 0;
				else if ((array1[i][j] == 1) && (count > 3))
					array2[i][j] = 0;
				else if ((array1[i][j] == 0) && (count == 3))
					array2[i][j] = 1;
			}
		}

		/*copy array2 to array1*/
		for (int i = 0; i < 200; i++)
		{
			for (int j = 0; j < 200; j++) 
			{
				array1[i][j] = array2[i][j];
			}
		}


		/*Display the viewable window*/
		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 40; j++)
			{
				if (array1[i+100][j+100] == 1)
					std::cout << "#";
				else
					std::cout << ".";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;//space between gens

		/*decrement index to run indefinitely*/
		index--;
	}

	return 0;
}