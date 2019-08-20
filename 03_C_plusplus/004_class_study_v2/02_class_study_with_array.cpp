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

/* int main 전 까지 내용은 동일 */
int main() 
{
	// 이전에 class를 사용하여 하나하나 이름을 적어가며 객체를 만드는 것이 아닌 배열을 사용하는 방법
	// 동적 할당
	Marine* marines[100];

	// 0번 주소에 객체 생성
	marines[0] = new Marine(2, 3);
	// 1번 주소에 객체 생성
	marines[1] = new Marine(3, 5);

	// 배열로 정의된 부분에서 특정 객체의 메소드를 호출할 경우
	// ->를 사용
	marines[0]->show_status();
	marines[1]->show_status();

	std::cout << std::endl << "마린 1 이 마린 2 를 공격! " << std::endl;

	// 배열로 정의된 부분에서 특정 객체의 메소드를 호출할 경우
	// ->를 사용
	marines[0]->be_attacked(marines[1]->attack());

	marines[0]->show_status();
	marines[1]->show_status();

	// 동적 할당하였으므로 해제!
	delete marines[0];
	delete marines[1];
}