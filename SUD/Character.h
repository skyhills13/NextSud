#pragma once

struct Position 
{
	int x;
	int y;
};


enum DIRECTION
{
	DIR_UP,
	DIR_DOWN,
	DIR_LEFT,
	DIR_RIGHT
};


class CCharacter
{
public:
	CCharacter(void);
	virtual ~CCharacter(void); 

	void SetPosition(Position pos){m_position = pos;}
	Position GetPosition(){return m_position;}
	void SetPosition(int x, int y);
	void PrintPosition();

	Position Move(DIRECTION dir);


	void SetName(std::string name){m_Name = name;}
	std::string GetName(){return m_Name;}

	void SetHP(int HP){m_HP = HP;}
	int GetHP(){return m_HP;}

	void SetPower(int power){m_Power = power;}
	int GetPower(){return m_Power;}

	bool IsAlive();
	//void HitCheck(AttackResult result, int damage);

protected:
	Position m_position;
	std::string m_Name;
	int m_HP;
	int m_Power;
	int m_Level;
	int m_Exp;
	std::string m_Lang;
};

