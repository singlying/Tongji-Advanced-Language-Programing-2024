
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	printf("请输入成绩（最多1000个），负数结束输入\n");

	int arr[1000];
	int score[101] = {0};
	int num = 0;

	while (scanf("%d", &arr[num]), arr[num] > -1) { //输入
		num++;
		if (num == 1000)
			break;
	}
	while (getchar() != '\n') {
	};

	if (!num) {
		printf("无有效输入\n");
		return 0;
	}

	printf("输入的数组为:");  //输出原数组
	for (int i = 0; i < num; i++) {
		if (!(i % 10))
			printf("\n");

		printf("%d ", arr[i]);
	}
	printf("\n");

	for (int i = 0; i < num; i++) { //计算人数
		score[arr[i]]++;
	}

	printf("分数与人数的对应关系为:\n"); //输出人数
	for (int i = 100; i > -1; i--) {
		if (score[i]) {
			printf("%d %d\n", i, score[i]);
		}
	}

	return 0;
}