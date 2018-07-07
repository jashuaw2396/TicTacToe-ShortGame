#pragma once
#include "PlayerBaseClass.h"
class HumanPlayer : public PlayerBaseClass
{
private:
	char m_playerInput;
public:
	HumanPlayer();
	~HumanPlayer();

	char PlayerTurn();
};

