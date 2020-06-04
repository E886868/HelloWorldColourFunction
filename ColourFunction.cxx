#include <stdio.h>
#include <string.h>

char colour(x)
{
	if (x=="b")
	{
		printf("\033[0;34m");
	}
}


int main()
{

	strcpy(str1, colour(b));

	//char str1[1];

	//strcpy(str1, "\033[0;34m");

	strcat(str1, "Hello World\n");

	printf(str1);

	return 0;
}
