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

void unpack(int p, char *a, char *b, char *c, char *d)
{
    *d = p & 0xFF;
    *c = (p >> 8) & 0xFF;
    *b = (p >> 16) & 0xFF;
    *a = (p >> 24) & 0xFF;
}

int main() {
    int packed = pack('a', 'b', 'c', 'd'); // i will use it more than once


    printf("abcd =");
    bit_print(packed);
    putchar('\n');

    char a, b, c, d;
    unpack(packed, &a, &b, &c, &d);
    printf("Unpacked: %c %c %c %c\n", a, b, c, d);
    
    return 0;
}

