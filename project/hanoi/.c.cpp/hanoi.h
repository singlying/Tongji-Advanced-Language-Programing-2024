
#pragma once
/* ------------------------------------------------------------------------------------------------------
     ���ļ����ܣ�
	1��Ϊ�˱�֤ hanoi_main.cpp/hanoi_menu.cpp/hanoi_multiple_solutions.cpp ���໥���ʺ����ĺ�������
	2��һ�����ϵ�cpp���õ��ĺ궨�壨#define����ȫ��ֻ����const����������������
	3�����Բο� cmd_console_tools.h ��д���������Ķ�����ᣩ
   ------------------------------------------------------------------------------------------------------ */

//�ڰ�ͼ�λ��õ��Ķ�λ
#define g_x 25 //ͼ�λ��ĳ�ʼx
#define g_y 15 //ͼ�λ��ĳ�ʼy
#define h_x g_x //��ʾ������ʼx
#define h_y g_y + 5 //��ʾ������ʼy

#define g_y_2 28 //pattern_7��ͼ�λ���ʼx
#define h_y_2 g_y_2 + 5  //pattern_7��ʾ������ʼy

//��Ϸ�õ��Ķ�λ
#define game_notion_y h_y_2 + 2  //��Ϸ��ʾ��λ�õ�y
#define game_notion_x 60   //��Ϸ��ʾ��λ�õ�x

//��ɫ�����õ��Ķ�λ
#define column_x 24  //���ӵĿ�
#define column_h 12  //���ӵĸ�
#define column_space 10 //���Ӽ�Ŀ��
#define A_column_middle_x column_space + column_x / 2 //A��x����
#define B_column_middle_x column_space * 2 + column_x + column_x / 2 //B��x����
#define C_column_middle_x column_space * 3 + 2 * column_x + column_x / 2 //C��x����
#define column_bottom_y column_h + column_space / 2  //���ӵײ���y����

//assisting functions
//�������븨������
int input_tools(const int min, const int max, const char prompt[]);

//��ջ
void push(char arr, int x);

//��ջ
int pop(char arr);

//��ӡջ
void print_stack();

//�����������
void to_be_continued();

//main functions
// ͨ��pattern��������ͬ��ģʽѡ��  pattern << 1 2 3 4 8 9
//���˵�
int Menu();

//���ݹ�
void hanoi(int n, char src, char tmp, char dst, int pattern, int delay); 

//����ʾ����
void MainDisplay(int n, char src, char dst, char pattern, int delay);

//ͼ�λ�
void Graphic(int pattern);  //pattern {0: 4��ͼ�λ�  1:8��9��ͼ�λ�}

//�ֶ��ӳٺ���
void MySleep(int delay); 

//�����뺯��
void input(int& n, char& src, char& tmp, char& dst, int& delay);

//��ʼ������
void Initia_arr(int arr, int n);

//�������
void empty_arr();

//������
void print_Column();

//������
void print_Plate();

//�ƶ�����
void MovePlate(char src, char dst, int delay);

//Mygame
void MyGame(int n, char src, char dst);

//is_GameEnd
bool is_GameEnd(int n, char src, char dst);

//GameErrorTips
void GameErrorTips(const char arr[]);

//GameInput_tools
int GameInput_tools(char a[]);