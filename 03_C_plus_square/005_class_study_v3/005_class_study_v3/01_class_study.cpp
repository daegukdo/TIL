// https://modoocode.com/188

#include <string.h>
#include <iostream>

class Marine 
{
private:
	int hp;                // ���� ü��
	int coord_x, coord_y;  // ���� ��ġ
	int damage;            // ���ݷ�
	bool is_dead;
	char* name;			   // ���� �̸� ... ������

public:
	Marine();                                       // �⺻ ������
	Marine(int x, int y, const char* marine_name);  // �̸����� ����
	Marine(int x, int y);							// x, y ��ǥ�� ���� ����
	~Marine();										// �Ҹ���

	int attack();                       // �������� �����Ѵ�.
	void be_attacked(int damage_earn);  // �Դ� ������
	void move(int x, int y);            // ���ο� ��ġ

	void show_status();					// ���¸� �����ش�.
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
	// ���� �Ҵ� ... �̸� �Ҹ��Ű�� ������ ��������� �޸� ������ �߻�
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

// �Ҹ��� ... �Ҹ��ڴ� instance�� ���� ������ overloading���� ����
Marine::~Marine() 
{
	std::cout << name << " �� �Ҹ��� ȣ�� ! " << std::endl;

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

	// �迭�� �޼ҵ� ����� ->
	marines[0]->show_status();
	marines[1]->show_status();

	std::cout << std::endl << "���� 1 �� ���� 2 �� ����! " << std::endl;

	marines[0]->be_attacked(marines[1]->attack());

	marines[0]->show_status();
	marines[1]->show_status();

	// ��ü�� �ı��Ǹ� ~�Ҹ��ڸ� ȣ��
	delete marines[0];
	delete marines[1];

	return 0;
}