#include <iostream>
#include <sstream>

 struct complex_t
{	
	float real;
	float imag;

	complex_t()
	{
		real = 0.0f;
		imag = 0.0f;
	}

	complex_t add(complex_t other) const //complex_t const * const
	{
		complex_t result;
		result.real = this->real + other.real;
		result.imag = this->imag + other.imag;
		return result;
	}

	complex_t sub(complex_t other) const //complex_t const * const
	{
		complex_t result;
		result.real = this->real - other.real;
		result.imag = this->imag - other.imag;
		return result;
	}

	complex_t mul(complex_t other) const //complex_t const * const
	{
		complex_t result;
		result.real = this->real*other.real - this->imag*other.imag;
		result.imag = this->imag*other.real - this->real*other.imag;
		return result;
	}

	complex_t div(complex_t other) const //complex_t const * const
	{
		complex_t result;
		result.real = (this->real*other.real - this->imag*other.imag) / (other.real*other.real + other.imag*other.imag);
		result.imag = (this->imag*other.real - this->real*other.imag) / (other.real*other.real + other.imag*other.imag);
		return result;
	}

	std::istream & read(std::istream & stream) //const // complex_t * const
	{
		char symbol;
		float real;
		float imag;

		if (stream >> symbol && symbol == '(' &&
			stream >> real &&
			stream >> symbol && symbol == ',' &&
			stream >> imag &&
			stream >> symbol && symbol == ')')
		{

			this->real = real;
			this->imag = imag;

		}
		else
		{
			stream.setstate(std::ios::failbit);
		}

		return stream;
	}	

	std::ostream & write(std::ostream & stream) const // complex_t * const
	{
		return stream << '(' << real << ", " << imag << ')';
	}
};

 int main()
 {
	 std::string input;
	 getline(std::cin, input);
	 std::istringstream stream(input);
	 complex_t complex1;
	 complex_t complex2;
	 char op;

	 if (complex1.read(stream) &&
		 stream >> op && (op == '+' || op == '-' || op == '*' || op == '/') &&
		 complex2.read(stream))
	 {
		 switch (op)
		 {
		 case '+':
		 {
			 auto result = complex1.add(complex2);
			 result.write(std::cout);
		     break;
		 }
		 case '-':
		 {
			 auto result = complex1.sub(complex2);
			 result.write(std::cout);
			 break;
		 }
		 case '*':
		 {
			 auto result = complex1.mul(complex2);
			 result.write(std::cout);
			 break;
		 }
		 case '/':
		 {
			 auto result = complex1.div(complex2);
			 result.write(std::cout);
			 break;
		 }
		 }
	 }
	 else
	 {
		 std::cout << "An error has occured while reading input data";
		 return 1;
	 }

	 std::cin.get();
	 return 0;
 }
