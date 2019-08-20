// https://modoocode.com/197

// 자기 자신을 가리키는 포인터 this
#include <iostream>

class Marine 
{

private:

	static int total_marine_num;
	const static int i = 0;

	int hp;											// 마린 체력
	int coord_x, coord_y;							// 마린 위치
	bool is_dead;

	const int default_damage;						// 기본 공격력

public:

	Marine();										// 기본 생성자
	Marine(int x, int y);							// x, y 좌표에 마린 생성
	Marine(int x, int y, int default_damage);

	int attack();									// 데미지를 리턴한다.
	Marine& be_attacked(int damage_earn);			// 입는 데미지
	void move(int x, int y);						// 새로운 위치

	void show_status();								// 상태를 보여준다.
	static void show_total_marine();
	~Marine() { total_marine_num--; }
};

int Marine::total_marine_num = 0;

void Marine::show_total_marine() 
{
	std::cout << "전체 마린 수 : " << total_marine_num << std::endl;
}

Marine::Marine()
    : hp(50), coord_x(0), coord_y(0), default_damage(5), is_dead(false) 
{
	total_marine_num++;
}

Marine::Marine(int x, int y)
    : coord_x(x),
      coord_y(y),
      hp(50),

      default_damage(5),
      is_dead(false) 
{
	total_marine_num++;
}

Marine::Marine(int x, int y, int default_damage)
    : coord_x(x),
      coord_y(y),
      hp(50),
      default_damage(default_damage),
      is_dead(false) 
{
	total_marine_num++;
}

void Marine::move(int x, int y) 
{
	coord_x = x;
	coord_y = y;
}

int Marine::attack()
{ 
	return default_damage; 
}

// this는 C++자체에 있는 키워드
// 객체 자신의 변수를 가리키는 포인터 ... 따라서 static은 this를 사용할 수 없음
Marine& Marine::be_attacked(int damage_earn) 
{
	hp -= damage_earn;
	if (hp <= 0) is_dead = true;

	return *this;
}

// 아래와 동일한 의미
////////////////////////////////////////////////////////////
////////// Marine& Marine::be_attacked(int damage_earn) {
//////////   this->hp -= damage_earn;
//////////   if (this->hp <= 0) this->is_dead = true;
////////// 
//////////   return *this;
////////// }
////////////////////////////////////////////////////////////

// 아래는 객체 자체를 리턴하는 예제
// 위와 다르게 아래의 함수를 사용하면 아래의 main 함수처럼 러퍼런스를 리턴하는 것이 아니기에 
// 복사된 객체를 전달하여 실제로는 한번만 공격 받은 것으로 됨
////////////////////////////////////////////////////////////
////////// Marine Marine::be_attacked(int damage_earn) {
//////////   this->hp -= damage_earn;
//////////   if (this->hp <= 0) this->is_dead = true;
//////////
//////////   return *this;
////////// }
////////////////////////////////////////////////////////////

void Marine::show_status() 
{
	std::cout << " *** Marine *** " << std::endl;
	std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) " << std::endl;
	std::cout << " HP : " << hp << std::endl;
	std::cout << " 현재 총 마린 수 : " << total_marine_num << std::endl;
}

int main() 
{
	Marine marine1(2, 3, 5);
	marine1.show_status();

	Marine marine2(3, 5, 10);
	marine2.show_status();

	std::cout << std::endl << "마린 1 이 마린 2 를 두 번 공격! " << std::endl;

	// 이는 marine의 레퍼런스를 return 받음
	// 즉, 공격받아 멤버 변수에 계산이 된 marine2 객체를 별명을 사용하여 다시 넘겨주고 이를 다시 공격
	marine2.be_attacked(marine1.attack()).be_attacked(marine1.attack());

	marine1.show_status();
	marine2.show_status();
}