
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

const int MAX_X = 69;	//����*��ɵı߿�Ŀ��
const int MAX_Y = 17;	//����*��ɵı߿�ĸ߶�

/***************************************************************************
  �������ƣ�
  ��    �ܣ������system("cls")һ���Ĺ��ܣ���Ч�ʸ�
  ���������
  �� �� ֵ��
  ˵    �������������Ļ���������������ǿɼ���������(ʹ�õ�ǰ��ɫ)
***************************************************************************/
void cls(const HANDLE hout)
{
	COORD coord = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO binfo; /* to get buffer info */
	DWORD num;

	/* ȡ��ǰ��������Ϣ */
	GetConsoleScreenBufferInfo(hout, &binfo);
	/* ����ַ� */
	FillConsoleOutputCharacter(hout, (TCHAR)' ', binfo.dwSize.X * binfo.dwSize.Y, coord, &num);
	/* ������� */
	FillConsoleOutputAttribute(hout, binfo.wAttributes, binfo.dwSize.X * binfo.dwSize.Y, coord, &num);

	/* ���ص�(0,0) */
	SetConsoleCursorPosition(hout, coord);
	return;
}

/***************************************************************************
  �������ƣ�gotoxy
  ��    �ܣ�������ƶ���ָ��λ��
  ���������HANDLE hout������豸���
			int X      ��ָ��λ�õ�x����
			int Y      ��ָ��λ�õ�y����
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void gotoxy(const HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/***************************************************************************
  �������ƣ�showch
  ��    �ܣ���ָ��λ�ô���ӡһ��ָ�����ַ�
  ���������HANDLE hout������豸���
			int X      ��ָ��λ�õ�x����
			int Y      ��ָ��λ�õ�y����
			char ch    ��Ҫ��ӡ���ַ�
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void showch(const HANDLE hout, const int X, const int Y, const char ch)
{
	gotoxy(hout, X, Y);
	putchar(ch);
}

/***************************************************************************
  �������ƣ�init_border
  ��    �ܣ���ʾ��ʼ�ı߿�����ַ�
  ���������HANDLE hout������豸���
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void init_border(const HANDLE hout)
{
	gotoxy(hout, 0, 0);	//����ƻ����Ͻ�(0,0)
	printf("***********************************************************************\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("***********************************************************************\n");

	/* �����ʾ20����д��ĸ����ĸ��ֵ��XY���궼�����ʾ
	   rand()�����Ĺ��ܣ��������һ���� 0-32767 ֮�������
	   ˼������ʲô����£��������ѭ��ִ�����ɺ��㿴����ʵ����ĸ��������20���� */
	int i;
	for (i = 0; i < 20; i++)
		showch(hout, rand() % MAX_X + 1, rand() % MAX_Y + 1, 'A' + rand() % 26);

	return;
}

/* -- �������ӵ����ɺ������Է��ڴ˴� --*/
int menu(const HANDLE hout)
{
	int choose;
	while (1) {
		printf("1.��I��J��K��L��������������(��Сд���ɣ��߽�ֹͣ)\n");
		printf("2.��I��J��K��L��������������(��Сд���ɣ��߽����)\n");
		printf("3.�ü�ͷ�������������ң��߽�ֹͣ\n");
		printf("4.�ü�ͷ�������������ң��߽����\n");
		printf("5.��I��J��K��L��������������(�����ͷ���������ƶ�����Сд���ɣ��߽�ֹͣ\n");
		printf("6.��I��J��K��L��������������(�����ͷ���������ƶ�����Сд���ɣ��߽����\n");
		printf("0.�˳�\n[��ѡ��0-6] ");

		choose = _getch();
		if (choose <= '6' && choose >= '0')
			break;
		else
			cls(hout);
	}

	return choose;
}

