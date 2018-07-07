#include "ComputerPlayer.h"



ComputerPlayer::ComputerPlayer()
{
}


ComputerPlayer::~ComputerPlayer()
{
}

char ComputerPlayer::PlayerTurn()
{
	// We get a random number inside our ranges, and that's our AI's play (very complex)
	switch (rand() % 9)
	{
	case 0: return '1';
		break;
	case 1: return '2';
		break;
	case 2: return '3';
		break;
	case 3: return '4';
		break;
	case 4: return '5';
		break;
	case 5: return '6';
		break;
	case 6: return '7';
		break;
	case 7: return '8';
		break;
	case 8: return '9';
		break;
	default:
		break;
	}
}
