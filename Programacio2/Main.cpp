#include <stdio.h>
#include "Tree.h"

int factorial(int f)
{
	int result = 1;
	
	for (int x = 1; x < f; x++)
	{
		result *= x;
	}
	return result;
}

int factorialRecursivitat(int f)
{
	return (f > 1) ? f*factorialRecursivitat(f - 1) : 1;
	
	/*if (f > 1)
	{
		return f * factorialRecursivitat(f - 1);
	}
	else
	{
	    return 1;
	}*/
}

int main(int argc, char** argv)
{
	int x = factorialRecursivitat(5);
	printf("%i", x);
	getchar();
	return(0);
}