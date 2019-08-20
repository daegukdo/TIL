// https://modoocode.com/197

// ���۷����� �����ϴ� �Լ�
#include <iostream>

class A 
{

private:

	int x;

public:

	A(int c) : x(c) {}

	int& access_x() { return x; }
	int get_x() { return x; }
	void show_x() { std::cout << "x : " << x << std::endl; }
};

int main() 
{
	// a��� ��ü�� ����� ��� ������ 5�� �Է�
	A a(5);
	// ��� ���� x�� ��� ... x = 5
	a.show_x();

	// refer type�� int& c�� ����Ͽ� a��ü ���� ��� ������ ����
	int& c = a.access_x();
	// c�� 4�� �ٲٸ� c�� ��� ���� x�� �����̹Ƿ� �� ���� 4�� �ٲ�� �� 
	c = 4;
	// ��� ������ ��� ... x = 4
	a.show_x();

	// c�� ��� ... c = 4
	std::cout << "c : " << c << std::endl;

	// int d��� ������ a�� x��� ��� ������ ����
	int d = a.access_x();
	// d�� ��� ... d = 4
	std::cout << "d : " << d << std::endl;
	// d = 3���� �ٲ� 
	d = 3;
	// ���縸 ����Ǿ����Ƿ� ���� ���� ��� ������ ��� ... x = 4
	a.show_x();
	// d�� ��� ... d = 3
	std::cout << "d : " << d << std::endl;

  // �Ʒ��� ����
  // int& e = a.get_x();
  // e = 2;
  // a.show_x();

	// int f��� ������ a�� x��� ��� ������ ����
	int f = a.get_x();
	// f�� ��� ... d = 4
	std::cout << "f : " << f << std::endl;
	// f = 1�� �ٲ�
	f = 1;
	// ���縸 ����Ǿ����Ƿ� ���� ���� ��� ������ ��� ... x = 4
	a.show_x();
	// f�� ��� ... d = 1
	std::cout << "f : " << f << std::endl;
}