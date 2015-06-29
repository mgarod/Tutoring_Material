/*
 Created by Michael Garod on 6/29/15.
 Copyright (c) 2015 MG. All rights reserved.
 
 Description: A tutorial on the use of ifstream and ofstream
 Purpose: CSCI 127 and 135 tutorial
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    
    string word;
    
    // You may declare the if/of stream object, then open a specific file
    ifstream input;
    input.open("textfile.txt");
    
    // Or you may use the if/of constructor with file name as the argument
    ofstream output("outputfile.txt");
    
    // A stream object's flag is 'good' until it reaches a point that changes
    // the state to something else, such as reaching end of file.
    // See: http://www.cplusplus.com/reference/ios/ios/good/ for more info.
    while(input.good())
    {
        input >> word;
        
        output << "output: " + word + "\n";
    }
    
    // Let's try it again a little differently. We reset the file's flag,
    // and return the file's internal pointer to the beginning
    // See: http://www.cplusplus.com/reference/ios/ios/clear/
    // See: http://www.cplusplus.com/reference/istream/istream/seekg/
    input.clear();
    input.seekg(0, ios::beg);
    
    // Start a new output file
    output.close();
    output.open("otheroutputfile.txt");
    
    // When the extraction (>>) operator is used, a bool is returned.
    // Extraction will fail (return false) if it has reached end of file.
    while(input >> word)
    {
        // Output the word in reverse
        string reverse;
        for(long i = word.length()-1; i >= 0; i--)
        {
            reverse = reverse + word[i];
        }
        
        output << reverse << endl;
    }
    
    // Always close your file streams when you are finished
    input.close();
    output.close();
    
    return 0;
}
