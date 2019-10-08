/*
 * Erik Cuba
 * CMPS 1063 - Fall 2019
 * 10 / 3 / 19
 * Description: stack.cpp
 *    Class implementation file for our array based stack of ints
 */

#include <iostream>
#include <climits>
#include "stack.h"

using namespace std;

/**
 * Stack constructor
 * Description:
 *    Inits an array of ints and sets our top
 */
Stack::Stack(){
  Size = 10;
  A = new int [Size];
  Top = -1;
}

/**
 * Stack constructor
 * Description:
 *    Inits an array of ints to a specified size and sets our top
 * Params:
 *    int s : integer size
 */
Stack::Stack(int s){
  Size = s;
  A = new int [Size];
  Top = -1;
}
/**
 * checkResize
 * Description:
 *    Adds items if needed to an array
 * Params:
 *    none
 * Returns:
 *     void
 */
void Stack::checkResize(){
    int count = 0;
    for(int i = 0; i < Size; i++){
        count++;
    }
    if(count >= .8 * Size){
        Enlarge();
    }else if(count <= .2 * Size){
        Reduce();
    }
}
/**
 * Enlarge
 * Description:
 *    Enlarges the stack
 * Params:
 *    void
 * Returns:
 *     new size
 */
int Stack::Enlarge(){
    int *copy;
    int old_size = Size;
    Size = int(Size * 1.5);
    copy = new int[Size];
    for (int i = 0; i < old_size; i++)
    {
        copy[i] = A[i];
    }
    for (int i = old_size; i < Size; i++)
    {
        copy[i] = INT_MIN;
    }
    delete[] A;
    A = copy;
    return Size;
}
/**
 * Reduce
 * Description:
 *    Reduces size of stack
 * Params:
 *    void
 * Returns:
 *     new size
 */
int Stack::Reduce(){
    int *copy;
    Size = int(Size * .5);
    copy = new int[Size];
    for (int i = 0; i < Size; i++)
    {
        copy[i] = A[i];
    }
    delete[] A;
    A = copy;
    return Size;
}
/**
 * Push
 * Description:
 *    Adds item to top of stack
 * Params:
 *    int val : integer size
 * Returns:
 *     bool : true = success
 */
bool Stack::Push(int val){
  if(!Full()){
    checkResize();
    Top++;
    A[Top] = val;
    return true;
  }else{
    return false;
  }
}

/**
 * Pop
 * Description:
 *    Removes top of stack and returns it
 * Params:
 *    void
 * Returns:
 *     int : item on stack
 */
int Stack::Pop(){
  if(!Empty()){
    checkResize();
    int temp = 0;   
    temp = A[Top];
    Top--;
    return temp;
  }else{
    // should return a value that implies failuer, but good enough for now
    cout<<"Cannot remove item from empty stack"<<endl;
  }
  return 0;
}

/**
 * Print
 * Description:
 *    Prints stack for inspection
 * Params:
 *    void
 * Returns:
 *     void
 */
void Stack::Print(){
  for(int i = Top;i>=0 ; i--){
    cout<<A[i]<<endl;
  }
}

/**
 * Empty
 * Description:
 *    Is stack empty
 * Params:
 *    void
 * Returns:
 *    bool : true = empty
 */
bool Stack::Empty(){
  return Top < 0;
}

/**
 * Full
 * Description:
 *    Is stack full
 * Params:
 *    void
 * Returns:
 *    bool : true = full
 */
bool Stack::Full(){
  return (Top == Size - 1);
}

