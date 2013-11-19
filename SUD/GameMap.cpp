#include "stdafx.h"
#include "GameMap.h"


//#define ZERO_MEMORY(mem, size) memset(mem, 0, size)

MapInfo mapInfo;

CGameMap::CGameMap(void)
{
	memset(m_MapInfo, 0, sizeof(m_MapInfo));
	//ZERO_MEMORY(m_MapInfo, sizeof(m_MapInfo);
}


CGameMap::~CGameMap(void)
{
	for(int i = 0; i < MAP_SIZE ; ++i)
	{
		for(int j = 0; j < MAP_SIZE; ++j)
		{
			delete m_MapInfo[i][j].pMonster;
			m_MapInfo[i][j].pMonster = nullptr;
		}
	}
}

MapInfo* CGameMap::GetMapInfo(int x, int y)
{
	//return &m_MapInfo[x][y]; //왜 reference로 받았냐. 조작하려고. value로 받으면 맵인포를 바꾸면 바뀌었다가 원래대로 돌아와
	if(x < 0 || x >= MAP_SIZE || y < 0 || y >= MAP_SIZE)
		return nullptr;

	return &m_MapInfo[x][y];

}

