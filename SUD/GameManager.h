#pragma once
#include "GameMap.h"
#include "PlayerCharacter.h"


enum BattleResult
{
	BATTLE_WIN,
	BATTLE_LOSE
};

class CGameManager
{
public:
	CGameManager(void);
	~CGameManager(void);

	void Init(); 
	void Run();
	void Release();

protected:
	bool InputProc(); //keyboard input 
	void CreateMonsters();
	void CheckMap();
	void StartBattle(CMonster* pMonster);
	//void MakeProblemSet();

protected:
	CGameMap m_Map;

	CPlayerCharacter* m_PlayerCharacter; //player character
};

