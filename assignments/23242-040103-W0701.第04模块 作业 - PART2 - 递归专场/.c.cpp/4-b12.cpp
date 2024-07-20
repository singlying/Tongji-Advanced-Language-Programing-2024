
#include <iostream>
#include <iomanip>
using namespace std;

/* ----����Ҫ��----
   1���������������ͷ�ļ�
   2����������ȫ�ֱ�������̬�ֲ�����
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
void hanoi(int n, char src, char tmp, char dst)
{
    if (n == 1) {
        cout << setw(2) << n << "# " << src << "-->" << dst << endl;
        return;
    }
    else {
        hanoi(n - 1, src, dst, tmp);
        cout << setw(2) << n << "# " << src << "-->" << dst << endl;
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

    while (1) { //input n
        cout << "�����뺺ŵ���Ĳ���(1-16)" << endl;
        cin >> n;
        if (cin.fail() || n < 1 || n > 16) {
            cin.clear();
            cin.ignore(1024, '\n');
        }
        else {
            cin.ignore(1024, '\n');
            break;
        }
    }

    while (1) { //input src
        cout << "��������ʼ��(A-C)" << endl;
        cin >> src;

        //���ͳһΪ��дABC
        if (src == 'a' || src == 'b' || src == 'c') {
            src += 'A' - 'a';
            break;
        }
        else if (src == 'A' || src == 'B' || src == 'C') {
            break;
        }
        
        cin.ignore(1024, '\n');
    }
    cin.ignore(1024, '\n');

    while (1) { //input dst
        cout << "������Ŀ����(A-C)" << endl;
        cin >> dst;

        if (dst == 'a' || dst == 'b' || dst == 'c') {
            dst += 'A' - 'a';
        }
        
        if (dst == 'A' || dst == 'B' || dst == 'C') {
            if (dst == src) {
                cout << "Ŀ����(" << dst << ")��������ʼ��(" << src << ")��ͬ" << endl;
            }
            else
                break;
        }

        cin.ignore(1024, '\n');
    }
    cin.ignore(1024, '\n');

    //��dmp
    if (src == 'A')
        tmp = (dst == 'B' ? 'C' : 'B');
    else if (src == 'B')
        tmp = (dst == 'C' ? 'A' : 'C');
    else
        tmp = (dst == 'A' ? 'B' : 'A');

    //hanoi
    cout << "�ƶ�����Ϊ:" << endl;
    hanoi(n, src, tmp, dst);

    return 0;
}
