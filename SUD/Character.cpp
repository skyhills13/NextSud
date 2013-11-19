#include "stdafx.h"
#include "Character.h"
#include "GameMap.h"

//��� ������ ��ġ �����
//��ġ ����ϴ� �Լ� �����
//�׸��� ���� Ű �Է¹����� ��ġ �Žñ�

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
		//++m_position.y; //���� ������ ���� ��ȯ, ������ ��ȯ�ϰ� ��. ���� ���� �� �޸� ȿ����.. �Ѵ� ����� �Ǳ� �� 
		//m_position.y = m_position.y > 1 ? --m_position.y : m_position.y; //���� ������
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

//void CCharacter::HitCheck(AttackResult result, int damage)
//{
//	switch (result)
//	{
//	case Attack_HIT:
//		printf_s("%s�� (%d)�� ���ظ� �Ծ���", GetName().c_str(), damage);
//		m_HP -= damage;
//		break;
//	case Attack_MISS:
//		printf_s();
//		break;
//	
//
//	}
//}