

/* ���������ϵͳ�ĺ궨�塢��Ҫ��ͷ�ļ��� */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<iomanip>
#include "read_stulist.h"
using namespace std;

#define MAX_FILENAME_LEN		512	//�����ļ�������󳤶�

/* stu_metge ����ÿ��ѧ������Ϣ������ѧ�š�������������Ҫ��˽����Ϣ���������ݲ�׼�����ɼ����������Ҫ��������� */
class stu_merge {
private:
	int  stu_no;					//ѧ��
	char stu_name[MAX_NAME_LEN];  //����
	bool tag1; //��ʾ�ڼ���ѡ��
	bool tag2; 

	/* ���������private���ݳ�Ա����Ա�����Լ�������Ҫ������ */
	friend class stu_list;
	stu_merge() : stu_no(0), tag1(false), tag2(false) {}

public:
	//���಻�������κεĹ������ݳ�Ա����Ա����
};

/* stu_list ������ѡ����Ϣ���������ݲ�׼�����ɼ����������Ҫ��������� */
class stu_list {
private:
	student list_round_1[MAX_STU_NUM];	//��һ��ѡ�ε�ѧ�������������򡢲�ȥ�أ�
	int list_num_1;						//��һ��ѡ�ε�ѧ������

	student list_round_2[MAX_STU_NUM];	//�ڶ���ѡ�ε�ѧ�������������򡢲�ȥ�أ�
	int list_num_2;						//�ڶ���ѡ�ε�ѧ������

	stu_merge list_merge[MAX_STU_NUM];	//�ϲ����ѧ��������ȥ�أ����������У�
	int list_merge_num;					//�ϲ����ѧ��������Ŀǰ����ӡ�����������ڲ������������Ҫ��Ҳ��Ҫɾ����

	/* ���������private���ݳ�Ա�ͳ�Ա����
	   ע�⣬���������array / set / map / vector��STL���� */

public:
	stu_list();										//���캯����������ɳ�ʼ�����ܣ��������Ҫ�������պ�������
	int read(const char* filename, const int round);	//���ļ��ж���ѡ����Ϣ��roundΪ1/2����ʾѡ���ִ�
	int print(const char* prompt = NULL);				//��ӡ���յ�ѡ������

	/* �������������public��Ա��������ʾ���ϲ���ȥ�ء�����ȣ�
	   �������幫�е����ݳ�Ա
	   �������ڳ�Ա������ʹ��array / set / map / vector��STL���� */

	void sort_round(); //��������
	void removeDuplicates_in_round(); //����ȥ��
	//void merge_after_sort();  //�ϲ�

	void merge();  //�ȺͲ�
	void sort_merge();  //������
	void removeDuplicates_in_merge();  //���ȥ�� 
};

/* --- ������Ը���stu_merge/stu_list������ĳ�Ա����������ʵ�� --- */
//����  ���ֵ�һ��ѡ���ǵڶ���ѡ
//		�����˿�

void stu_list::sort_round()
{
	//select sort
	//round 1
	for (int i = 0; i < list_num_1; i++) {
		int minIndex = i;
		for (int j = i + 1; j < list_num_1; j++) {
			if (list_round_1[j].no < list_round_1[minIndex].no)
				minIndex = j;
		}
		if (minIndex != i) {
			student temp = list_round_1[i];
			list_round_1[i] = list_round_1[minIndex];
			list_round_1[minIndex] = temp;
		}
	}

	//round 2
	for (int i = 0; i < list_num_2; i++) {
		int minIndex = i;
		for (int j = i + 1; j < list_num_2; j++) {
			if (list_round_2[j].no < list_round_2[minIndex].no)
				minIndex = j;
		}
		if (minIndex != i) {
			student temp = list_round_2[i];
			list_round_2[i] = list_round_2[minIndex];
			list_round_2[minIndex] = temp;
		}
	}
}

void stu_list::removeDuplicates_in_round()
{
	//round 1
	int index = 0;
	for (int i = 0; i < list_num_1; i++, index++) {
		list_round_1[index].no = list_round_1[i].no;
		strncpy(list_round_1[index].name, list_round_1[i].name, MAX_NAME_LEN - 1);
		while (i < list_num_1 && list_round_1[i + 1].no == list_round_1[i].no)
			i++;
	}
	list_num_1 = index;
	//round 2
	index = 0;
	for (int i = 0; i < list_num_2; i++, index++) {
		list_round_2[index].no = list_round_2[i].no;
		strncpy(list_round_2[index].name, list_round_2[i].name, MAX_NAME_LEN - 1);
		while (i < list_num_2 && list_round_2[i + 1].no == list_round_2[i].no)
			i++;
	}
	list_num_2 = index;
}

void stu_list::merge()
{

	int i = 0;
	for (int j = 0; j < list_num_1; j++, i++) {
		list_merge[i].stu_no = list_round_1[j].no;
		list_merge[i].tag1 = true;
		strncpy(list_merge[i].stu_name, list_round_1[j].name, MAX_NAME_LEN);
	}

	for (int j = 0; j < list_num_2; j++, i++) {
		list_merge[i].stu_no = list_round_2[j].no;
		list_merge[i].tag2 = true;
		strncpy(list_merge[i].stu_name, list_round_2[j].name, MAX_NAME_LEN);
	}


	list_merge_num = list_num_1 + list_num_2;
}

