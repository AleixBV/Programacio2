#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "BubbleSort.h"


int main()
{
	BubbleSort<int> array(10001);

	srand(time(NULL));

	for (unsigned int i = 0; i < 9999; i++)
	{
		array.pushBack(rand());
	}

	//int x = array.DoBubbleSort();
	int y = array.DoBubbleSortBetter();

	//printf("Standart bubble sort: %i", x);
	printf("\nBetter bubble sort: %i", y);
	getchar();
}







/*#include <stdio.h>
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
	
	//if (f > 1)
	//{
		//return f * factorialRecursivitat(f - 1);
	//}
	//else
	//{
	    //return 1;
	//}
}

int main(int argc, char** argv)
{
	int x = factorialRecursivitat(5);
	printf("%i", x);
	getchar();
	return(0);
}*/