#include "dictionary.h"
#include <iostream>
#include <string>
#include <fstream>

bool Dictionary::failure = false; //static var, false is false
bool Dictionary::success = true; //static var, true is true

Dictionary::Dictionary(): maxWordsinDict(10000), maxWordsPerFile(100) //default constructor, initialize const variables 
{
  totalWordsInDict = 0;
  numOfWordsInFile[0] = 0; //A.txt
  numOfWordsInFile[1] = 0; //B.txt
  numOfWordsInFile[2] = 0; //C.txt
  numOfWordsInFile[3] = 0; //D.txt
  numOfWordsInFile[4] = 0; //E.txt
  numOfWordsInFile[5] = 0; //F.txt
  numOfWordsInFile[6] = 0; //G.txt
  numOfWordsInFile[7] = 0; //H.txt
  numOfWordsInFile[8] = 0; //I.txt
  numOfWordsInFile[9] = 0; //J.txt
  numOfWordsInFile[10] = 0; //K.txt
  numOfWordsInFile[11] = 0; //L.txt
  numOfWordsInFile[12] = 0; //M.txt
  numOfWordsInFile[13] = 0; //N.txt
  numOfWordsInFile[14] = 0; //O.txt
  numOfWordsInFile[15] = 0; //P.txt
  numOfWordsInFile[16] = 0; //Q.txt
  numOfWordsInFile[17] = 0; //R.txt
  numOfWordsInFile[18] = 0; //S.txt
  numOfWordsInFile[19] = 0; //T.txt
  numOfWordsInFile[20] = 0; //U.txt
  numOfWordsInFile[21] = 0; //V.txt
  numOfWordsInFile[22] = 0; //W.txt
  numOfWordsInFile[23] = 0; //X.txt
  numOfWordsInFile[24] = 0; //Y.txt
  numOfWordsInFile[25] = 0; //Z.txt
}

Dictionary::Dictionary(int dictMaxWords, int fileMaxWords): maxWordsinDict(dictMaxWords), maxWordsPerFile(fileMaxWords) //initialize const variables
{
  totalWordsInDict = 0;
  numOfWordsInFile[0] = 0; //A.txt
  numOfWordsInFile[1] = 0; //B.txt
  numOfWordsInFile[2] = 0; //C.txt
  numOfWordsInFile[3] = 0; //D.txt
  numOfWordsInFile[4] = 0; //E.txt
  numOfWordsInFile[5] = 0; //F.txt
  numOfWordsInFile[6] = 0; //G.txt
  numOfWordsInFile[7] = 0; //H.txt
  numOfWordsInFile[8] = 0; //I.txt
  numOfWordsInFile[9] = 0; //J.txt
  numOfWordsInFile[10] = 0; //K.txt
  numOfWordsInFile[11] = 0; //L.txt
  numOfWordsInFile[12] = 0; //M.txt
  numOfWordsInFile[13] = 0; //N.txt
  numOfWordsInFile[14] = 0; //O.txt
  numOfWordsInFile[15] = 0; //P.txt
  numOfWordsInFile[16] = 0; //Q.txt
  numOfWordsInFile[17] = 0; //R.txt
  numOfWordsInFile[18] = 0; //S.txt
  numOfWordsInFile[19] = 0; //T.txt
  numOfWordsInFile[20] = 0; //U.txt
  numOfWordsInFile[21] = 0; //V.txt
  numOfWordsInFile[22] = 0; //W.txt
  numOfWordsInFile[23] = 0; //X.txt
  numOfWordsInFile[24] = 0; //Y.txt
  numOfWordsInFile[25] = 0; //Z.txt

}

bool Dictionary::SearchWord(string word)
{
  char firstletter = toupper(word[0]); //first index = first letter of word
  //pass in char then change to uppercase before searching for file
  string first = string(1,firstletter);
  string fileName = first + ".txt"; //all files should have ".txt extension
  vector<string> inventory; //use a vector to store the string data 
  ifstream fin;

  fin.open(fileName.data());

  //find a word, should return success if found
  while(fin) 
    {
      string compare;

      fin >> compare;
      inventory.push_back(compare);
      
      for(int i = 0; i < inventory.size(); i++)
	{ 
	  if(compare == word)
	    {
	      return Dictionary::success;
	    }
	}
    }

  fin.close();
  return Dictionary::failure; //return this if search has failed
}

bool Dictionary::AddWord(string word)
{
  char firstletter = toupper(word[0]);
  string first = string(1,firstletter);
  string fileName = first + ".txt"; //all files should have ".txt extension
  ifstream fin;
  ofstream fout;
  cout << fileName << endl;
  //open the specified .txt file
  fout.open(fileName.data(), ios::app);
  
  //checking if the search is a failure or success
  if(SearchWord(word) == Dictionary::success) //ios::app means appending the word to the file rather than overwriting the old information in the file
  {
    return Dictionary::failure; 
  }
//add the word if file and dictionary have enough space. if not, then its a failure
 if(totalWordsInDict <= maxWordsinDict && numOfWordsInFile[firstletter-65] <= maxWordsPerFile)
   {
     totalWordsInDict++;
     numOfWordsInFile[firstletter-65]++;
   }
 else
   {
     return Dictionary::failure;
   }
 //use tolower before entering word into dictionary
 
 fout << word << endl; //add output the word into the .txt file
 fout.close();
 
 return Dictionary::success; //return this if adding was a success
}

