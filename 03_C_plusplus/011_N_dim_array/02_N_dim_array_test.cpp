 // refs : https://modoocode.com/204

// N dimension array

class Array 
{
	const int dim;  // 몇 차원 배열인지
	int* size;		// size[0] * size[1] * ... * size[dim - 1] 짜리 배열이다.

	struct Address 
	{
		int level;
		// 맨 마지막 레벨(dim - 1 레벨) 은 데이터 배열을 가리키고, 그 위 상위
		// 레벨에서는 다음 Address 배열을 가리킨다.
		void* next;
	};

	Address* top;

public:
	Array(int dim, int* array_size) : dim(dim) 
	{
		size = new int[dim];
		for (int i = 0; i < dim; i++) size[i] = array_size[i];

		top = new Address;
		top->level = 0;

		initialize_address(top);
	}

	Array(const Array& arr) : dim(arr.dim) 
	{
		size = new int[dim];
		for (int i = 0; i < dim; i++) size[i] = arr.size[i];

		top = new Address;
		top->level = 0;

		initialize_address(top);
	}

	~Array() 
	{
		delete_address(top);
		delete[] size;
	}

	// address 를 초기화 하는 함수이다. 재귀 호출로 구성되어 있다.
	void initialize_address(Address *current) 
	{
		if (!current) return;

		if (current->level == dim - 1) 
		{  // 두 번째 질문 (종료 조건)
			current->next = new int[size[current->level]];
			return;
		}

		current->next = new Address[size[current->level]];

		for (int i = 0; i != size[current->level]; i++) 
		{  
			// 다음 단계로 넘어가는 과정
			(static_cast<Address *>(current->next) + i)->level = current->level + 1;

			initialize_address(static_cast<Address *>(current->next) + i);
		}
	}

	void delete_address(Address *current) 
	{
		if (!current) return;
		for (int i = 0; current->level < dim - 1 && i < size[current->level]; i++) {
		delete_address(static_cast<Address *>(current->next) + i);
	}

	delete[] current->next;
}
};

int main()
{
	int a = 5;

	Array b = Array(3, &a);

	return 0;
}