// https://modoocode.com/253

// explicit
#include <iostream>

class MyString 
{
private:
	char* string_content;				// 문자열 데이터를 가리키는 포인터
	int string_length;					// 문자열 길이

	int memory_capacity;

public:
	// capacity 만큼 미리 할당함. (explicit 키워드에 주목)
	explicit MyString(int capacity);

	// 문자열로 부터 생성
	MyString(const char* str);

	// 복사 생성자
	MyString(const MyString& str);

	~MyString();

	int length() const;
	int capacity() const;
};

// .. (생략) ..

void DoSomethingWithString(MyString s) 
{
	// Do something...
}

int main() 
{
	// 3은 잘못된 입력 ... 하지만 암시적 변환을 통하여 MyString(int capacity)가 실행됨
	// explicit 키워드를 사용하여 이를 방지할 수 있음
	// 아래는 에러!
	// DoSomethingWithString(3);
}