/* platinum.c your weight in platinum */

#include <stdio.h>

int main(void)
{
    float weight, value; /* 体重，相等重量的白金价值 */

    printf("Are you worth your weight in platinum?\n");
    printf("Let's check it out.\n");
    printf("Please enter your weight int pounds: ");

    scanf("%f", &weight); /* 获取用户的输入 */
    /* 假设白金的价格是每盎司$1700，14.5833用于把英镑常衡转换为金衡盎司*/
    value = 1700.0 * weight * 14.5833;

    printf("Your weight in platinum is worth $%.2f.\n", value);
    printf("You are easily worth that! If platinum prices drop,\n");
    printf("eat more to maintain your value.\n");

    return 0;
}
