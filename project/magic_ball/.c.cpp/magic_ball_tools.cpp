
#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <conio.h>
#include "magic_ball.h"
#include "cmd_console_tools.h"
using namespace std;


//functions
node* track_mouse(Matrix& matrix, int tag)
{
    int x, y;
    int event;
    int key1, key2;
    bool loop = true;
    node* select = NULL;
    char prompt[50]; // �㹻����ַ�����洢���

    cct_enable_mouse();
    cct_setcursor(CURSOR_INVISIBLE);

    while (loop) {
        if (cct_read_keyboard_and_mouse(x, y, event, key1, key2) == CCT_MOUSE_EVENT) {
            switch (event) {
                case MOUSE_ONLY_MOVED:
                    if (test_mouse_position(matrix.row, matrix.column, x, y, tag)) {
                        snprintf(prompt, sizeof(prompt), "[��ǰ���]    %c��%d��  ", (y - 1) / 2 + 'A', (x - 2) / 4 + 1);
                        output_tools(matrix, prompt, 2);
                    }
                    else {
                        snprintf(prompt, sizeof(prompt), "[��ǰ���]    �Ƿ�λ��              ");
                        output_tools(matrix, prompt, 2);
                    }
                    break;
                case MOUSE_LEFT_BUTTON_CLICK:  //���ѡ��
                    if (test_mouse_position(matrix.row, matrix.column, x, y, tag)
                        && !matrix.arr[(y - 1) / 2][(x - 2) / 4].is_triple) {  //�������ѡ��ķ���
                        snprintf(prompt, sizeof(prompt), "  ����ѡ��    %c��%d��  ", (y - 1) / 2 + 'A', (x - 2) / 4 + 1);
                        output_tools(matrix, prompt, 2);
                    }
                    else if (test_mouse_position(matrix.row, matrix.column, x, y, tag)) { //�����ѡ��ķ���
                        snprintf(prompt, sizeof(prompt), "  ��ǰѡ��    %c��%d��  ", (y - 1) / 2 + 'A', (x - 2) / 4 + 1);
                        output_tools(matrix, prompt, 2);
                        loop = false;
                        select = &matrix.arr[(y - 1) / 2][(x - 2) / 4];
                    }
                    break;
                case MOUSE_RIGHT_BUTTON_CLICK:  //�Ҽ��˳�
                    if (test_mouse_position(matrix.row, matrix.column, x, y, tag)) {
                        loop = false;
                    }
            }
        }
    }

    cct_disable_mouse();	//�������
    cct_setcursor(CURSOR_VISIBLE_NORMAL);
    return select;
}

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

void input_end()
{
    cout << endl << "��С�������������End����...";
    char str[3];
    int input;
    int num = 0;
    int x, y;
    cct_getxy(x, y);
    while (1) {
        num = 0;
        cct_showch(x, y, ' ', 0, 7, 50);
        cct_gotoxy(x, y);

        while ((input = _getch()) != '\r' && num < 20) {
            if (input == 224) {  //��������������ʾ
                input = _getch();
                continue;
            }
            
            if (input > 127 || input < 32)  //���ַ�����ȱ�ݣ�û�취ʹ���˸���������
                continue;
           
            cout << (char)input;

            if (num < 3)
                str[num++] = (char)input;
            else
                num++;
            
        }

        if (num != 3) {
            cct_gotoxy(x, y);
            cout << endl << "�������" << endl;
            continue;
        }
        else if ((str[0] == 'E' || str[0] == 'e')
            && (str[1] == 'N' || str[1] == 'n')
            && (str[2] == 'D' || str[2] == 'd'))
            return;
    }

}

void input_enter(const char prompt[])
{
    //����һ��ԭ�ȵĶ������
    int cur_x, cur_y;
    cct_getxy(cur_x, cur_y);
    cct_showch(cur_x, cur_y, ' ', COLOR_BLACK, COLOR_WHITE, 40); 
    cct_gotoxy(cur_x, cur_y);

    cout << prompt;
    int input;
    while (1) {
        input = _getch();
        if (input == 13)
            break;
    }
    cout << endl;
}

void erase_cout(Matrix& matrix, int tag)
{
    cct_showch(0, formatCout1Y, ' ', COLOR_BLACK, COLOR_WHITE, formatX);
    cct_showch(0, formatCout2Y, ' ', COLOR_BLACK, COLOR_WHITE, formatX);
    cct_gotoxy(0, formatCout1Y);
}

void output_tools(Matrix& matrix, const char prompt[], int row, int tag) // row = 1 ��һ�� 2 �ڶ���
{
    if (row == 1)
        cct_gotoxy(0, formatCout1Y);
    else if (row == 2) 
        cct_gotoxy(0, formatCout2Y);

    cout << prompt;
}