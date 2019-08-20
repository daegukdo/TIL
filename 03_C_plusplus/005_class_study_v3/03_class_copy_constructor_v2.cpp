// https://modoocode.com/188

// ����ĳ��
#include <string.h>
#include <iostream>

class Photon_Cannon_v2
{
private :
	int hp, shield;
	int coord_x, coord_y;
	int damage;

	// name�� �߰�
	char *name;

public:
	Photon_Cannon_v2(int x, int y);
	Photon_Cannon_v2(const Photon_Cannon_v2& pc);
	Photon_Cannon_v2(int x, int y, const char *cannon_name);

	// �Ҹ��� �߰�
	~Photon_Cannon_v2();

	void show_status();
};

// ���� ������
// � Ŭ���� T�� ���Ͽ� ... T(const T& a)�� ����
// ��, a�� ��� ���۷����� ������ �ǹ� ... a�� �����͸� ������ �� ���� instance�鿡�� ����
Photon_Cannon_v2::Photon_Cannon_v2(const Photon_Cannon_v2& pc) 
{
	std::cout << "���� ������ ȣ�� !" << std::endl;
	hp = pc.hp;
	shield = pc.shield;
	coord_x = pc.coord_x;
	coord_y = pc.coord_y;
	damage = pc.damage;

	// cannon_name�� ���� ���� (deep copy)
	name = new char[strlen(pc.name) + 1];
	strcpy(name, pc.name);

	// cannon_name�� ���� ���� (shallow copy) 
	// ��, a1=a2�� ���� ������ �Ͼ�ٸ�
	// a1�� name instance�� a2 �ּҸ� ��������
	// a1, a2 ��� �Ҹ��ڰ� �Ͼ��
	// ���� ����, �ּҸ� �����Ϸ����Ͽ� ��Ÿ�� error �߻�
	// code : name = pc.name;
}

Photon_Cannon_v2::Photon_Cannon_v2(int x, int y) 
{
	std::cout << "������ ȣ�� !" << std::endl;
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
	// 0 �� �ƴ� ���� if ������ true �� ó���ǹǷ�
	// 0 �ΰ� �ƴѰ��� ���� �� �׳� if(name) �ϸ�
	// if(name != 0) �� ������ �ǹ̸� ���� �� �ִ�.
	// ����� if �� ������ ������ 1 ���� �´ٸ�
	// �߰�ȣ�� ���� �����ϴ�.

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
	// int instance 2���� str instance 1���� �ʿ�� �ϴ� ������ ���
	Photon_Cannon_v2 pc1(3, 3, "Cannon");

	// ���� �����ڸ� ���
	// pc2 ��ü�� pc1�� ���� �ν��Ͻ� ���� ���� ����
	// �̋�, instance ���� �Ұ�
	// ����Ʈ ���� ������ ���
	Photon_Cannon_v2 pc2 = pc1;

	pc1.show_status();
	pc2.show_status();

	// ��� C++�� default copy constructor�� ����
	// �� ���� instance�� �ϳ��ϳ� ��� ���� ����
}