 // refs : https://modoocode.com/204

// N dimension array

class Array 
{
	const int dim;  // �� ���� �迭����
	int* size;		// size[0] * size[1] * ... * size[dim - 1] ¥�� �迭�̴�.

	struct Address 
	{
		int level;
		// �� ������ ����(dim - 1 ����) �� ������ �迭�� ����Ű��, �� �� ����
		// ���������� ���� Address �迭�� ����Ų��.
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

	// address �� �ʱ�ȭ �ϴ� �Լ��̴�. ��� ȣ��� �����Ǿ� �ִ�.
	void initialize_address(Address *current) 
	{
		if (!current) return;

		if (current->level == dim - 1) 
		{  // �� ��° ���� (���� ����)
			current->next = new int[size[current->level]];
			return;
		}

		current->next = new Address[size[current->level]];

		for (int i = 0; i != size[current->level]; i++) 
		{  
			// ���� �ܰ�� �Ѿ�� ����
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