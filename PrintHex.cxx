#include<stdio.h>


enum colours {BLUE, RED, CYAN, YELLOW, MAGENTA, GREEN, RESET, BOLDYELLOW};
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
       case  BOLDYELLOW:
		printf("\033[01;33m");
	     break;
       }
}



int main(int argc, char* argv[])
{
FILE *fp;
int ch, counter, header, address;
fp=fopen("test2.dmd","r");
counter = 1;
header = 0;
address = 0;
set_text_colour(BOLDYELLOW);
printf("Address   ");

while (true)
{
	if (header<16)
	{
		set_text_colour(BOLDYELLOW);
		printf("%x  ",header);
		header++;
	}
	else
	{
		break;
	}
}

printf("\n");
printf("%08x  ",address);
address++;

while (true)
{
        ch = fgetc (fp);


        if (ch != EOF)
        {
		if (ch == 0)
        	{
                	set_text_colour(BLUE);
        	}
	        else
        	{
                	set_text_colour(RESET);
        	}

	printf ("%02x ",ch);

        }

		else
		{
			break;
		}

	 if (counter%16==0)
        	{
			set_text_colour(BOLDYELLOW);
                	printf ("\n");
			printf("%08x  ",address);
        	}


	counter++;
	address++;

}

printf("\n");
fclose(fp);
return 0;
}
