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

using namespace std;

class Cipher{

private:
  string encrypted;     
  string decrypted;     
  int shift;          

public:
  //empty constructor
  Cipher(){
    encrypted = "";
    decrypted = "";
    shift = 0;
  }
  //loaded constructor
  Cipher(string e, string d, int s){
    encrypted = e;
    decrypted = d;
    shift = s;
  }

  /**
 * Encrypt
 * 
 * Description:
 *     Takes a normal message and makes it secret
  using a shift key
 * 
 * Params:
 *      None
 * 
 * Returns:
 *      None
 */
  void Encrypt(){
    int intVal;
    encrypted = decrypted;
    for(int i = 0; i < decrypted.size(); i++){
      intVal = (int)encrypted[i] - 65;   
      intVal += shift % 26;                   
      encrypted[i] = intVal + 65;        
    }
  }
  /**
 * Decrypt
 * 
 * Description:
 *     Reads a secret message and decrypts it based on a
 shift key.
 * 
 * Params:
 *      None
 * 
 * Returns:
 *      None
 */ 
  void Decrypt(){
    int intVal;
    decrypted = encrypted;

    for(int i = 0; i < encrypted.size(); i++){
      //cout << decrypted << endl;
      intVal = (int)decrypted[i]; 

      if(intVal > 65 && intVal < 90){
        intVal -= shift % 26;                   
        decrypted[i] = intVal;             
      }
    }
  }
  /**
 * UpperCase
 * 
 * Description:
 *      Ensures all letters on a line are uppercase
 * 
 * Params:
 *      None
 * 
 * Returns:
 *      decrypted
 */  
  string UpperCase(){
    int intVal;
    for(int i = 0; i < decrypted.size(); i++){ 
      if(intVal >= 97 && intVal <= 122){          
        intVal = (int)decrypted[i] - 65;   
        intVal -= 32;                           
        decrypted[i] = intVal + 65;        
      }
    }
    return decrypted;
  }
  /**
 * SetShift
 * 
 * Description:
 *      Sets the  shift key for encryption or decryption
 * 
 * Params:
 *      shift s that either is declared, or defaults at 13
 * 
 * Returns:
 *      None
 */
  void SetShift(int s = 13){
    shift = s;
  }
  /**
 * ReadCipherText
 * 
 * Description:
 *      Reads an encrypted file into string
 * 
 * Params:
 *      ifstream (to read file)
 * 
 * Returns:
 *      None
 */
  void ReadCipherText(ifstream &fin){
    string  str_shift;
    int     int_shift;

    int shift = 0;
    string message = "";        
    getline(fin,str_shift);
    getline(fin,message);

    int_shift = stoi(str_shift);
    cout<<"shift: "<<int_shift<<endl<<"message: "<<message<<endl;
    SetShift(int_shift);
    encrypted = message;
  }
  /**
 * WriteCipherText
 * 
 * Description:
 *      Writes an encrypted message to a file
 * 
 * Params:
 *      ofstream (to write to a file)
 * 
 * Returns:
 *      None
 */ 
  void WriteCipherText(ofstream &fout){
    fout << encrypted << endl;
  }
/**
 * ReadCipherText
 * 
 * Description:
 *      Reads an normal message into string
 * 
 * Params:
 *      ifstream (to read file)
 * 
 * Returns:
 *      None
 */
  void ReadPlainText(ifstream &fin){
    int shift = 0;
    string message = "";
    fin >> shift >> message; 
    SetShift(shift);
    decrypted = message;
  }
/**
 * WritePlainText
 * 
 * Description:
 *      Reads an encrypted file into string
 * 
 * Params:
 *      ofstream (to write to a file)
 * 
 * Returns:
 *      None
 */
  void WritePlainText(ofstream &fout){
    fout << decrypted << endl;
  }
};
