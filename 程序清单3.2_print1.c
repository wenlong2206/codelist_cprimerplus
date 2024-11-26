 /* print.c 演示printf()的一些特性 */

 #include <stdio.h>

 int main(void)
 {
    int ten = 10, two = 2;

    printf("Doing it right: ");
    printf("%d minus %d is %d\n", ten, 2, ten - two);
    printf("Doing it wrong: ");
    printf("%d minus %d is %d\n", ten, two * 2, ten); // 若遗漏参数，则会打印出意想不到的结果

    return 0;
 }

