
#pragma once

#define MAXROW 9  //�ڴ����������
#define MAXCOLUMN 9  //�ڴ����������

#define DELAYtiming 100

#define formatX 40  //��Ļ���򳤶�
#define formatWITHY 25  //���򳤶� ���ָ���
#define formatWITHOUTY 17  //���򳤶� �����ָ���

#define formatCout1Y (matrix.row + 1 + tag) * (1 + tag) - 2 + (tag == 0 ? 4 : 0) //��λ�������λ��
#define formatCout2Y (matrix.row + 1 + tag) * (1 + tag) - 1 + (tag == 0 ? 4 : 0)

#define WITH_DELIMITERS 1  //���ָ���
#define WITHOUT_DELIMITERS 0  //�����ָ���

#define NODELAY 0  //���ӳ�
#define ISDELSY 1  //�ӳ�

#define HEAD 0   //��ͷ
#define TAIL 1   //��β
#define DELIMITER 2  //�м�ָ���

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
int input_tools(const int min, const int max, const char prompt[]);  //����һ��min ~ max֮�����

void input_end(); //����end����

void input_enter(const char prompt[]);  //����enter

void erase_cout(Matrix& matrix, int tag = 1);  //��������������¶�λ  ����

void output_tools(Matrix& matrix, const char prompt[], int row, int tag = 1);  // ������ͼ�ν����µ����

//���ܺ���
int Menu(); //�˵�

void init_matirx(Matrix& matrix); //��ʼ��

void print_matrix(const Matrix& matrix); //��ӡ����

bool test_triple(Matrix& matrix); //����ʼ������� 0 û������ 1 ������

void drop_ball(Matrix& matrix);  //�����µ���

int refill_matrix(Matrix& matrix);  //������� ��������� //����

void reset_matrix(Matrix& matrix);  //�ָ�����node״̬ is_triple

bool detect_elimination(Matrix& matrix);  ///////////////�������д��̫���� �ٸ�һ��

bool test_exchange(Matrix& matrix, node* node1, node* node2);  // ����Ƿ��ܽ�����������

void exchange_2ball(node* node1, node* node2);  //����������

//ǰ�˺���
void graph_matrix(const Matrix& matrix, int tag = WITH_DELIMITERS, int delay = NODELAY);  //��Ҫ�滭 Ĭ�ϴ��ָ��� ���ӳ�

void graphic_head(const int column, int head, int tag = WITH_DELIMITERS, int delay = NODELAY);  //��ͷ ��β �м�ָ���

void graphic_eliminate(const Matrix& matrix, int tag = WITH_DELIMITERS); //��������

void graphic_drop_ball(const Matrix& matrix, int tag = WITH_DELIMITERS);  //���䶯��

void graphic_refill_matrix(const Matrix& matrix, int tag = WITH_DELIMITERS); //��䶯��

void graphic_triple(Matrix& matrix, int tag = WITH_DELIMITERS);  //���������

void graphic_exchangeable(const Matrix& matrix, int tag = WITH_DELIMITERS);  //����ɽ�����

void graphic_exchange(Matrix& matrix, const node* node1, const node* node2, int tag = WITH_DELIMITERS);  //��������

node* track_mouse(Matrix& matrix, int tag = WITH_DELIMITERS);

bool test_mouse_position(const int max_row, const int max_column, int x, int y, int tag = WITH_DELIMITERS);