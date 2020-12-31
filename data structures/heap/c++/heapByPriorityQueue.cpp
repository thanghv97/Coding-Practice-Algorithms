#include <queue>
#include <iostream>

class MinHeap {
   public:
    MinHeap();
   
    MinHeap(std::vector<int> a) {
        for (uint32_t i = 0; i < a.size(); i++) {
            heap_.push(a[i]);
        }
    }
    
    // copy element, push back and reoder heap
    void push(int val) {
        heap_.push(val); // reoder by using push_heap in algorithm lib
    }
    
    // contruct new element, push back and reoder heap 
    void emplace(int val) { 
        heap_.emplace(val); // reoder by using push_heap in algorithm lib 
    }
    
    // pop root and reoder heap
    void pop(void) {
        heap_.pop();
    }

    // size of heap
    int size() {
        return heap_.size(); 
    }

    void show() {
        std::priority_queue<int, std::vector<int>, std::greater<int>> tmp = heap_;
        while (!tmp.empty()) {
            std::cout<<tmp.top()<<" ";
            tmp.pop(); // reoder by using pop_heap in algorithm lib 
        }
        std::cout<<std::endl;
    }
    
    std::priority_queue<int, std::vector<int>, std::greater<int>> heap_;
};

class MaxHeap {
   public:
    MaxHeap(std::vector<int> a) {
        for (uint32_t i = 0; i < a.size(); i++) {
            heap_.push(a[i]);
        }
    }
    
    // copy element, push back and reoder heap
    void push(int val) {
        heap_.push(val); // reoder by using push_heap in algorithm lib 
    }
    
    // contruct new element, push back and reoder heap 
    void emplace(int val) { 
        heap_.emplace(val); // reoder by using push_heap in algorithm lib 
    }

    // pop root and reoder heap
    void pop(void) {
        heap_.pop();
    }
    
    // size of heap
    int size() {
        return heap_.size();
    }
    
    void show() {
        std::priority_queue<int> tmp = heap_;
        while (!tmp.empty()) {
            std::cout<<tmp.top()<<" ";
            tmp.pop(); // reoder by using pop_heap in algorithm lib 
        }
        std::cout<<std::endl;
    }
    std::priority_queue<int> heap_;
};

int main(int argc, char* argv[]) {
    (void)argc; 
    (void)argv;

    MinHeap* min_heap;
    MaxHeap* max_heap;
    
    std::vector<int> a = {0, 1, 5, 6, 1, 2, 0, 4, 3};
    min_heap = new MinHeap(a);
    max_heap = new MaxHeap(a);
    
    /*** test init heap ***/
    std::cout<<"min heap(" << min_heap->size() << "): ";
    min_heap->show();
    
    std::cout<<"max heap(" << max_heap->size() << "): ";
    max_heap->show();
    
    /*** test push -> update heap ***/
    std::cout<<"=> insert 4"<<std::endl;
    min_heap->push(4);
    max_heap->push(4);
 
    std::cout<<"min heap(" << min_heap->size() << "): ";
    min_heap->show();
    
    std::cout<<"max heap(" << max_heap->size() << "): ";
    max_heap->show();
    
    /*** test pop ->update heap ***/
    std::cout<<"=> pop"<<std::endl;
    min_heap->pop();
    max_heap->pop();

    std::cout<<"min heap(" << min_heap->size() << "): ";
    min_heap->show();
    
    std::cout<<"max heap(" << max_heap->size() << "): ";
    max_heap->show();
    
    return 0;
}