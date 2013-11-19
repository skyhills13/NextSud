// inclass.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
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

	//���α׷����� �����ϴ� ��ü ���� �� 6���� ��

}


void Heal(CCharacter player)
{
	player.SetHP(999);

}

void TestValue3()
{
	CCharacter gunHee;
	gunHee.SetHP(1);
	Heal(gunHee); //gunhee�� ���� �ƴ϶�, gunhee�� Ŭ���� ���ž�. �׷��� ���� �ȵ�
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
	//delete pPlayer2;//�ѹ� �����ߴµ� �� �����ؼ� ��Ÿ�� ����

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

	CCharacter*pPlayer = &player; //value->pointer //player�� ����⶧���� ����Ʈ �����൵��
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
	std::string helloWorld = "Hello world!"; //�̰��� ���ڿ��� �ƴ϶� ��ü�� �����������׷��� �̷��� �ϸ� �̻��ϰ� ���´�
	//usernamespace�� std���� �� �� ������ ���������� ����						
	printf_s("%s\n", helloWorld.c_str());

	std::cout<<"hi!"<<helloWorld<<"oh"<<std::endl;
	*/
	return 0;
}

