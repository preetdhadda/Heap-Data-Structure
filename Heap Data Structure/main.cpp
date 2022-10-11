// Author: Preet Dhadda
// Date: March 2022

#include "Heap.h"
#include <iostream>
#include <string.h>
#include <vector>
using std::string;
using std::cout;
using std::endl;
using std::vector;

// -------------- TESTING INTS --------------
void testCopiesInt() {
    Heap<int> heap1(20);
    heap1.insert(4);
    heap1.insert(7);
    heap1.insert(3);
    heap1.insert(12);
    heap1.insert(1);
    heap1.insert(3);
    //heap1.print();
    cout << "size = " << heap1.size() << endl;
    cout << "root = " << heap1.peek() << endl << endl;
    
    Heap<int> heap70(0);
    Heap<int> heap80 = heap70;
    Heap<int> heap90(heap70);
    Heap<int> heap100 = heap90.merge(heap80);
    
    cout << "size = " << heap100.size() << endl;
    
    
    Heap<int> heap2(heap1);
    //heap2.print();
    cout << "size = " << heap2.size() << endl;
    cout << "root = " << heap2.peek() << endl << endl;
    
    heap2.remove();
    Heap<int> heap3 = heap2;
    //heap3.print();
    cout << "size = " << heap3.size() << endl;
    cout << "root = " << heap3.peek() << endl << endl;
    
    Heap<int> heap7 = heap2.merge(heap3);
    //heap7.print();
    cout << "size = " << heap7.size() << endl;
    cout << "root = " << heap7.peek() << endl << endl;
    
    heap3.remove();
    heap3.remove();
    heap3.remove();
    heap3.remove();
    
    Heap<int> heap4 = heap3;
    //heap4.print();
    cout << "size = " << heap4.size() << endl;
    cout << "root = " << heap4.peek() << endl << endl;
    
    Heap<int> heap5(heap3);
    //heap5.print();
    cout << "size = " << heap4.size() << endl;
    cout << "root = " << heap4.peek() << endl << endl;
    
    heap3.remove();
    heap3.insert(47);
    
    Heap<int> heap8 = heap3;
    //heap4.print();
    cout << "size = " << heap8.size() << endl;
    cout << "root = " << heap8.peek() << endl << endl;
    
    Heap<int> heap9(heap3);
    //heap5.print();
    cout << "size = " << heap9.size() << endl;
    cout << "root = " << heap9.peek() << endl << endl;
}

void testInsertAndRemoveInt() {
    Heap<int> heap1(20);
    cout << "heap size = " << heap1.size() << endl;
    heap1.insert(4);
    heap1.insert(7);
    heap1.insert(3);
    heap1.insert(12);
    heap1.insert(1);
    heap1.insert(3);
    //heap1.print();
    cout << "heap size = " << heap1.size() << endl;
    cout << "root = " << heap1.peek() << endl;
    cout << endl;
    
    heap1.insert(21);
    heap1.insert(19);
    heap1.insert(20);
    heap1.insert(19);
    heap1.insert(14);
    heap1.insert(15);
    //heap1.print();
    cout << "heap size = " << heap1.size() << endl;
    cout << "root = " << heap1.peek() << endl;
    cout << endl;
    
    heap1.remove();
    //heap1.print();
    cout << "heap size = " << heap1.size() << endl;
    cout << "root = " << heap1.peek() << endl;
    cout << endl;
    
    heap1.remove();
    heap1.remove();
    heap1.remove();
    //heap1.print();
    cout << "heap size = " << heap1.size() << endl;
    cout << "root = " << heap1.peek() << endl;
    cout << endl;
    
    heap1.remove();
    heap1.remove();
    heap1.remove();
 //   heap1.print();
    cout << "heap size = " << heap1.size() << endl;
    cout << "root = " << heap1.peek() << endl;
    cout << endl;
    
    heap1.insert(9);
    heap1.insert(6);
    heap1.insert(2);
 //   heap1.print();
    cout << "heap size = " << heap1.size() << endl;
    cout << "root = " << heap1.peek() << endl;
    cout << endl;
    
    heap1.remove();
    heap1.remove();
    heap1.remove();
    heap1.remove();
    heap1.remove();
  //  heap1.print();
    cout << "heap size = " << heap1.size() << endl;
    cout << "root = " << heap1.peek() << endl;
    cout << endl;
    
    heap1.remove();
    heap1.remove();
  //  heap1.print();
    cout << "heap size = " << heap1.size() << endl;
    cout << "root = " << heap1.peek() << endl;
    cout << endl;
    
    heap1.remove();
    cout << "heap size = " << heap1.size() << endl;
    //cout << "root = " << heap1.peek() << endl; // should throw run time error
    
    //heap1.remove(); // should throw run time error
}

