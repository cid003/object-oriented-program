#include "dictionary.h"

int main()
{
  Dictionary CS211Dict;
  CS211Dict.ProcessTransactionFile();

  return 0;

}

/*****************************************************************************************
program should ignore all punctuations. all words should be in lowercase before it is 
placed in the dictionary. do not write 26 statements to open/close A.txt to Z.txt files.

when a filename is a variable, you need to open it as follows:

                     fin.open(fileName.data());




******************************************************************************************/
