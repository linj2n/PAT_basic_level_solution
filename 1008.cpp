//1008. 数组元素循环右移问题 (20)
//2h
//
//一个数组A中存有N（N>0）个整数，在不允许使用另外数组的前提下，将每个整数循环向右移M（M>=0）个位置，即将A中的数据由（A0 A1……AN-1）变换为（AN-M …… AN-1 A0 A1……AN-M-1）（最后M个数循环移至最前面的M个位置）。如果需要考虑程序移动数据的次数尽量少，要如何设计移动的方法？
//
//输入格式：每个输入包含一个测试用例，第1行输入N ( 1<=N<=100)、M（M>=0）；第2行输入N个整数，之间用空格分隔。
//
//输出格式：在一行中输出循环右移M位以后的整数序列，之间用空格分隔，序列结尾不能有多余空格。
//
//输入样例：
//6 2
//1 2 3 4 5 6
//输出样例：
//5 6 1 2 3 4

#include <cstdio>
int gcd(int a, int b)
{
    if (b == 0) return a;
    return gcd(b,a%b);
}
int main(int argc, const char * argv[]) {
    int n,m;
    int arr[101];
    scanf("%d%d",&n,&m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    
    m = m % n;  //修正m
    if (m != 0){    //若m == 0, 直接输出数组；
        int d = gcd(n,m);   //d 为m何n的最大公约数
        for (int i = n - m; i <= n - m + d - 1; i++ )
        {
            int temp = arr[i];
            int curr = i,pos = (curr - m + n) % n;
            do
            {
                int tempPos = pos;
                arr[curr] = arr[pos];
                pos = (curr - m + n) % n;
                curr = tempPos;
            }while(pos != i);
            arr[curr] = temp;
        }
    }
    
    //输出结果
    for (int i = 0; i < n; i++)
    {
        printf("%d",arr[i]);
        if (i != n - 1)
        {
            printf(" ");
        }
    }
    
    return 0;
}

