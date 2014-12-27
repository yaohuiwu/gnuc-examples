#include <stdio.h>
#include "calculator.h"
int main()
{
    double d1 , d2;
    puts("请输入两个数字，以一个空格隔开:");
    scanf("%lf %lf",&d1,&d2);
    double sum = plus(d1,d2);
    puts("两个数之和为:");
    printf("%lf%s",sum,"\n");
    return 0;
}
