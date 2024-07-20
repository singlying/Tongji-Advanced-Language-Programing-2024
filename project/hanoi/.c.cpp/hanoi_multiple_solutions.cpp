
#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <conio.h>
#include "hanoi.h"
#include "cmd_console_tools.h"
using namespace std;

/* ----------------------------------------------------------------------------------
     本文件功能：
	1、存放被 hanoi_main.cpp 中根据菜单返回值调用的各菜单项对应的执行函数

     本文件要求：
	1、不允许定义外部全局变量（const及#define不在限制范围内）
	2、允许定义静态全局变量（具体需要的数量不要超过文档显示，全局变量的使用准则是：少用、慎用、能不用尽量不用）
	3、静态局部变量的数量不限制，但使用准则也是：少用、慎用、能不用尽量不用
	4、按需加入系统头文件、自定义头文件、命名空间等

   ----------------------------------------------------------------------------------- */
   //全局变量
int a[10], b[10], c[10]; //记录圆柱
int p_a, p_b, p_c;  //栈顶指针
int count; //计数

  //functions
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
}

void to_be_continued()
{
    cct_setcolor(); //恢复缺省颜色

    empty_arr();

    cout << endl << "按回车键继续...";

    /* 忽略除回车键外的所有输入////////（注意：_getch的回车是\r，而getchar是\n）*/
    while (_getch() != '\r')
        ;

    cct_cls();

    return;
}

void hanoi(int n, char src, char tmp, char dst, int pattern, int delay)
{
    if (n == 1) {
        ::count++;
        MainDisplay(n, src, dst, pattern, delay);
        return;
    }
    else {
        hanoi(n - 1, src, dst, tmp, pattern, delay);
        ::count++;
        MainDisplay(n, src, dst, pattern, delay);
        hanoi(n - 1, tmp, src, dst, pattern, delay);
    }
}

void MainDisplay(int n, char src, char dst, char pattern, int delay)
{
    if (pattern == 1)
        cout << n << "# " << src << "---->" << dst;
    else if (pattern == 2) {
        cout << "第" << setw(4) << ::count << " 步" << "(" << setw(2)
            << n << "): " << src << "-->" << dst;
    }
    else if (pattern == 3) {
        cout << "第" << setw(4) << ::count << " 步" << "(" << setw(2)
            << n << "): " << src << "-->" << dst;
        pop(src);
        push(dst, n);
        print_stack();
    }
    else if (pattern == 4) {
        MySleep(delay);
        cct_gotoxy(h_x, h_y);

        cout << "第" << setw(4) << ::count << " 步" << "(" << setw(2)
            << n << "): " << src << "-->" << dst;
        pop(src);
        push(dst, n);
        print_stack();
        Graphic(0);
    }
    else if (pattern == 8) {
        MySleep(delay);
        MovePlate(src, dst, delay);
        cct_gotoxy(h_x, h_y_2);
        cout << "第" << setw(4) << ::count << " 步" << "(" << setw(2)
            << n << "): " << src << "-->" << dst;
        pop(src);
        push(dst, n);
        print_stack();
        Graphic(1);
    }
    
    cout << endl;
}

void MySleep(int delay)
{
    //项目4中为 0~ 5  0为断档
    //项目8中为 0 ~ 6  0为断档， 后面的每一档要有区分度
    if (!delay) {
        while (_getch() != 13) {
        };
    }
    /*else {
        int sleep_time = static_cast<int>(0.4 * (pow(6 - delay, 5) - 3 * pow(6 - delay, 3) + 2));
        Sleep(sleep_time);
    }*/
    else {
        switch (delay) {
            case 1:
                Sleep(500);
                break;
            case 2:
                Sleep(200);
                break;
            case 3:
                Sleep(100);
                break;
            case 4:
                Sleep(50);
                break;
            case 5:
                Sleep(10);
                break;
            case 6:
                Sleep(0);
                break;
        }
    }

}

void Graphic(int pattern)
{
    int _y = !pattern ? g_y : g_y_2;
    cct_gotoxy(g_x, _y);
    cout << "=========================";
    cct_gotoxy(g_x, _y + 1);
    cout << "  A         B         C  ";

    for (int i = 9; i > -1; i--) {
        cct_gotoxy(g_x + 2, _y - i - 1);
        if (i < p_a)
            cout << a[i];
        else
            cout << " ";
    }

    for (int i = 9; i > -1; i--) {
        cct_gotoxy(g_x + 12, _y - i - 1);
        if (i < p_b)
            cout << b[i];
        else
            cout << " ";
    }

    for (int i = 9; i > -1; i--) {
        cct_gotoxy(g_x + 22, _y - i - 1);
        if (i < p_c)
            cout << c[i];
        else
            cout << " ";
    }

    cct_gotoxy(0, h_y_2);
}

