#include "Utilities.h"
#include <stdio.h>
#include "p2Rectangle.h"
#include "String.h"

#define TEST(a) (a) ? printf("Test: " #a " SUCCESS"): printf("Test: " #a " FAILURE");

int fibonacci(int n)
{
	if (n<2)
		return n;
	else
		return fibonacci(n - 1) + fibonacci(n - 2);
}

int main(int argc, char** args)
{
	/*p2Rectangle <int> r(10, 10, 40, 50);
	p2Rectangle <int> r2(r);
	TEST(r.position.x == 10);
	TEST(r2.position.y == 10);
	TEST(r2.GetArea() == 2000);
	TEST(r2.Intersects(r) == true);*/

	String s("Hola Mundo");
	TEST(s.DoubleVocals() == 4);
	TEST(s == "Hoolaa Muundoo");

	system("pause");
	return 0;
}


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