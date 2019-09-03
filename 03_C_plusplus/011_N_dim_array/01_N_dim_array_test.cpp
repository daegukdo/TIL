// refs : https://modoocode.com/204

// N dimension array

class Array 
{
	const int dim;  // 몇 차원 배열인지
	int* size;		// size[0] * size[1] * ... * size[dim - 1] 짜리 배열이다.

public:
	Array(int dim, int* array_size) : dim(dim) 
	{
		size = new int[dim];
		for (int i = 0; i < dim; i++) size[i] = array_size[i];
	}
};

