#include<stdio.h>
int main()
{
FILE *fp;
int ch, i;
fp=fopen("test.DMD","r");

for (i = 1; i < 17; i++)
  {
	ch = fgetc (fp);
	printf("%02x ",ch);

  }

printf("\n");

for (i = 1; i < 17; i++)
  {
        ch = fgetc (fp);
        printf("%02x ",ch);

  }

printf("\n");

for (i = 1; i < 17; i++)
  {
        ch = fgetc (fp);
        printf("%02x ",ch);

  }

printf("\n");

for (i = 1; i < 17; i++)
  {
        ch = fgetc (fp);
        printf("%02x ",ch);

  }

printf("\n");

for (i = 1; i < 17; i++)
  {
        ch = fgetc (fp);
        printf("%02x ",ch);

  }


fclose(fp);
return 0;
}
