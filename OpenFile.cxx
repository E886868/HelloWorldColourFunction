#include<stdio.h>
int main()
{
FILE *fp;
int ch, i, b;
fp=fopen("test.DMD","r");

for (b = 1; b < 16; b++)
{
	for (i = 1; i < 17; i++)
  {
        ch = fgetc (fp);
        printf("%02x ",ch);
  }
	printf("\n");
}

fclose(fp);
return 0;
}
