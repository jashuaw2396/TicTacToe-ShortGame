#pragma once
#include "GameBoard.h"
class PlayerBaseClass
{
private:
	// The sign this player uses
	char m_playerSign;
	// playername? maybe
	//string m_playerName;

public:
	PlayerBaseClass();
	~PlayerBaseClass();

	// Pure virtual function that has to be overriden, making this a base class.
	virtual char PlayerTurn() = 0;

	// Getter/Accessor
	inline char GetPlayerSign()					{ return m_playerSign; }

	// Setter/Mutator
	inline void SetPlayerSign(char _sign)		{ m_playerSign = _sign; }
};