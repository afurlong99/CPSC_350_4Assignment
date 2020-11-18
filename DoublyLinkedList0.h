#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <iostream>
using namespace std;

/**
  virtual base class
  */
template <class T>
class VirtualDubLinkList{
  public:
    virtual T get(int pos) = 0;
    virtual int getSize() = 0;
    virtual bool isEmpty() = 0;
    virtual T getFront() = 0;
    virtual void insertAtHead(T x) = 0;
    virtual void insertAtTail(T x) = 0;
    virtual T deletePos(int pos) = 0;
    virtual T removeFront() = 0;
    virtual T removeBack() = 0;
    virtual void print() = 0;
};

/**
Node class that has a next
and back pointer and a value
*/

template <class T>
class Node{
  public:
    T data;
    Node* next;
    Node* prev;
    Node();
    Node(T x);
    ~Node();


    void print(){
      data.print();

    }
};

/**
default constructor
*/
template <class T>
Node<T>::Node(){
  next = nullptr;
  prev = nullptr;

}

/**
overloaded constructor
*/
template <class T>
Node<T>::Node(T x){
  data = x;
  next = nullptr;
  prev = nullptr;
}

/**
destructor
*/
template <class T>
Node<T>::~Node(){
  delete next;
  delete prev;
}

template <class T>
class DubLinkList: public VirtualDubLinkList<T>{
private:
  unsigned int size;
  Node<T>* front;
  Node<T>* back;
  T* available;

public:
  DubLinkList();
  ~DubLinkList();
  int getSize();
  T get(int pos);
  void insertAtHead(T x);
  void insertAtTail(T x);
  T deletePos(int pos);
  void print();
  bool isEmpty();
  T getFront();
  T removeFront();
  T removeBack();
  bool isAvailable();
  void SetWindowidletime();
  void Setstudentwaittime(int c);
  bool AllStudentdone();
  Node<T>* getFrontNode();
  void Assign(bool b);
};

//All studet done return true when every done has been servised
template <class T>
bool DubLinkList<T>::AllStudentdone(){
  if(front == nullptr){
    return true;
  }
  else{
    return false;
  }
}



template <class T>
void DubLinkList<T>::SetWindowidletime(){
  Node<T>* curr = front;
  while(curr != nullptr){
    curr -> data.setidle(1);
    curr = curr->next;
  }
}


template <class T>
void DubLinkList<T>::Setstudentwaittime(int c){
  Node<T>* curr = front;

  while(curr != nullptr){
    if(curr->data.getA()<= c){
      curr -> data.setwaitime(1);
    }

    curr = curr->next;
  }
}

template <class T>
void DubLinkList<T>::Assign(bool b){
  available->setisAvailable(b);
  available->print();
}


//if is availbe return valid node is not return null
template <class T>
bool DubLinkList<T>::isAvailable(){
//  std::cout << "We are in isAvailable fuction "<<'\n';
  Node<T>* curr = front;

  while(curr != nullptr){
//    std::cout << "Window s avialbe"<<'\n';
//    curr-> data.print();
      if(curr->data.getisAvailable() == true){
        available = &(curr-> data);
        return true;
      }
      else{
        curr = curr -> next;
      }
  }
//  std::cout << "exiting is avialbe" << '\n';
  return false;
}

/**
default constructor
*/
template <class T>
DubLinkList<T>::DubLinkList(){
  size = 0;
  front = nullptr;
  back = nullptr;
  available = nullptr;
}

/**
Inserts an element at a head
by manipulating the pointers
*/
template <class T>
void DubLinkList<T>::insertAtHead(T x){
  // cout << "courtnee" << endl;
  Node<T>* temp = new Node<T>(x);
  // cout << "courtnee" << endl;
  if(front == nullptr){
    front = temp;
    back = front;
    size++;
    return;
  }

  temp->prev = nullptr;
  temp->next = front;
  front->prev = temp;
  front = temp;
  size++;
}

/**
This prints out the list
*/
template <class T>
void DubLinkList<T>::print(){
  try{
    if(isEmpty()){
      throw 99;
    }
    Node<T>* curr = front;
    for(int n=0; n<size; n++){
      curr->print();
      curr = curr->next;
    }
  }catch(int x){
      cout << "It is empty" << endl;
    }
  }

/**
accessor method for the size
*/
template <class T>
int DubLinkList<T>::getSize(){
  return size;
}

/**
inserts an element at the back
of the list
*/
template <class T>
void DubLinkList<T>::insertAtTail(T x){

  Node<T>* temp = new Node<T>(x);
  if(back==nullptr){

    back = temp;
    front = back;
    size++;
  }else{


    back->next = temp;
    temp->prev = back;
    back = temp;
    size++;
  }
}

/**
deletes a position anywhere
in the ListBasedQueue
*/
template <class T>
T DubLinkList<T>::deletePos(int pos){
  T value;
  try{
    if(pos >= getSize()){
      // throw new exception();
      throw 100;
    }
    int currentPos = 0;
    Node<T>* curr = front;
    if(pos == getSize() - 1){
      removeBack();
    }else if(pos==0){
      removeFront();
    }else{
      while(currentPos != pos){
        currentPos++;
        curr = curr->next;
      }
      curr->prev->next = curr->next;
      curr->next->prev = curr->prev;
      value = curr->data;
      size--;
      return value;
    }
  }catch(int x){
    cerr << "That index is out of bounds" << endl;
    return value;
  }
}

/**
removes the back of the list
*/
template <class T>
T DubLinkList<T>::removeBack(){
  try{
    if(isEmpty()){
      throw 100;
    }
    if(getSize() == 0){

    }else if(getSize() == 1){
      T value = back->data;
      return value;
    }else{
      Node<T>* temp = back->prev;
      T value = back->data;
      temp->next = nullptr;
      back = temp;
      size--;
      return value;
    }

  }catch(int x){
    cout << "The data structure is not empty" << endl;
  }
}

/**
removes the front of the list
*/
template <class T>
T DubLinkList<T>::removeFront(){
  try{
    if(isEmpty()){
      throw 100;
    }else if(getSize() == 1){
      T value = front->data;
      front = nullptr;
      back = nullptr;
      size--;
      return value;
    }else{
      T value = front->data;
      Node<T>* temp = front->next;
      temp->prev = nullptr;
      front = temp;
      size--;
      return value;
    }
  }catch(int x){
    cout << "The data structure is not empty" << endl;
  }
}

/**
checks if the list is empty or not
and returns the appropriate boolean
*/
template <class T>
bool DubLinkList<T>::isEmpty(){
  bool emptyOrNot = false;
  if(getSize() == 0){
    emptyOrNot = true;
  }
  return emptyOrNot;
}

/**
returns the value of the
front of the linked list
*/
template <class T>
T DubLinkList<T>::getFront(){
  return front->data;
}

template <class T>
Node<T>* DubLinkList<T>::getFrontNode(){
  return front;
}



/**
destructor
*/
template <class T>
DubLinkList<T>::~DubLinkList(){
  delete front;
  delete back;
}

/**
returns a value anywhere in the
list given the index given
*/
template <class T>
T DubLinkList<T>::get(int pos){
  if(pos == 0){
    return front->data;
  }else if(pos == getSize()-1){
    return back->data;
  }else{
    Node<T>* curr = front;
    int counter = 0;
    while(counter < pos){
      curr = curr->next;
      counter++;
    }
    T value = curr->data;
    return value;
  }
}

#endif
