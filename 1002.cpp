#include <cstdio>
const char* pingyin[10] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
int main(int argc, const char * argv[]) {
    char input[101];
    scanf("%s",input);

    int sum = 0;
    for (int i = 0; input[i]; i++) {
        sum += (input[i] - '0');
    }
    int digit[3];
    digit[0] = sum / 100;
    sum %= 100;
    digit[1] = sum / 10;
    sum %= 10;
    digit[2] = sum;
    if (digit[0])
        printf("%s ",pingyin[digit[0]]);
    if (digit[0] || digit[1])
        printf("%s ",pingyin[digit[1]]);
    printf("%s",pingyin[digit[2]]);
    return 0;
}

