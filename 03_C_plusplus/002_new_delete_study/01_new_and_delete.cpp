// refer URL : https://modoocode.com/169

// think about difference between stack and heap

#include <iostream>

int nomain() //main() 
{
	// int Ÿ���� �ּҸ� ����Ű�� �����Ϳ� int ������ ���� �ּҸ� ����Ű�� ��
	int* p = new int;
	
	// p�� int ������ ���� �ּҸ� ����Ű�Ƿ� �� ������ 10�� �Ҵ�
	*p = 10;
	
	// int ������ �ּҸ� ����Ű�� ������ p�� ����ϸ� �� ������ ���� ��� --> 10
	std::cout << *p << std::endl;
	
	// int ������ �ּҸ� ����Ű�� p�� ����ϸ� �� ������ �ּҰ� ���
	std::cout << p << std::endl;

	// int ������ �Ҵ�� �κ��� ����
	// �̶� �����Ͱ� ����Ű�� �κ��� �ƴ� �ּ� ��ü�� ����
	delete p;
	return 0;
}