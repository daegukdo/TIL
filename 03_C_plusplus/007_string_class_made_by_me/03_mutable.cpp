// https://modoocode.com/253

// mutable
#include <iostream>

class A 
{
private:
	// mutable 키워드는 const 함수에서 변경이 가능한 변수로 지정
	// Cache와 같이 임시적으로 처리하는 경우에 필요
	mutable int data_;

public:
	A(int data) : data_(data) {}

	void DoSomething(int x) const 
	{
		data_ = x;  // 불가능!
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