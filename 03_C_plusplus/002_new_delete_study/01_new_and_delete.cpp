// refer URL : https://modoocode.com/169

// think about difference between stack and heap

#include <iostream>

int nomain() //main() 
{
	// int 타입의 주소를 가리키는 포인터에 int 공간을 만든 주소를 가리키게 함
	int* p = new int;
	
	// p는 int 공간을 만든 주소를 가리키므로 이 공간에 10을 할당
	*p = 10;
	
	// int 공간의 주소를 가리키는 포인터 p를 출력하면 이 공간의 값이 출력 --> 10
	std::cout << *p << std::endl;
	
	// int 공간의 주소를 가리키는 p를 출력하면 이 공간의 주소가 출력
	std::cout << p << std::endl;

	// int 공간이 할당된 부분을 해제
	// 이때 포인터가 가리키는 부분이 아닌 주소 자체를 헤제
	delete p;
	return 0;
}