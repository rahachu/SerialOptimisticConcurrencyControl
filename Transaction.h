#include <set>
#include <iostream>
#include <chrono> 
#include <ctime>
#include <map>

using namespace std::chrono; 
using namespace std;

class Transaction
{
private:
    /* data */
    static set<Transaction *> transactionSet;
    set<int *> writeSet;
    set<int *> readSet;
    map<int *,int> tempMemmory;
public:
    //member
    time_point<system_clock> startTS;
    time_point<system_clock> validationTS;
    time_point<system_clock> finishTS;

    //method
    Transaction(/* args */);
    ~Transaction();
    void read(int *varToRead);
    void write(int *varToWrite, int newVal);
    void validate();
    bool isValidated();
    bool writeOverlap(set<int *> readSet);
    void writeToMemory();
};