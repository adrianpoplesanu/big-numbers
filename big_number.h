#ifndef __BIG_NUMBERS
#define __BIG_NUMBERS

#include <string>
#define BAZA_DEFAULT 1000
#define MAX_CIFRE 1000

using namespace std;

void running(void);

class BigNumber {
private:
    int cifre[1000];
    int baza;
    int _len;
    bool sign; // false - positive; true - negative
public:
    BigNumber();
    BigNumber(int);
    BigNumber(string);
    BigNumber(const BigNumber&);
    ~BigNumber();
    void LoadFromInt(int);
    void LoadFromString(string);
    void LoadFromNumber(BigNumber);
    void Add(BigNumber);
    void Substract(BigNumber);
    void Multiply(BigNumber);
    void Divide(BigNumber);
    void Mod(BigNumber);
    int GetDigit(int);
    void PrintNumber(void);
    void PrintLineNumber(void);
    BigNumber operator + (const BigNumber&);
    BigNumber operator - (const BigNumber&);
    bool operator > (const BigNumber&);
    bool operator < (const BigNumber&);
    bool operator >= (const BigNumber&);
    BigNumber operator * (const BigNumber&);
    BigNumber& operator ++(); // need to check if this is correct
    BigNumber operator ++(int);
};

#endif
