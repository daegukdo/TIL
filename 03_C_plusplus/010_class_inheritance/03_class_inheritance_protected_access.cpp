// Ŭ���� ���(class inheritance)
// ref : https://modoocode.com/209

#include <iostream>
#include <string>

class Base 
{
protected:
	std::string parent_string;

public:
	Base() : parent_string("���") {  std::cout << "��� Ŭ����" <<  std::endl; }

	void what() {  std::cout << parent_string <<  std::endl; }
};
class Derived : public Base 
{
private:
	std::string child_string;

public:
	Derived() : child_string("�Ļ�"), Base() 
	{
		std::cout << "�Ļ� Ŭ����" <<  std::endl;

		// �׷��ٸ� ���� private �� Base ��
		// parent_string �� ������ �� ������?
		// private is not accessed in inheritance class
		parent_string = "�ٲٱ�";
	}

	void what() {  std::cout << child_string <<  std::endl; }
};