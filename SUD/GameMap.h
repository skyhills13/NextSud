#pragma once
#define MAP_SIZE 10
#include "Monster.h"



struct MapInfo
{
	CMonster* pMonster;
};

class CGameMap
{
public:
	CGameMap(void);
	~CGameMap(void);

	MapInfo* GetMapInfo(int x, int y);

protected:
	MapInfo m_MapInfo[MAP_SIZE][MAP_SIZE];
};

