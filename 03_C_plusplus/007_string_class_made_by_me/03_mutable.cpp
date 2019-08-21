// https://modoocode.com/253

// mutable
#include <iostream>

class A 
{
private:
	// mutable Ű����� const �Լ����� ������ ������ ������ ����
	// Cache�� ���� �ӽ������� ó���ϴ� ��쿡 �ʿ�
	mutable int data_;

public:
	A(int data) : data_(data) {}

	void DoSomething(int x) const 
	{
		data_ = x;  // �Ұ���!
	}

	void PrintData() const 
	{ 
		std::cout << "data: " << data_ << std::endl; 
	}
};

int main() 
{
	A a(10);
	a.DoSomething(3);
	a.PrintData();
}