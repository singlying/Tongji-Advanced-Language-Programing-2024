
#include <iostream>
#include <iomanip>
using namespace std;

/* ----    ??  ----
   1                ?? ?? 
   2            ?? ??           hanoi §Ø   ??    ?? ??     
   3                    
   4  main           ??    ??  
   --------------------------------------------------------------------- */

   /***************************************************************************
            ?? 
            ??   ??n ????     ?? ??  
              int n      
               char src    ??  
               char tmp   §Þ   
               char dst  ??    
           ??  
     ??        1           ¦Â¦±        ??   ??  
               2                   ¦Ê   ??  ??  
               3          ??    ?? ??     
   ***************************************************************************/
void hanoi(int n, char src, char tmp, char dst)
{
    static int count;

    if (n == 1) {
        count++;
        cout << setw(5) << count << ":" << setw(3) << n << "# " << src << "-->" << dst << endl;
        return;
    }
    else {
        hanoi(n - 1, src, dst, tmp);
        count++;
        cout << setw(5) << count << ":" << setw(3) << n << "# " << src << "-->" << dst << endl;
        hanoi(n - 1, tmp, src, dst);
    }
}

/***************************************************************************
         ?? 
         ?? 
           
        ??  
  ??        1        ??   ????üD  
            2             ??      ??  ??  
            3  ??  ????  ï…                            ??/??     ??  ????  ????            ?? ??   main §µ 
***************************************************************************/
int main()
{
    int n;
    char src, tmp, dst; //src  ?? tmp §Þ  dst??  

    while (1) { //input n
        cout << "     ????   ??   (1-16)" << endl;
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
        cout << "        ??  (A-C)" << endl;
        cin >> src;

        //   ??????  §ÕABC
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
        cout << "      ??    (A-C)" << endl;
        cin >> dst;

        if (dst == 'a' || dst == 'b' || dst == 'c') {
            dst += 'A' - 'a';
        }

        if (dst == 'A' || dst == 'B' || dst == 'C') {
            if (dst == src) {
                cout << "??    (" << dst << ")        ??  (" << src << ")  ??" << endl;
            }
            else
                break;
        }

        cin.ignore(1024, '\n');
    }
    cin.ignore(1024, '\n');

    //  dmp
    if (src == 'A')
        tmp = (dst == 'B' ? 'C' : 'B');
    else if (src == 'B')
        tmp = (dst == 'C' ? 'A' : 'C');
    else
        tmp = (dst == 'A' ? 'B' : 'A');

    //hanoi
    cout << " ??     ??:" << endl;
    hanoi(n, src, tmp, dst);

    return 0;

}
