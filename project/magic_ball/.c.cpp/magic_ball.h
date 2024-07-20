
#pragma once

#define MAXROW 9  //内存中最大行数
#define MAXCOLUMN 9  //内存中最大列数

#define DELAYtiming 100

#define formatX 40  //屏幕横向长度
#define formatWITHY 25  //纵向长度 带分隔符
#define formatWITHOUTY 17  //纵向长度 不带分隔符

#define formatCout1Y (matrix.row + 1 + tag) * (1 + tag) - 2 + (tag == 0 ? 4 : 0) //定位输出语句的位置
#define formatCout2Y (matrix.row + 1 + tag) * (1 + tag) - 1 + (tag == 0 ? 4 : 0)

#define WITH_DELIMITERS 1  //带分隔符
#define WITHOUT_DELIMITERS 0  //不带分隔符

#define NODELAY 0  //不延迟
#define ISDELSY 1  //延迟

#define HEAD 0   //表头
#define TAIL 1   //表尾
#define DELIMITER 2  //中间分割线

struct node {
	int data = 0;
	bool is_triple = false;
	bool is_selected = false;
};

struct Matrix {
	int row = 0;
	int column = 0;

	node arr[MAXROW][MAXCOLUMN];
};

//input output tools
int input_tools(const int min, const int max, const char prompt[]);  //输入一个min ~ max之间的数

void input_end(); //输入end结束

void input_enter(const char prompt[]);  //按下enter

void erase_cout(Matrix& matrix, int tag = 1);  //清空输出，光标重新定位  两行

void output_tools(Matrix& matrix, const char prompt[], int row, int tag = 1);  // 辅助在图形界面下的输出

//功能函数
int Menu(); //菜单

void init_matirx(Matrix& matrix); //初始化

void print_matrix(const Matrix& matrix); //打印矩阵

bool test_triple(Matrix& matrix); //检测初始情况三连 0 没有三连 1 有三连

void drop_ball(Matrix& matrix);  //下落新的球

int refill_matrix(Matrix& matrix);  //填充数组 返回填充数 //分数

void reset_matrix(Matrix& matrix);  //恢复所有node状态 is_triple

bool detect_elimination(Matrix& matrix);  ///////////////这个函数写的太糟了 再改一下

bool test_exchange(Matrix& matrix, node* node1, node* node2);  // 检测是否能交换两相邻球

void exchange_2ball(node* node1, node* node2);  //交换相邻球

//前端函数
void graph_matrix(const Matrix& matrix, int tag = WITH_DELIMITERS, int delay = NODELAY);  //主要绘画 默认带分隔符 不延迟

void graphic_head(const int column, int head, int tag = WITH_DELIMITERS, int delay = NODELAY);  //表头 表尾 中间分割线

void graphic_eliminate(const Matrix& matrix, int tag = WITH_DELIMITERS); //消除动画

void graphic_drop_ball(const Matrix& matrix, int tag = WITH_DELIMITERS);  //下落动画

void graphic_refill_matrix(const Matrix& matrix, int tag = WITH_DELIMITERS); //填充动画

void graphic_triple(Matrix& matrix, int tag = WITH_DELIMITERS);  //标出三连球

void graphic_exchangeable(const Matrix& matrix, int tag = WITH_DELIMITERS);  //标出可交换球

void graphic_exchange(Matrix& matrix, const node* node1, const node* node2, int tag = WITH_DELIMITERS);  //交换两球

node* track_mouse(Matrix& matrix, int tag = WITH_DELIMITERS);

bool test_mouse_position(const int max_row, const int max_column, int x, int y, int tag = WITH_DELIMITERS);