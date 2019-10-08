/*
 * Erik Cuba
 * CMPS 1063 - Fall 2019
 * 10 / 3 / 19
 * Description: stack.h
 *    Definition of our stack class.
 */

class Stack{
  private:
    
  public:
    int *A;         // container of items (could make it a list)
    int Size;       // Arrays need a size
    int Top;        // keep track of top
    Stack();        // Default constructor
    
    Stack(int);     // overloaded constructor
    void checkResize(); // Checks if array needs to be increased
    int Enlarge();
    int Reduce();
    bool Push(int); // Push value onto stack
    int Pop();      // Remove item from top of stack
    void Print();   // Help inspect values
    bool Empty();   // Is stack empty
    bool Full();    // is stack full
};