bool Dictionary::DeleteWord(string word)
{
  char firstletter = toupper(word[0]);
  string first = string(1,firstletter);
  string fileName = first + ".txt"; //all files should have ".txt extension 
  ifstream fin;
  ofstream fout;
  string compare; //likewise for comparing
  vector<string> cabinet; //or inventory or whatever

  fin.open(fileName.data());
  for(int i = 0; i < word.size(); i++)
    {
      word[i] = tolower(word[i]); //set to lowercase to help find the word
    }

  if(SearchWord(word) == Dictionary::failure)
    {
      return Dictionary::failure;
    }

  if(!fin)
    {
      cout << "Error with this file" <<endl;
      return Dictionary::failure;
    }
  else
    {
      while(fin)
	{
	  fin >> compare;
	  cabinet.push_back(compare);

	  for(int i = 0; i < cabinet.size(); i++)
	    {
	      if(cabinet[i] == word)
		{
		  cabinet.erase(cabinet.begin() + i); //delete word 
		  break;
		}
	    }
	}
    
      fin.close();
      totalWordsInDict--;
      numOfWordsInFile[toupper(word[0]) - 65]--;
      
      //output changes 
      fout.open(fileName.data());
      for(int i = 0; i < cabinet.size(); i++)
	{
	  fout << cabinet[i] << endl;
	}

      fout.close();

      return Dictionary::success; //return this when the process is completed
    }
}

bool Dictionary::PrintDictFile(string filename)
{
  ifstream fin;
  vector<string> inventory;
  string word;

  fin.open(filename.data());

  if(!fin)
    {
      return Dictionary::failure;
    }
  else //retrieve file
    {
      while(fin)
	{
	  fin >> word;
	  inventory.push_back(word); //push info into the vector
	}
    }
  cout << "Inside the File: " <<endl;

  //print the vector
  for(int i = 0; i < inventory.size(); i++)
    {
      //print 5 words per line ish
      for(int f = 0; f < 5; f++)
	{
	  if( i < inventory.size())
	    {
	      cout << inventory[i] << " ";
	      i++;
	    }
	  cout <<endl;
	}
      cout <<endl; //spacing for formatting
    }
  fin.close();
  return Dictionary::success; //return this if the process is completed
}

bool Dictionary::SpellChecking(string fileName)
{
  ifstream fin;
  string word; //word being used for spellcheck

  fin.open(fileName.data());

  if(!fin)
    {
      return Dictionary::failure; //return this if file name doesnt exist
    }
  
  //show the mispelled words with a cout
  cout << "Incorrectly spelled words: " << endl;
  
  //perform a spellcheck
  while(fin)
    {
      fin >> word;
      tolower(word[0]); //to compare words, turn each word lowercase 
      
      //do comparison
      if(SearchWord(word) == Dictionary::failure)
  	{
	  cout << word << endl;
  	}
    }
  
  fin.close();
  return Dictionary::success; //return this if the spellcheck went through entire process
  
}

bool Dictionary::InsertWordsIntoDict(string fileName) //this funct uses a vector
{
  ifstream fin;
  vector<string> inventory; //pushing contents of file 
  string word;

  fin.open(fileName.data());
  cout << fileName << endl;
    if(!fin)
    {
      return Dictionary::failure;
    }
  else //insertion process
    {
      while(fin)
	{
	  fin >> word; //fin word from the file
	  if(SearchWord(word) == false) //if the word doesnt already exist 
	    {
	      AddWord(word); //add the word if the word doesnt exist
	    }
	}
    }
  fin.close();
  return Dictionary::success; //return this when process is completed
}

void Dictionary::ProcessTransactionFile()
{
  string command;
  string content; //information from the transaction file
  ifstream fin;

  fin.open("Transaction.txt");
  
  if(!fin)
    {
      cout << "Unable to open file. Terminating the program" <<endl;
      exit(1);
    }
  else //first info is a command telling the programmer what to do, second is data change
    {
      //Read each line until the end of the file
      while(fin)
        {
	  fin >> command >> content; //take in file contents
	  
          if(command == "AddW")
            {
              //call addword function here
	      AddWord(content);
            }

          if(command == "DeleteW")
            {
              //call DeleteWord function here
	      DeleteWord(content);
            }

          if(command == "PrintF")
            {
	      //call PrintDictFile function here
	      PrintDictFile(content);
            }
	  
	  if(command == "SpellCheck")
	    {
	      //perform spellcheck on the data 
	      SpellChecking(content);
	    }

	  if(command == "InsertF")
	    {
	      //call InsertWordsIntoDict function here
	      InsertWordsIntoDict(content);
	    }

        }

    } //end of else statement
  fin.close();

}

