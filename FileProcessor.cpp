/**
 * FileProcessor is where we process the files and use the input and create the output files for DNAComplement
 * 
 * @author Devin Keller
 * @version 1.0
 * @see FileProcessor.cpp
 * 
 */

#include "FileProcessor.h"
#include "DNAComplement.h"
#include "RPNCalc.h"
#include <fstream>

FileProcessor::FileProcessor()
{
    //default constructor body, it's empty
}
FileProcessor::~FileProcessor()
{
    //default destructor
}

void FileProcessor::processFile(string dnaoutput) //takes in a file from the command line and outputs a new file
{
    char data[500];
    cout << "Enter File" <<endl;
    string file;
    cin >> file;

    // open and read the input file
    ifstream infile;
    infile.open(file);

    string sentence;
    string inputLine = "";

    while (getline(infile, sentence))
    {
        inputLine += sentence;
        //inputLine+= "\n";
    }

    //cout << "Reading from the file..." << endl;
    infile >> inputLine;
    DNAComplement *sp = new DNAComplement;
    //Creates outputParagraph and add DNA, Complement, and reverse complement to that
    string outputParagraph = sp->Complement(inputLine); //points to the translate english sentence function
    outputParagraph += "\n";
    outputParagraph += sp->ReverseComplement(inputLine);

    //close the inputed file.
    infile.close();
    //open an output file
    ofstream File;
    File.open(dnaoutput);

    //write inputted data into the file
    File << outputParagraph << endl;

    //close the output file
    File.close();
    //return outputParagraph;
}

//process takes in choice and chooses which file to run
void FileProcessor::process(string choice) 
{
    //Error checking to make sure choice is either RPN or DNA
    while(choice != "RPN" && choice != "DNA"){
        cout << "Bad Input" <<endl;
        cin >> choice;
    }
    //Runs RPN
    if(choice == "RPN"){
        RPNCalc *mp = new RPNCalc;
        //Runs eval from RPN Class
        float m = mp->Eval();
        delete mp;
    }
    //Runs DNA
    else if(choice == "DNA"){
        processFile("dnaoutput.txt");
    }
}


