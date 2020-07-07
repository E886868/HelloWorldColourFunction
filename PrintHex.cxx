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


void print_line_ascii(char arr1[], int length)
{
	int i;

	for (i = 0; i < 17; i++)
	{

		char ch = arr1[i];
		if (
                (ch >= ' ' && ch <= '~')
                )

                {
                        printf("%s",ch);
                }

                else
                {
                        printf(".");
                }


	}
}

void print_line_hex(char arr2[], int length)
{
	int i;

	for (i = 0; i < 17; i++)
	{

		char ch = arr2[i];
		printf("%x",ch);

	}
}



int main(int argc, char* argv[])
{
FILE *fp;
int ch, count, x;
char dumpline[17];
char arr, arr1[17], arr2[17];
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

while (ch != EOF)
{
	ch = fgetc (fp); //GETTING FIRST BYTE
	arr[(count%16)] = ch;
	count++;

	if ((count+1)%16==0) //DETERMINING THE END OF A LINE OF HEX
	{
		print_line_ascii(arr1, 17);
                print_line_hex(arr2, 17);
	}
}

printf("\n");
fclose(fp); //CLOSE FILE
return 0;
}
