// https://modoocode.com/188

// 포토캐논
#include <string.h>
#include <iostream>

class Photon_Cannon 
{
private :
	int hp, shield;
	int coord_x, coord_y;
	int damage;

public:
	Photon_Cannon(int x, int y);
	Photon_Cannon(const Photon_Cannon& pc);
	void show_status();
};

// 복사 생성자
// 어떤 클래스 T에 대하여 ... T(const T& a)로 정의
// 즉, a를 상수 레퍼런스로 받음을 의미 ... a의 데이터를 변경할 수 없고 instance들에게 복사
Photon_Cannon::Photon_Cannon(const Photon_Cannon& pc) 
{
	std::cout << "복사 생성자 호출 !" << std::endl;
	hp = pc.hp;
	shield = pc.shield;
	coord_x = pc.coord_x;
	coord_y = pc.coord_y;
	damage = pc.damage;
}

Photon_Cannon::Photon_Cannon(int x, int y) 
{
	std::cout << "생성자 호출 !" << std::endl;
	hp = shield = 100;
	coord_x = x;
	coord_y = y;
	damage = 20;
}

void Photon_Cannon::show_status() 
{
	std::cout << "Photon Cannon " << std::endl;
	std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) " << std::endl;
	std::cout << " HP : " << hp << std::endl;
}

int ain2() // main() 
{
	// int instance 2개를 필요로 하는 생성자 사용
	Photon_Cannon pc1(3, 3);

	// 복사 생성자를 사용
	// pc2 객체는 pc1의 여러 인스턴스 값을 복사 받음
	// 이떄, instance 변경 불가
	Photon_Cannon pc2(pc1);

	// 이 역시 복사 생성자
	// c++에서 옆과 같이 해석함 ... Photon_Cannon pc3(pc2);
	Photon_Cannon pc3 = pc2;

	pc1.show_status();
	pc2.show_status();

	// 사실 C++은 default copy constructor를 제공
	// 각 내부 instance를 하나하나 모두 복사 해줌

	return 0;
}