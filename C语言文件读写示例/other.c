/* ungetc(), fflush(), setvbuf(), fread(), fwrite() */

#include <stdio.h>
#include <stdlib.h>

void push_back(FILE *fp);     /* ungetc() */
void flush(FILE *fp);         /* fflush() */
void set_buf(FILE *fp);       /* setvbuf() */
void file_bin(FILE *fp2);     /* fwrite() */

int main(void)
{
    // 1
    char *filename = "example.txt";
    FILE *fp;
    fp = fopen(filename, "w+");
    if (fp == NULL)
    {
        printf("File %s read failure.", filename);
        exit(EXIT_FAILURE);
    }
    
    push_back(fp);
    // flush(fp);
    // set_buf(fp);

    // 2
    char *filename2 = "example.bin";
    FILE *fp2;
    fp2 = fopen(filename2, "wb+");
    if (fp2 == NULL)
    {
        printf("File %s read failure.", filename2);
        exit(EXIT_FAILURE);
    }
    file_bin(fp2);


    return 0;

}

void push_back(FILE *fp)      /* ungetc() */
{
    int ch = fgetc(fp);
    printf("Read character: '%c'. Push the character back.\n", ch);
    if (ungetc(ch, fp) == 0)
        printf("The character '%c' was successfully pushed back.\n\n", ch);
    else
    {
        printf("Character '%c' failed to push back.", ch);
        exit(EXIT_FAILURE);
    }

    ch = fgetc(fp);
    printf("Read character again: %c\n", ch);
        
    if (fclose(fp) != 0)
        printf("File closure failed.");
}

void flush(FILE *fp)        /* fflush() */
{
    #define COLS 2      // 定义常量

    char *strs[COLS] = {"This is another line.", "Hello, World!"};

    for (int index = 0; index < COLS; index++)
    {
        // fputs(strs[index], fp);
        fprintf(fp, "%s", *(strs + index));
        if (fflush(fp) == 0)
            printf("Refresh successful, data"
                   "has been written to the file.\n");
    }
   
    if (fclose(fp) != 0)
        printf("File closure failed.");
}


void set_buf(FILE *fp)  /* setvbuf() */
{
    if (setvbuf(fp, NULL, _IOFBF, 3) != 0)
    {
        perror("Failed to set buffer.");
        if (fclose(fp) == 0)
            printf("File closure completed.");
        
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < 1024; i++)
        fprintf(fp, "Line %d\n", i + 1);
    
    if (fclose(fp) == 0)
        printf("File closure completed.");

}

void file_bin(FILE *fp2)    /* fwrite()和fread() */
{
    #define LEN 5
    int data[LEN] = {1, 2, 3, 4, 5};
    int temp[LEN];
    size_t count = sizeof(data) / sizeof(data[0]);  // 此处类型应该一样

    // 写入数据
    if (fwrite(data, sizeof(int), count, fp2) != count)
        printf("Failed to write data.");
    
    // 读出数据
    rewind(fp2);
    if (fread(temp, sizeof(int), count, fp2) != count)
        printf("Failed to read data.");
    for (int index = 0; index < LEN; index++)
        printf("Index %d value = %d\n", index, temp[index]);

    if (fclose(fp2) != 0)
        printf("File closure completed.");
}
