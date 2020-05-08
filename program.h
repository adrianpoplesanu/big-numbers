#ifndef __PROGRAM_H
#define __PROGRAM_H

#include <map>
#include "big_number.h"

class Program {
private:
    map<string, BigNumber> variables;
public:
    Program();
    ~Program();
    void Init();
    string ReadCommand();
    void Loop();
};

#endif
