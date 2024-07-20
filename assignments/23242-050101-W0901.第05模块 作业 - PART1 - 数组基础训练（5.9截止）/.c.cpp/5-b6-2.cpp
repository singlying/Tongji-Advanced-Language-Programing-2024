
#include<iostream>
#include <iomanip>
using namespace std;

int row[3][10]; //��¼Բ��
int top[3];  //ջ��ָ��
int count; //����

//��ջ
void push(char arr, int x)
{
    switch (arr) {
        case 'A':
            if (top[0] != 10)
                row[0][top[0]++] = x;
            break;
        case 'B':
            if (top[1] != 10)
                row[1][top[1]++] = x;
            break;
        case 'C':
            if (top[2] != 10)
                row[2][top[2]++] = x;
            break;
    }
}

//��ջ
int pop(char arr)
{
    switch (arr) {
        case 'A':
            if (top[0])
                return row[0][--top[0]];
            break;
        case 'B':
            if (top[1] )
                return row[1][--top[1]];
            break;
        case 'C':
            if (top[2] )
                return row[2][--top[2]];
            break;
    }
    return -1;
}

//��ӡջ
void print()
{
    cout << " A:";
    for (int i = 0; i < 10; i++) {
        if (i < top[0])
            cout << setw(2) << row[0][i];
        else
            cout << "  ";
    }

    cout << " B:";
    for (int i = 0; i < 10; i++) {
        if (i < top[1])
            cout << setw(2) << row[1][i];
        else
            cout << "  ";
    }

    cout << " C:";
    for (int i = 0; i < 10; i++) {
        if (i < top[2])
            cout << setw(2) << row[2][i];
        else
            cout << "  ";
    }

    cout << endl;
}

void hanoi(int n, char src, char tmp, char dst)
{
    if (n == 1) {
        ::count++;
        cout << "��" << setw(4) << ::count << " ��" << "(" << setw(2) 
            << n << "): " << src << "-->" << dst;
        pop(src);
        push(dst, n);
        print();
        return;
    }
    else {
        hanoi(n - 1, src, dst, tmp);
        ::count++;
        cout << "��" << setw(4) << ::count << " ��" << "(" << setw(2) 
            << n << "): " << src << "-->" << dst;
        pop(src);
        push(dst, n);
        print();
        hanoi(n - 1, tmp, src, dst);
    }
}

//��ʼ������
void initia_arr(int arr, int n) {
    switch (arr) {
        case 'A':
            for (int i = 0; i < n; i++) {
                row[0][i] = n - i;
                top[0]++;
            }
            break;
        case 'B':
            for (int i = 0; i < n; i++) {
                row[1][i] = n - i;
                top[1]++;
            }
            break;
        case 'C':
            for (int i = 0; i < n; i++) {
                row[2][i] = n - i;
                top[2]++;
            }
            break;
    }
}

int main()
{
    int n;
    char src, tmp, dst; //src��ʼ tmp�м� dstĿ��

    while (1) { //input n
        cout << "�����뺺ŵ���Ĳ���(1-10)" << endl;
        cin >> n;
        if (cin.fail() || n < 1 || n > 10) {
            cin.clear();
            cin.ignore(1024, '\n');
        }
        else {
            cin.ignore(1024, '\n');
            break;
        }
    }

    while (1) { //input src
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

    while (1) { //input dst
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

    //hanoi
    cout << "��ʼ:" << setw(15) << " ";
    print();
    hanoi(n, src, tmp, dst);

    return 0;
}