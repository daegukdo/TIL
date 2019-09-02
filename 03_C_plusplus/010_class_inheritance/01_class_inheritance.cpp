// Ŭ���� ���(class inheritance)
// ref : https://modoocode.com/209
#include <iostream>
#include <string>

class Base 
{
private:
	std::string s;

public:
	Base() : s("���") {  std::cout << "��� Ŭ����" <<  std::endl; }

	void what() {  std::cout << s <<  std::endl; }
};

class Derived : public Base 
{
private:
	std::string s;

public:
	Derived() : Base(), s("�Ļ�") 
	{
		std::cout << "�Ļ� Ŭ����" <<  std::endl;

		// Base ���� what() �� ���� �޾����Ƿ�
		// Derived ���� �翬�� ȣ�� �����ϴ�
		// ������ �Ʒ��� �Լ��� ���ǵǾ� �ִٸ� �������̵� �� �Լ��� ����
		what();
	}

	void what() {  std::cout << s << s << std::endl; }
};

int main() 
{
	std::cout << " === ��� Ŭ���� ���� ===" <<  std::endl;
	Base p;

	std::cout << " === �Ļ� Ŭ���� ���� ===" <<  std::endl;
	Derived c;

	return 0;
}