// refer URL : https://modoocode.com/169

#include <iostream>

int main() 
{
	int arr_size;
	std::cout << "array size : ";
	std::cin >> arr_size;

	// int type을 가지는 array가 할당된 공간의 주소를 가리키는 포인터 list를 생성
	// 이때 위에서 입력받은 숫자만큼의 array를 만들 수 있게 정의
	int *list = new int[arr_size];

	// 할당은 되어 있지만 비어있는 array에 값을 저장
	// array는 첫번째 주소에 값을 넣을 수 있음
	for (int i = 0; i < arr_size; i++) 
	{
		std::cin >> list[i];
	}

	// array에 저장된 값을 출력
	// array는 첫번째 주소를 사용하여 저장된 값을 불러올 수 있음
	for (int i = 0; i < arr_size; i++) 
	{
		std::cout << i << "th element of list : " << list[i] << std::endl;
	}

	// new [] --> delete []
	delete[] list;
	return 0;
}