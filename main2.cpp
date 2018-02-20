class complex_t
{	
public:
	complex_t()
	{
		real = 0.0f;
		imag = 0.0f;
		++count;
	}
	complex_t add(complex_t other) const //complex_t const * const
	{
		complex_t result;
		result.real = this->real + other.real;
		result.imag = this->imag + other.imag;
		return result;
	}

	std::ostream & output(std::ostream & stream) const // complex_t * const
	{
		return stream << '(' << real << ", " << imag << ')';
	}
	~complex_t()
	{

	}
	static unsigned int count;
	void set_real(float value)
	{
		if (value > 0.0f)
		{
			real = value;
		}		
	}
private:
	float real;
	float imag;
};

unsigned int complex_t::count = 0;

int main()
{
	complex_t complex1;
	complex_t complex2;
	complex_t result = complex1.add(complex2);
	result.output(std::cout);
	std::cout << complex_t::count;
	complex1.set_real(0.0f);
    return 0;
}
