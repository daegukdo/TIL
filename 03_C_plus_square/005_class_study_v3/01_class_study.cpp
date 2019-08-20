// https://modoocode.com/188

#include <string.h>
#include <iostream>

class Marine 
{
private:
	int hp;                // 마린 체력
	int coord_x, coord_y;  // 마린 위치
	int damage;            // 공격력
	bool is_dead;
	char* name;			   // 마린 이름 ... 포인터

public:
	Marine();                                       // 기본 생성자
	Marine(int x, int y, const char* marine_name);  // 이름까지 지정
	Marine(int x, int y);							// x, y 좌표에 마린 생성
	~Marine();										// 소멸자

	int attack();                       // 데미지를 리턴한다.
	void be_attacked(int damage_earn);  // 입는 데미지
	void move(int x, int y);            // 새로운 위치

	void show_status();					// 상태를 보여준다.
};

Marine::Marine() 
{
	hp = 50;
	coord_x = coord_y = 0;
	damage = 5;
	is_dead = false;
	name = NULL;
}

Marine::Marine(int x, int y, const char* marine_name) 
{
	// 동적 할당 ... 이를 소멸시키지 않으면 장기적으로 메모리 누수가 발생
	name = new char[strlen(marine_name) + 1];
	strcpy(name, marine_name);

	coord_x = x;
	coord_y = y;
	hp = 50;
	damage = 5;
	is_dead = false;
}

Marine::Marine(int x, int y)
{
	coord_x = x;
	coord_y = y;
	hp = 50;
	damage = 5;
	is_dead = false;
	name = NULL;
}

// 소멸자 ... 소멸자는 instance를 받지 않으며 overloading되지 않음
Marine::~Marine() 
{
	std::cout << name << " 의 소멸자 호출 ! " << std::endl;

	if (name != NULL) 
	{
		delete[] name;
	}
}

void Marine::move(int x, int y) 
{
	coord_x = x;
	coord_y = y;
}

int Marine::attack() 
{
	return damage; 
}

void Marine::be_attacked(int damage_earn) 
{
	hp -= damage_earn;
	if (hp <= 0) is_dead = true;
}

void Marine::show_status()
{
	std::cout << " *** Marine : " << name << " ***" << std::endl;
	std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) " << std::endl;
	std::cout << " HP : " << hp << std::endl;
}

int ain() // main() 
{
	Marine* marines[100];

	marines[0] = new Marine(2, 3, "Marine 2");
	marines[1] = new Marine(1, 5, "Marine 1");

	// 배열의 메소드 사용은 ->
	marines[0]->show_status();
	marines[1]->show_status();

	std::cout << std::endl << "마린 1 이 마린 2 를 공격! " << std::endl;

	marines[0]->be_attacked(marines[1]->attack());

	marines[0]->show_status();
	marines[1]->show_status();

	// 객체가 파괴되면 ~소멸자를 호출
	delete marines[0];
	delete marines[1];

	return 0;
}