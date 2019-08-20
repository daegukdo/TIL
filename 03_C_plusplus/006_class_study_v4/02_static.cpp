// https://modoocode.com/197
// static variable

#include <iostream>

class Marine_Fake
{
private:
	static int total_marine_num;				// class 내에 딱 한개 !
};

class Marine 
{
private:

	// 모든 멤버 변수는 class 내에서 초기화가 불가능
	// const static인 경우는 가능
	static int total_marine_num;				// 전체 마린 숫자를 알기 위한 static 변수 ... class 내에서 딱 한개!

	int hp;										// 마린 체력
	int coord_x, coord_y;						// 마린 위치
	bool is_dead;

	const int default_damage;					// 기본 공격력

public:
  
	// static 함수도 정의 가능 ... 모든 class에서 딱 하나 있는 함수
	Marine();									// 기본 생성자
	Marine(int x, int y);						// x, y 좌표에 마린 생성
	Marine(int x, int y, int default_damage);	// initializer list를 사용한 생성자

	int attack();								// 데미지를 리턴한다.
	void be_attacked(int damage_earn);			// 입는 데미지
	void move(int x, int y);					// 새로운 위치

	void show_status();							// 상태를 보여준다.
	static void show_total_marine();			// static 함수 ... 객체 없이도 사용할 수 있음

	~Marine() { total_marine_num--; }			// 소멸자 정의
};

// static은 정의와 동시에 0으로 초기화
int Marine::total_marine_num = 0;

// static 함수의 내용을 기술 ... 객체 생성 없이 사용이 가능
// (클래스)::(static 함수) 형식으로 호출
// 또한 객체 없이 사용이 가능하기 때문에 객체가 생성될 때 값이 정의되는 멤버 변수는 static 함수에서 사용이 불가능
// 즉, static 함수에서는 static 변수만 사용이 가능
void Marine::show_total_marine() 
{
	std::cout << "전체 마린 수 : " << total_marine_num << std::endl;
}

// initializer list 정의 
// 생성자 호출시에 아래에 정의된 값으로 멤버 인스턴스를 초기화
// 즉, 생성과 동시에 초기화가 진행됨
Marine::Marine() 
	: hp(50), coord_x(0), coord_y(0), default_damage(5), is_dead(false) 
{
	total_marine_num++;
}

Marine::Marine(int x, int y)
    : coord_x(x), coord_y(y), hp(50), default_damage(5), is_dead(false)
{
	total_marine_num++;
}

Marine::Marine(int x, int y, int default_damage)
    : coord_x(x),
      coord_y(y),
      hp(50),
      default_damage(default_damage),
      is_dead(false) {total_marine_num++;}

void Marine::move(int x, int y) 
{
	coord_x = x;
	coord_y = y;
}

int Marine::attack() 
{ 
	return default_damage; 
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
	std::cout << " 현재 총 마린 수 : " << total_marine_num << std::endl;
}

void create_marine() 
{
	Marine marine3(10, 10, 4);
	// marine3.show_status();
	Marine::show_total_marine();
}

int main() 
{
	Marine marine1(2, 3, 5);
	// marine1.show_status();
	Marine::show_total_marine();

	Marine marine2(3, 5, 10);
	// marine2.show_status();
	Marine::show_total_marine();

	create_marine();

	std::cout << std::endl << "마린 1 이 마린 2 를 공격! " << std::endl;
	marine2.be_attacked(marine1.attack());

	marine1.show_status();
	marine2.show_status();
}