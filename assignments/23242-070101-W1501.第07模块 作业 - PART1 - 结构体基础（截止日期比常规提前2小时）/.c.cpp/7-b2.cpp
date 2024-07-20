
#include "7-b2.h"
#include "cmd_console_tools.h"
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <cstring>
using namespace std;
/* 1、按需加入头文件
   2、不允许定义全局变量，包括静态全局，但不限制const及define
   3、允许定义需要的结构体、函数等，但仅限本源程序文件使用 */

#define left_X para->start_x  //边框最左边
#define right_X para->start_x + 2 + para->width //边框最右边
#define up_Y para->start_y  //边框最上边
#define down_Y para->start_y + para->high + 1  //边框最下边

#define BG para->bg_color
#define FG para->fg_color

#define MAX_NUM 10 //实际选项数 10

#define UNDERLINE 1
#define NORMALLINE 0

//#define up 0
//#define down para->high

/* 例：声明仅本源程序文件需要的结构体，不要放到.h中
       仅为示例，不需要可删除 */
struct Status {
    int choose;  //当前选择项
    int position; //当前位置
};

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：定义仅本源程序文件需要的函数，设置为static即可
***************************************************************************/

//head , tail middle and title
static void GraphicHead(const struct PopMenu* para)
{
    //head
    cct_showstr(left_X, up_Y, "╔", BG, FG);
    cct_showstr(left_X + 2, up_Y, "═", BG, FG, para->width / 2);
    cct_showstr(right_X, up_Y, "╗", BG, FG);

    //tail
    cct_showstr(left_X, down_Y, "╚", BG, FG);
    cct_showstr(left_X + 2, down_Y, "═", BG, FG, para->width / 2);
    cct_showstr(right_X, down_Y, "╝", BG, FG);

    //middle
    for (int i = 1; i <= para->high; i++) {
        cct_showstr(left_X, up_Y + i, "║", BG, FG);
        cct_showch(left_X + 2, up_Y + i, ' ', 0, 7, para->width);
        cct_showstr(right_X, up_Y + i, "║", BG, FG);
    }
    
    //title
    int len = strlen(para->title);
    len += len % 2;  //把len转换为偶数
    int middle_x = left_X + 2 + para->width / 2 - (len / 2 + (len / 2) % 2);
    cct_showstr(middle_x, up_Y, para->title, BG, FG);
    if (strlen(para->title) % 2 == 1) {  //多打印一个空格  好像没必要...
        cct_showch(middle_x + len - 1, up_Y, ' ', BG, FG);
    }
}

static bool isGBK(unsigned char ch)
{
    return ch >= 0xA1 && ch <= 0xFE;
}

static void GraphicRow(const char menu[][MAX_ITEM_LEN], const struct PopMenu* para, int row, int line, int position) // line NORMALLINE 正常 UNDERLINE 反常
{
    if (line == UNDERLINE)
        cct_setcolor(FG, BG);
    else
        cct_setcolor(BG, FG);
    cct_gotoxy(left_X + 2, up_Y + 1 + position);

    //int length = 0;
    int col, lines, buffer_cols, buffer_lines;  //col 列
    cct_getconsoleborder(col, lines, buffer_cols, buffer_lines);
    int new_weigh = para->width;  //换行导致第一行最后可能多一个空格 总长度变化

    int i = 0;
    char ch;
    bool tag = false;  //不测试宽度不够的情况  最多只换一行
    while ((ch = menu[row][i]) != '\0' && i < para->width) {
        if (!isGBK(ch))
            putchar(ch);
        else if (isGBK(ch) && left_X + 2 + i == buffer_cols - 1 && ! tag) {  //半个汉字需要换行
            putchar(' ');
            i--;
            tag = true;
            new_weigh--;
        }
        else if (isGBK(ch) && i < para->width - 1) {  //完整汉字
            putchar(ch);
            putchar(menu[row][i + 1]);
            i++;
        }
        else //半个汉字 输出空格
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
    if (status.position == 0) {  //最上面
        GraphicRow(menu, para, status.choose, UNDERLINE, 0);
        for (int i = 0; i < para->high; i++)
            GraphicRow(menu, para, status.choose + i, NORMALLINE, i);
    }
    else {  //最下面
        for (int i = 0; i < para->high - 1; i++)
            GraphicRow(menu, para, status.choose - para->high + i + 1, NORMALLINE, i);
        GraphicRow(menu, para, status.choose, UNDERLINE, para->high - 1);
    }
}

/***************************************************************************
  函数名称：
  功    能：供测试用例调用的函数，函数声明在头文件中
  输入参数：
  返 回 值：
  说    明：
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

    for (int i = 0; i < para->high; i++) {  //打印内容
        GraphicRow(menu, para, i, NORMALLINE, i);
    }


    Status status;
    status.choose = 0;   //当前选择项 0 ~ 9
    status.position = 0;  //当前行标  0 ~ para->high - 1
    while (1) {
        //改变选定行的颜色
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
