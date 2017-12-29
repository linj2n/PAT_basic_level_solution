//1012. 数字分类 (20)
//17:19
//18:02
//给定一系列正整数，请按要求对数字进行分类，并输出以下5个数字：
//
//A1 = 能被5整除的数字中所有偶数的和；
//A2 = 将被5除后余1的数字按给出顺序进行交错求和，即计算n1-n2+n3-n4...；
//A3 = 被5除后余2的数字的个数；
//A4 = 被5除后余3的数字的平均数，精确到小数点后1位；
//A5 = 被5除后余4的数字中最大数字。
//输入格式：
//
//每个输入包含1个测试用例。每个测试用例先给出一个不超过1000的正整数N，随后给出N个不超过1000的待分类的正整数。数字间以空格分隔。
//
//输出格式：
//
//对给定的N个正整数，按题目要求计算A1~A5并在一行中顺序输出。数字间以空格分隔，但行末不得有多余空格。
//
//若其中某一类数字不存在，则在相应位置输出“N”。
//
//输入样例1：
//13 1 2 3 4 5 6 7 8 9 10 20 16 18
//输出样例1：
//30 11 2 9.7 9
//输入样例2：
//8 1 2 4 5 6 7 9 16
//输出样例2：
//N 11 2 N 9

#include <cstdio>
int main(int argc, const char * argv[]) {
    int n;
    scanf("%d",&n);
    int x;
    int a1 = 0,count1 = 0,a2 = 0,count2 = 0,a3 = 0,a4 = 0,count4 = 0,a5 = -1;
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&x);
        if(x % 5 == 0)
        {
            if (x % 2 == 0)
            {
                count1++;
                a1 += x;
            }
        }else if (x % 5 == 1)
        {
            if (count2 % 2 == 0)
            {
                a2 += x;
            }else{
                a2 -= x;
            }
            count2 ++;
        }else if (x % 5 == 2)
        {
            a3 ++;
            
        }else if (x % 5 == 3)
        {
            a4 += x;
            count4 ++;
        }else if (x % 5 == 4)
        {
            if (a5 < x)
            {
                a5 = x;
            }
        }
    }
    if (count1 != 0)
    {
        printf("%d ",a1);
    }else{
        printf("N ");
    }
    if (count2 != 0)
    {
        printf("%d ",a2);
    }else{
        printf("N ");
    }
    if (a3 != 0)
    {
        printf("%d ",a3);
    }else{
        printf("N ");
    }
    if (count4 != 0)
    {
        printf("%.1lf ",((double)a4) / count4);
    }else{
        printf("N ");
    }
    if (a5 >= 0)
    {
        printf("%d",a5);
    }else{
        printf("N");
    }
    return 0;
}

