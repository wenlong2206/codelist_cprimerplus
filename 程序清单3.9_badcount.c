/* badcount.c 参数错误的情况 */

#include <stdio.h>

int main(void)
{
    int n = 4;
    int m = 5;
    float f = 7.0f;
    float g = 8.0f;

    printf("%d\n", n, m);  /* 参数多了一个 */
    printf("%d %d %d\n", n);  /* 参数少了两个 */
    printf("%d %d\n", f, g);  /* 值的类型不匹配 */

    return 0;
}