void input(int& n, char& src, char& tmp, char& dst, int& delay)
{
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

    if (delay != -1) { //说明一定是pattern 4
        //输入移动速度
        delay = input_tools(0, 5, "请输入移动速度(0-5: 0-按回车单步演示 1-延时最长 5-延时最短)");
        cct_cls();

        cout << "从 " << src << " 移动到 " << dst << "，共 " << n << " 层，延时设置为 " << delay << endl;
        //Graphic();
    }
}

void Initia_arr(int arr, int n)
{
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

void empty_arr()
{
    for (int i = 0; i < 10; i++) {
        a[i] = 0;
        b[i] = 0;
        c[i] = 0;
    }
    p_a = p_b = p_c = 0;
    ::count = 0;
}

void print_Column()
{
    cct_cls();

    //打印横向柱子
    for (int i = 0; i < 3; i++) {
        cct_showch(column_space * (i + 1) + i * column_x, column_bottom_y, ' ', COLOR_HWHITE, COLOR_HWHITE, column_x);
        Sleep(100);
    }

    //打印竖向柱子
    for (int j = 0; j < column_h; j++) {
        for (int i = 0; i < 3; i++)
            cct_showch(column_space * (i + 1) + i * column_x + column_x / 2, column_bottom_y - 1 - j, ' ', COLOR_HWHITE, COLOR_HWHITE, 1);
        Sleep(100);
    }

    cct_gotoxy(0, column_h + column_space);
}

void print_Plate()
{
    //盘子对应颜色为 1 ~ 10
    if (p_a)
        for (int i = p_a; i > 0; i--) {
            cct_showch(A_column_middle_x - i, column_bottom_y - 1 + i - p_a, ' ', i, (i + 5) % p_a + 1, i * 2 + 1);
            Sleep(80);                       
        }                                    
    else if (p_b)                            
        for (int i = p_b; i > 0; i--) {      
            cct_showch(B_column_middle_x - i, column_bottom_y - 1 + i - p_b, ' ', i, (i + 5) % p_b + 1, i * 2 + 1);
            Sleep(80);                   
        }                                
    else                                 
        for (int i = p_c; i > 0; i--) {  
            cct_showch(C_column_middle_x - i, column_bottom_y - 1 + i - p_c, ' ', i, (i + 5) % p_c + 1, i * 2 + 1);
            Sleep(80);
        }

    cct_gotoxy(0, column_h + column_space);
    cct_setcolor(); //恢复缺省颜色
}

void MovePlate(char src, char dst, int delay)  //在移动时还要把柱子画上!
{
    cct_setcursor(CURSOR_INVISIBLE);  //关闭光标显示
    delay = delay == 0 ? 4 : delay;   //调整delay为0是的运行速度
    //从src移动到dst
    switch (src) {
        case 'A': {
            int i = a[p_a - 1];
            int cur_y = column_bottom_y - p_a;
            while (cur_y > column_space / 3) { //向上移动
                cct_showch(A_column_middle_x - i, cur_y, ' ', 0, 7, i * 2 + 1);
                if (cur_y >= column_bottom_y - column_h)
                    cct_showch(A_column_middle_x, cur_y, ' ', COLOR_HWHITE);
                cur_y--;
                cct_showch(A_column_middle_x - i, cur_y, ' ', i, 7, i * 2 + 1);
                MySleep(delay + 1);
            }
            int cur_x = A_column_middle_x;

            //cout << endl << (dst == 'B' ? B_column_middle_x : C_column_middle_x) << endl;
            int target_x = dst == 'B' ? B_column_middle_x : C_column_middle_x;
            while (cur_x < target_x) { //横向移动
                cct_showch(cur_x - i, cur_y, ' ', 0, 7, i * 2 + 1);
                cur_x++;
                cct_showch(cur_x - i, cur_y, ' ', i, 7, i * 2 + 1);
                MySleep(delay + 1);
            }

            int target_y = 0;
            switch (dst) {
                case 'B':
                    target_y = column_bottom_y - p_b - 1;
                    break;
                case 'C':
                    target_y = column_bottom_y - p_c - 1;
                    break;
            }

            //cout << "               " << target_y << endl; /////////////////
            while (cur_y < target_y) { //向下移动
                cct_showch(cur_x - i, cur_y, ' ', 0, 7, i * 2 + 1);
                if (cur_y >= column_bottom_y - column_h)
                    cct_showch(target_x, cur_y, ' ', COLOR_HWHITE);
                cur_y++;
                cct_showch(cur_x - i, cur_y, ' ', i, 7, i * 2 + 1);
                MySleep(delay + 1);
            }
            break;
        }
        case 'B': {  //i -> b[p_b - 1]
            int i = b[p_b - 1];
            int cur_y = column_bottom_y - p_b;
            while (cur_y > column_space / 3) { //向上移动
                cct_showch(B_column_middle_x - i, cur_y, ' ', 0, 7, i * 2 + 1);
                if (cur_y >= column_bottom_y - column_h)
                    cct_showch(B_column_middle_x, cur_y, ' ', COLOR_HWHITE);
                cur_y--;
                cct_showch(B_column_middle_x - i, cur_y, ' ', i, 7, i * 2 + 1);
                MySleep(delay + 1);
            }

            int cur_x = B_column_middle_x;
            int target_x = dst == 'A' ? A_column_middle_x : C_column_middle_x;
            if (dst == 'A')
                while (cur_x > A_column_middle_x) { //向左移动
                    cct_showch(cur_x - i, cur_y, ' ', 0, 7, i * 2 + 1);
                    cur_x--;
                    cct_showch(cur_x - i, cur_y, ' ', i, 7, i * 2 + 1);
                    MySleep(delay + 1);
                }
            else if (dst == 'C')
                while (cur_x < C_column_middle_x) { //向右移动
                    cct_showch(cur_x - i, cur_y, ' ', 0, 7, i * 2 + 1);
                    cur_x++;
                    cct_showch(cur_x - i, cur_y, ' ', i, 7, i * 2 + 1);
                    MySleep(delay + 1);
                }

            int target_y = 0;
            switch (dst) {
                case 'A':
                    target_y = column_bottom_y - p_a - 1;
                    break;
                case 'C':
                    target_y = column_bottom_y - p_c - 1;
                    break;
            }
            //cout << "               " << target_y << endl; /////////////////
            while (cur_y < target_y) { //向下移动
                cct_showch(cur_x - i, cur_y, ' ', 0, 7, i * 2 + 1);
                if (cur_y >= column_bottom_y - column_h)
                    cct_showch(target_x, cur_y, ' ', COLOR_HWHITE);
                cur_y++;
                cct_showch(cur_x - i, cur_y, ' ', i, 7, i * 2 + 1);
                MySleep(delay + 1);
            }
            break;
        }
        case 'C': {  //i -> c[p_c - 1]
            int i = c[p_c - 1];
            int cur_y = column_bottom_y - p_c;
            while (cur_y > column_space / 3) { //向上移动
                cct_showch(C_column_middle_x - i, cur_y, ' ', 0, 7, i * 2 + 1);
                if (cur_y >= column_bottom_y - column_h)
                    cct_showch(C_column_middle_x, cur_y, ' ', COLOR_HWHITE);
                cur_y--;
                cct_showch(C_column_middle_x - i, cur_y, ' ', i, 7, i * 2 + 1);
                MySleep(delay + 1);
            }

            int cur_x = C_column_middle_x;
            int target_x = dst == 'A' ? A_column_middle_x : B_column_middle_x;
            //cout << endl << (dst == 'B' ? B_column_middle_x : C_column_middle_x) << endl;
            while (cur_x > target_x) { //横向移动
                cct_showch(cur_x - i, cur_y, ' ', 0, 7, i * 2 + 1);
                cur_x--;
                cct_showch(cur_x - i, cur_y, ' ', i, 7, i * 2 + 1);
                MySleep(delay + 1);
            }

            int target_y = 0;
            switch (dst) {
                case 'A':
                    target_y = column_bottom_y - p_a - 1;
                    break;
                case 'B':
                    target_y = column_bottom_y - p_b - 1;
                    break;
            }

            //cout << "               " << target_y << endl; /////////////////
            while (cur_y < target_y) { //向下移动
                cct_showch(cur_x - i, cur_y, ' ', 0, 7, i * 2 + 1);
                if (cur_y >= column_bottom_y - column_h)
                    cct_showch(target_x, cur_y, ' ', COLOR_HWHITE);
                cur_y++;
                cct_showch(cur_x - i, cur_y, ' ', i, 7, i * 2 + 1);
                MySleep(delay + 1);
            }
            break;
        }
    }
    cct_gotoxy(0, column_h + column_space);
    cct_setcolor(); //恢复缺省颜色
    cct_setcursor(CURSOR_VISIBLE_NORMAL);  //光标显示为正常
}

void MyGame(int n, char cin_src, char cin_dst)
{
    cct_gotoxy(0, 0);
    cout << "从 " << cin_src << " 移动到 " << cin_dst << "，共 " << n << " 层 ";
    cct_gotoxy(0, game_notion_y);
    cout << "请输入移动的柱号(命令形式：AC=A顶端的盘子移动到C，Q=退出) : ";

    char src, dst;
    //char input;
    int move_num = 0;  //移动的盘子标号
    char arr[2];  //输入辅助存储  因为不允许传地址 只能出此下策

    while (!is_GameEnd(n, cin_src, cin_dst)) {
        //cct_showch(game_notion_x, game_notion_y, ' ', 0, 7, 100); //清除刚才输入的内容 ////////////////////////////////
        move_num = GameInput_tools(arr);

        if (!move_num) //结束游戏
            return;

        src = arr[0];
        dst = arr[1];

        ::count++;
        MainDisplay(move_num, src, dst, 8, 4);
    }

    cct_gotoxy(0, game_notion_y + 2);
    cout << " ************GAME OVER, CONGRUTULATIONS! ************ " << endl;
}

bool is_GameEnd(int n, char src, char dst)
{
    if (dst == 'A' && p_a < n) {
            return false;
    }
    else if (dst == 'B' && p_b < n) {
            return false;
    }
    else if (dst == 'C' && p_c < n){
            return false;
    }

    return true;
}

void GameErrorTips(const char arr[])
{
    cout << endl << arr;
    Sleep(1500);
    cct_showch(0, game_notion_y + 1, ' ', 0, 7, 30);
}

int GameInput_tools(char arr[])
{
    char src, dst;
    int input;  //暂时存储输入
    int num = 0;  //输入辅助计数

    while (1) {
        cct_showch(game_notion_x, game_notion_y, ' ', 0, 7, 100); //清除刚才输入的内容
        cct_gotoxy(game_notion_x, game_notion_y);
        num = 0;

        while ((input = _getch()) != '\r' && num < 20) {
            if (input == 224) {  // 如果输入错误，则不显示
                input = _getch();
                continue;
            }

            if (input > 127 || input < 32) {
                continue;
            }
            //显示输入的字符
            cout << (char)input;
            if (num < 2)
                arr[num++] = (char)input;
            else
                num++;
        }

        if (num == 1 && (arr[0] == 'q' || arr[0] == 'Q')) {  //q Q终止游戏
            cout << endl << "GAME IS OVER!!!!" << endl;
            return 0;
        }
        else if (num == 2 && (arr[0] == 'a' || arr[0] == 'b' || arr[0] == 'c'
            || arr[0] == 'A' || arr[0] == 'B' || arr[0] == 'C')
            && (arr[1] == 'a' || arr[1] == 'b' || arr[1] == 'c'
                || arr[1] == 'A' || arr[1] == 'B' || arr[1] == 'C')
            && arr[0] != arr[1]) {  //正确输入
            src = arr[0];
            dst = arr[1];
        }
        else //错误输入
            continue;

        if (src == 'a' || src == 'b' || src == 'c')  //统一为大写
            src = arr[0] -= 'a' - 'A';
        if (dst == 'a' || dst == 'b' || dst == 'c')
            dst = arr[1] -= 'a' - 'A';

        if (src == 'A') {  //判断非法操作
            if (p_a == 0) {
                GameErrorTips("原柱为空");
                continue;
            }

            if (dst == 'B' && p_b > 0 && a[p_a - 1] > b[p_b - 1])
                GameErrorTips("大盘压小盘非法移动");
            else if (dst == 'C' && p_c > 0 && a[p_a - 1] > c[p_c - 1])
                GameErrorTips("大盘压小盘非法移动");
            else
                return a[p_a - 1];
        }
        else if (src == 'B') {
            if (p_b == 0) {
                GameErrorTips("原柱为空");
                continue;
            }

            if (dst == 'A' && p_a > 0 && b[p_b - 1] > a[p_a - 1])
                GameErrorTips("大盘压小盘非法移动");
            else if (dst == 'C' && p_c > 0 && b[p_b - 1] > c[p_c - 1])
                GameErrorTips("大盘压小盘非法移动");
            else
                return b[p_b - 1];
        }
        else {
            if (p_c == 0) {
                GameErrorTips("原柱为空");
                continue;
            }

            if (dst == 'A' && p_a > 0 && a[p_a - 1] < c[p_c - 1])
                GameErrorTips("大盘压小盘非法移动");
            else if (dst == 'B' && p_b > 0 && b[p_b - 1] < c[p_c - 1])
                GameErrorTips("大盘压小盘非法移动");
            else
                return c[p_c - 1];
        }
    }
}