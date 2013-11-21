#pragma once
#include "character.h"
#define INITIAL_HP_M 1

struct Problem
{
	int index;
	std::string question;
	std::string options;
	int answer;
};

class CMonster :
	public CCharacter
{
public:
	CMonster(void);
	~CMonster(void);

	void InitHP(){m_info.hp = INITIAL_HP_M;}

	void SetIndex(int index){m_problem.index = index;}
	int GetIndex(){return m_problem.index;}

	//about these functions
	//get actually means print
	//if it works well, refactor.
	void SetQuestion(std::string question){m_problem.question = question;}
	std::string GetQuestion(){return m_problem.question;}

	void SetOptions(std::string options){m_problem.options = options;}
	std::string GetOptions(){return m_problem.options;}

	void SetAnswer(int answer){m_problem.answer = answer;}
	int GetAnswer(){return m_problem.answer;}

	void GiveProblem();

	Info Attacked(AttackResult attack_result);


protected:
	Problem m_problem;
};

