
#include <stdio.h>
#include <windows.h> //ȡϵͳʱ��

int main()
{
	LARGE_INTEGER tick, begin, end;

	QueryPerformanceFrequency(&tick);	//��ü�����Ƶ��
	QueryPerformanceCounter(&begin);	//��ó�ʼӲ������������

	/* �˴�����ĳ���ʼ */
	int count = 0; //��������
	for (int n_1 = 1; n_1 <= 9; n_1++) {
		for (int n_2 = 1; n_2 <= 9; n_2++) {

			if (n_2 == n_1) {
				continue;
			}

			for (int n_3 = 1; n_3 <= 9; n_3++) {
				if (n_3 == n_1 || n_3 == n_2) {
					continue;
				}

				for (int n_4 = 1; n_4 <= 9; n_4++) {
					if (n_4 == n_1 || n_4 == n_2 || n_4 == n_3) {
						continue;
					}

					for (int n_5 = 1; n_5 <= 9; n_5++) {
						if (n_5 == n_1 || n_5 == n_2 || n_5 == n_3 || n_5 == n_4) {
							continue;
						}

						for (int n_6 = 1; n_6 <= 9; n_6++) {
							if (n_6 == n_1 || n_6 == n_2 || n_6 == n_3 || n_6 == n_4 || n_6 == n_5) {
								continue;
							}

							for (int n_7 = 1; n_7 <= 9; n_7++) {
								if (n_7 == n_1 || n_7 == n_2 || n_7 == n_3 || n_7 == n_4 || n_7 == n_5 || n_7 == n_6) {
									continue;
								}

								for (int n_8 = 1; n_8 <= 9; n_8++) {
									if (n_8 == n_1 || n_8 == n_2 || n_8 == n_3 || n_8 == n_4 || n_8 == n_5 || n_8 == n_6 || n_8 == n_7) {
										continue;
									}

									for (int n_9 = 1; n_9 <= 9; n_9++) {
										if (n_9 == n_1 || n_9 == n_2 || n_9 == n_3 || n_9 == n_4 || n_9 == n_5 || n_9 == n_6 || n_9 == n_7 || n_9 == n_8) {
											continue;
										}

										//�����
										int num_1 = n_1 * 100 + n_2 * 10 + n_3;
										int num_2 = n_4 * 100 + n_5 * 10 + n_6;
										int num_3 = n_7 * 100 + n_8 * 10 + n_9;

										//��֦
										if (num_1 > num_2 || num_1 > num_3 || num_2 > num_3) {
											continue;
										}

										if (num_1 + num_2 + num_3 == 1953) {
											count++;
											printf("No.%3d : %d+%d+%d=1953\n", count, num_1, num_2, num_3);
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	
	printf("total=%d\n", count);


	/* �˴�����ĳ������ */

	QueryPerformanceCounter(&end);		//�����ֹӲ������������

	printf("������Ƶ�� : %lldHz\n", tick.QuadPart);
	printf("���������� : %lld\n", end.QuadPart - begin.QuadPart);
	printf("%.6f��\n", (double)(end.QuadPart - begin.QuadPart) / tick.QuadPart);

	return 0;
}
