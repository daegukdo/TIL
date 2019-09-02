// 클래스 상속(class inheritance)
// ref : https://modoocode.com/209

#include <iostream>
#include <string>

class Base 
{
protected:
	std::string parent_string;

public:
	Base() : parent_string("기반") {  std::cout << "기반 클래스" <<  std::endl; }

	void what() {  std::cout << parent_string <<  std::endl; }
};
class Derived : public Base 
{
private:
	std::string child_string;

public:
	Derived() : child_string("파생"), Base() 
	{
		std::cout << "파생 클래스" <<  std::endl;

		// 그렇다면 현재 private 인 Base 의
		// parent_string 에 접근할 수 있을까?
		// private is not accessed in inheritance class
		parent_string = "바꾸기";
	}

	void what() {  std::cout << child_string <<  std::endl; }
};