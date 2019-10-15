/**
 Erik Cuba
 Homework 04
 10 / 12 /19
 Filename: ListQueue.hpp
 */
#include <iostream>

using namespace std;


struct Node{          // Typical node setup for a list. 
  string name;
  Node* Next;

  Node(){             // default constructor
    name = "";
    Next = NULL;
  }

  Node(string n){  // overloaded constructor
    name = n;
    Next = NULL;
  }
};

/**
 * List Queue
 * 
 * List Based Queue
 * 
 */
class ListQueue{
private:
  Node* Front;            // front of the queue (where we remove from)
  Node* Rear;             // rear of the queue (where we add to)
public:
  ListQueue();            // construct
  void Push(string);      //Add animal
  string Pop();              // remove from front
  void Print();           // print for debugging
  bool Empty();           // is queue empty (can't remove from empty queue)
  void PrintPointers();   // added for lecture purposes
  Node* GetFront();       // added for lecture purposes
};


/**
 * ListQueue
 * Purpose:
 *     Constructs our queue
 * Params:
 *     void
 * Returns:
 *     void
 */
ListQueue::ListQueue(){
  Front = Rear = NULL;
}

/**
 * Push
 * Purpose:
 *     Adds animal to rear of queue
 * Params:
 *     string n : animal to be added
 * Returns:
 *     void
 */
void ListQueue::Push(string n){
  Node* temp = new Node(n);     // allocate new memory

  if(Front == NULL){              // if list is empty
    Front = Rear = temp;          // point everyone to it
  }else{
    Rear->Next = temp;            // otherwise link last node to new one
    Rear = temp;                  // then point Rear to it.
  }

}

/**
 * Pop
 * Purpose:
 *     Removes animal from front of queue
 * Params:
 *     void
 * Returns:
 *     string : front animal
 */
string ListQueue::Pop(){
  string temp = Front->name;     // get front data temporarily
  Node* T = Front;            // Point to the front temporarily
  Front = Front->Next;        // Move front to next animal 
  delete T;                   // Now we can delete the old front

  if(!Front){                 // If front is NULL make rear NULL as well
    Rear = NULL;              // because if front is NULL list is empty!  
  }

  return temp;                // return front animal
}

/**
 * Print
 * Purpose:
 *     Prints animals in queue for debugging
 * Params:
 *     void
 * Returns:
 *     void
 */
void ListQueue::Print(){
  Node* temp = Front;

  while(temp){
    cout<<temp->name;
    if(temp->Next){
      cout<<"->";
    }
    temp = temp->Next;
  }
  cout<<endl;
}

/**
 * Empty
 * Purpose:
 *     Checks for empty queue. Cant remove from empty queue!
 * Params:
 *     void
 * Returns:
 *     bool: true == empty 
 */
bool ListQueue::Empty(){
  return Front == NULL;
}

/**
 * PrintPointers
 * Purpose:
 *     Prints front and rear values for lecture purposes
 * Params:
 *     void
 * Returns:
 *     void
 */
void ListQueue::PrintPointers(){
  cout<<"Front = "<<Front<<endl;
  cout<<"Rear = "<<Rear<<endl;
}


/**
 * GetFront
 * Purpose:
 *     Returns the front node, for lecture purposes
 * Params:
 *     void
 * Returns:
 *     void
 */
Node* ListQueue::GetFront(){
  return Front;
}
