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

int main()
{
	string stroka;
	getline(cin, stroka);
	istringstream stream(stroka);
	complex_t ch1; complex_t ch2;
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
			cout << "(" << ch1.real + ch2.real << "," << ch1.imag + ch2.imag << ")" << endl;
		}
		if (op == '-')
		{
			cout << "(" << ch1.real - ch2.real << "," << ch1.imag - ch2.imag << ")" << endl;
		}
		if (op == '*')
		{
			cout << "(" << ch1.real*ch2.real - ch1.imag*ch2.imag << "," << ch1.imag*ch2.real + ch1.real*ch2.imag << ")" << endl;
		}
		if (op == '/')
		{
			cout << "(" << (ch1.real*ch2.real + ch1.imag*ch2.imag) / (ch2.real*ch2.real + ch2.imag*ch2.imag) << "," << (ch1.imag*ch2.real - ch1.real*ch2.imag) / (ch2.real*ch2.real + ch2.imag*ch2.imag) << ")" << endl;
		}
	}
	else
	{
		cout << "An error has occured while reading input data" << endl;
		return -3;
	}
	return 0;
}
