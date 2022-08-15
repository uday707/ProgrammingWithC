#include <iostream>
#include "common.h"


using namespace std;

class Node {
  public:
    int data;
    Node* next;
};

void print(Node* node) {
  while(node != NULL) {
     cout << node->data << "->";
     node = node->next;
  }
  cout << "NULL" << endl;
}

Node* push(Node* head, int val) {
    Node* node = new Node();
    node->data = val;
    
    // make next node of new node as head
    node->next = head;

    // move the head to head of new node
    head = node;
    return head;
}

void append(Node** head, int val) {
   // Creating the node..
  Node* node = new Node();
  (*node).data = val;
  node->next = NULL;

  if( *head == NULL) {
    // there is no element in current list,
    // so setting node as head and return
    *head = node;
    return;
  }
   Node* last = *head;

   // Going to the tail of list
   while(last->next != NULL) {
      last = last->next;
   }

   //now setting last->next node as node
   last->next = node; 
}

// given the previous node, insert a node after the 
// element
void insertAfter(Node* prev_node, int new_data) {
    if (prev_node == NULL) {
       cout << "Given node cann't be null, returning" << endl;
       return;
    }

    Node* node = new Node();
    node->data = new_data;
    
    node->next = prev_node->next;

    prev_node->next = node;
    
}

int main() {
  Node* node = NULL;
  append(&node, 5);
  node = push(node, 6);
 
  node = push(node, 3);
  append(&node, 1);
 
  print(node);
  
  insertAfter(node, 4);
  print(node);
  cout << endl << endl;
  return 0;
}