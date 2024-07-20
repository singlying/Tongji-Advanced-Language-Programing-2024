
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
		matrix.row = input_tools(5, 9, "请输入行数(5-9)");
		matrix.column = input_tools(5, 9, "请输入列数(5-9)");

		init_matirx(matrix);
		cout << "初始数组：" << endl;
		print_matrix(matrix);

		switch (select) {
			case 1: {
				input_enter("\n按回车键进行寻找初始可消除项的操作...");
				if (test_triple(matrix)) {
					cout << "初始可消除项（不同色标识）：" << endl;
					print_matrix(matrix);
				}
				else {
					cout << "初始已无可消除项" << endl;
				}
				input_end();
				break;
			}
			case 2: {
				input_enter("按回车键进行寻找初始可消除项的操作...");

				while (test_triple(matrix)) {
					cout << "初始可消除项（不同色标识）：" << endl;
					print_matrix(matrix);

					input_enter("按回车键进行数组下落除0操作...");
					cout << "下落除0后的数组(不同色标识)：" << endl;
					drop_ball(matrix);
					print_matrix(matrix);

					///
					input_enter("按回车键进行新值填充...");
					cout << "新值填充后的数组(不同色标识)：" << endl;
					refill_matrix(matrix);
					print_matrix(matrix);
					reset_matrix(matrix);
				}

				cout << "初始已无可消除项" << endl;
				input_end();
				break;
			}
			case 3: {
				input_enter("按回车键进行寻找初始可消除项的操作...");

				while (test_triple(matrix)) {
					cout << "初始可消除项（不同色标识）：" << endl;
					print_matrix(matrix);

					input_enter("按回车键进行数组下落除0操作...");
					cout << "下落除0后的数组(不同色标识)：" << endl;
					drop_ball(matrix);
					print_matrix(matrix);

					///
					input_enter("按回车键进行新值填充...");
					cout << "新值填充后的数组(不同色标识)：" << endl;
					refill_matrix(matrix);
					print_matrix(matrix);
					reset_matrix(matrix);
				}
				cout << "初始已无可消除项" << endl << endl;

				cout << "可选择的消除提示（不同色标识）：" << endl;
				detect_elimination(matrix);
				print_matrix(matrix);

				input_end();
				break;
			}
			case 4: {
				input_enter("按回车键显示图形...");
				graph_matrix(matrix, WITHOUT_DELIMITERS, ISDELSY);
				input_end();
				break;
			}
			case 5: {
				input_enter("按回车键显示图形...");
				graph_matrix(matrix, WITH_DELIMITERS, ISDELSY);
				input_end();
				break;
			}
			case 6: {
				bool tag = test_triple(matrix);
				graph_matrix(matrix, WITHOUT_DELIMITERS);
				if (!tag)
					cout << "未找到初始可消除项" << endl;

				input_end();
				break;
			}
			case 7: {
				bool tag = test_triple(matrix);
				graph_matrix(matrix);
				if (!tag)  //无初始可消除项 
					cout << "未找到初始可消除项" << endl;  ////这句话到后面删不掉 一直留在这里
				else {  //有初始可消除项
					do {
						graphic_triple(matrix);
						input_enter("按回车键进行消除及下落除0操作...");
						graphic_eliminate(matrix);

						input_enter("按回车键进行新值填充...");
						drop_ball(matrix);   //后端操作
						refill_matrix(matrix);
						graphic_refill_matrix(matrix);  //前端 /////到这里时新加入的球is_triple = true

					} while (test_triple(matrix));
				}

				input_enter("按回车键显示消除提示...");
				erase_cout(matrix);

				if (!detect_elimination(matrix)) {
					cout << "无可消除项，游戏结束！" << endl;
				}
				else
					graphic_exchangeable(matrix);

				input_end();
				break;
			}
			case 8: {
				graph_matrix(matrix);
				output_tools(matrix, "当前分数：0 右键退出", 1);
				output_tools(matrix, "[当前光标]", 2);

				while (test_triple(matrix)) {
					graphic_triple(matrix);
					graphic_eliminate(matrix);

					drop_ball(matrix);   //后端操作
					refill_matrix(matrix);
					graphic_refill_matrix(matrix);  //前端
				}

				if (!detect_elimination(matrix)) {
					output_tools(matrix, "无可消除项，游戏结束！            ", 2);
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
				output_tools(matrix, "当前分数：0 右键退出     ", 1);
				output_tools(matrix, "[当前光标]", 2);

				char prompt[50]; // 足够大的字符数组存储结果
				node* last_node = NULL;
				int score = 0;
				bool is_first_time = true;  // 第一次消除不算分

				while (1) {
					while (test_triple(matrix)) {  // 消除初始triple
						graphic_triple(matrix);
						graphic_eliminate(matrix);

						drop_ball(matrix);   // 后端操作
						int temp = refill_matrix(matrix);
						if (!is_first_time)  // 加分
							score += temp;
						graphic_refill_matrix(matrix);  //前端
					}

					is_first_time = false;
					snprintf(prompt, sizeof(prompt), "当前分数：%d 右键退出     ", score); //更改分数
					output_tools(matrix, prompt, 1);

					if (detect_elimination(matrix)) {
						graphic_exchangeable(matrix);

						node* select_node = track_mouse(matrix);

						if (!select_node)  //返回无效值 直接结束
							break;
						else {  //返回有效值
							int i = (select_node - matrix.arr[0]) / MAXCOLUMN; //行
							int j = (select_node - matrix.arr[0]) % MAXCOLUMN; //列
							int last_i = (last_node - matrix.arr[0]) / MAXCOLUMN; //上一个节点的行
							int last_j = (last_node - matrix.arr[0]) % MAXCOLUMN; //上一个节点的列

							if (!last_node) {  // 选择第一个球
								matrix.arr[i][j].is_selected = true;
								last_node = select_node;  //记录位置
							}
							else { //选择第二个球
								if (last_node == select_node) {  //选了上次相同的球
									matrix.arr[i][j].is_selected = false;
									last_node = NULL;
								}
								else if (!(i == last_i && fabs(j - last_j) == 1 || j == last_j && fabs(i - last_i) == 1)) { //不相邻
									matrix.arr[last_i][last_j].is_selected = false;
									last_node = select_node;
									matrix.arr[i][j].is_selected = true;
								}
								else if (!test_exchange(matrix, last_node, select_node)) { //选相邻但不相关
									matrix.arr[last_i][last_j].is_selected = false;
									last_node = NULL;

									snprintf(prompt, sizeof(prompt), "不能交换 %c行%d列<<=>>%c行%d列  ", i + 'A', j + 1, last_i + 'A', last_j + 1);
									output_tools(matrix, prompt, 2);
									Sleep(1000);
								}
								else { //相关
									matrix.arr[last_i][last_j].is_selected = false;
									exchange_2ball(last_node, select_node);
									graphic_exchange(matrix, select_node, last_node);
									last_node = NULL;
								}
							}
						}
					}
					else {
						graphic_exchangeable(matrix);  //防止出现结束时动画没有更新的情况
						output_tools(matrix, "无可消除项，游戏结束！            ", 2);
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