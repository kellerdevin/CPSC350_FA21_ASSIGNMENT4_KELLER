
/**
 * DoublyLinkedList Template file
 * 
 * @author Devin Keller
 * @version 1.0
 * @see DoublyLinkedList.h
 * 
 */
#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <iostream>
#include <exception>
using namespace std;

template <class T> class ListNode{
public:
  ListNode();
  ListNode(T d);
  ~ListNode();
  ListNode *next;
  ListNode *prev;
  T data;
};

//implementation
template <class T>
ListNode<T>::ListNode(){}

template <class T>
ListNode<T>::ListNode(T d){
  data = d;
  next = NULL;
  prev = NULL;
}

template <class T>
ListNode<T>::~ListNode(){
}

//doublylinked list class
template <class T> class DoublyLinkedList{
private:
  ListNode<T> *front;
  ListNode<T> *back;
  unsigned int size;
public:
  DoublyLinkedList();
  ~DoublyLinkedList();

  void insertFront(T d);
  void insertBack(T d);
  T removeFront();
  T removeBack();
  T removeNode(T value);
  int find(T value);
  bool isEmpty();
  unsigned int getSize();
};

template <class T>
DoublyLinkedList<T>::DoublyLinkedList(){
  front = NULL;
  back = NULL;
  size = 0;
}

template <class T>
DoublyLinkedList<T>::~DoublyLinkedList(){
}

template <class T>
void DoublyLinkedList<T>::insertFront(T d){
  ListNode<T> *node = new ListNode<T>(d);

  if(isEmpty()) {
    back = node;
  }
  else{
    //Not empty
    node->next = front;
    front->prev = node;
  }
  front = node;
  ++size;
}

template <class T>
void DoublyLinkedList<T>::insertBack(T d){
  ListNode<T> *node = new ListNode<T>(d);

  if(isEmpty()){
    front = node;
  }
  else{
    node->prev = back;
    back->next = node;
  }
  back = node;
  ++size;
}

template <class T>
T DoublyLinkedList<T>::removeFront(){
  if(isEmpty()) {
    throw runtime_error("list is empty");
  }

  ListNode<T> *temp = front;

  if(front->next==NULL) {
    back=NULL;
  }
  else{
    front->next->prev=NULL;
  }
  front = front->next;
  temp->next=NULL;
  T data = temp->data;
  --size;
  delete temp;
  return data;
}

template <class T>
T DoublyLinkedList<T>::removeBack(){
  if(isEmpty()) {
    throw runtime_error("list is empty");
  }

  ListNode<T> *temp = back;

  if(back->prev == NULL){
    front = NULL;
  }
  else{
    back->prev->next=NULL;
  }
  back = back->prev;
  temp->prev = NULL;
  T data = temp->data;
  --size;
  delete temp;
  return data;
}

template <class T>
T DoublyLinkedList<T>::removeNode(T value){
  if(isEmpty()) {
    throw runtime_error("list is empty!");
  }

  ListNode<T> *curr = front;
  while(curr->data!=value) {
    curr = curr->next;

    //end
    if(curr==NULL) {
      return -1;
    }
  }
  if(curr != front && curr != back) {
    //its in between front and back
    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
  }

  if(curr == front) {
    front = curr->next;
    front->prev = NULL;
  }

  if(curr == back) {
    back = curr->prev;
    back->next = NULL;
  }

  curr->next = NULL;
  curr->prev = NULL;
  T data = curr->data;
  --size;
  delete curr;
  return data;
}

template <class T>
int DoublyLinkedList<T>::find(T value){
  int pos = -1;
  ListNode<T> *curr = front;
  while(curr != NULL){
    ++pos;
    if(curr-> data == value){
      break;
    }
    curr = curr->next;
  }
  if(curr == NULL){
    pos = -1;
  }
  return pos;
}

template <class T>
bool DoublyLinkedList<T>::isEmpty(){
  return (size == 0);
}

template <class T>
unsigned int DoublyLinkedList<T>::getSize(){
  return size;
}

#endif
