#include "GenStack.h"
#include "Checkfile.h"
#include <iostream>

Checkfile::Checkfile ()
{
  line = 1;
}

Checkfile::~Checkfile()
{

}

void Checkfile::tocheck (string filename)
{
  SyntaxChecker.open (filename);

  if (!SyntaxChecker) {             //Exception if error in opening file
    cout << "Unable to open the file. Please check the following and run the program again -" << endl;
    cout << "1 - File is not open already" << endl;
    cout << "2 - Check some other program is not using it" << endl;
    cout << "3 - File name and its extension is correct" << endl;
    exit(1);
  }

  GenStack <char> myStack;
  while (SyntaxChecker.get(bracket)) {
    if (bracket == '\n') {
      ++line;
    }
    else if (bracket == '(' || bracket == '{' || bracket == '[') {
      myStack.push(bracket);
    }
    else if (bracket == ')' || bracket == '}' || bracket == ']') {
      if (bracket == ')') {
        if (myStack.top() != '(') {
          if (myStack.top() == '{') {
            cout << "Line " << line << ": Expected '}' and found '" << bracket << "'." << endl;
            exit(1);
          }
          else if (myStack.top() == '[') {
            cout << "Line " << line << ": Expected ']' and found '" << bracket << "'." << endl;
            exit(1);
          }
          else if (myStack.size() == 0) {
            cout << "Line " << line << ": Missing '('." << endl;
            exit(1);
          }
        }
        else {
          myStack.pop();
        };
      }
      else if (bracket == '}') {
        if (myStack.top() != '{') {
          if (myStack.top() == '(') {
            cout << "Line " << line << ": Expected ')' and found '" << bracket << "'." << endl;
            exit(1);
          }
          else if (myStack.top() == '[') {
            cout << "Line " << line << ": Expected ']' and found '" << bracket << "'." << endl;
            exit(1);
          }
          else if (myStack.size() == 0) {
            cout << "Line " << line << ": Missing '{'." << endl;
            exit(1);
          }
        }
        else {
          myStack.pop();
        };
      }
      else if (bracket == ']') {
        if (myStack.top() != '[') {
          if (myStack.top() == '(') {
            cout << "Line " << line << ": Expected '(' and found '" << bracket << "'." << endl;
            exit(1);
          }
          else if (myStack.top() == '{') {
            cout << "Line " << line << ": Expected '{' and found '" << bracket << "'." << endl;
            exit(1);
          }
          else if (myStack.size() == 0) {
            cout << "Line " << line << ": Missing '['." << endl;
            exit(1);
          }
        }
        else {
          myStack.pop();
        }
      }
    }
    else continue;
  }

  if (myStack.size() != 0) {
    if (myStack.top() == '(') {
      cout << "Reached end of file. Missing ')'." << endl;
    }
    else if (myStack.top() == '{') {
      cout << "Reached end of file. Missing '}'." << endl;
    }
    else if (myStack.top() == '[') {
      cout << "Reached end of file. Missing ']'." << endl;
    }
  }
}
