#include "stdafx.h"
#include "GameManager.h"
#include <stdio.h>
#include "Character.h"
#include <time.h>
#include <synchapi.h>

CGameManager* CGameManager::m_pInstance = nullptr;
 
CGameManager::CGameManager(void)
	:m_GameStatus(NORMAL)
{
	m_PlayerCharacter = new CPlayerCharacter;
	isRun = true;
}


CGameManager::~CGameManager(void)
{
	delete m_PlayerCharacter;
}

CGameManager* CGameManager::GetInstance()
{
	if( m_pInstance == nullptr )
		m_pInstance = new CGameManager();
	
	return m_pInstance;
}

void CGameManager::ReleaseInstance()
{
	if( m_pInstance != nullptr )
	{
		delete m_pInstance;
		m_pInstance = nullptr;
	}	
}

void CGameManager::Init()
{
	printf_s("[개발자의 말]\n");
	printf_s("본 게임은 프로그래밍의 프자도 모르는 이들이\n");
	printf_s("C언어의 기본적인 요소들을 가볍게 익힐 수 있는 게임으로\n"); 
	printf_s("개발자의 힘들었던 작년 경험을 살려 만들었습니다.\n");
	printf_s("\n");
	printf_s("(▼ 계속 보려면 엔터키를 누르세요)");
	std::cin.get();
	printf_s("\n");
	printf_s("프로그래밍 경험이 조금이라도 있다면,\n");
	printf_s("이 게임은 아마 너무 쉬울 것입니다.\n");
	printf_s("그럼에도 불구하고, 게임을 시작하시겠습니까? (y/n)\n");

	std::string strInput;
	getline(std::cin, strInput);
	printf_s("INPUT:%s\n",strInput.c_str());
	if(strInput == "y" || strInput =="Y")
	{
		printf_s("당신의 1학기가 조금이라도 나아지길 바라며..\n");
		//to look like it's on loading
		for(int i = 0 ; i < 5 ; ++i)
		{
			printf_s(".");
			Sleep(300);
		}
	}
	else if(strInput == "n" || strInput =="N")
	{
		printf_s("bye bye\n");
		Sleep(1500);
		isRun = false;
		return;
	}

	printf_s("[GAME START!]\n");

	m_PlayerCharacter->SetInfo();
	m_PlayerCharacter->PrintInfo();

	//SetNPCs();

	//StartTutorial();

	srand((unsigned int)time(NULL));
	CreateMonsters();
}

//in all questions, run is number 0 
//make it as printf_s

void CGameManager::CreateMonsters()
{
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
			//pMonster->SetIndex(0);
			pMonster->SetProblemIndex(0);
			pMonster->InitWasWrong();
			totalMonster++;
		}
		else
		{
			--i;
		}
	}
	printf_s("총 %d마리의 몬스터가 생성되었습니다.\n",totalMonster); 
	m_Map.PrintMap();
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
		m_GameStatus = BATTLE;
		BattleResult result = StartBattle(pMapInfo->pMonster);
		if(result == BATTLE_WIN){
			delete pMapInfo->pMonster;
			pMapInfo->pMonster = nullptr;
		}
		//warmth of the body printf

	}
}

