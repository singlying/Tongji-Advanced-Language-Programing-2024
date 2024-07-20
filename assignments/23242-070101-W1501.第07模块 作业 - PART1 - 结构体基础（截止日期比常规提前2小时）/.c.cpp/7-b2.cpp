
#include "7-b2.h"
#include "cmd_console_tools.h"
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <cstring>
using namespace std;
/* 1���������ͷ�ļ�
   2����������ȫ�ֱ�����������̬ȫ�֣���������const��define
   3����������Ҫ�Ľṹ�塢�����ȣ������ޱ�Դ�����ļ�ʹ�� */

#define left_X para->start_x  //�߿������
#define right_X para->start_x + 2 + para->width //�߿����ұ�
#define up_Y para->start_y  //�߿����ϱ�
#define down_Y para->start_y + para->high + 1  //�߿����±�

#define BG para->bg_color
#define FG para->fg_color

#define MAX_NUM 10 //ʵ��ѡ���� 10

#define UNDERLINE 1
#define NORMALLINE 0

//#define up 0
//#define down para->high

/* ������������Դ�����ļ���Ҫ�Ľṹ�壬��Ҫ�ŵ�.h��
       ��Ϊʾ��������Ҫ��ɾ�� */
struct Status {
    int choose;  //��ǰѡ����
    int position; //��ǰλ��
};

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    �����������Դ�����ļ���Ҫ�ĺ���������Ϊstatic����
***************************************************************************/

//head , tail middle and title
static void GraphicHead(const struct PopMenu* para)
{
    //head
    cct_showstr(left_X, up_Y, "�X", BG, FG);
    cct_showstr(left_X + 2, up_Y, "�T", BG, FG, para->width / 2);
    cct_showstr(right_X, up_Y, "�[", BG, FG);

    //tail
    cct_showstr(left_X, down_Y, "�^", BG, FG);
    cct_showstr(left_X + 2, down_Y, "�T", BG, FG, para->width / 2);
    cct_showstr(right_X, down_Y, "�a", BG, FG);

    //middle
    for (int i = 1; i <= para->high; i++) {
        cct_showstr(left_X, up_Y + i, "�U", BG, FG);
        cct_showch(left_X + 2, up_Y + i, ' ', 0, 7, para->width);
        cct_showstr(right_X, up_Y + i, "�U", BG, FG);
    }
    
    //title
    int len = strlen(para->title);
    len += len % 2;  //��lenת��Ϊż��
    int middle_x = left_X + 2 + para->width / 2 - (len / 2 + (len / 2) % 2);
    cct_showstr(middle_x, up_Y, para->title, BG, FG);
    if (strlen(para->title) % 2 == 1) {  //���ӡһ���ո�  ����û��Ҫ...
        cct_showch(middle_x + len - 1, up_Y, ' ', BG, FG);
    }
}

static bool isGBK(unsigned char ch)
{
    return ch >= 0xA1 && ch <= 0xFE;
}

static void GraphicRow(const char menu[][MAX_ITEM_LEN], const struct PopMenu* para, int row, int line, int position) // line NORMALLINE ���� UNDERLINE ����
{
    if (line == UNDERLINE)
        cct_setcolor(FG, BG);
    else
        cct_setcolor(BG, FG);
    cct_gotoxy(left_X + 2, up_Y + 1 + position);

    //int length = 0;
    int col, lines, buffer_cols, buffer_lines;  //col ��
    cct_getconsoleborder(col, lines, buffer_cols, buffer_lines);
    int new_weigh = para->width;  //���е��µ�һ�������ܶ�һ���ո� �ܳ��ȱ仯

    int i = 0;
    char ch;
    bool tag = false;  //�����Կ�Ȳ��������  ���ֻ��һ��
    while ((ch = menu[row][i]) != '\0' && i < para->width) {
        if (!isGBK(ch))
            putchar(ch);
        else if (isGBK(ch) && left_X + 2 + i == buffer_cols - 1 && ! tag) {  //���������Ҫ����
            putchar(' ');
            i--;
            tag = true;
            new_weigh--;
        }
        else if (isGBK(ch) && i < para->width - 1) {  //��������
            putchar(ch);
            putchar(menu[row][i + 1]);
            i++;
        }
        else //������� ����ո�
            putchar(' ');

        i++;
    }

    while (i < new_weigh) {
        putchar(' ');
        i++;
    }

    cct_setcolor();
}

static void UpdateRow(const char menu[][MAX_ITEM_LEN], const struct PopMenu* para, Status status)
{
    if (status.position == 0) {  //������
        GraphicRow(menu, para, status.choose, UNDERLINE, 0);
        for (int i = 0; i < para->high; i++)
            GraphicRow(menu, para, status.choose + i, NORMALLINE, i);
    }
    else {  //������
        for (int i = 0; i < para->high - 1; i++)
            GraphicRow(menu, para, status.choose - para->high + i + 1, NORMALLINE, i);
        GraphicRow(menu, para, status.choose, UNDERLINE, para->high - 1);
    }
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ��������������õĺ���������������ͷ�ļ���
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int pop_menu(const char menu[][MAX_ITEM_LEN], const struct PopMenu* original_para)
{
    PopMenu new_para = *original_para;
    PopMenu* para = &new_para;
    para->width = (para->width < (int)strlen(para->title) ? strlen(para->title) : para->width);
    para->width += para->width % 2;
    para->high = para->high > MAX_NUM ? MAX_NUM : para->high;

    cct_setcursor(CURSOR_INVISIBLE);

    GraphicHead(para);

    for (int i = 0; i < para->high; i++) {  //��ӡ����
        GraphicRow(menu, para, i, NORMALLINE, i);
    }


    Status status;
    status.choose = 0;   //��ǰѡ���� 0 ~ 9
    status.position = 0;  //��ǰ�б�  0 ~ para->high - 1
    while (1) {
        //�ı�ѡ���е���ɫ
        GraphicRow(menu, para, status.choose, UNDERLINE, status.position);

        int input = _getch();
        if (input == '\r')
            return status.choose + 1;
        else if (input == 224) {
            input = _getch();
            
            switch (input) {
                case 72:
                    if (status.position > 0) {
                        GraphicRow(menu, para, status.choose, NORMALLINE, status.position);
                        status.choose--;
                        status.position--;
                    }
                    else if (status.choose > 0) {
                        status.choose--;
                        UpdateRow(menu, para, status);
                    }
                    break;
                case 80:
                    if (status.choose < para->high - 1) {
                        GraphicRow(menu, para, status.choose, NORMALLINE, status.position);
                        status.choose++;
                        status.position++;
                    }
                    else if (status.choose < MAX_NUM - 1) {
                        status.choose++;
                        UpdateRow(menu, para, status);
                    }
                    break;
            }
        }
    }

}
