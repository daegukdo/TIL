// c++ code-war
/*
issue description

Progressive Spiral Number Position

Assume that you started to store items in progressively expanding square location, like this for the first 9 numbers:

05 04 03
06 01 02
07 08 09
And like this for the expanding to include up to the first 25 numbers:

17 16 15 14 13
18 05 04 03 12
19 06 01 02 11
20 07 08 09 10
21 22 23 24 25
You might easily notice that the first - and innermost - layer containes only one number (01), the second one - immediately around it - contains 8 numbers (number in the 02-09 range) and so on.

Your task is to create a function that given a number n simply returns the number of layers required to store up to n (included).

layers(1) == 1
layers(5) == 2
layers(25) == 3
layers(30) == 4
layers(50) == 5
Fair warning: you will always and only get positive integers, but be ready for bigger numbers in the tests!

If you had fun with this, also try some follow up kata: progressive spiral number branch and progressive spiral number distance.

*[Base idea taken from here]*
*/

int layers(int n);

int main()
{
	int r0 = layers(1);
	int r1 = layers(5);
	int r2 = layers(25);
	int r3 = layers(30);
	int r4 = layers(50);

	int r5 = layers(111111150);

	return 0;
}

int layers(int n)
{
	int numOfLayer = 0;

	if(n > 1)
	{
		int startLayer = 1;
		int endLayer = 0;

		while(true)
		{
			startLayer = 4 + ((1+2*(numOfLayer-1))*4) + startLayer;
			endLayer = 4 + ((1+2*(numOfLayer))*4) + startLayer;

			if((n > startLayer) && (n <= endLayer))
			{
				break;
			}
			else
			{
				numOfLayer++;
			}
		}

		return numOfLayer+2;
	}
	else
	{
		return 1;
	}
}