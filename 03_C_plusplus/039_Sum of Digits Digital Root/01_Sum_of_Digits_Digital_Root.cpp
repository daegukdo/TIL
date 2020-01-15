// c++ code-war
/*
issue description

Sum of Digits / Digital Root

In this kata, you must create a digital root function.

A digital root is the recursive sum of all the digits in a number. 

Given n, take the sum of the digits of n. 

If that value has more than one digit, continue reducing in this way until a single-digit number is produced. 

This is only applicable to the natural numbers.

Here's how it works:

digital_root(16)
=> 1 + 6
=> 7

digital_root(942)
=> 9 + 4 + 2
=> 15 ...
=> 1 + 5
=> 6

digital_root(132189)
=> 1 + 3 + 2 + 1 + 8 + 9
=> 24 ...
=> 2 + 4
=> 6

digital_root(493193)
=> 4 + 9 + 3 + 1 + 9 + 3
=> 29 ...
=> 2 + 9
=> 11 ...
=> 1 + 1
=> 2
*/

int digital_root(int n);

int main()
{
	return 0;
}

int digital_root(int n)
{
	// 0. 변수 선언
	int resultOfSum = 0;
	float digitCheckCount = 1;
	int lengthOfDigits = 0;
	float tmpCheckDigit = 1;

    // 1. 자릿수 파악 및 메모리 할당
	while(tmpCheckDigit >= 1)
	{
		digitCheckCount = digitCheckCount * 10;
		tmpCheckDigit = n / digitCheckCount;
		lengthOfDigits++;
	}

	int *arrayDigits = new int[lengthOfDigits];

	// 2. 각 자리수 값 저장
	int digitCount = 1;
	for(int i = 0; i < lengthOfDigits; i++)
	{
		digitCount = digitCount * 10;
		arrayDigits[i] = n - (n / digitCount);
	}

	// 3. 각 자리수 값을 더하기 및 메모리 정리
	for(int i = 0; i < lengthOfDigits; i++)
	{
		resultOfSum += arrayDigits[i];
	}

	delete[] arrayDigits;

	// 4. 더한 결과값이 10의 자리이상의 값인지 확인하여 결과값을 바탕으로 반복 
	if(resultOfSum >= 10)
	{
		digital_root(resultOfSum);
	}
	else
	{
		return resultOfSum;
	}
}