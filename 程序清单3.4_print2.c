/* print2.c 更多printf()的特性 */

#include <stdio.h>

int main(void)
{
    unsigned short un2 = 66666;
    unsigned long int un3 = 333333;
    unsigned long long int un4 = 55555555;
    int mid = 2000;

    unsigned int un = 3000000000; /* int为32位和short为16位的系统 */
    short end = 200;
    long big = 65537;
    long long verybig = 12345678908642;

    printf("un = %u and not %d\n", un, un);
    printf("end = %hd and %d\n", end, end);
    printf("big = %ld and not %hd\n", big, big);
    printf("verybig = %lld and not %ld\n\n", verybig, verybig);

    printf("nu2 = %hu, un = %u, un2 = %ld, un3 = %lld\n", un2, un, un3, un4);
    printf("end = %hd, mid = %d, big = %ld, verybig = %lld\n", end, mid, big, verybig);
    printf("un4_o = %llo, un4 = %llu, un4_x = %llx", un4, un4, un4);

    return 0;
}