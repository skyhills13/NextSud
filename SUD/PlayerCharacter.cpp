#include "stdafx.h"
#include "PlayerCharacter.h"


CPlayerCharacter::CPlayerCharacter(void)
{
	
}


CPlayerCharacter::~CPlayerCharacter(void)
{
}

void CPlayerCharacter::SetInfo()
{
	printf_s("캐릭터 별명을 입력하세요\n");
	std::string str_alias;
	getline(std::cin, str_alias);
	SetName(str_alias);

	printf_s("다음 중 플레이할 언어 입력하세요 \n"); 
	printf_s("1) C  2) JAVA  3) Python \n");
	/*later about language
	1. input by number
	2. put language information by string just like now
	###more importantly### 
	3. divide problem set by number 
	4. create monsters by this input number*/
	std::string str_language;
	getline(std::cin, str_language);
	SetLang(str_language);
	InitPosition();
	InitLevel();
	InitExp();
	InitHP();
	
}

void CPlayerCharacter::PrintInfo()
{
	printf_s("============================================\n");
	printf_s("============================================\n");
	printf_s("[alias : %s ] \n",m_info.name.c_str());
	printf_s("[languae : %s ] \n", m_info.lang.c_str());
	printf_s("[HP : %d ] \n", m_info.hp);
	printf_s("[level : %d ] \n", m_info.level);
	printf_s("[exp : %d / %d ] \n", m_info.current_exp, m_info.total_exp);
	PrintPosition();
	printf_s("============================================\n");
	printf_s("============================================\n");
	
}

void CPlayerCharacter::CheckLevel(int current_exp)
{
	if(current_exp % LEVELUP_EXP == 0 )
	{
		++m_info.level;
		printf_s("!!CONGRATULATIONS, LEVEL UP!!");
	}
	else
	{
		printf_s("============================================\n");
		printf_s("============================================\n");
		printf_s("[level : %d ] \n", m_info.level);
		printf_s("[exp : %d / %d ] \n", m_info.current_exp, m_info.total_exp);
		printf_s("(%d exp) to level up\n", 5-(current_exp % 5));
		printf_s("============================================\n");
		printf_s("============================================\n");
	}
}

//1.should this return type be Info? why can't it be just void
//1. why it has an error when I declare it on character.h
// agebreak : character.h 에 선언해도 상관 없습니다. 선언부를 구현해 두었습니다. 참고하시기 바랍니다.
Info CPlayerCharacter::Attacked( AttackResult attack_result)
{
	switch(attack_result)
	{
	case ATTACK_SUCCESS:
	++m_info.current_exp;
	CheckLevel(m_info.current_exp);

	//make planned attributes
	case ATTACK_FAIL:
	break;

	case DEFENSE:
	break;

	case RUN:
	break;
	}
	
	return m_info;

}



