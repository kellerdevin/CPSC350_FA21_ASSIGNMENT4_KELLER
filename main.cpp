/**
 * main file, where are main method lives
 * 
 * @author Devin Keller
 * @version 1.0
 * @see main.cpp
 * 
 */
#include <iostream> //pre-processir directive
using namespace std;
#include "FileProcessor.h"

int main(int argc, char ** argv)
{   
    //Allows us to use methods from FileProcessor
    FileProcessor *sp = new FileProcessor;
    //Takes in DNA or RPN
    sp->process(argv[1]);

    //deletes sp
    delete sp;
    return 0;
}