#include "stdafx.h"
#include "GameManager.h"
#include <stdio.h>
#include "Character.h"
#include <time.h>



CGameManager::CGameManager(void)
{
	m_PlayerCharacter = new CPlayerCharacter;
}


CGameManager::~CGameManager(void)
{
	delete m_PlayerCharacter;
}

void CGameManager::Init()
{
	printf("[GAME START!]\n");

	m_PlayerCharacter->SetInfo();
	m_PlayerCharacter->PrintInfo();

	srand((unsigned int)time(NULL));
	CreateMonsters();

}
//string CGameManager::problemSet(int index)
//{
//	std::string a[25] ={ qwd}
//	return a[index];
//}
void CGameManager::CreateMonsters()
{
// 	std::string a[25] ={ "����1", };
// 	int b[25] ={2, };
	/*
	for( int i = 0; i < 5 ; ++i)
	{
		printf_s("RAND: %d\n",rand());
	}*/
	int random_x, random_y;
	int maxMonster = MAP_SIZE*MAP_SIZE/4;
	int totalMonster=0;
	char buf[16];
	
	
	for (int i = 0; i < maxMonster; ++i)
	{
		random_x = rand()%MAP_SIZE;
		random_y = rand()%MAP_SIZE;

		
		if(m_Map.GetMapInfo(random_x,random_y)->pMonster == NULL)
		{
			CMonster* pMonster = new CMonster();
		
			sprintf_s(buf, "monster %d", i);
			std::string monsterName = buf;
			pMonster->SetName(monsterName);

			pMonster->SetPosition(random_x, random_y);		
			
			m_Map.GetMapInfo(random_x, random_y)->pMonster = pMonster;
			//pMonster->m_a = a[i] 
			//pMonster->m_a = this->problemSet(i);
			//pMonster->aa();
			
			//for debugging 
			/*printf_s("Monster Name: %s   " , pMonster->GetName().c_str()); 
			pMonster->PrintPosition();*/
			
			totalMonster++;
		}

		else
		{
			--i;
		}
	}
	printf_s("�� %d������ ���Ͱ� �����Ǿ����ϴ�.\n",totalMonster); 

}

//!!!!!!!!!!!!!!!!!!!!!compare to previous source code of mine!!!!!!!!!!!!!!!!!!!
void CGameManager::CheckMap()
{
	Position currentPosition  = m_PlayerCharacter->GetPosition();
	MapInfo* pMapInfo = m_Map.GetMapInfo(currentPosition.x, currentPosition.y);
	if(!pMapInfo)
		return;

	if(pMapInfo->pMonster)
	{		
		StartBattle(pMapInfo->pMonster);
	}
}

void CGameManager::StartBattle(CMonster* pMonster)
{
	printf_s("�ش� �ڸ��� ���Ͱ� ��(��)���ϴ�\n");
	while(m_PlayerCharacter->IsAlive() && pMonster->IsAlive())
	{
		printf_s("���͸� �������ϴ�\n");
		pMonster->GiveProblem();
	}

}

void CGameManager::Run()
{
	while(InputProc())
	{
		CheckMap();
	}
}

void CGameManager::Release()
{

}


bool CGameManager::InputProc()
{
	//Ű���� �Է��� �޾Ƽ� 
	//Ŀ�ǵ带 �Ľ��ϰ� �����Ѵ�.
	//q�� �Է¹����� ����ȴ�
	
	std::string strInput;
	/*
	char quitKey1 = 'q';
	char quitKey2 = 'Q';*/
	printf_s("���ϴ� Ű�� �Է��ϼ���\n");
	getline(std::cin, strInput);
	printf_s("INPUT:%s\n",strInput.c_str());
	

	if(strInput == "w" || strInput =="W")
	{
		m_PlayerCharacter->Move(DIR_UP);
	}
	else if(strInput == "S" || strInput =="s")
	{
		m_PlayerCharacter->Move(DIR_DOWN);
	}
	else if(strInput == "a" || strInput =="A")
	{
		m_PlayerCharacter->Move(DIR_LEFT);
	}
	else if(strInput == "d" || strInput =="D")
	{
		m_PlayerCharacter->Move(DIR_RIGHT);
	}

	m_PlayerCharacter->PrintPosition();
	
	if(strInput=="q" || strInput == "Q")
	{
		printf_s("quit\n");
		return false;
	}


	return true;
}