#include "program.h"
#include "interpreter.h"

#include <iostream>
#include <string>
using namespace std;

Program::Program() {
    //...
}

Program::~Program() {

}

string Program::ReadCommand() {
    string s;
    getline(cin, s);
    return s;
}

void Program::Init() {

}

void Program::Loop() {
    Init();
    while(1) {
        cout << "> ";
        string command = ReadCommand();
        if (command == "help") {
            cout << "=== Help Big Number =========================" << endl;
            cout << "  > help - shows help information" << endl;
            cout << "  > version - shows compiler version" << endl;
            cout << "  > verbose - change verbose flag - current[off]" << endl;
            cout << "  > purge - clears all variables in the stack" << endl;
            cout << "  > exit - exit interpreter ; same as quit" << endl;
            cout << "  > quit - exit interpreter ; same as exit" << endl;
            cout << "=============================================" << endl;
        } else if (command == "version") {
            cout << "1.15" << endl;
        } else if (command == "purge") {
            Init();
        } else if (command == "exit" || command =="quit") {
            cout << "\033[29;1mBye!\033[0m" << endl;
            break;
        } else {
            CommandInterpreter commandInterpreter(command);
            commandInterpreter.Analyze();
            commandInterpreter.Execute(variables);
        }
    }
}
