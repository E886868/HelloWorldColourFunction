#include <stdio.h>
#include <string.h>

enum colours {BLUE, RED, CYAN, YELLOW, MAGENTA, GREEN, RESET};
void set_text_colour(enum colours colour)
{
       switch (colour)
       {
       case BLUE:
		 printf("\033[0;34m");
             break;
       case RED:
		printf("\033[0;31m");
             break;
       case CYAN:
		printf("\033[0;36m");
             break;
       case YELLOW:
		printf("\033[0;33m");
             break;
       case MAGENTA:
		printf("\033[35m");
             break;
       case GREEN:
		printf("\033[32m");
             break;
       case  RESET:
		printf("\033[0m");
             break;
       }
}



int main()
{
	set_text_colour(BLUE);
	printf("I am blue\n");

 	set_text_colour(RED);
	printf("I am RED\n");

	return 0;
}
