#include <iostream>
#include <fstream>
#include "big_number.h"
#include "big_number.cpp"
#include "interpreter.h"
#include "interpreter.cpp"
#include "program.h"
#include "program.cpp"
#include "expressions.h"
#include "expressions.cpp"
using namespace std;

int main(int argc, char *argv[]) {
    if (argc == 2) {
        cout << "interpret every command from the file: " << argv[1] << endl;
        return 0;
    } else if (argc > 2) {
        cout << "Usage: " << endl << "$ ./main                   lauches the interpreter" << endl << "$ ./main file.bn           executes file.bn in BigNumbers interpreter" << endl;
        return 0;
    }
    running();
    BigNumber numar1, numar2, numar3;
    numar1.LoadFromString("44748564589467812374783957123");
    numar2.LoadFromString("17000000000000000000000000000");
    numar3 = numar1 + numar2;
    cout << "\033[29;1mcompiler test:\033[0m ";
    numar3.PrintNumber();
    cout << " ... \033[32;1mok!\033[0m" << endl;
    //cout << " ... ok!" << endl;
    cout << (numar1 < numar2) << endl;
    cout << (numar2 < numar1) << endl;
    cout << (numar1 > numar2) << endl;
    cout << (numar2 > numar1) << endl;
    ++numar2;
    numar2++;
    numar2.PrintNumber();
    cout << endl;

    BigNumber numar4, numar5, numar6;
    numar4.LoadFromString("3");
    numar5.LoadFromString("5");
    numar6 = numar4 * numar5;
    numar6.PrintLineNumber();

    Program program;
    program.Loop();
    return 0;
}
