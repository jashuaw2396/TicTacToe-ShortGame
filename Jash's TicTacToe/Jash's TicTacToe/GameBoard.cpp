#include "GameBoard.h"


GameBoard::GameBoard()
{
	// We first initialize the board
	for (int i = 0; i < 9; i++)
		m_gameboard.push_back((i + 1) + 48);

	// Let's give the human player an advantage at least 
	m_playerTurn = 0;

	// Set play counter to 0
	m_playsLeft = 0;
}


GameBoard::~GameBoard()
{
}

void GameBoard::GameInstructions()
{
	cout << "						Welcome to Tic Tac Toe!" << endl;
	cout << "					        Here's the instructions:" << endl << endl;
	cout << "					  - Input from 1-9 to play your piece" << endl;
	cout << "						     on the board" << endl << endl;
	cout << "					- If you get 3 pieces in a row, you win!" << endl << endl;
	cout << "				   - If your opponent get 3 pieces in a row, you lose!" << endl << endl;
}

void GameBoard::PrintBoard()
{
	System::Console::SetCursorPosition((System::Console::WindowWidth() / 2) - 10, 3);
	cout << m_gameboard[0] << "  |  " << m_gameboard[1] << "  |  " << m_gameboard[2];
	System::Console::SetCursorPosition((System::Console::WindowWidth() / 2) - 10, 4);
	cout << "-------------";
	System::Console::SetCursorPosition((System::Console::WindowWidth() / 2) - 10, 5);
	cout << m_gameboard[3] << "  |  " << m_gameboard[4] << "  |  " << m_gameboard[5];
	System::Console::SetCursorPosition((System::Console::WindowWidth() / 2) - 10, 6);
	cout << "-------------";
	System::Console::SetCursorPosition((System::Console::WindowWidth() / 2) - 10, 7);
	cout << m_gameboard[6] << "  |  " << m_gameboard[7] << "  |  " << m_gameboard[8];
}

void GameBoard::NextTurn()
{
	// Passing the turn
	m_playerTurn++;
	// Mkaing sure we don't add a third player
	if (m_playerTurn == 2)
		m_playerTurn = 0;
	// Adding another turn
	m_playsLeft++;
}

bool GameBoard::PerformMove(char _input, char _playerSign)
{
	int _playerInput;
	// First we must turn the player's input into an index
	switch (_input)
	{
		case '1': _playerInput = 0;
			break;
		case '2': _playerInput = 1;
			break;
		case '3': _playerInput = 2;
			break;
		case '4': _playerInput = 3;
			break;
		case '5': _playerInput = 4;
			break;
		case '6': _playerInput = 5;
			break;
		case '7': _playerInput = 6;
			break;
		case '8': _playerInput = 7;
			break;
		case '9': _playerInput = 8;
			break;
		default:
		{	
			cout << "Illegal Move";
			return false;
			break;
		}
	}

	// Check for the human player
	if (_playerSign == 'X')
	{
		if (m_gameboard[_playerInput] != 'O' && m_gameboard[_playerInput] != _playerSign)
		{
			m_gameboard[_playerInput] = _playerSign;
			return true;
		}
	}

	// Check for the computer player
	else if (_playerSign == 'O')
	{
		if (m_gameboard[_playerInput] != 'X' && m_gameboard[_playerInput] != _playerSign)
		{
			m_gameboard[_playerInput] = _playerSign;
			return true;
		}
	}

	// If the play wasn't legal, we can't play that
	return false;
}

char GameBoard::CheckForWinner()
{
	// We check for 3 signs in a row to see if there's a winner

	// First, check for: xxx
	//					 345
	//					 678
	if ((m_gameboard[0] == m_gameboard[1]) && (m_gameboard[1] == m_gameboard[2]))
		return m_gameboard[0];

	// Now, check for:	 012
	//					 xxx
	//					 678
	else if ((m_gameboard[3] == m_gameboard[4]) && (m_gameboard[4] == m_gameboard[5]))
			return m_gameboard[3];

	// Now, check for:	 012
	//					 345
	//					 xxx
	else if ((m_gameboard[6] == m_gameboard[7]) && (m_gameboard[7] == m_gameboard[8]))
		return m_gameboard[6];

	// Now, check for:	 x12
	//					 x45
	//					 x78
	else if ((m_gameboard[0] == m_gameboard[3]) && (m_gameboard[3] == m_gameboard[6]))
		return m_gameboard[0];

	// Now, check for:	 0x2
	//					 3x5
	//					 6x8
	else if ((m_gameboard[1] == m_gameboard[4]) && (m_gameboard[4] == m_gameboard[7]))
		return m_gameboard[1];

	// Now, check for:	 01x
	//					 34x
	//					 67x
	else if ((m_gameboard[2] == m_gameboard[5]) && (m_gameboard[5] == m_gameboard[8]))
		return m_gameboard[2];

	// Now, check for:	 x12
	//					 3x5
	//					 67x
	else if ((m_gameboard[0] == m_gameboard[4]) && (m_gameboard[4] == m_gameboard[8]))
		return m_gameboard[0];

	// Now, check for:	 01x
	//					 3x5
	//					 x78
	else if ((m_gameboard[2] == m_gameboard[4]) && (m_gameboard[4] == m_gameboard[6]))
		return m_gameboard[2];

	// If no winner was found, return "false'
	else
		return 'f';
}