void stu_list::sort_merge()
{
	//select sort
	for (int i = 0; i < list_merge_num - 1; i++) {
		int minIndex = i;
		for (int j = i + 1; j < list_merge_num; j++) {
			if (list_merge[j].stu_no < list_merge[minIndex].stu_no)
				minIndex = j;
		}
		if (minIndex != i) {
			stu_merge temp = list_merge[i];
			list_merge[i] = list_merge[minIndex];
			list_merge[minIndex] = temp;
		}
	}
}

//BUG :  11-145.txt 21-189.txt ��141��ʼ��BUG

void stu_list::removeDuplicates_in_merge()
{
	int index = 0;
	for (int i = 0; i < list_merge_num; i++, index++) {
		list_merge[index].stu_no = list_merge[i].stu_no;
		list_merge[index].tag1 = list_merge[i].tag1;
		list_merge[index].tag2 = list_merge[i].tag2;
		strncpy(list_merge[index].stu_name, list_merge[i].stu_name, MAX_NAME_LEN);
		/*if (i < list_merge_num - 1 && list_merge[i].stu_no == list_merge[i + 1].stu_no) {
			list_merge[index].tag1 = 3;
			i++;
			list_merge_num--;
		}*/
		while (i < list_merge_num - 1 && list_merge[i].stu_no == list_merge[i + 1].stu_no) {
			list_merge[index].tag1 = list_merge[i + 1].tag1 || list_merge[index].tag1;
			list_merge[index].tag2 = list_merge[i + 1].tag2 || list_merge[index].tag2;
			i++;
		}
	}
	list_merge_num = index;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ����ļ��ж���ѡ����Ϣ��roundΪ1/2����ʾѡ���ִ�
  ���������
  �� �� ֵ��
  ˵    �������캯����������ɳ�ʼ�����ܣ��������Ҫ�������պ�������
***************************************************************************/
stu_list::stu_list()
{
	list_num_1 = 0;
	list_num_2 = 0;
	list_merge_num = 0;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ���ʾ��̬���ӿ��ʹ�ã��������е��þ�̬���ӿ��е�Ԥ�ú���
  ���������
  �� �� ֵ��
  ˵    ��������������Ҫ�޸� 
***************************************************************************/
int stu_list::read(const char* filename, const int round)
{
	int ret = 0;
	/* ��ȡ��1/2�ֵ�ѡ����������ӡ */
	switch (round) {
		case 1:
			this->list_num_1 = read_stulist(filename, this->list_round_1, MAX_STU_NUM);
			if (this->list_num_1 > 0)
				print_stulist("��һ��ѡ��������", this->list_round_1, this->list_num_1);
			else
				ret = -1;
			break;
		case 2:
			this->list_num_2 = read_stulist(filename, this->list_round_2, MAX_STU_NUM);
			if (this->list_num_2 > 0)
				print_stulist("�ڶ���ѡ��������", this->list_round_2, this->list_num_2);
			else
				ret = -1;
			break;
		default:
			ret = -1;
			break;
	}

	return ret;
}


/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ������ӡ���յ�ѡ������
***************************************************************************/
int stu_list::print(const char* prompt)
{
	cout << prompt << endl;
	cout << "============================================================" << endl;
	cout << "��� ѧ��     ����                            ��һ�� �ڶ���" << endl;
	cout << "============================================================" << endl;

	for (int i = 0; i < list_merge_num; i++) {
		cout << left << setw(5) << i + 1 << setw(9) << list_merge[i].stu_no << setw(32) << list_merge[i].stu_name;
		/*switch (list_merge[i].tag1) {
			case 1:
				cout << setw(7) << 'Y' << "�˿�" << endl;
				break;
			case 2:
				cout << setw(7) << '/' << "��ѡ" << endl;
				break;
			case 3:
				cout << setw(7) << 'Y' << 'Y' << endl;
				break;
		}*/
		if (list_merge[i].tag1 && list_merge[i].tag2) // 1 1
			cout << setw(7) << 'Y' << 'Y' << endl;
		else if (!list_merge[i].tag1 && list_merge[i].tag2) // 0 1
			cout << setw(7) << '/' << "��ѡ" << endl;
		else // 1 0
			cout << setw(7) << 'Y' << "�˿�" << endl;
	}
	cout << "============================================================" << endl;
	return 0;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main(int argc, char** argv)
{
	char file1[MAX_FILENAME_LEN], file2[MAX_FILENAME_LEN];

	cout << "������ǰһ��ѡ�ε������ļ� : ";
	gets_s(file1); //cin���ܶ��пո���ļ�

	cout << "�������һ��ѡ�ε������ļ� : ";
	gets_s(file2);

	stu_list list;

	/* �������� */
	if (list.read(file1, 1) < 0)
		return -1;
	if (list.read(file2, 2) < 0)
		return -1;

	/* �������� */
	list.sort_round();
	list.removeDuplicates_in_round();
	list.merge();
	list.sort_merge();
	list.removeDuplicates_in_merge();

	/* ��ӡ */
	list.print("����ѡ������");

	return 0;
}