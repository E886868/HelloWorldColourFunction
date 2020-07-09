#include<stdio.h>
#include<memory.h>

//--------------------
//TEXT COLOUR FUNCTION
//--------------------
//Function returns ANSI colour codes
//to change text colour.
//E.G. 'set_text_colour(YELLOW);'

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

//------------------------------
//PRINT ASCII CHARACTOR FUNCTION
//------------------------------
//Determines whether to print a byte
//of data, 'ch', as its ascii charactor
//or a dot '.'.
//These charactors are then stored in
//array, 'dumpline', to be printed later
//in the main code.

void ascii(int ch, char* dumpline, int count)
{

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


}

//-------------------
//HEX COLOUR FUNCTION
//-------------------
//setting hex values equal to '0' to blue
//and hex values that do not equal to '0'
//to white.

void hex_colour(int ch)
{

	if (ch == 0)
                {
                        set_text_colour(BLUE);
                }
                else
                {
                        set_text_colour(RESET);
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

        ascii(ch, dumpline, count);

        if (ch != EOF)
        {

	hex_colour(ch);

        printf ("%02x ", ch); //PRINTING HEX BYTES

        }

                else
                {
                        break;
                }


         if ((count+1)%16==0) //DETERMINING THE END OF A LINE OF HEX
                {
                        set_text_colour(BOLDYELLOW);
                        printf("%s",dumpline);
                        printf ("\n");
                        printf("%08x  ",count+1); //PRINTING NEXT ADDRESS ON NEW LINE
                }


        count++;


}




printf("\n");
fclose(fp); //CLOSE FILE
return 0;
}
