// https://modoocode.com/188

// ����ĳ��
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

// ���� ������
// � Ŭ���� T�� ���Ͽ� ... T(const T& a)�� ����
// ��, a�� ��� ���۷����� ������ �ǹ� ... a�� �����͸� ������ �� ���� instance�鿡�� ����
Photon_Cannon::Photon_Cannon(const Photon_Cannon& pc) 
{
	std::cout << "���� ������ ȣ�� !" << std::endl;
	hp = pc.hp;
	shield = pc.shield;
	coord_x = pc.coord_x;
	coord_y = pc.coord_y;
	damage = pc.damage;
}

Photon_Cannon::Photon_Cannon(int x, int y) 
{
	std::cout << "������ ȣ�� !" << std::endl;
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
	// int instance 2���� �ʿ�� �ϴ� ������ ���
	Photon_Cannon pc1(3, 3);

	// ���� �����ڸ� ���
	// pc2 ��ü�� pc1�� ���� �ν��Ͻ� ���� ���� ����
	// �̋�, instance ���� �Ұ�
	Photon_Cannon pc2(pc1);

	// �� ���� ���� ������
	// c++���� ���� ���� �ؼ��� ... Photon_Cannon pc3(pc2);
	Photon_Cannon pc3 = pc2;

	pc1.show_status();
	pc2.show_status();

	// ��� C++�� default copy constructor�� ����
	// �� ���� instance�� �ϳ��ϳ� ��� ���� ����

	return 0;
}