#include<stdio.h>
#include<memory.h>

//TEXT COLOUR FUNCTION
enum colours {BLUE, RED, CYAN, YELLOW, MAGENTA, GREEN, RESET, BOLDYELLOW};
void set_text_colour(enum colours colour)
{
       switch (colour)
       {
       case BLUE:
                 printf("\033[0;34m"); //TEXT COLOUR BLUE
             break;
       case RED:
                printf("\033[0;31m"); //TEXT COLOUR RED
             break;
       case CYAN:
                printf("\033[0;36m"); //TEXT COLOUR CYAN
             break;
       case YELLOW:
                printf("\033[0;33m"); //TEXT COLOUR YELLOW
             break;
       case MAGENTA:
                printf("\033[35m"); //TEXT COLOUR MAGENTA
             break;
       case GREEN:
                printf("\033[32m"); //TEXT COLOUR GREEN
             break;
       case  RESET:
                printf("\033[0m"); //TEXT COLOUR TO DEFAULT (WHITE)
             break;
       case  BOLDYELLOW:
		printf("\033[01;33m"); //TEXT COLOUR BOLD YELLOW
	     break;
       }
}


int main(int argc, char* argv[])
{
FILE *fp;
int ch, count, x;
char dumpline[17];
memset(dumpline,0,17); //CLEARING ARRAY MEMORY
fp=fopen("test2.dmd","r"); //POINTING TO .DMD FILE
count = 0;

set_text_colour(BOLDYELLOW);
printf("Address   "); //COLUMN TITLE 'ADDRESS'

for (x = 0; x < 16; x++) //PRINTING HEX HEADING 0-F
{
	set_text_colour(BOLDYELLOW);
        printf("%x  ",x);

}

printf("Dump"); //COLUMN TITLE 'DUMP'
printf("\n");
printf("%08x  ",count); //PRINTING FIRST ADDRESS '00000000'

while (true)
{
	ch = fgetc (fp); //GETTING FIRST BYTE


	//DETERMINING WHICH CHARACTORS TO PRINT IN DUMP COLUMN
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
		//SETTING HEX COLOUR DEPENDING ON WHETHER HEX IS EQUAL TO '00' OR NOT
		if (ch == 0)
        	{
                	set_text_colour(BLUE);
        	}
	        else
        	{
                	set_text_colour(RESET);
        	}

	printf ("%02x ", ch); //PRINTING HEX BYTES

        }

		else
		{
			break;
		}


	 if ((count+1)%16==0) //DETERMINING THE END OF A LINE OF HEX
        	{
			set_text_colour(BOLDYELLOW);
			printf("%s",dumpline); //PRINTING ARRAY IN ASCII CHARACTORS IN DUMP COLUMN
                	printf ("\n");
			printf("%08x  ",count+1); //PRINTING NEXT ADDRESS ON NEW LINE 
        	}


	count++;


}




printf("\n");
fclose(fp); //CLOSE FILE
return 0;
}
