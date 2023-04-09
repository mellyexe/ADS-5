// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

int getPriority(char c) {
    switch (c) {
    case '(':
        return 0;
    case ')':
        return 1;
    case '+':
        return 2;
    case '-':
        return 2;
    case '*':
        return 3;
    case '/':
        return 3;
    }
}

std::string infx2pstfx(std::string inf) {
    TStack<char, 100>  strStack;
    std::string result = "";
    int i = 0;
    while (i < inf.length()) {
        char c = inf[i];
        if (isdigit(c)) {
            result += c;
            while (++i < inf.length()) {
                c = inf[i];
                if (isdigit(c)) {
                    result += c;
                } else {
                    i--;
                    break;
                }
            }
            result += ' ';
        } else if (c == '(') {
            strStack.push(c);
        } else if (c == ')') {
            while (strStack.peek() != '(') {
                result += strStack.pop();
                result += ' ';
            }
            strStack.pop();
        } else {
            while (!strStack.isEmpty() && \
                   getPriority(c) <= getPriority(strStack.peek())) {
                result += strStack.pop();
                result += ' ';
            }
            strStack.push(c);
        }
        i++;
    } //while (i < inf.length())
    while (!strStack.isEmpty()) {
        result += strStack.pop();
        if (!strStack.isEmpty()) result += ' ';
    }
    return result;
}

int eval(std::string pref) {
    TStack<char, 100>  intStack;
    std::string number = "";
    int i = 0;
    while (i < pref.length()) {
        char c = pref[i];
        if (isdigit(c)) {
            number += c;
            while (++i < pref.length()) {
                c = pref[i];
                if (isdigit(c)) {
                    number += c;
                } else {
                    i--;
                    break;
                }
            }
            intStack.push(atoi(number.c_str()));
            number = "";
        } else if (c == ' ') {
            i++;
            continue;
        } else {
            int num1 = intStack.pop();
            int num2 = intStack.pop();
            switch (c) {
            case '+':
                intStack.push(num2 + num1);
                break;
            case '-':
                intStack.push(num2 - num1);
                break;
            case '*':
                intStack.push(num2 * num1);
                break;
            case '/':
                intStack.push(num2 / num1);
                break;
            }
        }
        i++;
    } //while (i < inf.length())
    return intStack.pop();
}
