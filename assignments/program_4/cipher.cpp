//////////////////////////////////////////////////////////
//
// Author:           ERIK CUBA
// Assignment:       Program_04
// Date:             1 December 2019
// Title:            Program 4 - Caeser Cipher
// Semester:         Fall 2019
// Course:           CMPS 1063 
// 
// Files:            cipher.cpp, 
//                   caeser.hpp, 
//                   decrypted.txt 
//                   encrypted.txt
// Description:
//       This program reads in secret messages and decodes
//          them based  off of a shift key
//////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include "caeser.hpp"

using namespace std; 

int main(int argc , char** argv){
  ifstream fin;
  fin.open("encrypted.txt");
  ofstream fout;
  fout.open("decrypted.txt");
  fout<<"ERIK CUBA\n12/1/2019\nProgram 4 Output\n"<<endl;

  string  str_numMessages;
  int     int_numMessages;
  Cipher SecretStuff;
  getline(fin,str_numMessages);
  cout<<str_numMessages<<endl;
  for(int i=0; i<stoi(str_numMessages); i++){
    SecretStuff.ReadCipherText(fin);
    SecretStuff.UpperCase();
    SecretStuff.Decrypt();
    SecretStuff.WritePlainText(fout);
  }
  fout.close();
  fin.close();

  return 0;
}
