/**
 * The DNAComplement class computes the complement and reverse complement of a DNA sequence. 
 * 
 * @author Devin Keller
 * @version 1.0
 * @see DNAComplement.cpp
 * 
 */

#include "DNAComplement.h"
#include "FileProcessor.h"

DNAComplement::DNAComplement()
{
    //default constructor
}
DNAComplement::~DNAComplement()
{
    //default destructor
}
//takes in a string of DNA and output complement and reverse complement
string DNAComplement::Complement(string dna){
    complementStack = new GenStack<char>(50);
    string complement;
    complement += "Sequence: ";
    complement += dna;
    complement += "\n";
    complement += "Complement: ";
    
    //Adds the complement of dna to the stack
    for(int i = 0; i<dna.length(); ++i){
        if(dna[i] == 'A'){
            complement +='T';
            complementStack->push('T');
        }
        else if(dna[i] == 'T'){
            complement += 'A';
            complementStack->push('A');
        }
        else if(dna[i] == 'C'){
            complement += 'G';
            complementStack->push('G');
        }
        else if(dna[i] == 'G'){
            complement += 'C';
            complementStack->push('C');
        }
    }

    //reverses complement
    string reverse = ReverseComplement(complement);
    complement += "\n";
    complement += "reverse:";
    complement += reverse;
    return complement;
}

//Reverses complement
string DNAComplement::ReverseComplement(string complement){
    string reverse;
    //while compStack isEmpty pop the string from compStack reverse
    while(!complementStack->isEmpty()){
        reverse+=complementStack->pop();

    }
    return reverse;
}





