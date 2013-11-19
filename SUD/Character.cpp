#include "stdafx.h"
#include "Character.h"
#include "GameMap.h"

//멤버 변수로 위치 만들고
//위치 출력하는 함수 만들고
//그리고 각각 키 입력받으면 위치 거시기

CCharacter::CCharacter(void)
{
	m_position.x = m_position.y = 0;
}


CCharacter::~CCharacter(void)
{
}

Position CCharacter::Move(DIRECTION dir)
{
	switch(dir)
	{
	case DIR_UP:
		//++m_position.y; //전위 연산은 빼고 반환, 후위는 반환하고 빼. 앞의 것이 더 메모리 효율이.. 둘다 계산이 되긴 해 
		//m_position.y = m_position.y > 1 ? --m_position.y : m_position.y; //삼항 연산자
		m_position.y = __max(m_position.y - 1, 0);
		break;
	case DIR_DOWN:
		m_position.y = __min(m_position.y + 1, MAP_SIZE - 1 );
		break;
	case DIR_LEFT:
		m_position.x = __max(m_position.x -1, 0);
		break;
	case DIR_RIGHT:
		m_position.x = __min(m_position.x +1, MAP_SIZE -1);
		break;
	}
	
	return m_position;
}


//overriding
void CCharacter::SetPosition(int x, int y)
{
	Position pos;
	pos.x = x;
	pos.y = y;
	SetPosition(pos);
}


void CCharacter::PrintPosition()
{
	printf_s("position : [%d, %d] \n", m_position.x, m_position.y);	
}

void CCharacter::HitCheck(AttackResult result, int damage)
{
	switch (result)
	{
	case Attack_HIT:
		printf_s("%s가 (%d)의 피해를 입었다", GetName().c_str(), damage);
		m_HP -= damage;
		break;
	case Attack_MISS:
		printf_s();
		break;
	

	}
}