#include <stdio.h>
#include <stdlib.h>

char *decimal_to_binary(int n)
{
   int c, d, count;
   char *pointer;

   count = 0;
   pointer = (char *)malloc(32 + 1);

   if (pointer == NULL)
      exit(EXIT_FAILURE);

   for (c = 5; c >= 0; c--)
   {
      d = n >> c;

      if (d & 1)
         *(pointer + count) = 1 + '0';
      else
         *(pointer + count) = 0 + '0';

      count++;
   }
   *(pointer + count) = '\0';

   return pointer;
}

int main(int argc, char **argv)
{
   int s = 60;
   int e = 123;
   int b = 0;
   char *pointer;
   int num = 6;
   int rem = 0;
   int decimal_val = 0;
   int base = 1;

   for (int c = s; c <= e; c++)
   {
      printf("%d - ", c);
      b = c - s;
      pointer = decimal_to_binary(b);
      while (num > 0)
      {
         rem = num % 10;
         decimal_val = decimal_val + rem * base;
         num = num / 10;
         base = base * 2;
      }
      printf("%s - %d - %d\n", pointer, b, decimal_val);
   }

   free(pointer);

   return 0;
}