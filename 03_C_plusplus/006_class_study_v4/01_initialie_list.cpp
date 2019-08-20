// https://modoocode.com/197
// initializer list

#include <iostream>

class Marine 
{
private:

	int hp;								// 마린 체력
	int coord_x, coord_y;				// 마린 위치
	int damage;							// 공격력
	bool is_dead;

public:
  
	Marine();							// 기본 생성자
	Marine(int x, int y);				// x, y 좌표에 마린 생성

	int attack();                       // 데미지를 리턴한다.
	void be_attacked(int damage_earn);  // 입는 데미지
	void move(int x, int y);            // 새로운 위치

	void show_status();					// 상태를 보여준다.
};

////////////////////////////////////////
//////// // 기존에 배웠던 생성자 함수
//////// Marine::Marine() {
////////   hp = 50;
////////   coord_x = coord_y = 0;
////////   damage = 5;
////////   is_dead = false;
//////// }
////////////////////////////////////////

// initializer list 정의 
// 생성자 호출시에 아래에 정의된 값으로 멤버 인스턴스를 초기화
// 즉, 생성과 동시에 초기화가 진행됨
Marine::Marine() 
	: hp(50), coord_x(0), coord_y(0), damage(5), is_dead(false) {}

Marine::Marine(int x, int y)
    : coord_x(x), coord_y(y), hp(50), damage(5), is_dead(false) {}

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

int main() 
{
	Marine marine1(2, 3);
	Marine marine2(3, 5);

	marine1.show_status();
	marine2.show_status();
}