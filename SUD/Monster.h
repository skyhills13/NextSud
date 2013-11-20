#pragma once
#include "character.h"
#define INITIAL_HP_M 1
class CMonster :
	public CCharacter
{
public:
	CMonster(void);
	~CMonster(void);

	void InitHP(){m_info.hp = INITIAL_HP_M;}
	void GiveProblem();
	//void aa();

protected:
	//std::string m_a;
	//int m_b;
};

