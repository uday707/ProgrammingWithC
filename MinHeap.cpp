#include <iostream>
#include <climits>
#include "common.h"

using namespace std;
// class for MinHeap
class MinHeap {
   int *harr; //pointer to array of elements in heap
   int capacity; // maximum capacity of size of heap
   int heap_size; // current number of elements in min heap

   public:
     // Constructor 
     MinHeap(int cap);

     //to heapify the subtree with root at given index
     void MinHeapify(int);
    
    // index of parent of given element at index position i.
    int parent(int i) {
      return (i -1)/2;
    }

    // get index of left child of node at index i
    int left(int i) {
      return (2*i +1); 
    }

    // get index of right child of node at index i
    int right(int i) {
      return (2*i +2);
    }

    // extract the node which is the minimum element
    int extractMin();

    // decrease the key value at index i to new value
    void decreaseKey(int i, int new_val);

    // return the minimun key (key at root) from min heap
    int getMin() {
      return harr[0];
    }

    // deletes at key sorted at index i
    void deleteKey(int i);

    // insert a new key
    void insertKey(int k);

    // print the heap
    void display() {
      print(harr, heap_size);
    }

};

MinHeap::MinHeap(int cap) {
  heap_size = 0;
  capacity = cap;
  harr = new int[capacity];
}

// insert new key 'k'
void MinHeap::insertKey(int k) {
   if(heap_size == capacity) {
      cout << "\nOverflow: could not insert key \n";
      return;
   }
   // first insert new key at end
   heap_size++;
   int i = heap_size -1;
   harr[i] = k;

   //fix the min heap property if it is violated
   while(i != 0 && harr[parent(i)] > harr[i]) {
    swap(harr[i], harr[parent(i)]);
    i = parent(i);
   }  
}

// Decreases the value of key at index 'i' to new_val
// It is assumed that new_val is lesser than harr[i] 
void MinHeap::decreaseKey(int i, int new_val) {
   harr[i] = new_val;
   // fix the min heap property if it is violated
   while(i != 0 && harr[parent(i)] > harr[i]) {
      swap(harr[i], harr[parent(i)]);
      i = parent(i);
   }
}

// Extract the minimum element from (from root) from Min Heap
int MinHeap::extractMin() {
   if(heap_size <= 0) {
     return -1;
   }

   if(heap_size == 1) {
    heap_size--;
    return harr[0];
   }

   // store the minimum value and remove it from heap
   int root = harr[0];
   harr[0]  = harr[heap_size -1];
   heap_size--;
   MinHeapify(0);

   return root;
}
// delete key at index i, first set the reduced value of infinite at index i
// then call method extractMin to move that negative infinite value to root
// location and then remove it.
void MinHeap::deleteKey(int i) {
    decreaseKey(i, INT_MIN);
    extractMin();
}

// recursive method to heapify a subtree with the root at given index
// this method assumes that the subtree is already heapified
void MinHeap::MinHeapify(int i) {
  int l = left(i);
  int r = right(i);
  int smallest = i;
  if (l < heap_size && harr[l] < harr[i])
      smallest = l;
  if (r < heap_size && harr[r] < harr[smallest])
      smallest = r;
  
  if(smallest != i) {
    swap(harr[i], harr[smallest]);
    MinHeapify(smallest);
  }
}

int main() {

    MinHeap heap(11);
    heap.insertKey(3);
    heap.insertKey(2);
    heap.insertKey(1);
    heap.display();
    heap.deleteKey(1);
    heap.display();
    heap.insertKey(15);
    heap.insertKey(5);
    heap.insertKey(4);
    heap.insertKey(45);
    heap.display();
    cout << "Extract Min: " << heap.extractMin() << endl;
    heap.display();
    cout << "Get Min (do'nt remove): " << heap.getMin() << endl;
    cout << "Get Min (do'nt remove): " << heap.getMin() << endl;
    heap.decreaseKey(2, 1);
    heap.display();
    cout << "Get Min: (don't remove): " << heap.getMin() << endl;
    heap.display();
    heap.insertKey(15);
    heap.insertKey(21);
    heap.insertKey(3);
    heap.display();
    cout << endl << endl;

}