template<class TYPE>
void swap(TYPE& a, TYPE& b)
{
	TYPE tmp;
	tmp = a;
	a = b;
	b = tmp;
}


unsigned int fib(unsigned int pos)
{
	unsigned int x = 0;

	if (pos = 0)
	{
		return 1;
	}

	else
		x = fib(pos--);

	return (x + fib(pos--));
}