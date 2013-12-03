#pragma once
#define TOTAL_EXP 25
#define LEVELUP_EXP 5 // level up every 5 exp to 

struct Position 
{
	int x;
	int y;
};

//when refactoring
//set this structure in the playercharacter class
struct Info
{
	std::string name;
	std::string lang;
	int hp;
	int level;
	int current_exp;
	int total_exp;

};


enum DIRECTION
{
	DIR_UP,
	DIR_DOWN,
	DIR_LEFT,
	DIR_RIGHT
};

enum AttackResult
{
	ATTACK_SUCCESS,
	ATTACK_FAIL,
	DEFENSE,
	RUN
};

class CCharacter
{
public:
	CCharacter(void);
	virtual ~CCharacter(void); 

	void SetPosition(Position pos){m_position = pos;}
	void InitPosition();
	Position GetPosition(){return m_position;}
	void SetPosition(int x, int y);
	void PrintPosition();

	Position Move(DIRECTION dir);


	void SetName(std::string name){m_info.name = name;}
	std::string GetName(){return m_info.name;}

	void SetLang(std::string lang){m_info.lang = lang;}
	std::string GetLang(){return m_info.lang;}

	void SetHP(int HP){m_info.hp = HP;}

	int GetHP(){return m_info.hp;}

	void SetLevel(int level){m_info.level = level;}
	void InitLevel(){m_info.level = 1;}
	int GetLevel(){return m_info.level;}

	//monster does not have experience point. How should I make it better?
	void SetExp(int exp){m_info.current_exp = exp;}
	void InitExp();
	int GetExp(){return m_info.current_exp;}

	bool IsAlive(){return m_info.hp > 0;}

	//what is it for?
	//virtual void aa();

	virtual Info Attacked(AttackResult attack_result);

protected:
	Position m_position;
	Info m_info;

};

