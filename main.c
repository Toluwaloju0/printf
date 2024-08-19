#include "main.h"
#include <stdio.h>

int main(void)
{

	int a, b;

	a = _printf("i am null %s\n", (char *)0);
	b = 4;
	printf("--------------------------\na - %d\nb- %d\n", a, b);

	return 0;
}
