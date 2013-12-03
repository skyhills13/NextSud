#include "stdafx.h"
#include "GameManager.h"
#include <stdio.h>
#include "Character.h"
#include <time.h>
#include <synchapi.h>

//array for lang
std::string question[25] = {
	"프로그래밍 언어에서 마침표 역할을 하는 것은?\n",
	"4byte 짜리 숫자 자료형은?\n",
	"다음 중 visual studio와 비슷한 역할을 하는것이 아닌것은?\n",
	"프로그래밍 언어에서 마침표 역할을 하는 것은?\n",
	"4byte 짜리 숫자 자료형은?\n",
	"다음 중 visual studio와 비슷한 역할을 하는것이 아닌것은?\n",
	"프로그래밍 언어에서 마침표 역할을 하는 것은?\n",
	"4byte 짜리 숫자 자료형은?\n",
	"다음 중 visual studio와 비슷한 역할을 하는것이 아닌것은?\n",
	"프로그래밍 언어에서 마침표 역할을 하는 것은?\n",
	"4byte 짜리 숫자 자료형은?\n",
	"다음 중 visual studio와 비슷한 역할을 하는것이 아닌것은?\n",
	"프로그래밍 언어에서 마침표 역할을 하는 것은?\n",
	"4byte 짜리 숫자 자료형은?\n",
	"다음 중 visual studio와 비슷한 역할을 하는것이 아닌것은?\n",
	"프로그래밍 언어에서 마침표 역할을 하는 것은?\n",
	"4byte 짜리 숫자 자료형은?\n",
	"다음 중 visual studio와 비슷한 역할을 하는것이 아닌것은?\n",
	"프로그래밍 언어에서 마침표 역할을 하는 것은?\n",
	"4byte 짜리 숫자 자료형은?\n",
	"다음 중 visual studio와 비슷한 역할을 하는것이 아닌것은?\n",
	"프로그래밍 언어에서 마침표 역할을 하는 것은?\n",
	"4byte 짜리 숫자 자료형은?\n",
	"다음 중 visual studio와 비슷한 역할을 하는것이 아닌것은?\n",
	"다음 중 visual studio와 비슷한 역할을 하는것이 아닌것은?\n",
};
std::string options[25]= { 
	"(1) ; \n(2) : \n(3) . \n(4) / \n(5) 모르겠다 \n",//make for loop for number 5 option
	"(1) char \n(2) short \n(3) int \n(4) long \n(5) 모르겠다 \n",
	"(1) eclipse \n(2) virtualbox \n(3) sublime text \n(4) xcode \n(5) 모르겠다\n",
	"(1) ; \n(2) : \n(3) . \n(4) / \n(5) 모르겠다 \n",
	"(1) char \n(2) short \n(3) int \n(4) long \n(5) 모르겠다 \n",
	"(1) eclipse \n(2) virtualbox \n(3) sublime text \n(4) xcode \n(5) 모르겠다\n",
	"(1) ; \n(2) : \n(3) . \n(4) / \n(5) 모르겠다 \n",
	"(1) char \n(2) short \n(3) int \n(4) long \n(5) 모르겠다 \n",
	"(1) eclipse \n(2) virtualbox \n(3) sublime text \n(4) xcode \n(5) 모르겠다\n",
	"(1) ; \n(2) : \n(3) . \n(4) / \n(5) 모르겠다 \n",
	"(1) char \n(2) short \n(3) int \n(4) long \n(5) 모르겠다 \n",
	"(1) eclipse \n(2) virtualbox \n(3) sublime text \n(4) xcode \n(5) 모르겠다\n",
	"(1) ; \n(2) : \n(3) . \n(4) / \n(5) 모르겠다 \n",
	"(1) char \n(2) short \n(3) int \n(4) long \n(5) 모르겠다 \n",
	"(1) eclipse \n(2) virtualbox \n(3) sublime text \n(4) xcode \n(5) 모르겠다\n",
	"(1) ; \n(2) : \n(3) . \n(4) / \n(5) 모르겠다 \n",
	"(1) char \n(2) short \n(3) int \n(4) long \n(5) 모르겠다 \n",
	"(1) eclipse \n(2) virtualbox \n(3) sublime text \n(4) xcode \n(5) 모르겠다\n",
	"(1) ; \n(2) : \n(3) . \n(4) / \n(5) 모르겠다 \n",
	"(1) char \n(2) short \n(3) int \n(4) long \n(5) 모르겠다 \n",
	"(1) eclipse \n(2) virtualbox \n(3) sublime text \n(4) xcode \n(5) 모르겠다\n",
	"(1) ; \n(2) : \n(3) . \n(4) / \n(5) 모르겠다 \n",
	"(1) char \n(2) short \n(3) int \n(4) long \n(5) 모르겠다 \n",
	"(1) eclipse \n(2) virtualbox \n(3) sublime text \n(4) xcode \n(5) 모르겠다\n",
	"(1) eclipse \n(2) virtualbox \n(3) sublime text \n(4) xcode \n(5) 모르겠다\n"
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
	printf_s("총 %d마리의 몬스터가 생성되었습니다.\n",totalMonster); 

}

