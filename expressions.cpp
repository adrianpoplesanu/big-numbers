#include "expressions.h"
#include <iostream>
#include <regex>
using namespace std;

bool EvaluateCondition(map<string, BigNumber> variables, string cond) {
    //cout << "evaluating:... " << cond << endl;
    regex check_conditional_keywords("\\(*(.*)(and|or)(.*)\\)*");
    smatch m;
    regex_search(cond, m, check_conditional_keywords);
    return true;
}

BigNumber EvaluateAritmeticExpression(string expression) {
    // TODO: add the expresion evaluator used in syntax068.cpp
    BigNumber numar;
    return numar;
}