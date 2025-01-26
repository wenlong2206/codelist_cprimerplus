/* fgets()、fputs() */

#include <stdio.h>
#include <stdlib.h>
#define LEN 3
#define END '#'

int main(void)
{
    char *filename = "example.txt";
    char words[LEN];
    FILE *fp;

    if ((fp = fopen(filename, "w+")) == NULL)
    {
        fprintf(stdout, "File %s create error.\n", filename);
        exit(EXIT_FAILURE);
    }

    // 从屏幕上输入数据，并将其输出到文件中，每次读取一行
    while ((fgets(words, LEN, stdin) != NULL) && (*words != END))
        fputs(words, fp);

    // 从文件中读取数据，并将其打印到屏幕上
    rewind(fp);
    while (fgets(words, LEN, fp) != NULL)
        fputs(words, stdout);

    if (fclose(fp) != 0)
        printf("Error in close file %s", filename);
        
    return 0;
}

