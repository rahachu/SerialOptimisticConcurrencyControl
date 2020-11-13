#include "Transaction.h"


set<Transaction *> Transaction::transactionSet;

Transaction::Transaction(/* args */)
{
    startTS = chrono::system_clock::now();
    validationTS = chrono::time_point<system_clock>::max();
    finishTS = chrono::time_point<system_clock>::max();
}

Transaction::~Transaction()
{
}

void Transaction::read(int *varToRead){
    readSet.insert(varToRead);
    tempMemmory.insert(pair<int *,int>(varToRead,*varToRead));
}

void Transaction::write(int *varToWrite, int newVal){
    writeSet.insert(varToWrite);
    tempMemmory[varToWrite]=newVal;
}

bool Transaction::writeOverlap(set<int *> readSet){
    set<int *>::iterator itr1,itr2;
    for (itr1 = this->writeSet.begin(); itr1 != this->writeSet.end(); ++itr1)
    {
        for (itr2 = this->writeSet.begin(); itr2 != this->writeSet.end(); ++itr2)
        {
            if (*itr1 == *itr2)
            {
                return true;
            }
        }
    }
    return false;
}

void Transaction::validate(){
    set<Transaction *>::iterator itr;
    if (transactionSet.size() == 0)
    {
        //validated
        this->validationTS = system_clock::now();
        cout << "Transaction validated, start to write to memmory" << endl;
        writeToMemory();
        this->finishTS = system_clock::now();
        Transaction::transactionSet.insert(this);
    }
    else
    {
        for (itr = transactionSet.begin(); itr != transactionSet.end(); ++itr)
        {
            if ((*itr)!=this){
                if ((*itr)->validationTS < this->validationTS)
                {
                    if ((*itr)->finishTS < this->startTS)
                    {
                        //validated CASE
                    }
                    else if (!(this->startTS >= (*itr)->finishTS || (*itr)->finishTS >= this->validationTS || (*itr)->writeOverlap(this->readSet)))
                    {
                        //validation CASE
                    }
                    else
                    {
                        break;
                    }
                    
                }
                else
                {
                    break;
                }
                
            }
        }
        if (itr == transactionSet.end())
        {
            //Validated
            this->validationTS = system_clock::now();
            cout << "Transaction validated, start to write to memmory" << endl;
            writeToMemory();
            this->finishTS = system_clock::now();
            transactionSet.insert(this);
        }
        else
        {
            //not validated
            cout << "Transaction validation failure, must rollback" << endl;
        }
        
    }
    
}

bool Transaction::isValidated(){
    return validationTS == chrono::time_point<system_clock>::max();
}

void Transaction::writeToMemory(){
    set<int *>::iterator itr;
    for (itr = writeSet.begin(); itr != writeSet.end(); ++itr)
    {
        *(*itr) = tempMemmory[*itr];
    }
    
}