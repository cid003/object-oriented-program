/**************************************************
Mariah Cid
Assignment 2 

writing an object-orientec program to create a 
dictionary.
10/17/2017
*************************************************/
#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <cstdlib>
#include<iostream>
#include<string>
#include<vector> //must use a vector
using namespace std;

class Dictionary
{
 private:
  const int maxWordsinDict; //initilize it in function
  const int maxWordsPerFile;
  int totalWordsInDict;
  int numOfWordsInFile[26]; //array of the alphabet
  static bool failure;
  static bool success;
  
 public:
  Dictionary(); //constructor, initialize const values and static values
  Dictionary(int dictMaxWords, int fileMaxWords); //initialize const values
  bool AddWord(string word);
  bool DeleteWord(string word);
  bool SearchWord(string word);
  bool PrintDictFile(string filename);
  bool SpellChecking(string fileName);
  bool InsertWordsIntoDict(string fileName);
  void ProcessTransactionFile();

};

#endif
