// inclass.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "Character.h"

void TestValue1(){
	CCharacter player;
	player.SetHP(999);
	player.PrintHP();

}

void TestValue2(){
	CCharacter party[3];

	CCharacter soeun;
	CCharacter wonHyo;
	CCharacter jinsang;

	party[0] = soeun;
	party[1] = wonHyo;
	party[2] = jinsang;

	party[0].SetHP(111);
	soeun.PrintHP();

	//프로그램에서 존재하는 객체 값이 총 6개가 되

}


void Heal(CCharacter player)
{
	player.SetHP(999);

}

void TestValue3()
{
	CCharacter gunHee;
	gunHee.SetHP(1);
	Heal(gunHee); //gunhee가 들어간게 아니라, gunhee의 클론이 들어간거야. 그래서 힐이 안됨
	gunHee.PrintHP();

}

void TestPointer_1()
{
	CCharacter* pPlayer= new CCharacter();

	pPlayer->SetHP(999);
	pPlayer->PrintHP();
	
	delete pPlayer;

}
void TestPointer_2()
{
	CCharacter* pParty[3];

	CCharacter *psoeun = new CCharacter();
	CCharacter *pwonHyo= new CCharacter();
	CCharacter *pjinsang = new CCharacter();

	pParty[0] = psoeun;
	pParty[1] = pwonHyo;
	pParty[2] = pjinsang;

	pParty[0]->SetHP(111);
	psoeun->PrintHP();

	for(int i = 0 ; i < 3 ; i++)
	{
		delete pParty[i];
	}
}

void Heal(CCharacter *pPlayer)
{
	pPlayer->SetHP(999);

}
void TestPointer_3()
{
	CCharacter* pKyu = new CCharacter();

	pKyu->SetHP(1);
	pKyu->PrintHP();

	Heal(pKyu);
	pKyu->PrintHP();

	delete pKyu;

}

void CopyPointer(CCharacter **pPlayer1, CCharacter **pPlayer2)
{
	*pPlayer1 = *pPlayer2;
}
void TestPointer_4()
{
	CCharacter* pPlayer1 = new CCharacter();
	CCharacter* pPlayer2 = new CCharacter();

	pPlayer1->SetHP(10);
	pPlayer2->SetHP(20);

	pPlayer1->PrintHP();
	pPlayer2->PrintHP();

	//pPlayer1 = pPlayer2;
	
	CopyPointer(&pPlayer1, &pPlayer2);
	pPlayer1->PrintHP();
	pPlayer2->PrintHP();


	CCharacter player3;
	CCharacter* pPlayer4 = &player3;


	delete pPlayer1;
	//delete pPlayer2;//한번 해제했는데 또 해제해서 런타임 에라

}

void TestReference_1()
{
	CCharacter player;
	CCharacter& refPlayer = player;

	refPlayer.SetHP(666);
	player.PrintHP();
}

void TestValuePointer()
{
	CCharacter player; //value
	player.SetHP(888);

	CCharacter*pPlayer = &player; //value->pointer //player가 밸류기때문에 딜리트 안해줘도되
	pPlayer->PrintHP();

	CCharacter player2 = *pPlayer;//pointer->value 
	player2.PrintHP();
}




int _tmain(int argc, _TCHAR* argv[])
{
	//TestValue1();
	
	//TestValue2();
	//TestValue3();
	//TestPointer_1();
	//TestPointer_2();
	//TestPointer_3();
	//TestPointer_4();
	//TestReference_1();
	TestValuePointer();
	
	getchar();


	/*week4 
	std::string helloWorld = "Hello world!"; //이것은 문자열이 아니라 객체야 ㅋㅋㅋㅋㅋ그래서 이렇게 하면 이상하게 나온다
	//usernamespace로 std생략 할 수 있지만 현업에서는 안해						
	printf_s("%s\n", helloWorld.c_str());

	std::cout<<"hi!"<<helloWorld<<"oh"<<std::endl;
	*/
	return 0;
}

