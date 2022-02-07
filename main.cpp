/* main.cpp 
 Encripting strings using lambda expression.
 This program encripts the string by adding 1 to each character that is either a letter or a digit (spaces and punctuation are ignored).  Further, if the original character was 'Z', 'z', or '9', then it is cycled back to 'A', 'a', or '0', respectively. 
 
 Author:     Elena Mudrakova
 Module:     8
 
 
 Algorithm:
 1. Take a string input from user until the user    prints 'n' or 'N'.
 2. In for_each loop beginning from the first char of user input till the last char of user input, apply lambda expression [ ](char &c){encrypt(c);} for encrypting the string.
 3. After main() declare void encrypt(char &character).
  3.1 Declare string temp = "".
  3.2 Check if the character is a letter or number using isalnum() function and encript the char according description above. 
 */

#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
using namespace std;

// Prototypes
void encrypt(char &character);

int main()
{
  string input = "";
  while(true){
    cout << "\nEnter a string: ";
    cin.clear() ;
    getline(cin, input);

    // See if user wants to quit (convert to lower-case)
    string test = input ;
    for_each(test.begin(), test.end(), [](char &c) { c = tolower(c) ; } ) ;
    if (test == "quit") {
        cout << "Thanks for using our encryption service" << endl ;
        exit(0) ;
    }

    // Encrypt the string using lambda and re-print
    cout << "Original string: " << input << endl;
    for_each(input.begin(), input.end(), [](char &c) { encrypt(c) ; } ) ;
    cout << "Encrypted string: " << input << endl << endl ;

  }
  return 0;
}

// Free functions
void encrypt(char &character)
{
    string temp = "";

    if (isalnum(character)){
        if(character == 'z'){
            character = 'a';
            temp += character;
        }
        else if(character == 'Z'){
            character = 'A';
            temp += character;
        }
        else if(character == '9'){
            character = '0';
            temp += character;
        }
        else{
            character = character + 1;
            temp += character;
        }
    }
    else {
        temp += character;
    }
    
}