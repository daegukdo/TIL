// refer URL : https://modoocode.com/169

#include <iostream>

int main() 
{
	int arr_size;
	std::cout << "array size : ";
	std::cin >> arr_size;

	// int type�� ������ array�� �Ҵ�� ������ �ּҸ� ����Ű�� ������ list�� ����
	// �̶� ������ �Է¹��� ���ڸ�ŭ�� array�� ���� �� �ְ� ����
	int *list = new int[arr_size];

	// �Ҵ��� �Ǿ� ������ ����ִ� array�� ���� ����
	// array�� ù��° �ּҿ� ���� ���� �� ����
	for (int i = 0; i < arr_size; i++) 
	{
		std::cin >> list[i];
	}

	// array�� ����� ���� ���
	// array�� ù��° �ּҸ� ����Ͽ� ����� ���� �ҷ��� �� ����
	for (int i = 0; i < arr_size; i++) 
	{
		std::cout << i << "th element of list : " << list[i] << std::endl;
	}

	// new [] --> delete []
	delete[] list;
	return 0;
}