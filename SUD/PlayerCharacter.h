#pragma once
#include "character.h"

#define INITIAL_HP_P 10

//concept of ATTACK is only on player character


class CPlayerCharacter :
	public CCharacter
{
public:
	CPlayerCharacter(void);
	~CPlayerCharacter(void);

	
	void InitHP(){m_info.hp = INITIAL_HP_P;}
	void SetInfo();
	void PrintInfo();
	void CheckLevel(int current_exp);
	Info Attacked(AttackResult attack_result);
};

