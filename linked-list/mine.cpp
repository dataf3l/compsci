/*
 * The purpose of this code is to learn how to make a linked list.
 * It implements 
 * */
#include <iostream>
using namespace std;

class Node {
  Node* next;
  int value;

  // Values are kept private in order to prevent unauthorized access.

  public:
   Node(int value){
      this->value = value;
      this->next = NULL;
   }
   
   int getValue(){
     return this->value;
   }
   void setValue(int v){
     this->value = v;
   }
   Node* getNext(){
     return this->next;
   }
   void setNext(Node* n){
     this->next = n;
   }
   Node* AddElement(Node *n) {
     this->next = n;
     return n;
   }
   void DeleteElement(int value){
      Node* prev = this;
      Node* cursor = this->next;
      while(cursor->next != NULL) {
       if(cursor->value == value){
         prev->next = cursor->next; // skip one
	 return;
       }
       prev = cursor;
       cursor = cursor->next;
     }
   
   }
   void PrintNodes(){
     Node* cursor = this;

     while(cursor->next != NULL) {
       cout << "NODE " << cursor->value << endl;
       cursor = cursor->next;
     }
   }
};

class LinkedList {
  Node* firstElement;
  int length;
  public:
  Node* AddNode(Node* n){ // returns last element.
     Node* cursor = this->firstElement;

     while(cursor->getNext() != NULL) {
       cursor = cursor->getNext();
     }
    cursor->AddElement(n);
    this->length++;

    return cursor;
  }
  Node* RemoveNode(int v){ // returns last element.
    Node* cursor = this->firstElement;
    cursor->DeleteElement(v);
    this->length--;
    return cursor;
  }
  Node* getFirstElement(){
    return this->firstElement;
  }
  LinkedList(Node *n){
    this->firstElement = n;
  }
  void PrintNodes(){
    this->firstElement->PrintNodes();
  }
  int Length(){
    return this->length;
  }

  // Find out if an element exist, if it does not exist, we return -1

  int IndexOf(int value){
     Node* cursor = this->firstElement;
     int idx = 0;
     while(cursor->getNext() != NULL) {
       if(cursor->getValue() == value){
         return idx;
       }
       idx++;
       cursor = cursor->getNext();
     }
    return -1;
  }

  // If we find a value, we replace it with a different value.

  int Replace(int oldValue, int newValue){
     Node* cursor = this->firstElement;
     int idx = 0;
     while(cursor->getNext() != NULL) {
       if(cursor->getValue() == oldValue){
	 cursor->setValue(newValue);
       }
       cursor = cursor->getNext();
     }
    return -1;
  }

  void Reverse(){
     // Begin at second position	 
     Node* prevCursor = this->firstElement;
     Node* cursor = this->firstElement->getNext();
     if(cursor == NULL) {
	// single     
	cout << "ERROR"<< endl; 
       return;
     }
     Node* nextNode = cursor->getNext();

     while(nextNode != NULL) {
       cout << "REV CURSOR "<<cursor->getValue()<<"POINTS AT:"<< cursor->getNext()<<endl;
       //cursor = nextNode;       
       Node* currentNode = cursor;

       cursor->setNext(prevCursor);   // make current element point at tail
       prevCursor = cursor;           // advance prevcursor. 
       cursor = nextNode;             // "advance" in the list.

       nextNode = nextNode->getNext(); // advance the next cursor
       
     } 
     //this->firstElement->setNext(NULL);
     this->firstElement = cursor;
  }

}; 

int main(){
  // Example of Node usage.

  Node* n = new Node(100);
  Node* last = n;
  last = last->AddElement(new Node(200));
  last = last->AddElement(new Node(399));
  last = last->AddElement(new Node(391));
  last = last->AddElement(new Node(392));
  last = last->AddElement(new Node(393));

  n->DeleteElement(391);

  cout << "LIST 1" << endl;
  n->PrintNodes();


  // Example of LinkedList usage.

  LinkedList* l = new LinkedList(new Node(1234));
  LinkedList* head = l;
  Node* last2 = l->getFirstElement();
  l->AddNode(new Node(123));
  l->AddNode(new Node(1235));
  l->AddNode(new Node(123));
  l->AddNode(new Node(124));
  l->AddNode(new Node(123));

  cout << "FIRST LIST 2" << endl;

  l->RemoveNode(1235);

  cout << "Found 124 at index: ";
  cout << l->IndexOf(124) << endl;

  cout << "Found 1124 at index: ";
  cout << l->IndexOf(1124) << endl;

  head->Replace(123,321);
  head->PrintNodes();
  
  cout << "FIRST LIST 2 (reversed)" << endl;
  l->Reverse();
  l->PrintNodes();
  
  cout << "LENGTH" << endl;
  cout << head->Length();


  return 0;
}
