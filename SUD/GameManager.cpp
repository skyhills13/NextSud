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
	srand((unsigned int)time(NULL));
	CreateMonsters();

	/*
	Position pos;
	pos.x = 5;
	pos.y = 5;
	m_PlayerCharacter->SetPosition(pos);
	*/
	m_PlayerCharacter->SetInfo();
	m_PlayerCharacter->SetPosition(5,5);
	m_PlayerCharacter->PrintInfo();
	m_PlayerCharacter->PrintPosition(); // ����Ʈ ���� ������ ������ �ּ� ó���� �� 

}

void CGameManager::CreateMonsters()
{
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

			printf_s("Monster Name: %s   " , pMonster->GetName().c_str()); 
			pMonster->PrintPosition();
			
			totalMonster++;
		}

		else
		{
			--i;
		}
	}
	/*
	CMonster* pMonster = new CMonster;
	pMonster->SetName("monster1");
	m_Map.GetMapInfo(2,3)->pMonster = pMonster;
	*/

	printf_s("�� %d������ ���Ͱ� �����Ǿ����ϴ�.\n",totalMonster); 

}

void CGameManager::CheckMap()
{
	Position currentPosition  = m_PlayerCharacter->GetPosition;
	if(m_Map.GetMapInfo(currentPosition.x,currentPosition.y)->pMonster != NULL)
	{		
		StartBattle(m_Map.GetMapInfo(currentPosition.x,currentPosition.y)->pMonster);
		//�����ϰ� ��ĥ��
	}
}

void CGameManager::StartBattle(CMonster* pMonster)
{
	
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
