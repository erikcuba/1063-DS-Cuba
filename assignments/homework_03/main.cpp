/**
 Erik Cuba
 Homework 03
 10 / 12 / 19
 Filename: main.cpp
 */
#include "ListStack.h"    // include our stack definition
#include <fstream>        
#include <iostream>

using namespace std;

int main() {
  string n;
  double w, s;
    ifstream fin("animals.txt");  // input file of animal info                   
    Animal *a;                    // animal pointer used to hold popped animals
    ListStack LS;                 // List based stack object

    // While still animals in the file
    while (fin>>n>>w>>s) {
       a = new Animal(n,w,s);                         // allocate memory for an animal
        LS.Push(a);                               // push animal onto the stack
    }


    LS.Print();             // Print the stack

    cout << endl;           // ummm

    a = LS.Pop();           // get animal off top of stack
    
    cout << a << endl;      // print animal (cout operator overloaded)

    a = LS.Pop();           // get animal off top of stack again
    
    cout << a << endl;      // print animal (cout operator overloaded)

    LS.Print();             // print the stack
}
