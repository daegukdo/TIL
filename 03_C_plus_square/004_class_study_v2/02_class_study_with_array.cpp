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

/* int main �� ���� ������ ���� */
int main() 
{
	// ������ class�� ����Ͽ� �ϳ��ϳ� �̸��� ����� ��ü�� ����� ���� �ƴ� �迭�� ����ϴ� ���
	// ���� �Ҵ�
	Marine* marines[100];

	// 0�� �ּҿ� ��ü ����
	marines[0] = new Marine(2, 3);
	// 1�� �ּҿ� ��ü ����
	marines[1] = new Marine(3, 5);

	// �迭�� ���ǵ� �κп��� Ư�� ��ü�� �޼ҵ带 ȣ���� ���
	// ->�� ���
	marines[0]->show_status();
	marines[1]->show_status();

	std::cout << std::endl << "���� 1 �� ���� 2 �� ����! " << std::endl;

	// �迭�� ���ǵ� �κп��� Ư�� ��ü�� �޼ҵ带 ȣ���� ���
	// ->�� ���
	marines[0]->be_attacked(marines[1]->attack());

	marines[0]->show_status();
	marines[1]->show_status();

	// ���� �Ҵ��Ͽ����Ƿ� ����!
	delete marines[0];
	delete marines[1];
}