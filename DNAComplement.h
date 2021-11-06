
/**
 * DNAComplement header file
 * 
 * @author Devin Keller
 * @version 1.0
 * @see DNAComplement.h
 * 
 */

#include <iostream> 
#include "GenStack.h"
using namespace std;

class DNAComplement
{

public:
    DNAComplement(); //default constructor
    ~DNAComplement(); //destructor
    string Complement(string input);
    string ReverseComplement(string input);
private:
    GenStack<char> *complementStack;
};