void testMergeInt() {
    Heap<int> heap1(10);
    heap1.insert(4);
    heap1.insert(7);
    heap1.insert(3);
    heap1.insert(12);
    heap1.insert(1);
    heap1.insert(3);
    cout << endl;

    Heap<int> heap2(7);
    heap2.insert(5);
    heap2.insert(14);
    heap2.insert(2);
    heap2.insert(6);
    cout << endl;
    
    Heap<int> heap6(2);
    heap6.insert(4);
    cout << endl;
    
    Heap<int> heap7(2);
    heap7.insert(1);
    heap7.insert(5);
    cout << endl;

    Heap<int> mergedHeap3 = heap6.merge(heap7);
   // mergedHeap3.print();
    cout << "size = " << mergedHeap3.size() << endl;
    cout << "root = " << mergedHeap3.peek() << endl;
    cout << endl;

    Heap<int> mergedHeap = heap1.merge(heap2);
   // mergedHeap.print();
    cout << "size = " << mergedHeap.size() << endl;
    cout << "root = " << mergedHeap.peek() << endl;
    cout << endl;
    
    Heap<int> heap3(10);
    heap3.insert(20);
    heap3.insert(6);
    heap3.insert(9);
    heap3.insert(33);
    heap3.insert(88);
    heap3.insert(56);
    heap3.insert(79);
    //heap3.print();
    cout << endl;
    
    Heap<int> heap4(7);
    heap4.insert(81);
    heap4.insert(100);
    heap4.insert(45);
    heap4.insert(37);
    heap4.insert(11);
    heap4.insert(67);
    //heap4.print();
    cout << endl;
    
    Heap<int> mergedHeap2 = heap3.merge(heap4);
   // mergedHeap2.print();
    cout << "size = " << mergedHeap2.size() << endl;
    cout << "root = " << mergedHeap2.peek() << endl;
}

void testFunctionInt() {
    vector<int> vec = {10, 5, 2, 8, 6, 4, 3, 9, 1};
    vector<int> ret = smallestm(vec, 4);
    
    cout << "printing vector:" << endl;
    for (int x:ret) {
        cout << x << " ";
    }
    cout << endl;
    
    vector<int> vec2 = {5, 7, 5, 5, 6, 4};
    vector<int> ret2 = smallestm(vec2, 9);

    cout << "printing vector:" << endl;
    for (int x:ret2) {
        cout << x << " ";
    }
    cout << endl;

    vector<int> vec3 = {};
    vector<int> ret3 = smallestm(vec3, 3);

    cout << "printing vector:" << endl;
    for (int x:ret3) {
        cout << x << " ";
    }
    cout << endl;
    
    vector<int> vec4 = {99, 100, 45, 81, 97, 4, 9, 0, 1, 8};
    vector<int> ret4 = smallestm(vec4, 6);
    
    cout << "printing vector:" << endl;
    for (int x:ret4) {
        cout << x << " ";
    }
    cout << endl;
}

// -------------- TESTING STRINGS --------------
void testCopiesStr() {
    Heap<string> heap1(20);
    heap1.insert("cat");
    heap1.insert("dog");
    heap1.insert("bat");
    heap1.insert("pig");
    heap1.insert("dog");
    heap1.insert("cow");
   // heap1.print();
    cout << "size = " << heap1.size() << endl;
    cout << "root = " << heap1.peek() << endl << endl;
    
    Heap<string> heap2(heap1);
   // heap2.print();
    cout << "size = " << heap2.size() << endl;
    cout << "root = " << heap2.peek() << endl << endl;
    heap2.remove();
    Heap<string> heap3 = heap2;
  //  heap3.print();
    cout << "size = " << heap3.size() << endl;
    cout << "root = " << heap3.peek() << endl << endl;
    
    Heap<string> heap7 = heap2.merge(heap3);
   // heap7.print();
    cout << "size = " << heap7.size() << endl;
    cout << "root = " << heap7.peek() << endl << endl;
    
    heap3.remove();
    heap3.remove();
    heap3.remove();
    heap3.remove();
    
    Heap<string> heap4 = heap3;
  //  heap4.print();
    cout << "size = " << heap4.size() << endl;
    cout << "root = " << heap4.peek() << endl << endl;
    Heap<string> heap5(heap3);
//    heap5.print();
    cout << "size = " << heap4.size() << endl;
    cout << "root = " << heap4.peek() << endl << endl;
}

