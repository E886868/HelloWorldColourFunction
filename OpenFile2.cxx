#include<stdio.h>


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
FILE *fp;
int ch, i, b;
fp=fopen("test2.dmd","r");

for (b = 0; b < 1092; b++)
{
  for (i = 0; i < 16; i++)
  {
        ch = fgetc (fp);
	if (ch == 0)
	{
		set_text_colour(BLUE);
	}
	else
	{
		set_text_colour(RESET);
	}

        printf("%02x ",ch);
  }
  printf("\n");
}

fclose(fp);
return 0;
}

