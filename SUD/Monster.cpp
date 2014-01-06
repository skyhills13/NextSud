#include "stdafx.h"
#include "Monster.h"



CMonster::CMonster(void)
{
	//m_problem.problemIndex = NULL;
}


CMonster::~CMonster(void)
{
}

void CMonster::GiveProblem(int monsterIndex)
{
	char buf[20];

	sprintf_s(buf, "problem/%d.txt",monsterIndex);
	std::ifstream problemFile(buf);
	std::string answer_str;
	std::getline(problemFile,answer_str);
	m_problem.answer = atoi(answer_str.c_str());

	while(!problemFile.eof())
	{
		std::string problemLine;
		std::getline(problemFile, problemLine);
		printf_s("%s\n",problemLine.c_str());
	}
	problemFile.close();
}

Info CMonster::GetAttackResult( AttackResult attack_result )
{
	//splendid idea needed
	switch(attack_result)
	{
	case ATTACK_SUCCESS: 
		//which means answer of player is wrong so, should practice more 
		//therefore, hp++ 
		//and it would be better if the position changes.
		m_info.hp++;
		SetWasWrong(true);
		break;

	case ATTACK_FAIL:
		--m_info.hp;
		break;

	case DEFENSE:
		break;

	case RUN:
		break;
	}

	return m_info;
}
