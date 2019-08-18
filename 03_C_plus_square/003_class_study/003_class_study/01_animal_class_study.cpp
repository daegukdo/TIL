// ref : https://modoocode.com/172

#include <iostream>

// animal class�� ����
class Animal 
{

// animal�̶�� class�� ����ؼ� ��ü�� ������� �� �ܺο��� ������ �Ұ����� ���� �� �Լ���
private:

	int food;
	int weight;

// animal�̶�� class�� ����ؼ� ��ü�� ������� �� ���� ������ ���� �� �Լ���
public:

	void set_animal(int _food, int _weight) 
	{
		food = _food;
		weight = _weight;
	}


	void increase_food(int inc) 
	{
		food += inc;
		weight += (inc / 3);
	}


	void view_stat() 
	{
		std::cout << "�� ������ food   : " << food << std::endl;
		std::cout << "�� ������ weight : " << weight << std::endl;
	}

};

int main() 
{
	// animal�̶�� class�� ����Ͽ� ��ü�� ����
	Animal animal;

	// �ܺο��� ��� ������ �Լ����� ���
	animal.set_animal(100, 50);
	animal.increase_food(30);

	animal.view_stat();

	return 0;
}