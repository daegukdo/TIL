// https://modoocode.com/197
// initializer list

#include <iostream>

class Marine 
{
private:

	int hp;								// ���� ü��
	int coord_x, coord_y;				// ���� ��ġ
	int damage;							// ���ݷ�
	bool is_dead;

public:
  
	Marine();							// �⺻ ������
	Marine(int x, int y);				// x, y ��ǥ�� ���� ����

	int attack();                       // �������� �����Ѵ�.
	void be_attacked(int damage_earn);  // �Դ� ������
	void move(int x, int y);            // ���ο� ��ġ

	void show_status();					// ���¸� �����ش�.
};

////////////////////////////////////////
//////// // ������ ����� ������ �Լ�
//////// Marine::Marine() {
////////   hp = 50;
////////   coord_x = coord_y = 0;
////////   damage = 5;
////////   is_dead = false;
//////// }
////////////////////////////////////////

// initializer list ���� 
// ������ ȣ��ÿ� �Ʒ��� ���ǵ� ������ ��� �ν��Ͻ��� �ʱ�ȭ
// ��, ������ ���ÿ� �ʱ�ȭ�� �����
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