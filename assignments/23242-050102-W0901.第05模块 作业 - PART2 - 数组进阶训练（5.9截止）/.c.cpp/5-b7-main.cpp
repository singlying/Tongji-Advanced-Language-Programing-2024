
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <cmath>
#include <windows.h>
#include "5-b7.h"
using namespace std;

#define g_x 30 //ͼ�λ���ʼx
#define g_y 15 //ͼ�λ���ʼy
#define h_x 30 //������ʼx
#define h_y 20 //������ʼy

int a[10], b[10], c[10]; //��¼Բ��
int p_a, p_b, p_c;  //ջ��ָ��
int count; //����

int delay; //��ʱ
bool is_display; //�Ƿ���ʾ�ڲ�����

//��ջ
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

//��ջ
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

//��ӡջ
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

//ͼ�λ�
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

//��ʱ����
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

//����ʾ����
void main_display(int n, char src, char dst)
{
    my_sleep();
    cct_gotoxy(h_x, h_y);
    cout << "��" << setw(4) << ::count << " ��" << "(" << setw(2)
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

//���ݹ�
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

//��ʼ������
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

//�������븨������
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
    char src, tmp, dst; //src��ʼ tmp�м� dstĿ��

    //input n
    n = input_tools(1, 10, "�����뺺ŵ���Ĳ���(1-10)");

    //input src
    while (1) {
        cout << "��������ʼ��(A-C)" << endl;
        cin >> src;

        //���ͳһΪ��дABC
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
        cout << "������Ŀ����(A-C)" << endl;
        cin >> dst;

        if (dst == 'a' || dst == 'b' || dst == 'c') {
            dst += 'A' - 'a';
        }

        if (dst == 'A' || dst == 'B' || dst == 'C') {
            if (dst == src) {
                cout << "Ŀ����(" << dst << ")��������ʼ��(" << src << ")��ͬ" << endl;
            }
            else
                break;
        }

        cin.ignore(1024, '\n');
    }
    cin.ignore(1024, '\n');

    //��tmp
    tmp = 'A' + 'B' + 'C' - src - dst;

    //��ʼ������
    initia_arr(src, n);

    //�����ƶ��ٶ�
    delay = input_tools(0, 5, "�������ƶ��ٶ�(0-5: 0-���س�������ʾ 1-��ʱ� 5-��ʱ���)");

    //�Ƿ���ʾ�ڲ�����
    is_display = input_tools(0, 1, "�������Ƿ���ʾ�ڲ�����ֵ(0-����ʾ 1-��ʾ)");

    cct_cls();

    cout << "�� " << src << " �ƶ��� " << dst << "���� " << n << " �㣬��ʱ����Ϊ "
        << delay << (is_display ? "����ʾ�ڲ�����ֵ" : "������ʾ�ڲ�����ֵ") << endl;

    if (is_display) {
        cct_gotoxy(h_x, h_y);
        cout << "��ʼ:" << setw(15) << " ";
        print_stack();
    }
    else
        graphic();

    //hanoi
    hanoi(n, src, tmp, dst);

    cct_gotoxy(h_x + 50, h_y + 3);
	system("pause"); //���������ʾ��ͣ��ע�⣺ֻ�ʺ����ض��������ر������ĳ���Ӵ˾���÷�Ϊ0��
	return 0;
}
