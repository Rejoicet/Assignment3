#include "Genstack.h"
#include "Checkfile.h"
#include "Closefile.h"
#include <iostream>

using namespace std;

string nameoffile;

char prompt;

int main () {

  prompt = 'Y';

  while (prompt == 'Y' || prompt == 'y') {
    cout << "Please enter the exact name of the file along with the extension" << endl;
    getline(cin, nameoffile);

    Checkfile file;
    file.tocheck(nameoffile);

    Closefile cfile;
    cfile.toclose();

    cout <<endl;
    cout << "Congratulations!! No problems found!!" << endl;
    cout << endl;
    cout << "Do you wish to check another file?" << endl;
    cout << "Press 'Y' if yes else press any other key followed by enter to exit." << endl;
    cin >> prompt;
  }

  cout << "Thank you for using our feature! Tada!" << endl;

}
