#include<stdio.h>
#include<memory.h>


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
int ch, count, x;
char dumpline[17];
memset(dumpline,0,17);
fp=fopen("test2.dmd","r");
count = 0;

set_text_colour(BOLDYELLOW);
printf("Address   ");

for (x = 0; x < 16; x++)
{
	set_text_colour(BOLDYELLOW);
        printf("%x  ",x);

}

printf("Dump");
printf("\n");
printf("%08x  ",count);

while (true)
{
	ch = fgetc (fp);

	if (
		(ch >= ' ' && ch <= '~')
	   )

	{
		dumpline[count%16] = ch;
	}

	else
	{
		dumpline[count%16] = '.';
	}

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

	printf ("%02x ", ch);

        }

		else
		{
			break;
		}


	 if ((count+1)%16==0)
        	{
			set_text_colour(BOLDYELLOW);
			printf("%s",dumpline);
                	printf ("\n");
			printf("%08x  ",count+1);
        	}


	count++;


}




printf("\n");
fclose(fp);
return 0;
}
