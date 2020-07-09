#include <memory.h>
#include <stdio.h>

//--------------------
// TEXT COLOUR FUNCTION
//--------------------
// Function returns ANSI colour codes
// to change text colour.
// E.G. 'set_text_colour(YELLOW);'

enum colours { BLUE, RED, CYAN, YELLOW, MAGENTA, GREEN, RESET, BOLDYELLOW };
void set_text_colour(enum colours colour) {
  switch (colour) {
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
  case RESET:
    printf("\033[0m");
    break;
  case BOLDYELLOW:
    printf("\033[01;33m");
    break;
  }
}

//------------------------------
// PRINT ASCII CHARACTOR FUNCTION
//------------------------------
// Determines whether to print a byte
// of data, 'ch', as its ascii charactor
// or a dot '.'.
// These charactors are then stored in
// array, 'dumpline', to be printed later
// in the main code.

char get_printable_char(int ch) {

  if ((ch >= ' ' && ch <= '~'))

  {
    return ch;
  }

  else {
    return '.';
  }
}

//---------------
// SET_HEX_COLOUR
//---------------
// setting hex values equal to '0' to blue
// and hex values that do not equal to '0'
// to white.

void hex_colour(int ch) {

  if (ch == 0) {
    set_text_colour(BLUE);
  } else {
    set_text_colour(RESET);
  }
}

int main(int argc, char *argv[]) {

  if (argc != 2) {
    printf("usage: %s <filename>\n", argv[0]);
    return -1;
  }

  char *filename = argv[1];

  FILE *fp;
  int ch, count, x;
  char dumpline[17];
  memset(dumpline, 0, 17);   // CLEARING ARRAY MEMORY
  fp = fopen(filename, "r"); // POINTING TO .DMD FILE
  count = 0;

  set_text_colour(BOLDYELLOW);
  printf("Address   "); // COLUMN TITLE 'ADDRESS'

  for (x = 0; x < 16; x++) // PRINTING HEX HEADING 0-F
  {
    set_text_colour(BOLDYELLOW);
    printf("%x  ", x);
  }

  printf("Dump"); // COLUMN TITLE 'DUMP'
  printf("\n");
  printf("%08x  ", count); // PRINTING FIRST ADDRESS '00000000'

  while (true) {
    ch = fgetc(fp); // GETTING FIRST BYTE

    if (ch != EOF) {

      hex_colour(ch);

      printf("%02x ", ch); // PRINTING HEX BYTES

      dumpline[count % 16] = get_printable_char(ch);

    }

    else {
      break;
    }

    count++;

    if (count % 16 == 0) // DETERMINING THE END OF A LINE OF HEX
    {
      set_text_colour(BOLDYELLOW);
      printf("%s", dumpline);
      printf("\n");
      printf("%08x  ", count); // PRINTING NEXT ADDRESS ON NEW LINE
    }
  }

  printf("\n");
  fclose(fp); // CLOSE FILE
  return 0;
}
