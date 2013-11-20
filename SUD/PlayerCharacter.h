#pragma once
#include "character.h"

#define INITIAL_HP_P 10

enum AttackResult
{
	ATTACK_SUCCESS,
	ATTACK_FAIL,
	DEFENSE,
	RUN
};

class CPlayerCharacter :
	public CCharacter
{
public:
	CPlayerCharacter(void);
	~CPlayerCharacter(void);

	void InitHP(){m_info.hp = INITIAL_HP;}
	void SetInfo();
	void PrintInfo();
	void CheckLevel(int current_exp);
};

