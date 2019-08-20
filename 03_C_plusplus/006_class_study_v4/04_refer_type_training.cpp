// https://modoocode.com/197

// 레퍼런스를 리턴하는 함수
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
	// a라는 객체를 만들며 멤버 변수에 5를 입력
	A a(5);
	// 멤버 변수 x를 출력 ... x = 5
	a.show_x();

	// refer type의 int& c를 사용하여 a객체 내의 멤버 변수에 접근
	int& c = a.access_x();
	// c를 4로 바꾸면 c는 멤버 변수 x의 별명이므로 이 또한 4로 바뀌게 됨 
	c = 4;
	// 멤버 변수를 출력 ... x = 4
	a.show_x();

	// c를 출력 ... c = 4
	std::cout << "c : " << c << std::endl;

	// int d라는 변수에 a의 x라는 멤버 변수를 복사
	int d = a.access_x();
	// d를 출력 ... d = 4
	std::cout << "d : " << d << std::endl;
	// d = 3으로 바뀜 
	d = 3;
	// 복사만 진행되었으므로 변경 없는 멤버 변수를 출력 ... x = 4
	a.show_x();
	// d를 출력 ... d = 3
	std::cout << "d : " << d << std::endl;

  // 아래는 오류
  // int& e = a.get_x();
  // e = 2;
  // a.show_x();

	// int f라는 변수에 a의 x라는 멤버 변수를 복사
	int f = a.get_x();
	// f를 출력 ... d = 4
	std::cout << "f : " << f << std::endl;
	// f = 1로 바뀜
	f = 1;
	// 복사만 진행되었으므로 변경 없는 멤버 변수를 출력 ... x = 4
	a.show_x();
	// f를 출력 ... d = 1
	std::cout << "f : " << f << std::endl;
}