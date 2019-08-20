// https://modoocode.com/197
// static variable

#include <iostream>

class Marine_Fake
{
private:
	static int total_marine_num;				// class ���� �� �Ѱ� !
};

class Marine 
{
private:

	// ��� ��� ������ class ������ �ʱ�ȭ�� �Ұ���
	// const static�� ���� ����
	static int total_marine_num;				// ��ü ���� ���ڸ� �˱� ���� static ���� ... class ������ �� �Ѱ�!

	int hp;										// ���� ü��
	int coord_x, coord_y;						// ���� ��ġ
	bool is_dead;

	const int default_damage;					// �⺻ ���ݷ�

public:
  
	// static �Լ��� ���� ���� ... ��� class���� �� �ϳ� �ִ� �Լ�
	Marine();									// �⺻ ������
	Marine(int x, int y);						// x, y ��ǥ�� ���� ����
	Marine(int x, int y, int default_damage);	// initializer list�� ����� ������

	int attack();								// �������� �����Ѵ�.
	void be_attacked(int damage_earn);			// �Դ� ������
	void move(int x, int y);					// ���ο� ��ġ

	void show_status();							// ���¸� �����ش�.
	static void show_total_marine();			// static �Լ� ... ��ü ���̵� ����� �� ����

	~Marine() { total_marine_num--; }			// �Ҹ��� ����
};

// static�� ���ǿ� ���ÿ� 0���� �ʱ�ȭ
int Marine::total_marine_num = 0;

// static �Լ��� ������ ��� ... ��ü ���� ���� ����� ����
// (Ŭ����)::(static �Լ�) �������� ȣ��
// ���� ��ü ���� ����� �����ϱ� ������ ��ü�� ������ �� ���� ���ǵǴ� ��� ������ static �Լ����� ����� �Ұ���
// ��, static �Լ������� static ������ ����� ����
void Marine::show_total_marine() 
{
	std::cout << "��ü ���� �� : " << total_marine_num << std::endl;
}

// initializer list ���� 
// ������ ȣ��ÿ� �Ʒ��� ���ǵ� ������ ��� �ν��Ͻ��� �ʱ�ȭ
// ��, ������ ���ÿ� �ʱ�ȭ�� �����
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
	std::cout << " ���� �� ���� �� : " << total_marine_num << std::endl;
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

	std::cout << std::endl << "���� 1 �� ���� 2 �� ����! " << std::endl;
	marine2.be_attacked(marine1.attack());

	marine1.show_status();
	marine2.show_status();
}