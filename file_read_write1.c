/* getc(), putc(), getchar(), putchar() */

#include <stdio.h>
#include <stdlib.h>
#define END '%'

int main(void)
{
    char *filename = "example.txt";
    FILE *fp;
    char ch;

    if ((fp = fopen(filename, "w+")) == NULL)   // 注意打开文件的模式
    {
        fprintf(stdout, "The %s failed file to open.", filename);
        exit(EXIT_FAILURE);
    }

    // 将输入字符写入文件中
    while ((ch = getchar()) != END)
        putc(ch, fp);               /* getchar() 与 putc() */
    
    // 打印文件中的字符串
    printf("File contents: \n");
    rewind(fp);
    while ((ch = getc(fp)) != EOF)
        putc(ch, stdout);      // 与putchar(ch); 代码等价
    
    
    if (fclose(fp) != 0)
        fprintf(stdout, "Error in close file %s.\n", filename);

    return 0;
}
