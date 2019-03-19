// GameOfLife1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <windows.h>
using namespace std;

bool Grid[20][20];
bool GridCopy[20][20];
void CopyGrid(bool Grid1[20][20], bool Grid2[20][20]);

void OutputGrid()
{
	for (int x = 0; x < 20; x++)
	{
		for (int y = 0; y < 20; y++) {
			cout << ((Grid[x][y]) ? "0" : " ");
		}
		cout << endl;
	}
}

void NextGeneration()
{
	CopyGrid(Grid, GridCopy);

	for (int x = 1; x < 19; x++)
	{
		for (int y = 1; y < 19; y++) {
			int Neighbours = 0;
			
			if (Grid[x-1][y-1])	// - - 
				Neighbours++;
			if (Grid[x+1][y-1])	// + -
				Neighbours++;
			if (Grid[x-1][y+1])	// - +
				Neighbours++;
			if (Grid[x+1][y+1])	// + +
				Neighbours++;
			if (Grid[x-1][y])	// - _
				Neighbours++;
			if (Grid[x][y-1])	// _ -
				Neighbours++;
			if (Grid[x+1][y])	// + _
				Neighbours++;
			if (Grid[x][y+1])	// _ +
				Neighbours++;
			
			if (Grid[x][y])
			{
				if (Neighbours < 2 || Neighbours > 3)	// if underpopulated or overpopulated, then the cell dies
					GridCopy[x][y] = false;
				if (Neighbours == 2 || Neighbours == 3)	// if population is just right, then the cell stays alive
					GridCopy[x][y] = true;
			}
				else {
					if (Neighbours == 3)				// Empty cell with 3 neighbours, comes alive
						GridCopy[x][y] = true;
			}
		}
	}
		CopyGrid(GridCopy, Grid);
}

void CopyGrid(bool Grid1[20][20], bool Grid2[20][20]) {
	for (int a = 0; a < 20; a++)
	{
		for (int b = 0; b < 20; b++)
		{
			Grid2[a][b] = Grid1[a][b];
		}
	}
}

int main()
{
	Grid[10][10] = true;
	Grid[10][11] = true;
	Grid[11][10] = true;
	Grid[11][12] = true;
	Grid[ 9][10] = true;
	Grid[ 9][ 9] = true;
	Grid[10][13] = true;
	Grid[10][14] = true;
	Grid[13][14] = true;
	Grid[13][10] = true;

	for (int Gen = 0; Gen < 50; Gen++)
	{
		NextGeneration();
		system("cls");
		OutputGrid();
		Sleep(300);
	}
	system ("pause");
}