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
private:
	static CGameManager* m_pInstance;

	CGameManager(void);
	virtual ~CGameManager(void);

public:
	static CGameManager* GetInstance();
	static void ReleaseInstance();

public:
	void Init(); 
	void Run();
	void Release();

	CPlayerCharacter* GetPlayerCharacter() {return m_PlayerCharacter;}

protected:
	bool InputProc(); //keyboard input 
	void CreateMonsters();
	void CheckMap();
	BattleResult StartBattle(CMonster* pMonster);
	void SetNPCs();
	void StartTutorial();
	void ResetPosition( CMonster* pMonster );
protected:
	bool isRun;
	GameStatus m_GameStatus;
	CGameMap m_Map;
	CPlayerCharacter* m_PlayerCharacter; //player character
};

