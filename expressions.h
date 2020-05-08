#ifndef __EXPRESSIONS_H
#define __EXPRESSIONS_H

#include "big_number.h"
#include <map>

bool EvaluateCondition(map<string, BigNumber>, string);
BigNumber EvaluateAritmeticExpression(string);

#endif