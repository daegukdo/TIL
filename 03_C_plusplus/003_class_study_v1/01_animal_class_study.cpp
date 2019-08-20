// ref : https://modoocode.com/172

#include <iostream>

// animal class를 정의
class Animal 
{

// animal이라는 class를 사용해서 객체를 만들었을 때 외부에서 접근이 불가능한 변수 및 함수들
private:

	int food;
	int weight;

// animal이라는 class를 사용해서 객체를 만들었을 때 접근 가능한 변수 및 함수들
public:

	void set_animal(int _food, int _weight) 
	{
		food = _food;
		weight = _weight;
	}


	void increase_food(int inc) 
	{
		food += inc;
		weight += (inc / 3);
	}


	void view_stat() 
	{
		std::cout << "이 동물의 food   : " << food << std::endl;
		std::cout << "이 동물의 weight : " << weight << std::endl;
	}

};

int main() 
{
	// animal이라는 class를 사용하여 객체를 생성
	Animal animal;

	// 외부에서 사용 가능한 함수들을 사용
	animal.set_animal(100, 50);
	animal.increase_food(30);

	animal.view_stat();

	return 0;
}