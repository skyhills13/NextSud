#include "stdafx.h"
#include "GameManager.h"
#include <stdio.h>
#include "Character.h"
#include <time.h>
#include <synchapi.h>

//array for lang
std::string question[25] = {
	"���α׷��� ���� ��ħǥ ������ �ϴ� ����?\n",
	"4byte ¥�� ���� �ڷ�����?\n",
	"���� �� visual studio�� ����� ������ �ϴ°��� �ƴѰ���?\n",
	"���α׷��� ���� ��ħǥ ������ �ϴ� ����?\n",
	"4byte ¥�� ���� �ڷ�����?\n",
	"���� �� visual studio�� ����� ������ �ϴ°��� �ƴѰ���?\n",
	"���α׷��� ���� ��ħǥ ������ �ϴ� ����?\n",
	"4byte ¥�� ���� �ڷ�����?\n",
	"���� �� visual studio�� ����� ������ �ϴ°��� �ƴѰ���?\n",
	"���α׷��� ���� ��ħǥ ������ �ϴ� ����?\n",
	"4byte ¥�� ���� �ڷ�����?\n",
	"���� �� visual studio�� ����� ������ �ϴ°��� �ƴѰ���?\n",
	"���α׷��� ���� ��ħǥ ������ �ϴ� ����?\n",
	"4byte ¥�� ���� �ڷ�����?\n",
	"���� �� visual studio�� ����� ������ �ϴ°��� �ƴѰ���?\n",
	"���α׷��� ���� ��ħǥ ������ �ϴ� ����?\n",
	"4byte ¥�� ���� �ڷ�����?\n",
	"���� �� visual studio�� ����� ������ �ϴ°��� �ƴѰ���?\n",
	"���α׷��� ���� ��ħǥ ������ �ϴ� ����?\n",
	"4byte ¥�� ���� �ڷ�����?\n",
	"���� �� visual studio�� ����� ������ �ϴ°��� �ƴѰ���?\n",
	"���α׷��� ���� ��ħǥ ������ �ϴ� ����?\n",
	"4byte ¥�� ���� �ڷ�����?\n",
	"���� �� visual studio�� ����� ������ �ϴ°��� �ƴѰ���?\n",
	"���� �� visual studio�� ����� ������ �ϴ°��� �ƴѰ���?\n",
};
std::string options[25]= { 
	"(1) ; \n(2) : \n(3) . \n(4) / \n(5) �𸣰ڴ� \n",//make for loop for number 5 option
	"(1) char \n(2) short \n(3) int \n(4) long \n(5) �𸣰ڴ� \n",
	"(1) eclipse \n(2) virtualbox \n(3) sublime text \n(4) xcode \n(5) �𸣰ڴ�\n",
	"(1) ; \n(2) : \n(3) . \n(4) / \n(5) �𸣰ڴ� \n",
	"(1) char \n(2) short \n(3) int \n(4) long \n(5) �𸣰ڴ� \n",
	"(1) eclipse \n(2) virtualbox \n(3) sublime text \n(4) xcode \n(5) �𸣰ڴ�\n",
	"(1) ; \n(2) : \n(3) . \n(4) / \n(5) �𸣰ڴ� \n",
	"(1) char \n(2) short \n(3) int \n(4) long \n(5) �𸣰ڴ� \n",
	"(1) eclipse \n(2) virtualbox \n(3) sublime text \n(4) xcode \n(5) �𸣰ڴ�\n",
	"(1) ; \n(2) : \n(3) . \n(4) / \n(5) �𸣰ڴ� \n",
	"(1) char \n(2) short \n(3) int \n(4) long \n(5) �𸣰ڴ� \n",
	"(1) eclipse \n(2) virtualbox \n(3) sublime text \n(4) xcode \n(5) �𸣰ڴ�\n",
	"(1) ; \n(2) : \n(3) . \n(4) / \n(5) �𸣰ڴ� \n",
	"(1) char \n(2) short \n(3) int \n(4) long \n(5) �𸣰ڴ� \n",
	"(1) eclipse \n(2) virtualbox \n(3) sublime text \n(4) xcode \n(5) �𸣰ڴ�\n",
	"(1) ; \n(2) : \n(3) . \n(4) / \n(5) �𸣰ڴ� \n",
	"(1) char \n(2) short \n(3) int \n(4) long \n(5) �𸣰ڴ� \n",
	"(1) eclipse \n(2) virtualbox \n(3) sublime text \n(4) xcode \n(5) �𸣰ڴ�\n",
	"(1) ; \n(2) : \n(3) . \n(4) / \n(5) �𸣰ڴ� \n",
	"(1) char \n(2) short \n(3) int \n(4) long \n(5) �𸣰ڴ� \n",
	"(1) eclipse \n(2) virtualbox \n(3) sublime text \n(4) xcode \n(5) �𸣰ڴ�\n",
	"(1) ; \n(2) : \n(3) . \n(4) / \n(5) �𸣰ڴ� \n",
	"(1) char \n(2) short \n(3) int \n(4) long \n(5) �𸣰ڴ� \n",
	"(1) eclipse \n(2) virtualbox \n(3) sublime text \n(4) xcode \n(5) �𸣰ڴ�\n",
	"(1) eclipse \n(2) virtualbox \n(3) sublime text \n(4) xcode \n(5) �𸣰ڴ�\n"
};


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