void move_by_ijkl(const HANDLE hout, int tag, int bonus_question) //tag: 0�߽�ֹͣ 1�߽���� bonus_question: 0 ���������ͷ 1�������ͷ
{
	cls(hout);
	init_border(hout);

	gotoxy(hout, 35, 9);
	int x = 35, y = 9; //��ǰ����
	int arrow; //���뷽��

	while (1) {
		arrow = _getch();

		//���������ͷ
		if (bonus_question && arrow == 224) {
			arrow = _getch();
			continue;
		}

		//�������ƶ�
		if (arrow == 'i' || arrow == 'I') {
			if (y == 1) {
				if (!tag)
					y++;
				else
					y = 18;
			}
			gotoxy(hout, x, --y);
		}
		else if (arrow == 'j' || arrow == 'J') {
			if (x == 1) {
				if (!tag)
					x++;
				else
					x = 70;
			}
			gotoxy(hout, --x, y);
		}
		else if (arrow == 'k' || arrow == 'K') {
			if (y == 17) {
				if (!tag)
					y--;
				else
					y = 0;
			}
			gotoxy(hout, x, ++y);
		}
		else if (arrow == 'l' || arrow == 'L') {
			if (x == 69) {
				if (!tag)
					x--;
				else
					x = 0;
			}
			gotoxy(hout, ++x, y);
		}

		//����ո�
		if (arrow == ' ') {
			showch(hout, x, y, ' ');
			gotoxy(hout, x, y);
		}

		//����q����
		if (arrow == 'q' || arrow == 'Q') {
			gotoxy(hout, 0, 23);
			printf("��Ϸ���������س������ز˵�.");

			while (1)
			{
				arrow = _getch();
				if (arrow == '\r')
				{
					cls(hout);
					gotoxy(hout, 0, 0);
					return;
				}
			}
		}
	}
}

void move_by_arrow(const HANDLE hout,  int tag) //tag: 0�߽�ֹͣ 1�߽����
{
	cls(hout);
	init_border(hout);

	gotoxy(hout, 35, 9);
	int x = 35, y = 9; //��ǰ����
	int arrow; //���뷽��


	while (1) {
		arrow = _getch();
		if (arrow == 224) { //���뷽���_getch()���ȡ����
			arrow = _getch();

			//�������ƶ�
			if (arrow == 72) { //i
				if (y == 1) {
					if (!tag)
						y++;
					else
						y = 18;
				}
				gotoxy(hout, x, --y);
			}
			else if (arrow == 75) { //j
				if (x == 1) {
					if (!tag)
						x++;
					else
						x = 70;
				}
				gotoxy(hout, --x, y);
			}
			else if (arrow == 80) { //k
				if (y == 17) {
					if (!tag)
						y--;
					else
						y = 0;
				}
				gotoxy(hout, x, ++y);
			}
			else if (arrow == 77) { //l
				if (x == 69) {
					if (!tag)
						x--;
					else
						x = 0;
				}
				gotoxy(hout, ++x, y);
			}
		}

		//����ո�
		if (arrow == ' ') {
			showch(hout, x, y, ' ');
			gotoxy(hout, x, y);
		}

		//����q����
		if (arrow == 'q' || arrow == 'Q') {
			gotoxy(hout, 0, 23);
			printf("��Ϸ���������س������ز˵�.");

			while (1)
			{
				arrow = _getch();
				if (arrow == '\r')
				{
					cls(hout);
					gotoxy(hout, 0, 0);
					return;
				}
			}
		}
	}
}

int main()
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //ȡ��׼����豸��Ӧ�ľ��

	//����α�����������
	srand((unsigned int)(time(0)));

	int choose;
	while (1) {
		choose = menu(hout);

		switch (choose)
		{
			case '1':
				move_by_ijkl(hout, 0, 0);
				break;
			case '2':
				move_by_ijkl(hout, 1, 0);
				break;
			case '3':
				move_by_arrow(hout, 0);
				break;
			case '4':
				move_by_arrow(hout, 1);
				break;
			case '5':
				move_by_ijkl(hout, 0, 1);
				break;
			case '6':
				move_by_ijkl(hout, 1, 1);
				break;
			case '0':
				return 0;
		}
	}

	return 0;
}

//������ĸ���ֲ�һ��Ϊ20����
//������������ĸ��λ���ص���ʱ�򲻵�20��