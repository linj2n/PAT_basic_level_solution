//1016. 部分A+B (15)
//17:43
//17:53
//正整数A的“DA（为1位整数）部分”定义为由A中所有DA组成的新整数PA。例如：给定A = 3862767，DA = 6，则A的“6部分”PA是66，因为A中有2个6。
//
//现给定A、DA、B、DB，请编写程序计算PA + PB。
//
//输入格式：
//
//输入在一行中依次给出A、DA、B、DB，中间以空格分隔，其中0 < A, B < 1010。
//
//输出格式：
//
//在一行中输出PA + PB的值。
//
//输入样例1：
//3862767 6 13530293 3
//输出样例1：
//399
//输入样例2：
//3862767 1 13530293 8
//输出样例2：
//0
#include <cstdio>
int main(int argc, const char * argv[]) {
    long long a, da, b, db;
    long long pa = 0,pb = 0;
    scanf("%lld%lld%lld%lld",&a,&da,&b,&db);
    while (a != 0)
    {
        if (a % 10 == da)
        {
            pa = pa * 10 + da;
        }
        a = a / 10;
    }
    while (b != 0)
    {
        if (b % 10 == db)
        {
            pb = pb * 10 + db;
        }
        b = b / 10;
    }
    printf("%lld\n", pa + pb);
    return 0;
}

