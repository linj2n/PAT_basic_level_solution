//1018. 锤子剪刀布 (20)
//18:09
//19:35
//现给出两人的交锋记录，请统计双方的胜、平、负次数，并且给出双方分别出什么手势的胜算最大。
//
//输入格式：
//
//输入第1行给出正整数N（<=105），即双方交锋的次数。随后N行，每行给出一次交锋的信息，即甲、乙双方同时给出的的手势。C代表“锤子”、J代表“剪刀”、B代表“布”，第1个字母代表甲方，第2个代表乙方，中间有1个空格。
//
//输出格式：
//
//输出第1、2行分别给出甲、乙的胜、平、负次数，数字间以1个空格分隔。第3行给出两个字母，分别代表甲、乙获胜次数最多的手势，中间有1个空格。如果解不唯一，则输出按字母序最小的解。
//
//输入样例：
//10
//C J
//J B
//C B
//B B
//B C
//C C
//C B
//J B
//B C
//J J
//输出样例：
//5 3 2
//2 3 5
//B B
#include <cstdio>

#define B 0;
#define C 1;
#define J 2;
int charToKey(char c){
    if (c == 'B') {return 0;}
    else if (c == 'C') {return 1;}
    else {return 2;}
}

int main(int argc, const char * argv[]) {
    int n;
    scanf("%d",&n);
    int W = 0, P = 1, L = 2;
    int a_result[3] = {0}, b_result[3] = {0};
    int a_ges[3] = {0}, b_ges[3] = {0};
    for (int i = 0; i < n; i++)
    {
        char g1, g2;
        getchar();
        scanf("%c %c",&g1,&g2);
        int k1 = charToKey(g1);
        int k2 = charToKey(g2);
        if (k1 == k2){
            a_result[P]++;
            b_result[P]++;
        }else if((k1 + 1) % 3 == k2){
            a_result[W]++; b_result[L]++;
            a_ges[k1] ++;
        }else{
            b_result[W]++; a_result[L]++;
            b_ges[k2]++;
        }
    }
    
    char ges[3] = {'B','C','J'};
    int t1 = 0,t2 = 0,a_times = 0,b_times = 0;
    for (int i = 0; i< 3; i++)
    {
        if (a_times < a_ges[i]){a_times = a_ges[i]; t1 = i;}
    }
    for (int i = 0; i < 3; i++)
    {
        if (b_times < b_ges[i]){b_times = b_ges[i];t2 = i;}
    }
    printf("%d %d %d\n",a_result[W],a_result[P],a_result[L]);
    printf("%d %d %d\n",b_result[W],b_result[P],b_result[L]);
    printf("%c %c\n",ges[t1],ges[t2]);
    return 0;
}

