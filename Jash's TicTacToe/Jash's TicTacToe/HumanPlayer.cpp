#include "HumanPlayer.h"



HumanPlayer::HumanPlayer()
{
}


HumanPlayer::~HumanPlayer()
{
}

char HumanPlayer::PlayerTurn()
{
	System::Console::SetCursorPosition((System::Console::WindowWidth() / 2) - 10, 10);
	cout << "Where would you like to play? ";
	cin >> m_playerInput;
	return m_playerInput;
}
