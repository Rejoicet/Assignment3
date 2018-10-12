#include <iostream>
#include <fstream>
using namespace std;

class Checkfile {
  ifstream SyntaxChecker;
  char bracket;
  int line;

public:
  Checkfile();
  ~Checkfile();
  void tocheck (string filename);
};