BattleResult CGameManager::StartBattle(CMonster* pMonster)
{
	BattleResult battleResult = (BattleResult)NULL;
	
	//printf_s("해당 자리에 몬스터가 있습니다\n");//for debug
	
	printf_s("몬스터를 만났습니다\n");
	printf_s("문제:\n");
	if(pMonster->GetWasWrong() == false)
		pMonster->GiveProblem(m_PlayerCharacter->GetProblemCounter());
	else
		pMonster->GiveProblem(pMonster->GetProblemIndex());
	std::string str_input_answer;
	getline(std::cin,str_input_answer); //change it to int type for efficiency
	int player_answer = atoi(str_input_answer.c_str());
	//answer is in the range of 1~4
	if(player_answer==pMonster->GetAnswer()) //for easy debugging
	{
		printf_s("\n");
		printf_s("정답입니다\n");
		pMonster->GetAttackResult(ATTACK_FAIL);

		if(!pMonster->IsAlive())
		{
			printf_s("############\n");
			printf_s("몬스터가 죽었습니다\n");
			printf_s("############\n");
			battleResult = BATTLE_WIN;
		}
		/*else if(pMonster->IsAlive())
		{
			
		}*/
		
		if(pMonster->GetWasWrong() == false)
			m_PlayerCharacter->IncreaseProblemCounter();
		m_PlayerCharacter->GetAttackResult(ATTACK_SUCCESS);
	}
	/*else if( player_answer == 0 ) //run
	{
		printf_s("##########################################\n");
		printf_s("얼레리 꼴레리\n");
	
	}
	else if( player_answer == 5 ) //hint
	{
		printf_s("##########################################\n");
		printf_s("힌트 드릴까요?\n");
	}*/
	else //dealing with exceptions when user inputs are other than 0,1,2,3,4,5
	{
		printf_s("##########################################\n");
		printf_s("틀렸네요\n");
		m_PlayerCharacter->GetAttackResult(ATTACK_FAIL);
		pMonster->GetAttackResult(ATTACK_SUCCESS);
		//m_Map.SetMapInfoNullptr(pMonster->GetPosition().x, pMonster->GetPosition().y );
		//ResetPosition(pMonster);
		printf_s("해당 몬스터가 체력을 얻었습니다.\n"); //맞을때까지 다시 나온다
		
		if(!m_PlayerCharacter->IsAlive())
		{
			printf_s("############\n");
			printf_s("캐릭터가 죽었습니다. 공부를 조금 더 합시다\n");
			battleResult = BATTLE_LOSE;
		}
	}
	Sleep(1000); //to look like it's game. 
					//print lines with the term of 1 second

	m_GameStatus = NORMAL;
	return battleResult;

}

void CGameManager::Run()
{
	while(isRun && InputProc())
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
	m_Map.PrintMap();
	
	if(strInput=="q" || strInput == "Q")
	{
		printf_s("quit\n");
		return false;
	}
	return true;
}

void CGameManager::SetNPCs()
{
	
}

void CGameManager::StartTutorial()
{
	printf_s("먼저, 게임에 필요한 기본 요소를 익히고, 게임이 어떤 방식으로 진행되는지 맛보기를 해보겠습니다\n");
	printf_s("이 게임은 %d x %d 크기의 바둑판 같은 모양의 지도 위에서 진행됩니다\n", MAP_SIZE, MAP_SIZE);
	printf_s("당신의 위치는 키보드 입력이 있을때마다 출력되므로 어디있는지 외우지는 않아도 됩니다.\n");
	printf_s("먼저 상점으로 이동해 보겠습니다.\n");
	printf_s("이동은 W(위쪽), A(왼쪽), S(아래쪽), D(오른쪽)를 누르고 엔터를 누르면 됩니다.\n");
	//printf("상점 위치 : [%d, %d] \n", , );
}

void CGameManager::ResetPosition(CMonster *pMonster)
{
	int random_x, random_y;
	char buf[16];

	random_x = rand()%MAP_SIZE;
	random_y = rand()%MAP_SIZE;

	if(m_Map.GetMapInfo(random_x,random_y)->pMonster == NULL)
	{
		pMonster->SetPosition(random_x, random_y);		
		m_Map.GetMapInfo(random_x, random_y)->pMonster = pMonster;
		pMonster->SetWasWrong(true);
		pMonster->SetProblemIndex(m_PlayerCharacter->GetProblemCounter());
		printf_s("problem Counter = %d\n", m_PlayerCharacter->GetProblemCounter());
		pMonster->SetHP(2);
	}
	printf_s("해당 몬스터가 재배치 되었습니다.\n");
	printf_s("해당 몬스터를 %d번 더 만나게 됩니다.\n", pMonster->GetHP());
}
