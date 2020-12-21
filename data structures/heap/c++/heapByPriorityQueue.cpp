#include <queue>
#include <iostream>

using namespace std;

class MinHeap {
   public:
    MinHeap();
   
    MinHeap(vector<int> a) {
        for (int i = 0; i < a.size(); i++) {
            heap.push(a[i]);
        }
    }
    
    // copy element, push back and reoder heap
    void push(int val) {
        heap.push(val); // reoder by using push_heap in algorithm lib
    }
    
    // contruct new element, push back and reoder heap 
    void emplace(int val) { 
        heap.emplace(val); // reoder by using push_heap in algorithm lib 
    }
    
    // size of heap
    int size() {
        return heap.size(); 
    }
    
    void show() {
        priority_queue<int, vector<int>, greater<int>> tmp = heap;
        while (!tmp.empty()) {
            cout<<tmp.top()<<" ";
            tmp.pop(); // reoder by using pop_heap in algorithm lib 
        }
        cout<<endl;
    }
    
    priority_queue<int, vector<int>, greater<int>> heap;
};

class MaxHeap {
   public:
    MaxHeap(vector<int> a) {
        for (int i = 0; i < a.size(); i++) {
            heap.push(a[i]);
        }
    }
    
    // copy element, push back and reoder heap
    void push(int val) {
        heap.push(val); // reoder by using push_heap in algorithm lib 
    }
    
    // contruct new element, push back and reoder heap 
    void emplace(int val) { 
        heap.emplace(val); // reoder by using push_heap in algorithm lib 
    }
    
    // size of heap
    int size() {
        return heap.size();
    }
    
    void show() {
        priority_queue<int> tmp = heap;
        while (!tmp.empty()) {
            cout<<tmp.top()<<" ";
            tmp.pop(); // reoder by using pop_heap in algorithm lib 
        }
        cout<<endl;
    }
    priority_queue<int> heap;
};

int main(int argc, char* argv[]) {
    MinHeap* min_heap;
    MaxHeap* max_heap;
    
    vector<int> a = {0, 1, 5, 6, 1, 2, 0, 4, 3};
    min_heap = new MinHeap(a);
    max_heap = new MaxHeap(a);
    
    /*** test init heap ***/
    cout<<"min heap(" << min_heap->size() << "): ";
    min_heap->show();
    
    cout<<"max heap(" << max_heap->size() << "): ";
    max_heap->show();
    
    /*** test push -> update heap ***/
    cout<<"=> insert 4"<<endl;
    min_heap->push(4);
    max_heap->push(4);
 
    cout<<"min heap(" << min_heap->size() << "): ";
    min_heap->show();
    
    cout<<"max heap(" << max_heap->size() << "): ";
    max_heap->show();
    
    /*** test pop ->update heap ***/
    
    
    return 0;
}