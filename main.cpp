#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

struct complex_t
{
	float real;
	float imag;
};

//bool read(istringstream & stream)
//{
//string stroka;
//getline(cin, stroka);
//istringstream stream(stroka);
//}

bool proverka(istringstream & stream, complex_t & ch)
{
	char op1, op2, op3;
	bool f = 1;
	if (stream >> op1)
	{
		if (op1 == '(')
		{
			if (stream >> ch.real)
			{
				if (stream >> op2)
				{
					if (op2 == ',')
					{
						if (stream >> ch.imag)
						{
							if (stream >> op3)
							{
								if (op3 == ')')
								{
								}
								else
								{
									f = 0;
								}
							}
							else
							{
								f = 0;
							}
						}
						else {
							f = 0;
						}
					}
					else
					{
						f = 0;
					}
				}
				else
				{
					f = 0;
				}
			}
			else
			{
				f = 0;
			}
		}
		else
		{
			f = 0;
		}
	}
	else
	{
		f = 0;
	}
	return f;
}

complex_t add(complex_t a, complex_t b)
{
	complex_t c;
	c.real = a.real + b.real; 
	c.imag = a.imag + b.imag;
	return c;
}

complex_t mul(complex_t a, complex_t b)
{
	complex_t c;
	c.real = a.real*b.real - a.imag*b.imag;
	c.imag = a.imag*b.real + a.real*b.imag;
	return c; 
}

complex_t div(complex_t a, complex_t b)
{
	complex_t c;
	c.real = (a.real*b.real + a.imag*b.imag) / (b.real*b.real + b.imag*b.imag);
	c.imag = (a.imag*b.real - a.real*b.imag) / (b.real*b.real + b.imag*b.imag);
	return c;
}

complex_t sub(complex_t a, complex_t b)
{
	complex_t c;
	c.real = a.real - b.real;
	c.imag = a.imag - b.imag;
	return c;
}

void write(complex_t c)
{
	cout << "(" << c.real << "," << c.imag << ")" << endl;
}


int main()
{
	string stroka;
	getline(cin, stroka);
	istringstream stream(stroka);
	complex_t ch1; complex_t ch2;
	complex_t res;
	char op;
	if (proverka(stream, ch1))
	{
		stream >> op;
		if ((op != '+') && (op != '-') && (op != '*') && (op != '/'))
		{
			cout << "An error has occured while reading input data" << endl;
			return -2;
		}
	}
	else
	{
		cout << "An error has occured while reading input data" << endl;
		return -1;
	}
	if (proverka(stream, ch2))
	{
		if (op == '+')
		{
			res=add(ch1, ch2);
		}
		if (op == '-')
		{
			res=sub(ch1, ch2);
		}
		if (op == '*')
		{
			res=mul(ch1, ch2);
		}
		if (op == '/')
		{
			res=div(ch1, ch2);
		}
	}
	else
	{
		cout << "An error has occured while reading input data" << endl;
		return -3;
	}
	write(res);
	return 0;
}
