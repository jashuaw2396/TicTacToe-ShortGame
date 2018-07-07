#pragma once
#include <iostream>
using namespace std;
#include <vector>
#include "Console.h"

class GameBoard
{
private:
	// Gameboard being used
	vector<char> m_gameboard;
	// Player turn counter
	int m_playerTurn;
	// Counter for max plays (in case of a tie)
	int m_playsLeft;

public:
	GameBoard();
	~GameBoard();

	// Prints game intro
	void GameInstructions();

	// Prints board (used after every successful move)
	void PrintBoard();

	// Increments player turn counter
	void NextTurn();

	// Receive the player input, return true if move successful, return false if not
	bool PerformMove(char _input, char _playerSign);

	// Check to see if a winner is found
	char CheckForWinner();
	
	// Getter
	int GetPlayerTurn() { return m_playerTurn; }
	int GetPlaysLeft()  { return m_playsLeft; }
};