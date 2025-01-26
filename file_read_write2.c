/* fprintf(), fscanf(), printf(), scanf() */

#include <stdio.h>
#include <stdlib.h>
#define MAX 41

int main(void)
{
    char *filename = "example.txt";
    char words[MAX];
    FILE *fp;
    char ch;

    if ((fp = fopen(filename, "w+")) == NULL)
    {
        fprintf(stdout, "File %s create error.\n", filename);
        exit(EXIT_FAILURE);
    }

    // 输入字符串(一行一个单词)数据，并将数据存储在文件中
    while ((fscanf(stdin, "%s", words) == 1) && (*words != '#'))
        fprintf(fp, "%s\n", words);
    
    // 打印文件中的数据
    rewind(fp);
    while ((ch = getc(fp)) != EOF)
        putchar(ch);    // 与putc(ch, stdout)等价

    if (fclose(fp) != 0)
        fprintf(stdout, "Error in close file %s.\n", filename);

    return 0;
}
