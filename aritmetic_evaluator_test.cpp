/*
    Expression parser that resolves the data to BigNumber/string data structure
*/
#include <iostream>
#include <string>
#include <stack>
#include "big_number.h"
#include "big_number.cpp"
using namespace std;

int precedence (char op) {
    if(op == '+' || op == '-')
        return 1;
    if(op == '*' || op == '/')
        return 2;
    return 0;
}

BigNumber applyOp (BigNumber a, BigNumber b, char op) {
    BigNumber result;
    switch(op) {
        case '+': result = a + b; break;//return a + b;
        //case '-': return a - b;
        //case '*': return a * b;
        //case '/': return a / b;
    }
    //return 0; // this is dumb
    return result;
}

BigNumber evaluate (string tokens) {
    int i;
    //stack <int> values;
    stack <BigNumber> values;
    stack <char> ops;

    for (i = 0; i < tokens.length(); i++) {
        //cout << i << endl;
        if (tokens[i] == ' ')
            continue;
        else if (tokens[i] == '(') {
            ops.push(tokens[i]);
        }
        else if (isdigit(tokens[i])) {
            //int val = 0;
            string numar;
            while (i < tokens.length() && isdigit(tokens[i])) {
                numar = numar + tokens[i];
                //val = (val*10) + (tokens[i]-'0');
                i++; // asta e problema cu segmentation fault cand paranteza de inchidere nu are spatiu in fata ei
            }
            i--; // this seems to fix the seg fault issue with parenthesis closing imediately after )
            cout << numar << endl;
            BigNumber val;
            val.LoadFromString(numar);
            values.push(val);
            //values.push(val);
        }

        else if (tokens[i] == ')') {
            //cout << "aaa" << endl;
            while (!ops.empty() && ops.top() != '(') {
                BigNumber val2 = values.top();
                values.pop();

                BigNumber val1 = values.top();
                values.pop();

                char op = ops.top();
                ops.pop();

                values.push(applyOp(val1, val2, op));
            }

            if(!ops.empty())
               ops.pop();
        } else {
            //cout << "bbb" << endl;
            while (!ops.empty() && precedence(ops.top()) >= precedence(tokens[i])) {
                BigNumber val2 = values.top();
                values.pop();

                BigNumber val1 = values.top();
                values.pop();

                char op = ops.top();
                ops.pop();

                values.push(applyOp(val1, val2, op));
            }
            ops.push(tokens[i]);
        }
    }

    while (!ops.empty()) {
        BigNumber val2 = values.top();
        values.pop();

        BigNumber val1 = values.top();
        values.pop();

        char op = ops.top();
        ops.pop();

        values.push(applyOp(val1, val2, op));
    }

    return values.top();
}

int main() {
    BigNumber numar = evaluate("10 + 2 + 6 + 1");
    numar.PrintLineNumber();
    return 0;
}