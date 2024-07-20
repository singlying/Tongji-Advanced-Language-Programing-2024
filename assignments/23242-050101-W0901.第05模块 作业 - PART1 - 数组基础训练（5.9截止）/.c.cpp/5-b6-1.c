
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int a[10], b[10], c[10]; //记录圆柱
int p_a, p_b, p_c;  //栈顶指针
int count; //计数

//入栈
void push(char arr, int x)
{
    switch (arr) {
        case 'A':
            if (p_a != 10)
                a[p_a++] = x;
            break;
        case 'B':
            if (p_b != 10)
                b[p_b++] = x;
            break;
        case 'C':
            if (p_c != 10)
                c[p_c++] = x;
            break;
    }
    
}

//出栈
int pop(char arr)
{
    switch (arr) {
        case 'A':
            if (p_a)
                return a[--p_a];
            break;
        case 'B':
            if (p_b)
                return b[--p_b];
            break;
        case 'C':
            if (p_c)
                return c[--p_c];
            break;
    }
    return -1;
}

//打印栈
void print()
{
    printf(" A:");
    for (int i = 0; i < 10; i++) {
        if (i < p_a)
            printf("%2d", a[i]);
        else
            printf("  ");
    }

    printf(" B:");
    for (int i = 0; i < 10; i++) {
        if (i < p_b)
            printf("%2d", b[i]);
        else
            printf("  ");
    }

    printf(" C:");
    for (int i = 0; i < 10; i++) {
        if (i < p_c)
            printf("%2d", c[i]);
        else
            printf("  ");
    }

    printf("\n");
}

//递归函数
void hanoi(int n, char src, char tmp, char dst)
{
    if (n == 1) {
        count++;
        printf("第%4d 步(%2d): %c-->%c", count, n, src, dst);
        pop(src);
        push(dst, n);
        print();
        return;
    }
    else {
        hanoi(n - 1, src, dst, tmp);
        count++;
        printf("第%4d 步(%2d): %c-->%c", count, n, src, dst);
        pop(src);
        push(dst, n);
        print();
        hanoi(n - 1, tmp, src, dst);
    }
}

//初始化数组
void initia_arr(int arr, int n) {
    switch (arr) {
        case 'A':
            for (int i = 0; i < n; i++) {
                a[i] = n - i;
                p_a++;
            }
            break;
        case 'B':
            for (int i = 0; i < n; i++) {
                b[i] = n - i;
                p_b++;
            }
            break;
        case 'C':
            for (int i = 0; i < n; i++) {
                c[i] = n - i;
                p_c++;
            }
            break;
    }
}

int main()
{
    int n;
    char src, tmp, dst; //src起始 tmp中间 dst目标

    while (1) { //input n
        printf("请输入汉诺塔的层数(1-10)\n");
        int ret = scanf("%d", &n);
        if (ret != 1 || n < 1 || n > 10) {
            while (getchar() != '\n') {
            };
        }
        else {
            while (getchar() != '\n') {
            };
            break;
        }
    }

    while (1) { //input src
        printf("请输入起始柱(A-C)\n");
        scanf("%c", &src);

        //结果统一为大写ABC
        if (src == 'a' || src == 'b' || src == 'c') {
            src += 'A' - 'a';
            break;
        }
        else if (src == 'A' || src == 'B' || src == 'C') {
            break;
        }

        while (getchar() != '\n') {
        };
    }
    while (getchar() != '\n') {
    };

    while (1) { //input dst
        printf("请输入目标柱(A-C)\n");
        scanf("%c", &dst);

        if (dst == 'a' || dst == 'b' || dst == 'c') {
            dst += 'A' - 'a';
        }

        if (dst == 'A' || dst == 'B' || dst == 'C') {
            if (dst == src) {
                printf("目标柱(%c)不能与起始柱(%c)相同\n", dst, src);
            }
            else
                break;
        }

        while (getchar() != '\n') {
        };
    }
    while (getchar() != '\n') {
    };

    //求tmp
    tmp = 'A' + 'B' + 'C' - src - dst;

    //初始化数组
    initia_arr(src, n);

    //hanoi
    printf("初始:%15c", ' ');
    print();
    hanoi(n, src, tmp, dst);

    return 0;
}