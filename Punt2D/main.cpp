#include "Utilities.h"
#include <stdio.h>

#define TEST(a) (a) ? LOG("Test: " #a " SUCCESS"): LOG("Test: " #a " FAILURE");

int fibonacci(int n)
{
	if (n<2)
		return n;
	else
		return fibonacci(n - 1) + fibonacci(n - 2);
}

int main(int argc, char** args){ }

int fibonacci_iter(unsigned int pos)
{
	int sum = 1;
	int prev = 0;

	if (pos < 2)
		return 1;
	else
	{
		for (unsigned int i = 0; i < pos; i++)
		{
			sum += prev;
			pos *= sum - prev;
		}
		return sum;
	}

}