void testInsertAndRemoveStr() {
    Heap<string> heap1(20);
    heap1.insert("cat");
    heap1.insert("dog");
    heap1.insert("bat");
    heap1.insert("pig");
    heap1.insert("dog");
    heap1.insert("cow");
 //   heap1.print();
    cout << "heap size = " << heap1.size() << endl;
    cout << "root = " << heap1.peek() << endl;
    cout << endl;
    
    heap1.insert("horse");
    heap1.insert("donkey");
    heap1.insert("giraffe");
    heap1.insert("giraffe");
    heap1.insert("zebra");
    heap1.insert("armadillo");
  //  heap1.print();
    cout << "heap size = " << heap1.size() << endl;
    cout << "root = " << heap1.peek() << endl;
    cout << endl;
    
    heap1.remove();
  //  heap1.print();
    cout << "heap size = " << heap1.size() << endl;
    cout << "root = " << heap1.peek() << endl;
    cout << endl;
    
    heap1.remove();
    heap1.remove();
    heap1.remove();
   // heap1.print();
    cout << "heap size = " << heap1.size() << endl;
    cout << "root = " << heap1.peek() << endl;
    cout << endl;
    
    heap1.remove();
    heap1.remove();
    heap1.remove();
  //  heap1.print();
    cout << "heap size = " << heap1.size() << endl;
    cout << "root = " << heap1.peek() << endl;
    cout << endl;
    
    heap1.insert("frog");
    heap1.insert("leopard");
    heap1.insert("zebra");
  //  heap1.print();
    cout << "heap size = " << heap1.size() << endl;
    cout << "root = " << heap1.peek() << endl;
    cout << endl;
    
    heap1.remove();
    heap1.remove();
    heap1.remove();
    heap1.remove();
    heap1.remove();
 //   heap1.print();
    cout << "heap size = " << heap1.size() << endl;
    cout << "root = " << heap1.peek() << endl;
    cout << endl;
    
    heap1.remove();
    heap1.remove();
 //   heap1.print();
    cout << "heap size = " << heap1.size() << endl;
    cout << "root = " << heap1.peek() << endl;
    cout << endl;
    
    heap1.remove();
    cout << "heap size = " << heap1.size() << endl;
    //cout << "root = " << heap1.peek() << endl; // should throw run time error
    
    //heap1.remove(); // should throw run time error
}

void testMergeStr() {
    Heap<string> heap1(10);
    heap1.insert("cat");
    heap1.insert("dog");
    heap1.insert("bat");
    heap1.insert("pig");
    heap1.insert("dog");
    heap1.insert("cow");
    //heap1.print();
    cout << endl;

    Heap<string> heap2(7);
    heap2.insert("donkey");
    heap2.insert("giraffe");
    heap2.insert("giraffe");
    heap2.insert("monkey");
    //heap2.print();
    cout << endl;

    Heap<string> mergedHeap = heap1.merge(heap2);
  //  mergedHeap.print();
    cout << "size = " << mergedHeap.size() << endl;
    cout << "root = " << mergedHeap.peek() << endl;
    cout << endl;
    
    Heap<string> heap3(10);
    heap3.insert("cheetah");
    heap3.insert("frog");
    heap3.insert("bear");
    heap3.insert("bison");
    heap3.insert("zebra");
    heap3.insert("coyote");
    heap3.insert("bear");
    //heap3.print();
    cout << endl;
    
    Heap<string> heap4(7);
    heap4.insert("snake");
    heap4.insert("puma");
    heap4.insert("panther");
    heap4.insert("monkey");
    heap4.insert("bird");
    heap4.insert("penguin");
    //heap4.print();
    cout << endl;
    
    Heap<string> mergedHeap2 = heap3.merge(heap4);
  //  mergedHeap2.print();
    cout << "size = " << mergedHeap2.size() << endl;
    cout << "root = " << mergedHeap2.peek() << endl;
}

void testFunctionStr() {
    vector<string> vec = {"dog", "cat", "bird", "bear", "donkey", "frog", "horse", "penguin"};
    vector<string> ret = smallestm(vec, 6);
    
    cout << "printing vector:" << endl;
    for (string x:ret) {
        cout << x << " ";
    }
    cout << endl;
    
    vector<string> vec2 = {"dog", "cat", "cat", "dog", "cat", "zebra"};
    vector<string> ret2 = smallestm(vec2, 4);
    
    cout << "printing vector:" << endl;
    for (string x:ret2) {
        cout << x << " ";
    }
    cout << endl;
    
    vector<string> vec3 = {"puma"};
    vector<string> ret3 = smallestm(vec3, 8);
    
    cout << "printing vector:" << endl;
    for (string x:ret3) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
testCopiesInt();
testInsertAndRemoveInt();
testMergeInt();
testFunctionInt();

 testCopiesStr();
 testInsertAndRemoveStr();
testMergeStr();
 testFunctionStr();
}