#pragma once
#include "character.h"
#include <fstream>
#define INITIAL_HP_M 1

struct Problem
{
//	int index;
	int answer;
	int problemIndex;
	bool wasWrong;
};

class CMonster :
	public CCharacter
{
public:
	CMonster(void);
	~CMonster(void);

	void InitHP(){m_info.hp = INITIAL_HP_M;}

	void SetProblemIndex(int index){m_problem.problemIndex = index;}
	int GetProblemIndex(){return m_problem.problemIndex;}

	//about these functions
	//get actually means print
	//if it works well, refactor.
	//void SetQuestion(std::string question){m_problem.question = question;}
	//std::string GetQuestion(){return m_problem.question;}

	//void SetOptions(std::string options){m_problem.options = options;}
	//std::string GetOptions(){return m_problem.options;}
	
	void SetWasWrong(bool wrong){m_problem.wasWrong = wrong;}
	bool GetWasWrong(){return m_problem.wasWrong;}
	void InitWasWrong(){m_problem.wasWrong = false;}

	void SetAnswer(int answer){m_problem.answer = answer;}
	int GetAnswer(){return m_problem.answer;}

	void GiveProblem(int monsterIndex);

	Info GetAttackResult(AttackResult attack_result);
	void ResetPosition();

protected:
	Problem m_problem;
};

