#pragma once
class CCharacter
{
public:
	CCharacter(void);
	CCharacter(const CCharacter& src);
	~CCharacter(void);

	void SetHP( int hp ) {m_HP = hp;}
	void PrintHP();

protected:
	int m_HP;
};

