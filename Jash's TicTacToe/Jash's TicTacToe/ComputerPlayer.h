#pragma once
#include "PlayerBaseClass.h"
class ComputerPlayer :
	public PlayerBaseClass
{
public:
	ComputerPlayer();
	~ComputerPlayer();

	char PlayerTurn();
};

