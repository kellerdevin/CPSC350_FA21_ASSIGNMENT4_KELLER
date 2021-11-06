/**
 * RPNCalc performs the integer operations in postfix notation
 * 
 * @author Devin Keller
 * @version 1.0
 * @see RPNCalc.cpp
 * 
 */
#include "RPNCalc.h"
#include "FileProcessor.h"
RPNCalc::RPNCalc()
{
    //default constructor body, it's empty
}

RPNCalc::~RPNCalc()
{
    //default destructor
}

//Eval takes in the formulafrom the user and outputs the answer
float RPNCalc::Eval(){
    string final;
    cout << "Enter calculation in RPM" <<endl;
    cin >> final;
    //Creates new Stack
    rpnStack = new GenStack<float>(50);
    addToStack(final);
    //creates temporary variables to run the operation
    int temp1;
    int temp2;
    //checks to see if operator and pushes it to stack
    for(int i= 0; i<final.length();++i){
        if(isOperator(final[i])!= -1){
            temp1 = reverse->peek();
            reverse->pop();
            temp2 = reverse->peek();
            reverse->pop();
            reverse->push(operation(temp1,temp2,final[i]));
        }
        else if(isNum(final[i])>0){
            reverse->push(toNum(final[i]));
        }
    }
    cout << reverse->peek()<<endl;
    //returns value at top of stack
    return reverse->peek();
}
//Adds content from userinput onto file
void RPNCalc::addToStack(string file){
    //Runs through input add adds all to stack
    for(int i = 0; i<file.length();++i){
        rpnStack->push(file[i]);
        //cout<<file[i]<<endl;
    }
    //reversesStack
    reverseStack();
}
//creates a new stack which is the reverse of the inital stack
void RPNCalc::reverseStack(){
    reverse = new GenStack<float>(50);
    //While the fist stack isn't empty remove element and add it to reverse
    while(!rpnStack->isEmpty()){
        reverse->push(rpnStack->pop());
    }
}
//getNum changes the char into a float
float RPNCalc::toNum(char c){
    int value;
    value = c;
    //turns into float
    return float(value-'0');
}

//Checks to see if c is an Operator
int RPNCalc::isOperator(char c){
    if(c == '+' || c == '-' ||c == '*'||c == '/'){
        return 1;
    }
    return -1;
}
//Checks to see if c is a Number
int RPNCalc::isNum(char c){
    if(c>='0' &&c<='9'){
        return 1;
    }
    return -1;
}
//Operation exucutes the math equation
float RPNCalc::operation(int temp1, int temp2, char opp){
    if(opp=='+'){
        return temp2+temp1;
    }
    else if(opp=='-'){
        return temp2-temp1;
    }
    else if(opp == '*'){
        return temp2*temp1;
    }
    else if(opp == '/'){
        return temp2/temp1;
    }
}
