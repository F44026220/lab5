#ifndef HUGEINT_H
#define HUGEINT_H

#include <iostream>
#include <string>

#define SIZE_ARR 100

using namespace std;

class HugeInt
{
    friend ostream & operator << (ostream &, const HugeInt &);
    friend istream & operator >> (istream &, HugeInt &);

 public:
    HugeInt(long int=0);
    HugeInt(string);
    HugeInt operator + (HugeInt);
    HugeInt operator - (HugeInt);
    const HugeInt & operator = (const HugeInt &);
    bool operator >= (const HugeInt &);

    int ptr[SIZE_ARR];
    int sign;
};

#endif
