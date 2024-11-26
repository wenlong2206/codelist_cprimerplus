/* bases.c 以十进制、八进制、十六进制打印十进制数100 */
/* short int / int / long int /long long int */
/* short / int / long / long long */
/* unsigned int / unsigned */

#include <stdio.h>

int main(void)
{
    int x = 100;

    printf("dec = %d; octal = %o; hex = %x\n", x, x, x);
    printf("dec = %d; octal = %#o; hex = %#x\n", x, x, x);

    return 0;
}
