/* 文件指针位置 */

#include <stdio.h>
#include <stdlib.h>
#define MAX 50

int main(void)
{
    FILE *fp;
    char *filename = "example.txt";
    
    if ((fp = fopen(filename, "r")) == NULL)
    {
        fprintf(stdout, "File %s create error.\n", filename);
        exit(EXIT_FAILURE);
    }

    fseek(fp, 10, SEEK_SET);
    printf("n1 = %ld\n", ftell(fp));

    fseek(fp, 20, SEEK_CUR);
    printf("n2 = %ld\n", ftell(fp));
    
    fseek(fp, -100, SEEK_END);
    printf("n2 = %ld\n", ftell(fp));
}
