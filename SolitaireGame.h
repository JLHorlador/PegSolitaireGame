/*
 * SolitaireGame.h
 *
 *  Created on: Nov 16, 2015
 *      Author: TheAsianGuy
 */
class SolitaireGame
{
private:
	int choice;
	void setupBoard();
public:
	SolitaireGame();
	int makeChoice();
	void displayBoard();
	int playerMove();
};