//!!!!!!!!!!!!!!!!!!!!!compare to previous source code of mine!!!!!!!!!!!!!!!!!!!
void CGameManager::CheckMap()
{

	Position currentPosition  = m_PlayerCharacter->GetPosition();
	MapInfo* pMapInfo = m_Map.GetMapInfo(currentPosition.x, currentPosition.y);
	if(!pMapInfo)
		return;

	if(pMapInfo->pMonster && pMapInfo -> pMonster -> IsAlive())
	//if(pMapInfo->pMonster)
	{
		StartBattle(pMapInfo->pMonster);
		//BattleResult result =StartBattle();
		//warmth of the body printf

	}
}

void CGameManager::StartBattle(CMonster* pMonster)
{
	//BattleResult battleResult;
	
	//CMonster* pMonster to pMapInfo
	//delete pMapInfo->pMonster;
	//pMapInfo -> pMonster = nullptr;

	printf_s("해당 자리에 몬스터가 있(었)습니다\n");//for debug
	while(m_PlayerCharacter->IsAlive() && pMonster->IsAlive())
	{
		
		printf_s("몬스터를 만났습니다\n");
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
			printf_s("정답입니다\n");
			printf_s("############\n");

			// agebreak : Attacked는 공격을 당했을때 호출 해야 합니다. 논리적으로 맞지 않습니다. 개선이 필요해 보입니다.
			m_PlayerCharacter->Attacked(ATTACK_SUCCESS);
			pMonster->Attacked(ATTACK_FAIL);
		}
		else if( player_answer == 0 ) 
		{
			printf_s("############\n");
			printf_s("얼레리 꼴레리\n");
			printf_s("############\n");	
		}
		else if( player_answer == 5 )
		{
			printf_s("############\n");
			printf_s("힌트 줄까?\n");
			printf_s("############\n");
		}
		else //exception처리 6,7,8,9 눌렀을때
		{
			printf_s("############\n");
			printf_s("틀렸어\n");
			printf_s("############\n");
			m_PlayerCharacter->Attacked(ATTACK_FAIL);
			pMonster->Attacked(ATTACK_SUCCESS);
		}

		if(!m_PlayerCharacter->IsAlive())
		{
			printf_s("############\n");
			printf_s("캐릭터가 죽었습니다. 공부를 조금 더 합시다\n");
			printf_s("############\n");
		}

		if(!pMonster->IsAlive())
		{
			printf_s("############\n");
			printf_s("몬스터가 죽었습니다\n");
			printf_s("############\n");
			//battleResult = BATTLE_WIN;
		}

		Sleep(1000); //why? to look like it's game. 
					//print lines with the term of 1 second
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
	//키보드 입력을 받아서 
	//커맨드를 파싱하고 실행한다.
	//q를 입력받으면 종료된다
	
	std::string strInput;
	/*
	char quitKey1 = 'q';
	char quitKey2 = 'Q';*/
	printf_s("원하는 키를 입력하세요\n");
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