// refs : https://modoocode.com/202

// operator overloading

// syntax : (리턴 타입) operator(연산자) (연산자가 받는 인자)
// 유일하게 함수 이름에 연산자가 들어갈 수 있음

// Complex number class ... real, imaginary 영역이 있으므로 반드시 class 사용

#include <iostream>

class Complex 
{
private:
	double real, img;

	double get_number(const char* str, int from, int to);

public:
	Complex(double real, double img) : real(real), img(img) {}
	Complex(const Complex& c) { real = c.real, img = c.img; }
	Complex(const char* str);

	// 복잡 ... ex) a.plus(b.divide(c)).plus(d);
////////////////////////////////////////////
////Complex plus(const Complex& c);
////Complex minus(const Complex& c);
////Complex times(const Complex& c);
////Complex divide(const Complex& c);
////////////////////////////////////////////

	// 값만 받아서 연산에 사용! ... 실제로는 값을 변경하거나 하지 않음
	// 값을 복사하여 리턴! ... 레퍼런스 타입인 경우 이중 연상이 발생할 수 있음
	// ex) a = b + c + b = 2 * b + c vs. (reference type) 2 * b + 2 * c ... b는 연산이 되었는데 그 자체를 다시 연산에 사용하므로 
	Complex operator+(const Complex& c);
	Complex operator-(const Complex& c);
	Complex operator*(const Complex& c);
	Complex operator/(const Complex& c);

	// 대입 연산자
	// 이는 레퍼런스 타입을 리턴
	// 사실 ... 컴파일러 차원에서 디폴트 대입 연산자(default assignment operator)를 지원
	Complex& operator=(const Complex& c);

	// 대입 사칙연산
	// 연산자 오버로딩을 사용 시, a = a + b; 가 정의 되어 있다고 a+= b 가 가능한 것이 아님 
	Complex& operator+=(const Complex& c);
	Complex& operator-=(const Complex& c);
	Complex& operator*=(const Complex& c);
	Complex& operator/=(const Complex& c);

	// 만약 complex number를 (부호) (실수부) (부호) i (허수부)로 string 형식으로 표현 할 수 있다고 약속한다면
	// a = a.operator+("-1.1 + i3.923"); 가 자동으로 Complex(const char* str); 생성자를 사용하므로 만들 필요가 없다!
	//Complex operator+(const char* str);
	//Complex operator-(const char* str);
	//Complex operator*(const char* str);
	//Complex operator/(const char* str);

	void println() { std::cout << "( " << real << " , " << img << " ) " << std::endl; }
};

Complex::Complex(const char* str) 
{
	// 입력 받은 문자열을 분석하여 real 부분과 img 부분을 찾아야 한다.
	// 문자열의 꼴은 다음과 같습니다 "[부호](실수부)(부호)i(허수부)"
	// 이 때 맨 앞의 부호는 생략 가능합니다. (생략시 + 라 가정)

	int begin = 0, end = strlen(str);
	img = 0.0;
	real = 0.0;

	// 먼저 가장 기준이 되는 'i' 의 위치를 찾는다.
	int pos_i = -1;

	for (int i = 0; i != end; i++) 
	{
		if (str[i] == 'i') 
		{
			pos_i = i;
			break;
		}
	}

	// 만일 'i' 가 없다면 이 수는 실수 뿐이다.
	if (pos_i == -1) 
	{
		real = get_number(str, begin, end - 1);
		return;
	}

	// 만일 'i' 가 있다면,  실수부와 허수부를 나누어서 처리하면 된다.
	real = get_number(str, begin, pos_i - 1);
	img = get_number(str, pos_i + 1, end - 1);

	if (pos_i >= 1 && str[pos_i - 1] == '-') 
		img *= -1.0;
}

double Complex::get_number(const char* str, int from, int to) 
{
	bool minus = false;
	if (from > to) return 0;

	if (str[from] == '-') minus = true;
	if (str[from] == '-' || str[from] == '+') from++;

	double num = 0.0;
	double decimal = 1.0;

	bool integer_part = true;
	for (int i = from; i <= to; i++) 
	{
		if (isdigit(str[i]) && integer_part) 
		{
			num *= 10.0;
			num += (str[i] - '0');
		} 
		else if (str[i] == '.')
		{
			integer_part = false;
		}
		else if (isdigit(str[i]) && !integer_part) 
		{
			decimal /= 10.0;
			num += ((str[i] - '0') * decimal);
		} 
		else
			break;  // 그 이외의 이상한 문자들이 올 경우
	}

	if (minus) num *= -1.0;

	return num;
}

Complex Complex::operator+(const Complex& c) 
{
	Complex temp(real + c.real, img + c.img);
	return temp;
}

Complex Complex::operator-(const Complex& c) 
{
	Complex temp(real - c.real, img - c.img);
	return temp;
}

Complex Complex::operator*(const Complex& c) 
{
	Complex temp(real * c.real - img * c.img, real * c.img + img * c.real);
	return temp;
}

Complex Complex::operator/(const Complex& c) 
{
	Complex temp(
		(real * c.real + img * c.img) / (c.real * c.real + c.img * c.img),
		(img * c.real - real * c.img) / (c.real * c.real + c.img * c.img));
	return temp;
}

Complex& Complex::operator=(const Complex& c)
{
	real = c.real;
	img = c.img;
	return *this;
}

Complex& Complex::operator+=(const Complex& c) 
{
	(*this) = (*this) + c;
	return *this;
}

Complex& Complex::operator-=(const Complex& c) 
{
	(*this) = (*this) - c;
	return *this;
}

Complex& Complex::operator*=(const Complex& c) 
{
	(*this) = (*this) * c;
	return *this;
}

Complex& Complex::operator/=(const Complex& c) 
{
	(*this) = (*this) / c;
	return *this;
}

//Complex Complex::operator+(const char* str)
//{
//	Complex temp(str);
//	return (*this) + temp;
//}
//
//Complex Complex::operator-(const char* str) 
//{
//	Complex temp(str);
//	return (*this) - temp;
//}
//
//Complex Complex::operator*(const char* str) 
//{
//	Complex temp(str);
//	return (*this) * temp;
//}
//
//Complex Complex::operator/(const char* str) 
//{
//	Complex temp(str);
//	return (*this) / temp;
//}

int main() 
{
	Complex a(0, 0);
	a = a + "-1.1 + i3.923";
	a.println();
	a = a - "1.2 -i1.823";
	a.println();
	a = a * "2.3+i22";
	a.println();
	a = a / "-12+i55";
	a.println();

	return 0;
}