
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/* ----����Ҫ��----
   1���������������ͷ�ļ�
   2��������һ��ȫ�ֱ������������徲̬�ֲ�����
   3�������������������
   4��main�����������룬����ѭ��
   --------------------------------------------------------------------- */


   /***************************************************************************
     �������ƣ�
     ��    �ܣ���ӡn�㺺ŵ�����ƶ�˳��
     ���������int n������
               char src����ʼ��
               char tmp���м���
               char dst��Ŀ����
     �� �� ֵ��
     ˵    ����1�����������βΡ��������;���׼��
               2������������������κ���ʽ��ѭ��
   ***************************************************************************/

int count = 0; //����ȫ�ֱ���
void hanoi(int n, char src, char tmp, char dst)
{
    if (n == 1) {
        count++;
        printf("%5d:%3d# %c-->%c\n", count, n, src, dst);
        return;
    }
    else {
        hanoi(n - 1, src, dst, tmp);
        count++;
        printf("%5d:%3d# %c-->%c\n", count, n, src, dst);
        hanoi(n - 1, tmp, src, dst);
    }
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����1��������롢���õݹ麯��
            2�������������ʱ������ʹ��ѭ��
            3��Ϊ��ͳһ��飬���������������������������ʼ/Ŀ�����Ĵ��벻Ҫ��ͳһ����������ֱ�ӷ���main�У�
***************************************************************************/
int main()
{
    int n;
    char src, tmp, dst; //src��ʼ tmp�м� dstĿ��

    while (1) {
        printf("�����뺺ŵ���Ĳ���(1-16)\n");
        int ret = scanf("%d", &n);
        if (ret != 1 || n < 1 || n > 16) {
            while (getchar() != '\n') {
            };
        }
        else {
            while (getchar() != '\n') {
            };
            break;
        }
    }

    while (1) { //input src
        printf("��������ʼ��(A-C)\n");
        scanf("%c", &src);

        //���ͳһΪ��дABC
        if (src == 'a' || src == 'b' || src == 'c') {
            src += 'A' - 'a';
            break;
        }
        else if (src == 'A' || src == 'B' || src == 'C') {
            break;
        }

        while (getchar() != '\n') {
        };
    }
    while (getchar() != '\n') {
    };

    while (1) { //input dst
        printf("������Ŀ����(A-C)\n");
        scanf("%c", &dst);

        if (dst == 'a' || dst == 'b' || dst == 'c') {
            dst += 'A' - 'a';
        }

        if (dst == 'A' || dst == 'B' || dst == 'C') {
            if (dst == src) {
                printf("Ŀ����(%c)��������ʼ��(%c)��ͬ\n", dst, src);
            }
            else
                break;
        }

        while (getchar() != '\n') {
        };
    }
    while (getchar() != '\n') {
    };

    //��dmp
    if (src == 'A')
        tmp = (dst == 'B' ? 'C' : 'B');
    else if (src == 'B')
        tmp = (dst == 'C' ? 'A' : 'C');
    else
        tmp = (dst == 'A' ? 'B' : 'A');

    //hanoi
    printf("�ƶ�����Ϊ:\n");
    hanoi(n, src, tmp, dst);

    return 0;
}