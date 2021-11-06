/**
 * Header class for RPNCalc.cpp file
 * 
 * @author Devin Keller
 * @version 1.0
 * @see RPNCalc.h
 * 
 */
#include <iostream> //pre-processir directive
#include "GenStack.h"
using namespace std;


class RPNCalc
{

public:
    RPNCalc();  //default constructor
    ~RPNCalc(); //destructor
    float toNum(char input);
    int isOperator(char input);
    int isNum(char input);
    float operation(int a, int b, char op);
    float Eval();
    void addToStack(string input);
    void reverseStack();

private:
    GenStack<float> *rpnStack;
    GenStack<float> *reverse;
};
