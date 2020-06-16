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
int ch;
fp=fopen("test2.dmd","r");


while (ch != EOF)
{
        ch = fgetc (fp);

        if (ch != EOF)
        {

        printf ("%x",ch);

        }

}

fclose(fp);
return 0;
}

