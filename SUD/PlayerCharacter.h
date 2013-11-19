#pragma once
#include "character.h"
class CPlayerCharacter :
	public CCharacter
{
public:
	CPlayerCharacter(void);
	~CPlayerCharacter(void);


	void SetInfo();
	void PrintInfo();
};

