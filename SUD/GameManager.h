#pragma once
#include "GameMap.h"
#include "PlayerCharacter.h"

enum GameStatus
{
	NORMAL,
	BATTLE
};

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
	BattleResult StartBattle(CMonster* pMonster);
	void SetNPCs();
	void StartTutorial();

protected:
	bool isRun;
	GameStatus m_GameStatus;
	CGameMap m_Map;
	CPlayerCharacter* m_PlayerCharacter; //player character
};

