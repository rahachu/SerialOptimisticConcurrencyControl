#include "Transaction.h"
// #define testcase2

int main(int argc, char const *argv[])
{
    /* code */
    int a,b;
    Transaction t1;
    t1.read(&b);
    Transaction t2;
    t2.read(&b);
    t2.read(&a);
    t1.validate();
    #ifdef testcase2
    t1.write(&a,5);
    #endif
    t2.validate();
    return 0;
}
