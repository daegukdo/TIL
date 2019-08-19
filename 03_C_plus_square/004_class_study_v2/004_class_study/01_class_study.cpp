// https://modoocode.com/188

#include <iostream>

// startcraft�� marine�� �����ϴ� class�� ������
class Marine 
{
	// class�� ������ instance�� ����
private:
	int hp;                // ���� ü��
	int coord_x, coord_y;  // ���� ��ġ
	int damage;            // ���ݷ�
	bool is_dead;

	// class�� ������ �Լ��� ���� ... class�� �����ϰ� ǥ���ϱ� ���� �Ʒ��� ���� type, name, �ʿ�� �ϴ� instance�� ����
	// header�� class ���� ���
public:
	Marine();              // �⺻ ������
  
	Marine(int x, int y);  // x, y ��ǥ�� ���� ����
 
	int attack();                       // �������� �����Ѵ�.
	void be_attacked(int damage_earn);  // �Դ� ������
	void move(int x, int y);            // ���ο� ��ġ
	void show_status();  // ���¸� �����ش�.
};

// :: ��ȣ�� ����Ͽ� Ư�� class�� ǥ��Ǿ� �ִ� �Լ��� ���� ������ ���
// �����ڸ� ����Ͽ� class�� ����Ͽ� ��ü ���� �� �⺻���� instance�� ������ ��
Marine::Marine() 
{
	hp = 50;
	coord_x = coord_y = 0;
	damage = 5;
	is_dead = false;
}

// ������ overloading
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

int ain() // main() 
{
	// class�� ����Ͽ� ��ü�� ����
	// �̶� 2����  int�� instance�� ������ ��ü�� ����
	Marine marine1(2, 3);
	Marine marine2(3, 5);

	// class�� ���ǵǾ� ������, �ܺο� ::�� ����Ͽ� ����Ǿ� �ִ� �Լ��� ���
	marine1.show_status();
	marine2.show_status();

	std::cout << std::endl << "���� 1 �� ���� 2 �� ����! " << std::endl;
	marine2.be_attacked(marine1.attack());

	marine1.show_status();
	marine2.show_status();
}