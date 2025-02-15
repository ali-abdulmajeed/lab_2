#include <stdio.h>

void bit_print(int v)
{ 
   int i, mask = 1 << 31;  
   
   for (i = 1; i <= 32; ++i) {
      putchar(((v & mask) == 0) ? 'o' : '1');
      v <<= 1;
      if (i % 8 == 0 && i != 32)
         putchar(' ');
   }
}

int pack(char a, char b, char c, char d)
{ 
   int p = a; 
   p = (p << 8) | b;
   p = (p << 8) | c;
   p = (p << 8) | d;
   return p;
}

int main() {
   printf("abcd =");
   bit_print(pack('a', 'b', 'c', 'd'));
   putchar('\n');
   return 0;
}
