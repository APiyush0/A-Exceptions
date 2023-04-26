//
//  main.cpp
//  W15A Exceptions
//
//  Created by Piyush Aggarwal on 4/25/23.
//

#include <iostream>


using namespace std;

// Define custom exceptions
class invalidCharacterException :
    public exception
{
    virtual const char* what() const throw()
    {
        return "Error: Input is not a letter (A-Z, a-z).";
    }
};


class invalidRangeException :
    public exception
{
    
    virtual const char* what() const throw()
    {
        return "Error: Result is not a letter (A-Z, a-z).";
    }
};


class caseTransitionException :
    public exception
{
    
    virtual const char* what() const throw()
    {
        return "Error: Upper and Lower case transitions are not allowed.";
    }
};

// Function to calculate character offsets
char character(char start, int offset)
{
    
    // Check if start is a letter
    if (!isalpha(start))
    {
        throw invalidCharacterException();
    }
    
    // Check if offset causes upper- and lower-case transitions
    if (isupper(start) && islower(start + offset))
    {
        throw caseTransitionException();
    }
    
    
    if (islower(start) && isupper(start + offset))
    {
        throw caseTransitionException();
    }
    
    
    // Calculate target character
    char target = start + offset;
    
    // Check if target is a letter
    if (!isalpha(target))
    {
        throw invalidRangeException();
    }
    return target;
}

// Driver program to test the character function
int main()
{
    // Test cases
    try
    {
        cout << character('a', 1) << endl;  // expected output: 'b'
    }
    
    
    catch (exception& e)
    {
        cout << e.what() << endl;
    }
    
    
    try
    {
        cout << character('a', -1) << endl;  // expected output: Error: Result is not a letter (A-Z, a-z).
    }
    
    
    catch (exception& e)
    {
        cout << e.what() << endl;
    }
    
    
    try
    {
        cout << character('Z', -1) << endl;  // expected output: 'Y'
    }
    
    catch (exception& e)
    {
        cout << e.what() << endl;
    }
    
    try
    {
        cout << character('?', 5) << endl;  // expected output: Error: Input is not a letter (A-Z, a-z).
    }
    
    
    catch (exception& e)
    {
        cout << e.what() << endl;
    }
    try
    {
        cout << character('A', 32) << endl;  // expected output: Error: Upper and Lower case transitions are not allowed.
    }
    
    
    catch (exception& e)
    {
        cout << e.what() << endl;
    }
    
    
    
     return 0;
}
