/**
 * FileProcessor header file
 * 
 * @author Devin Keller
 * @version 1.0
 * @see FileProccessor.h
 * 
 */

#include <iostream> 

using namespace std;

class FileProcessor
{

public:
    FileProcessor(); //default constructor
    ~FileProcessor(); //destructor
    void processFile(string output);
    void process(string choice);
};