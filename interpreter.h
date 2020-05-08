#ifndef __INTERPRETER_H
#define __INTERPRETER_H

#include <iostream>
#include <ctime>
#include <map>
#include "big_number.h"
using namespace std;

bool isNumber(string);
bool isVariable(string);
void AddNumber(BigNumber&, BigNumber);
bool CheckVariableExists(map<string, BigNumber>, string);
void AddVariable(map<string, BigNumber>&, string, BigNumber);
BigNumber GetVariable(map<string, BigNumber>, string);
void SetVariable(map<string, BigNumber>&, string, BigNumber);
void AddNormalInstruction(map<string, BigNumber>, string, bool&, BigNumber&);
void ForInstruction(map<string, BigNumber>&, string);
void IfInstruction(map<string, BigNumber>&, string);
void PrintCommand(map<string, BigNumber>, string);

enum Command {
    UNKNOWN,
    EMPTY,
    VARIABLE_ASSIGN,
    VARIABLE_REFERENCE,
    ASSIGN_SCALAR,
    NUMBER_REFERENCE,
    PRINT_COMMAND, // this might be the same as VARIABLE_REFERENCE, only with the twist of couting the variable
    FOR_INSTRUCTION,
    IF_INSTRUCTION,
    ADD_NORMAL_INSTRUCTION,
    ADD_INVARIABLE_INSTRUCTION,
    LOAD_FROM_FILE,
    DROP_TO_FILE,
    SHOWALL // show all variable currently existing
};

class CommandInterpreter {
private:
    string text;
    Command command_type;
    clock_t start;
    clock_t end;
public:
    CommandInterpreter();
    CommandInterpreter(string);
    ~CommandInterpreter();
    void Analyze();
    void Execute(map<string, BigNumber>&);
};

#endif
