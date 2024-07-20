
#include <iostream>
#include <Windows.h>
#include "magic_ball.h"
#include "cmd_console_tools.h"
using namespace std;

int main()
{
	int select;
	while (1) {
		select = Menu();
		if (select == 0)
			return 0;

		cct_cls();
		Matrix matrix;
		matrix.row = input_tools(5, 9, "����������(5-9)");
		matrix.column = input_tools(5, 9, "����������(5-9)");

		init_matirx(matrix);
		cout << "��ʼ���飺" << endl;
		print_matrix(matrix);

		switch (select) {
			case 1: {
				input_enter("\n���س�������Ѱ�ҳ�ʼ��������Ĳ���...");
				if (test_triple(matrix)) {
					cout << "��ʼ���������ͬɫ��ʶ����" << endl;
					print_matrix(matrix);
				}
				else {
					cout << "��ʼ���޿�������" << endl;
				}
				input_end();
				break;
			}
			case 2: {
				input_enter("���س�������Ѱ�ҳ�ʼ��������Ĳ���...");

				while (test_triple(matrix)) {
					cout << "��ʼ���������ͬɫ��ʶ����" << endl;
					print_matrix(matrix);

					input_enter("���س����������������0����...");
					cout << "�����0�������(��ͬɫ��ʶ)��" << endl;
					drop_ball(matrix);
					print_matrix(matrix);

					///
					input_enter("���س���������ֵ���...");
					cout << "��ֵ���������(��ͬɫ��ʶ)��" << endl;
					refill_matrix(matrix);
					print_matrix(matrix);
					reset_matrix(matrix);
				}

				cout << "��ʼ���޿�������" << endl;
				input_end();
				break;
			}
			case 3: {
				input_enter("���س�������Ѱ�ҳ�ʼ��������Ĳ���...");

				while (test_triple(matrix)) {
					cout << "��ʼ���������ͬɫ��ʶ����" << endl;
					print_matrix(matrix);

					input_enter("���س����������������0����...");
					cout << "�����0�������(��ͬɫ��ʶ)��" << endl;
					drop_ball(matrix);
					print_matrix(matrix);

					///
					input_enter("���س���������ֵ���...");
					cout << "��ֵ���������(��ͬɫ��ʶ)��" << endl;
					refill_matrix(matrix);
					print_matrix(matrix);
					reset_matrix(matrix);
				}
				cout << "��ʼ���޿�������" << endl << endl;

				cout << "��ѡ���������ʾ����ͬɫ��ʶ����" << endl;
				detect_elimination(matrix);
				print_matrix(matrix);

				input_end();
				break;
			}
			case 4: {
				input_enter("���س�����ʾͼ��...");
				graph_matrix(matrix, WITHOUT_DELIMITERS, ISDELSY);
				input_end();
				break;
			}
			case 5: {
				input_enter("���س�����ʾͼ��...");
				graph_matrix(matrix, WITH_DELIMITERS, ISDELSY);
				input_end();
				break;
			}
			case 6: {
				bool tag = test_triple(matrix);
				graph_matrix(matrix, WITHOUT_DELIMITERS);
				if (!tag)
					cout << "δ�ҵ���ʼ��������" << endl;

				input_end();
				break;
			}
			case 7: {
				bool tag = test_triple(matrix);
				graph_matrix(matrix);
				if (!tag)  //�޳�ʼ�������� 
					cout << "δ�ҵ���ʼ��������" << endl;  ////��仰������ɾ���� һֱ��������
				else {  //�г�ʼ��������
					do {
						graphic_triple(matrix);
						input_enter("���س������������������0����...");
						graphic_eliminate(matrix);

						input_enter("���س���������ֵ���...");
						drop_ball(matrix);   //��˲���
						refill_matrix(matrix);
						graphic_refill_matrix(matrix);  //ǰ�� /////������ʱ�¼������is_triple = true

					} while (test_triple(matrix));
				}

				input_enter("���س�����ʾ������ʾ...");
				erase_cout(matrix);

				if (!detect_elimination(matrix)) {
					cout << "�޿��������Ϸ������" << endl;
				}
				else
					graphic_exchangeable(matrix);

				input_end();
				break;
			}
			case 8: {
				graph_matrix(matrix);
				output_tools(matrix, "��ǰ������0 �Ҽ��˳�", 1);
				output_tools(matrix, "[��ǰ���]", 2);

				while (test_triple(matrix)) {
					graphic_triple(matrix);
					graphic_eliminate(matrix);

					drop_ball(matrix);   //��˲���
					refill_matrix(matrix);
					graphic_refill_matrix(matrix);  //ǰ��
				}

				if (!detect_elimination(matrix)) {
					output_tools(matrix, "�޿��������Ϸ������            ", 2);
				}
				else {
					graphic_exchangeable(matrix);
					track_mouse(matrix);
				}

				input_end();
				break;
			}
			case 9: {
				graph_matrix(matrix);
				output_tools(matrix, "��ǰ������0 �Ҽ��˳�     ", 1);
				output_tools(matrix, "[��ǰ���]", 2);

				char prompt[50]; // �㹻����ַ�����洢���
				node* last_node = NULL;
				int score = 0;
				bool is_first_time = true;  // ��һ�����������

				while (1) {
					while (test_triple(matrix)) {  // ������ʼtriple
						graphic_triple(matrix);
						graphic_eliminate(matrix);

						drop_ball(matrix);   // ��˲���
						int temp = refill_matrix(matrix);
						if (!is_first_time)  // �ӷ�
							score += temp;
						graphic_refill_matrix(matrix);  //ǰ��
					}

					is_first_time = false;
					snprintf(prompt, sizeof(prompt), "��ǰ������%d �Ҽ��˳�     ", score); //���ķ���
					output_tools(matrix, prompt, 1);

					if (detect_elimination(matrix)) {
						graphic_exchangeable(matrix);

						node* select_node = track_mouse(matrix);

						if (!select_node)  //������Чֵ ֱ�ӽ���
							break;
						else {  //������Чֵ
							int i = (select_node - matrix.arr[0]) / MAXCOLUMN; //��
							int j = (select_node - matrix.arr[0]) % MAXCOLUMN; //��
							int last_i = (last_node - matrix.arr[0]) / MAXCOLUMN; //��һ���ڵ����
							int last_j = (last_node - matrix.arr[0]) % MAXCOLUMN; //��һ���ڵ����

							if (!last_node) {  // ѡ���һ����
								matrix.arr[i][j].is_selected = true;
								last_node = select_node;  //��¼λ��
							}
							else { //ѡ��ڶ�����
								if (last_node == select_node) {  //ѡ���ϴ���ͬ����
									matrix.arr[i][j].is_selected = false;
									last_node = NULL;
								}
								else if (!(i == last_i && fabs(j - last_j) == 1 || j == last_j && fabs(i - last_i) == 1)) { //������
									matrix.arr[last_i][last_j].is_selected = false;
									last_node = select_node;
									matrix.arr[i][j].is_selected = true;
								}
								else if (!test_exchange(matrix, last_node, select_node)) { //ѡ���ڵ������
									matrix.arr[last_i][last_j].is_selected = false;
									last_node = NULL;

									snprintf(prompt, sizeof(prompt), "���ܽ��� %c��%d��<<=>>%c��%d��  ", i + 'A', j + 1, last_i + 'A', last_j + 1);
									output_tools(matrix, prompt, 2);
									Sleep(1000);
								}
								else { //���
									matrix.arr[last_i][last_j].is_selected = false;
									exchange_2ball(last_node, select_node);
									graphic_exchange(matrix, select_node, last_node);
									last_node = NULL;
								}
							}
						}
					}
					else {
						graphic_exchangeable(matrix);  //��ֹ���ֽ���ʱ����û�и��µ����
						output_tools(matrix, "�޿��������Ϸ������            ", 2);
						break;
					}
				}

				input_end();
				break;
			}
		}
	}

	return 0;
}