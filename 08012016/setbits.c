/* setbits (x,p,n,y) returns x with n bits that begin at position p set to rightmost n bits of y , leaving other bits unchanged*/
#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);

int main(void)
{
    printf("%u\n", setbits(5732, 6, 3, 9823));
    return 0;
}

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    // xxxxx00000xxxxx
    unsigned a = x & ~(~(~0U << n) << (p + 1 - n));

    // 00000yyyyy00000
    unsigned b = (y & ~(~0U << n)) << (p + 1 - n);

    // xxxxxyyyyyxxxxx
    return a | b;
}