// 클래스 상속(class inheritance)
// ref : https://modoocode.com/209
#include <iostream>
#include <string>

class Base 
{
private:
	std::string s;

public:
	Base() : s("기반") {  std::cout << "기반 클래스" <<  std::endl; }

	void what() {  std::cout << s <<  std::endl; }
};

class Derived : public Base 
{
private:
	std::string s;

public:
	Derived() : Base(), s("파생") 
	{
		std::cout << "파생 클래스" <<  std::endl;

		// Base 에서 what() 을 물려 받았으므로
		// Derived 에서 당연히 호출 가능하다
		// 하지만 아래에 함수가 정의되어 있다면 오버라이딩 된 함수가 실행
		what();
	}

	void what() {  std::cout << s << s << std::endl; }
};

int main() 
{
	std::cout << " === 기반 클래스 생성 ===" <<  std::endl;
	Base p;

	std::cout << " === 파생 클래스 생성 ===" <<  std::endl;
	Derived c;

	return 0;
}