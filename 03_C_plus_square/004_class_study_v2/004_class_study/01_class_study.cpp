// https://modoocode.com/188

#include <iostream>

// startcraft의 marine을 구성하는 class를 만들어보자
class Marine 
{
	// class가 가지는 instance를 정의
private:
	int hp;                // 마린 체력
	int coord_x, coord_y;  // 마린 위치
	int damage;            // 공격력
	bool is_dead;

	// class가 가지는 함수의 정의 ... class를 간단하게 표기하기 위해 아래와 같이 type, name, 필요로 하는 instance만 정의
	// header의 class 정의 방식
public:
	Marine();              // 기본 생성자
  
	Marine(int x, int y);  // x, y 좌표에 마린 생성
 
	int attack();                       // 데미지를 리턴한다.
	void be_attacked(int damage_earn);  // 입는 데미지
	void move(int x, int y);            // 새로운 위치
	void show_status();  // 상태를 보여준다.
};

// :: 기호를 사용하여 특정 class에 표기되어 있는 함수의 세부 내용을 기술
// 생성자를 사용하여 class를 사용하여 객체 생성 시 기본적인 instance를 가지게 함
Marine::Marine() 
{
	hp = 50;
	coord_x = coord_y = 0;
	damage = 5;
	is_dead = false;
}

// 생성자 overloading
Marine::Marine(int x, int y) 
{
	coord_x = x;
	coord_y = y;
	hp = 50;
	damage = 5;
	is_dead = false;
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
	std::cout << " *** Marine *** " << std::endl;
	std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) " << std::endl;
	std::cout << " HP : " << hp << std::endl;
}

int ain() // main() 
{
	// class를 사용하여 객체를 생성
	// 이때 2개의  int형 instance를 가지는 객체를 생성
	Marine marine1(2, 3);
	Marine marine2(3, 5);

	// class에 정의되어 있으며, 외부에 ::를 사용하여 기술되어 있는 함수를 사용
	marine1.show_status();
	marine2.show_status();

	std::cout << std::endl << "마린 1 이 마린 2 를 공격! " << std::endl;
	marine2.be_attacked(marine1.attack());

	marine1.show_status();
	marine2.show_status();
}