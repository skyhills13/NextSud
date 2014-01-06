#include "stdafx.h"
#include "GameMap.h"
#include "GameManager.h"

// 커밋 테스트용


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

void CGameMap::PrintMap()
{
	int character_x = CGameManager::GetInstance()->GetPlayerCharacter()->GetPosition().x;
	int character_y = CGameManager::GetInstance()->GetPlayerCharacter()->GetPosition().y;

	for(int j = 0; j < MAP_SIZE; ++j)
	{
		for(int i = 0; i < MAP_SIZE ; ++i)
		{
			if(i == character_x && j == character_y)
				printf_s("0 ");
			else
				printf_s("X ");
			/*if(m_MapInfo[i][j].pMonster != nullptr)
				if(m_MapInfo[i][j].pMonster->GetWasWrong())
					printf_s("%d ",m_MapInfo[i][j].pMonster->GetProblemIndex());
				else
					printf_s("Y ");
			else
				printf_s("N ");
				*/
		}
		printf_s("\n");
	}
}

void CGameMap::SetMapInfoNullptr( int x, int y )
{
	delete m_MapInfo[x][y].pMonster;
	m_MapInfo[x][y].pMonster = nullptr;
}