//in all questions, run is number 0 
//make it as printf_s
//void CGameManager::MakeProblemSet()
//{

//}

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
			
			pMonster->InitHP();
			pMonster->SetIndex(i);
			pMonster->SetQuestion(question[i]);
			pMonster->SetOptions(options[i]);
			pMonster->SetAnswer(1);
			
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
	printf_s("�ش� �ڸ��� ���Ͱ� ��(��)���ϴ�\n");//for debug
	while(m_PlayerCharacter->IsAlive() && pMonster->IsAlive())
	{
		
		printf_s("���͸� �������ϴ�\n");
		pMonster->GiveProblem();
		std::string str_input_answer;
		getline(std::cin,str_input_answer); //change it to int type for efficiency
		int player_answer = atoi(str_input_answer.c_str());

		//answer is in the range of 1~4
		/*for easiness, mapping answer with question index, which is, monster index.
		if(((pMonster->GetIndex())% 4)+1 == atoi(input_answer.c_str()))*/
		if(player_answer==1) //for easy debugging
		{
			printf_s("############\n");
			printf_s("�����Դϴ�\n");
			printf_s("############\n");
			m_PlayerCharacter->Attacked(ATTACK_SUCCESS);
			pMonster->Attacked(ATTACK_FAIL);
		}
		else if( player_answer == 0 ) 
		{
			printf_s("############\n");
			printf_s("�󷹸� �÷���\n");
			printf_s("############\n");	
		}
		else if( player_answer == 5 )
		{
			printf_s("############\n");
			printf_s("��Ʈ �ٱ�?\n");
			printf_s("############\n");
		}
		else //exceptionó�� 6,7,8,9 ��������
		{
			printf_s("############\n");
			printf_s("Ʋ�Ⱦ�\n");
			printf_s("############\n");
			m_PlayerCharacter->Attacked(ATTACK_FAIL);
			pMonster->Attacked(ATTACK_SUCCESS);
		}

		if(!m_PlayerCharacter->IsAlive())
		{
			printf_s("############\n");
			printf_s("ĳ���Ͱ� �׾����ϴ�. ���θ� ���� �� �սô�\n");
			printf_s("############\n");
		}

		if(!pMonster->IsAlive())
		{
			printf_s("############\n");
			printf_s("���Ͱ� �׾����ϴ�\n");
			printf_s("############\n");
		}

		Sleep(1000); //why?
	}
	
	printf_s("============================================\n");
	printf_s("============================================\n");
	printf_s("[HP : %d ] \n", m_PlayerCharacter->GetHP());
	printf_s("[level : %d ] \n", m_PlayerCharacter->GetLevel());
//	printf_s("[exp : %d / %d ] \n", m_PlayerCharacter->GetExp(), m_PlayerCharacter->m_info);
	printf_s("[exp : %d ] \n", m_PlayerCharacter->GetExp());

	printf_s("============================================\n");
	printf_s("============================================\n");
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