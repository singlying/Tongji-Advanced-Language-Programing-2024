
#include <iostream>
using namespace std;

#define  N  10	/* �������ת��10������ */

/* �������ٶ�������������ȫ�ֱ��� */

int main()
{
	/* ����в���Ҫ�ı���������ɾ��������������ӻ��滻Ϊ�������͵ı��� */
	char str[256], * p;
	int  a[N] = { 0 }, * pnum, * pa;
	bool is_num;

	/* ����Ķ��岻׼��(ɾ������Ҫ�ı�������)������Ϊ����ľ���ʵ�֣�Ҫ�󲻵��ٶ����κα����������������� */
	// ����
	cout << "�����������������������ֵ��ַ���" << endl;
	gets_s(str);

	//����
	p = str;
	pa = a;

	while (*p != '\0') {
		if (*p <= '9' && *p >= '0') {
			while (*p <= '9' && *p >= '0') {
				*pa = *pa * 10 + *p - '0';
				p++;
			}
			pa++;
		}
		else
			p++;

		if (pa == a + N)
			break;
	}

	// ���
	cout << "����" << pa - a << "������" << endl;
	pnum = pa;
	pa = a;
	while (pa < pnum) {
		cout << *pa << " ";
		pa++;
	}
	cout << endl;


	return 0;
}
