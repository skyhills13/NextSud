#pragma once
#include "GameMap.h"
#include "PlayerCharacter.h"

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

protected:
	CGameMap m_Map;

	CPlayerCharacter* m_PlayerCharacter; //player character
};

