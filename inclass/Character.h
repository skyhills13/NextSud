#pragma once
class CCharacter
{
public:
	CCharacter(void);
	CCharacter(const CCharacter& src);
	virtual ~CCharacter(void);

	void SetHP( int hp ) {m_HP = hp;}
	void PrintHP();

	virtual void PrintType();

protected:
	int m_HP;
};

