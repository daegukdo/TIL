// https://modoocode.com/253

// explicit
#include <iostream>

class MyString 
{
private:
	char* string_content;				// ���ڿ� �����͸� ����Ű�� ������
	int string_length;					// ���ڿ� ����

	int memory_capacity;

public:
	// capacity ��ŭ �̸� �Ҵ���. (explicit Ű���忡 �ָ�)
	explicit MyString(int capacity);

	// ���ڿ��� ���� ����
	MyString(const char* str);

	// ���� ������
	MyString(const MyString& str);

	~MyString();

	int length() const;
	int capacity() const;
};

// .. (����) ..

void DoSomethingWithString(MyString s) 
{
	// Do something...
}

int main() 
{
	// 3�� �߸��� �Է� ... ������ �Ͻ��� ��ȯ�� ���Ͽ� MyString(int capacity)�� �����
	// explicit Ű���带 ����Ͽ� �̸� ������ �� ����
	// �Ʒ��� ����!
	// DoSomethingWithString(3);
}