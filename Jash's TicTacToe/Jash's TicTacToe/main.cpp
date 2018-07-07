#include <iostream>
#include "GameBoard.h"
#include "PlayerBaseClass.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"
#include <ctime>
using namespace std;

int main()
{
	// seeding the random number generator
	srand(unsigned int(time(0)));

	// Making the board & showing intro page
	GameBoard* gameboard;
	gameboard = new GameBoard();
	gameboard->GameInstructions();

	// Now, we make the players
	vector<PlayerBaseClass*> m_players;
	// Set the size of two players
	m_players.resize(2);
	// Now we allocate each one to the corresponding player
	m_players[0] = new HumanPlayer();
	m_players[0]->SetPlayerSign('X');
	m_players[1] = new ComputerPlayer();
	m_players[1]->SetPlayerSign('O');

	// Waiting for input
	cout << endl << endl << endl << "					    ";
	system("pause");

	// Being used for player input
	char currPlayerInput;
	bool check;
	
	// This will be the game loop
	for (;;)
	{
		// Clear page
		System::Console::Clear();

		// Now we print the board
		gameboard->PrintBoard();
		
		for (;;)
		{
			// Now we get input from the curr player's turn
			currPlayerInput = m_players[gameboard->GetPlayerTurn()]->PlayerTurn();

			// Passing the player's move and checking for a legal play
			check = gameboard->PerformMove(currPlayerInput, m_players[gameboard->GetPlayerTurn()]->GetPlayerSign());

			if (check)
			{
				System::Console::Clear();
				gameboard->PrintBoard();
				cout << endl << "Player " << m_players[gameboard->GetPlayerTurn()]->GetPlayerSign() << " played his move!";
				break;
			}
		}

		// Checking to see if there's a winner
		if (gameboard->CheckForWinner() != 'f')
		{
			cout << endl << endl << endl << "The winner of the game is: Player " << gameboard->CheckForWinner() << "!!!";
			break;
		}

		// At the end, we pass the turn to the other player
		gameboard->NextTurn();

		// We check to see if the game  is tied
		if (gameboard->GetPlaysLeft() == 9)
		{
			cout << endl << endl << "We have a tied game! No one won!";
			break;
		}

		system("pause");
	}

	



	// Waiting for input
	cout << endl << endl << endl << "					    ";
	system("pause");
	return 0;
}