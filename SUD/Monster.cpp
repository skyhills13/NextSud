#include "stdafx.h"
#include "Monster.h"


CMonster::CMonster(void)
{
}


CMonster::~CMonster(void)
{
}

void CMonster::GiveProblem()
{
	printf_s("%s", m_problem.question.c_str());
	printf_s("%s", m_problem.options.c_str());
}

Info CMonster::Attacked( AttackResult attack_result )
{
	//splendid idea needed
	switch(attack_result)
	{
	case ATTACK_SUCCESS: 
		//which means answer of player is wrong so, should practice more 
		//therefore, hp++ 
		//and it would be better if the position changes.
		m_info.hp++;
		break;

	case ATTACK_FAIL:
		--m_info.hp;
		if(IsAlive()==true)
		{
			SetPosition(5,6);//randomly redistribute
		}
		else
		{
			//delete object
		}

	case DEFENSE:
		break;

	case RUN:
		break;
	}

	return m_info;
}
