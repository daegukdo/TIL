// https://modoocode.com/188

// 포토캐논
#include <string.h>
#include <iostream>

class Photon_Cannon_v2
{
private :
	int hp, shield;
	int coord_x, coord_y;
	int damage;

	// name을 추가
	char *name;

public:
	Photon_Cannon_v2(int x, int y);
	Photon_Cannon_v2(const Photon_Cannon_v2& pc);
	Photon_Cannon_v2(int x, int y, const char *cannon_name);

	// 소멸자 추가
	~Photon_Cannon_v2();

	void show_status();
};

// 복사 생성자
// 어떤 클래스 T에 대하여 ... T(const T& a)로 정의
// 즉, a를 상수 레퍼런스로 받음을 의미 ... a의 데이터를 변경할 수 없고 instance들에게 복사
Photon_Cannon_v2::Photon_Cannon_v2(const Photon_Cannon_v2& pc) 
{
	std::cout << "복사 생성자 호출 !" << std::endl;
	hp = pc.hp;
	shield = pc.shield;
	coord_x = pc.coord_x;
	coord_y = pc.coord_y;
	damage = pc.damage;

	// cannon_name의 깊은 복사 (deep copy)
	name = new char[strlen(pc.name) + 1];
	strcpy(name, pc.name);

	// cannon_name의 얕은 복사 (shallow copy) 
	// 즉, a1=a2로 복사 생성이 일어났다면
	// a1은 name instance의 a2 주소를 보고있음
	// a1, a2 모두 소멸자가 일어나면
	// 같은 공간, 주소를 해제하려고하여 런타임 error 발생
	// code : name = pc.name;
}

Photon_Cannon_v2::Photon_Cannon_v2(int x, int y) 
{
	std::cout << "생성자 호출 !" << std::endl;
	hp = shield = 100;
	coord_x = x;
	coord_y = y;
	damage = 20;

	name = NULL;
}

Photon_Cannon_v2::Photon_Cannon_v2(int x, int y, const char *cannon_name) 
{
	hp = shield = 100;
	coord_x = x;
	coord_y = y;
	damage = 20;

	name = new char[strlen(cannon_name) + 1];
	strcpy(name, cannon_name);
}

Photon_Cannon_v2::~Photon_Cannon_v2() 
{
	// 0 이 아닌 값은 if 문에서 true 로 처리되므로
	// 0 인가 아닌가를 비교할 때 그냥 if(name) 하면
	// if(name != 0) 과 동일한 의미를 가질 수 있다.
	// 참고로 if 문 다음에 문장이 1 개만 온다면
	// 중괄호를 생략 가능하다.

	if (name) delete[] name;
}

void Photon_Cannon_v2::show_status() 
{
	std::cout << "Photon Cannon " << std::endl;
	std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) " << std::endl;
	std::cout << " HP : " << hp << std::endl;
}

int main() 
{
	// int instance 2개와 str instance 1개를 필요로 하는 생성자 사용
	Photon_Cannon_v2 pc1(3, 3, "Cannon");

	// 복사 생성자를 사용
	// pc2 객체는 pc1의 여러 인스턴스 값을 복사 받음
	// 이떄, instance 변경 불가
	// 디폴트 복사 생성자 사용
	Photon_Cannon_v2 pc2 = pc1;

	pc1.show_status();
	pc2.show_status();

	// 사실 C++은 default copy constructor를 제공
	// 각 내부 instance를 하나하나 모두 복사 해줌
}