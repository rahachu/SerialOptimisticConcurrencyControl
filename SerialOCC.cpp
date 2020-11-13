#include "Transaction.h"
// #define testcase2

int main(int argc, char const *argv[])
{
    /* code */
    int a,b;
    cout << "T1 start" << endl;
    Transaction t1;
    cout << "T1 read variable b" << endl;
    t1.read(&b);
    cout << "T2 start" << endl;
    Transaction t2;
    cout << "T2 read variable b" << endl;
    t2.read(&b);
    cout << "T2 read variable a" << endl;
    t2.read(&a);
    cout << "T1 validate" << endl;
    #ifdef testcase2
    cout << "T1 write variable a" << endl;
    t1.write(&a,5);
    #endif
    t1.validate();
    cout << "T2 validate" << endl;
    t2.validate();
    return 0;
}
