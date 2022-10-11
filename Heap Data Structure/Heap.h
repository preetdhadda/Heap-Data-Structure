// Author: Preet Dhadda
// Date: March 2022
#pragma once

#include <stdexcept>
#include <iostream>
#include <vector>
using std::runtime_error;
using std::vector;
using namespace std;

// ---------------- CLASS DEFINITION: ----------------
template <class T>
class Heap {
public:
    // constructor
    Heap(int n);
    
    // copy constructor
    Heap(const Heap & heap);
    
    // destructor
    ~Heap();
    
    // overloaded assignment operator
    Heap& operator=(const Heap & heap);
    
    // insert method
    void insert(T val);
    
    // remove method
    T remove();
    
    // peek method
    T peek() const;
    
    // merge method
    Heap merge(const Heap & heap) const;
    
    // size method
    int size() const;
    
private:
    // attributes
    int currSize;
    int maxSize;
    T* arr;
    
    // deep copy helper method (used in copy constructor & assignment operator)
    void copy(const Heap & heap);
    
    // bubbleUp helper method (used in insert method)
    void bubbleUp(int i);
    
    // bubbleDown helper method (used in remove method)
    void bubbleDown(int i);
    
    // swap helper method (used in remove method)
    void swap(T* arr, int i, int j);
};

// --------------------- FUNCTIONS: ----------------------
// smallestm function
template <class T>
vector<T> smallestm(vector<T> inputVec, int m) {
    vector<T> returnVec;
    int k = 0;
    
    // If m = 0, return empty vector
    if (m == 0) {
        return returnVec;
    }
    
    // If m is <= vector's size:
    else if (m <= static_cast<int>(inputVec.size())) {
        // Create heap of size m and insert m values from vector
        Heap<T> heap(m);
        for (int i = 0; i < m; i++) {
            heap.insert(inputVec[i]);
        }
        
        // Compare the rest of the vector's elements to the heap's root
        for (int i = m; i < static_cast<int>(inputVec.size()); i++) {
            // Remove root and insert vector element if root > vector element
            if (heap.peek() > inputVec[i]) {
                heap.remove();
                heap.insert(inputVec[i]);
            }
        }
        
        // Remove everything from heap and insert into vector in ascending order
        while (k < m) {
            returnVec.insert(returnVec.begin(), heap.remove());
            k++;
        }
    }
    
    // If m > vector's size:
    else {
        // Create a heap equal to the size of the vector and insert all vector elements
        Heap<T> heap(static_cast<int>(inputVec.size()));
        for (int i = 0; i < static_cast<int>(inputVec.size()); i++) {
            heap.insert(inputVec[i]);
        }
        
        // Remove everything from heap and insert into vector in ascending order
        for (int i = 0; i < static_cast<int>(inputVec.size()); i++) {
            returnVec.insert(returnVec.begin(), heap.remove());
        }
    }

    return returnVec;
}

// ------------- PUBLIC CLASS IMPLEMENTATION: ------------
// constructor
template <class T>
Heap<T>::Heap(int n) {
    currSize = 0;
    maxSize = n;
    arr = new T[maxSize];
}

// copy constructor
template <class T>
Heap<T>::Heap(const Heap & heap) {
    arr = heap.arr;
    currSize = heap.currSize;
    maxSize = heap.maxSize;
    
    // Call deep copy helper method
    copy(heap);
}

// destructor
template <class T>
Heap<T>::~Heap() {
    // Deallocate dynamic memory for array
    delete[] arr;
}

// overloaded assignment operator
template <class T>
Heap<T>& Heap<T>::operator=(const Heap & heap) {
    // Only perform if address of calling object != address of parameter
    if (this != &heap) {
        // Deallocate array memory
        delete[] arr;
        // Call deep copy helper method
        copy(heap);
    }
    return *this;
}

// insert method
template <class T>
void Heap<T>::insert(T val) {
    // Run time error
    if (currSize == maxSize) {
        throw runtime_error("Heap is full - cannot insert new value");
    }
    
    // Add input to end of array
    arr[currSize] = val;
    // bubbleUp the heap to put input in correct spot
    bubbleUp(currSize);
    currSize++;
}

// remove method
template <class T>
T Heap<T>::remove() {
    // Run time error
    if (currSize == 0) {
        throw runtime_error("Heap is empty - cannot remove root");
    }
    
    // Store root value, swap root with last element in heap, & decrement size
    T root = arr[0];
    swap(arr, 0, currSize-1);
    currSize--;
    // bubbleDown the heap to reorder if necessary
    bubbleDown(0);
    return root;
}

// peek method
template <class T>
T Heap<T>::peek() const {
    // Run time error
    if (currSize == 0) {
        throw runtime_error("Heap is empty - cannot peek the root");
    }
    
    return arr[0];
}

// merge method
template <class T>
Heap<T> Heap<T>::merge(const Heap & heap) const {
    // Size of merged heap = sum of previous heap sizes
    int mergedSize = currSize + heap.currSize;
    // Created new heap and update its parameters
    Heap<T> mergedHeap(mergedSize);
    mergedHeap.currSize = mergedSize;
    mergedHeap.maxSize = mergedSize;
    
    // Copy values from both heaps into new heap's array
    for (int i = 0; i < currSize; i++) {
        mergedHeap.arr[i] = arr[i];
    }
    for (int i = currSize; i < mergedHeap.currSize; i++) {
        mergedHeap.arr[i] = heap.arr[i-currSize];
    }
    
    // Call bubbleDown in reverse order starting at the last non-leaf in heap
    // - Referenced https://www.geeksforgeeks.org/merge-two-binary-max-heaps/
    //   to see when to call bubbleDown
    for (int i = (mergedSize/2)-1; i >= 0; i--) {
        mergedHeap.bubbleDown(i);
    }
    
    return mergedHeap;
}

// size method
template <class T>
int Heap<T>::size() const {
    return currSize;
}

// ------------- PRIVATE CLASS IMPLEMENTATION: ------------
// deep copy helper method (used in copy constructor & assignment operator)
template <class T>
void Heap<T>::copy(const Heap & heap) {
    currSize = heap.currSize;
    maxSize = heap.maxSize;
    arr = new T[maxSize];
    for (int i=0; i<currSize; i++) {
        arr[i] = heap.arr[i];
    }
}

// bubbleUp helper method (used in insert method)
template <class T>
void Heap<T>::bubbleUp(int i) {
    // Get index of parent
    int parent = (i-1)/2;
    // Traverse up the heap swapping values so that all parents > their children
    if (i > 0 && arr[i] > arr[parent]) {
        swap(arr, i, parent);
        bubbleUp(parent);
    }
}

// bubbleDown helper method (used in remove & merge methods)
template <class T>
void Heap<T>::bubbleDown(int i) {
    // Get index of root, left child, and right child
    int max = i;
    int left = (2*i)+1;
    int right = (2*i)+2;
    
    // Update root index if value at left or right child is > value at root
    if (left < currSize && arr[left] > arr[i]) {
        max = left;
    }
    if (right < currSize && arr[right] > arr[max]) {
        max = right;
    }
    
    // Traverse down the heap swapping values if left or right > root
    if (i != max) {
        swap(arr, i, max);
        bubbleDown(max);
    }
}

// swap helper method (used in remove method)
template <class T>
void Heap<T>::swap(T* arr, int i, int j) {
    T temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
