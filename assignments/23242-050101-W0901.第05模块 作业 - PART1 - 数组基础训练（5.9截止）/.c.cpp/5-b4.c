
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	printf("������ɼ������1000������������������\n");

	int arr[1000];
	int score[101] = {0};
	int num = 0;

	while (scanf("%d", &arr[num]), arr[num] > -1) { //����
		num++;
		if (num == 1000)
			break;
	}
	while (getchar() != '\n') {
	};

	if (!num) {
		printf("����Ч����\n");
		return 0;
	}

	printf("���������Ϊ:");  //���ԭ����
	for (int i = 0; i < num; i++) {
		if (!(i % 10))
			printf("\n");

		printf("%d ", arr[i]);
	}
	printf("\n");

	for (int i = 0; i < num; i++) { //��������
		score[arr[i]]++;
	}

	printf("�����������Ķ�Ӧ��ϵΪ:\n"); //�������
	for (int i = 100; i > -1; i--) {
		if (score[i]) {
			printf("%d %d\n", i, score[i]);
		}
	}

	return 0;
}