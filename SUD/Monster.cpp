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
	printf_s("%s", m_problem.c_str());
}

//void CMonster::aa()
//{
//	printf("@@@@@@@@@@@@@@@@@@@@ %s\n",m_a.c_str());
//}
