/*
 * SolitaireGame.cpp
 *
 *  Created on: Nov 16, 2015
 *      Author: TheAsianGuy
 */
#include "SolitaireGame.h"
#include <iostream>
using namespace std;

int** board;
int a, b;

SolitaireGame::SolitaireGame()
{
	choice = makeChoice();
	setupBoard();
}

void SolitaireGame::setupBoard()
{
	if (choice == 1 || choice == 3)
	{
		a = 7;
		b = 7;
		board = new int*[a];
		for (int i = 0; i < a; i++)
			board[i] = new int[b];
		if (choice == 1)
		{
			//Populate with french setup
			for (int y = 0; y < a; y++)
			{
				for (int x = 0; x < b; x++)
				{
					if ((y == 0 || y == 6)
							&& (x == 0 || x == 1 || x == 5 || x == 6))
						board[x][y] = 'X';
					else if ((y == 1 || y == 5) && (x == 0 || x == 6))
						board[x][y] = 'X';
					else
						board[x][y] = 'O';
				}
			}
		}
		else
		{
			//Populate with english setup
			for (int y = 0; y < a; y++)
			{
				for (int x = 0; x < b; x++)
				{
					if ((y == 0 || y == 1 || y == 5 || y == 6)
							&& (x == 0 || x == 1 || x == 5 || x == 6))
						board[x][y] = 'X';
					else
						board[x][y] = 'O';
				}
			}
		}
	}
	else if (choice == 2 || choice == 4)
	{
		a = 9;
		b = 9;
		board = new int*[a];
		for (int i = 0; i < a; i++)
			board[i] = new int[b];
		if (choice == 2)
		{
			//Populate with german setup
			for (int y = 0; y < a; y++)
			{
				for (int x = 0; x < b; x++)
				{
					if ((y == 0 || y == 1 || y == 2 || y == 6 || y == 7 || y == 8)
							&& (x == 0 || x == 1 || x == 2 || x == 6 || x == 7 || x == 8))
						board[x][y] = 'X';
					else
						board[x][y] = 'O';
				}
			}
		}
		else
		{
			//Populate with diamond setup
			for (int y = 0; y < a; y++)
			{
				for (int x = 0; x < b; x++)
				{
					if ((y == 0 || y == 8)
							&& (x == 0 || x == 1 || x == 2 || x == 3 || x == 5 || x == 6 || x == 7 || x == 8))
						board[x][y] = 'X';
					else if ((y == 1 || y == 7)
							&& (x == 0 || x == 1 || x == 2 || x == 6 || x == 7 || x == 8))
						board[x][y] = 'X';
					else if ((y == 2 || y == 6)
							&& (x == 0 || x == 1 || x == 7 || x == 8))
						board[x][y] = 'X';
					else if ((y == 3 || y == 5)
							&& (x == 0 || x == 8))
						board[x][y] = 'X';
					else
						board[x][y] = 'O';
				}
			}
		}
	}
}

int SolitaireGame::makeChoice()
{
	int c = 0;
	cout << "Select board style: 1)French 2)German 3)English 4)Diamond\n";
	while (!(cin >> c) || (c < 1 || c > 4))
	{
		cout << "Please enter the number corresponding to the board style: \n";
		cin.clear();
		cin.ignore(1000, '\n');
	}
	return c;
}

int SolitaireGame::playerMove()
{
	return 0;
}

void SolitaireGame::displayBoard()
{
	for (int y = 0; y < a; y++)
	{
		for (int x = 0; x < b; x++)
		{
			if (board[x][y] == 'X')
				cout << " ";
			else if (board[x][y] == 'O')
				cout << "O";
			cout << " ";
		}
		cout << "\n";
	}
}

int main()
{
	SolitaireGame game;
	game.displayBoard();
}
