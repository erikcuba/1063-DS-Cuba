/**
 Erik Cuba
 Homework 04
 10 / 12 /19
 Filename: main.cpp
 */
#include <iostream>
#include <fstream>
#include "ListQueue.hpp"

using namespace std;


int main() {
  ListQueue LQ;                 // Queue instance 
  string n;
  ifstream fin;
  fin.open("animals.txt");      // Opens animal file

  while(fin>>n){ //Loop to add animals from file
    LQ.Push(n);
  }
  
  LQ.Print();                     // print queue to see where animals are
}
