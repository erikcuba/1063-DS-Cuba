/**
 * Erik Cuba
 * CMPS 1063 - Fall 2019
 * 10 / 4 / 19
 * Description: main.cpp
 *    Main driver of an Array based implementation of a stack.
 */

#include <iostream>
#include <fstream>
#include "stack.h"
#include "stdlib.h"

using namespace std;

/**
 * Main Program
 * 
 */
int main(){
    Stack S1; 
    ifstream fin;
    ofstream fout;
    fin.open("input.txt");
    fout.open("output.txt");
    char x;
    int y;
    int i = 0; //i is the counter
    int Max_Size = 0;
    while(!fin.eof()){
        fin >> x >> y;
        if(x =='+'){
            S1.Push(y);
        }else{
            S1.Pop();
        }
        if(S1.Size > Max_Size){
            Max_Size =S1.Size;
        }
        
    }
    S1.Print();
    fout << "Erik Cuba\n" << "10 / 04 / 19\n" << "Homework 2 Output\n" << endl
        << "Stack Size: " << S1.Size << endl << "Largest Size: " << Max_Size << endl
        << "Values: "; 
    for(int i = S1.Top;i>=0 ; i--){
    fout<<S1.A[i]<< ", ";
    }

    fin.close();
    fout.close();

    return 0;
}
