
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <cmath>
#include <windows.h>
#include "5-b7.h"
using namespace std;

#define g_x 30 //图形化初始x
#define g_y 15 //图形化初始y
#define h_x 30 //步数初始x
#define h_y 20 //步数初始y

int a[10], b[10], c[10]; //记录圆柱
int p_a, p_b, p_c;  //栈顶指针
int count; //计数

int delay; //延时
bool is_display; //是否显示内部数组

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
void print_stack()
{
    cout << " A:";
    for (int i = 0; i < 10; i++) {
        if (i < p_a)
            cout << setw(2) << a[i];
        else
            cout << "  ";
    }

    printf(" B:");
    for (int i = 0; i < 10; i++) {
        if (i < p_b)
            cout << setw(2) << b[i];
        else
            cout << "  ";
    }

    printf(" C:");
    for (int i = 0; i < 10; i++) {
        if (i < p_c)
            cout << setw(2) << c[i];
        else
            cout << "  ";
    }

    //cout << endl;
}

//图形化
void graphic()
{
    cct_gotoxy(g_x, g_y);
    cout << "=========================";
    cct_gotoxy(g_x, g_y + 1);
    cout << "  A         B         C  ";
    
    for (int i = 9; i > -1; i--) {
        cct_gotoxy(g_x + 2, g_y - i - 1);
        if (i < p_a)
            cout << a[i];
        else
            cout << " ";
    }

    for (int i = 9; i > -1; i--) {
        cct_gotoxy(g_x + 12, g_y - i - 1);
        if (i < p_b)
            cout << b[i];
        else
            cout << " ";
    }

    for (int i = 9; i > -1; i--) {
        cct_gotoxy(g_x + 22, g_y - i - 1);
        if (i < p_c)
            cout << c[i];
        else
            cout << " ";
    }
}

//延时函数
void my_sleep()
{
    if (!delay) {
        while (_getch() != 13) {
        };
    }
    else {
        int sleep_time = static_cast<int>(0.4 * (pow(6 - delay, 5) - 3 * pow(6 - delay, 3) + 2));
        Sleep(sleep_time);
    }
}

//主显示函数
void main_display(int n, char src, char dst)
{
    my_sleep();
    cct_gotoxy(h_x, h_y);
    cout << "第" << setw(4) << ::count << " 步" << "(" << setw(2)
        << n << "): " << src << "-->" << dst;
    pop(src);
    push(dst, n);
    if (is_display) {
        print_stack();
    }
    if (is_display)
        my_sleep();
    graphic();
}

//主递归
void hanoi(int n, char src, char tmp, char dst)
{
    if (n == 1) {
        ::count++;
        main_display(n, src, dst);
        return;
    }
    else {
        hanoi(n - 1, src, dst, tmp);
        ::count++;
        main_display(n, src, dst);
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

//整形输入辅助函数
int input_tools(const int min, const int max, const char prompt[])
{
    int input;
    while (1) {
        cout << prompt << endl;
        if (cin >> input) {
            if (input >= min && input <= max) {
                cin.ignore(1024, '\n');
                return input;
            }
        }
        else {
            cin.clear();
            cin.ignore(1024, '\n');
        }
    }
}

int main()
{
    int n;
    char src, tmp, dst; //src起始 tmp中间 dst目标

    //input n
    n = input_tools(1, 10, "请输入汉诺塔的层数(1-10)");

    //input src
    while (1) {
        cout << "请输入起始柱(A-C)" << endl;
        cin >> src;

        //结果统一为大写ABC
        if (src == 'a' || src == 'b' || src == 'c') {
            src += 'A' - 'a';
            break;
        }
        else if (src == 'A' || src == 'B' || src == 'C') {
            break;
        }

        cin.ignore(1024, '\n');
    }
    cin.ignore(1024, '\n');

    //input dst
    while (1) {
        cout << "请输入目标柱(A-C)" << endl;
        cin >> dst;

        if (dst == 'a' || dst == 'b' || dst == 'c') {
            dst += 'A' - 'a';
        }

        if (dst == 'A' || dst == 'B' || dst == 'C') {
            if (dst == src) {
                cout << "目标柱(" << dst << ")不能与起始柱(" << src << ")相同" << endl;
            }
            else
                break;
        }

        cin.ignore(1024, '\n');
    }
    cin.ignore(1024, '\n');

    //求tmp
    tmp = 'A' + 'B' + 'C' - src - dst;

    //初始化数组
    initia_arr(src, n);

    //输入移动速度
    delay = input_tools(0, 5, "请输入移动速度(0-5: 0-按回车单步演示 1-延时最长 5-延时最短)");

    //是否显示内部数组
    is_display = input_tools(0, 1, "请输入是否显示内部数组值(0-不显示 1-显示)");

    cct_cls();

    cout << "从 " << src << " 移动到 " << dst << "，共 " << n << " 层，延时设置为 "
        << delay << (is_display ? "，显示内部数组值" : "，不显示内部数组值") << endl;

    if (is_display) {
        cct_gotoxy(h_x, h_y);
        cout << "初始:" << setw(15) << " ";
        print_stack();
    }
    else
        graphic();

    //hanoi
    hanoi(n, src, tmp, dst);

    cct_gotoxy(h_x + 50, h_y + 3);
	system("pause"); //最后用这句表示暂停（注意：只适合于特定程序，无特别声明的程序加此句则得分为0）
	return 0;
}
