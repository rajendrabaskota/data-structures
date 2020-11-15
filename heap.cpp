#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// ....................PRIORITY QUEUE..............MAX HEAP............

template<int heapSize>
class MaxHeap{
    private:
        int heap[heapSize];
        int size = heapSize;
        int presentSize;

        // ...........heapify algorithm......
        void construction(){
            // cout << endl << presentSize << endl;
            for(int i=presentSize/2; i > 0; i--){
                int current = i;
                while(current*2 < presentSize){
                    int maxIndex = heap[2*current] > heap[2*current + 1] ? 2*current : 2*current + 1;
                    if(heap[maxIndex] > heap[current]){
                        int temp = heap[current];
                        heap[current] = heap[maxIndex];
                        heap[maxIndex] = temp;
                        current = maxIndex;
                    }else{
                        break;
                    }
                }
            }
        }

    public:
        MaxHeap(int *arr, int presentSize){
            this->presentSize = presentSize;
            for(int i=0; i<=presentSize; i++){
                this->heap[i] = arr[i];
            }
            // this->displayHeap();
            this->construction();
        }

        void displayHeap(){
            cout << endl;
            for(int i=1; i<=this->presentSize; i++){
                cout << this->heap[i] << endl;
            }
        }

        void addElement(int element){
            *(heap+presentSize+1) = element;
            this->presentSize++;
            int localIndex = presentSize;
            int parentIndex = floor((presentSize)/2);
            while(parentIndex >= 1){
                if(element > *(this->heap+parentIndex)){
                    *(this->heap+parentIndex) = *(this->heap+parentIndex) + *(this->heap+localIndex);
                    *(this->heap+localIndex) = *(this->heap+parentIndex) - *(this->heap+localIndex);
                    *(this->heap+parentIndex) = *(this->heap+parentIndex) - *(this->heap+localIndex);
                    localIndex = parentIndex;
                    parentIndex = floor((localIndex)/2);
                }else{
                    break;
                }
            }
        }

        void removeElement(){
            // cout << this->heap[presentSize-1];
            this->heap[1] = this->heap[this->presentSize];
            this->heap[this->presentSize] = 0;
            this->presentSize--;
            int parentIndex = 1;
            int localIndex = parentIndex * 2;
            int maxIndex;
            while(localIndex <= this->presentSize){
                if(localIndex + 1 > this->presentSize){
                    maxIndex = localIndex;
                }else{
                    maxIndex = this->heap[localIndex] > this->heap[localIndex + 1] ? localIndex : localIndex + 1;
                }
                if(this->heap[maxIndex] > this->heap[parentIndex]){
                    *(this->heap+parentIndex) = *(this->heap+parentIndex) + *(this->heap+maxIndex);
                    *(this->heap+maxIndex) = *(this->heap+parentIndex) - *(this->heap+maxIndex);
                    *(this->heap+parentIndex) = *(this->heap+parentIndex) - *(this->heap+maxIndex);
                }else{
                    break;
                }
                parentIndex = maxIndex;
                localIndex = parentIndex * 2;
            }
        }

        int removeElement(int presentSize){
            // cout << this->heap[presentSize-1];
            int removedElement = this->heap[1];
            this->heap[1] = this->heap[presentSize];
            // this->heap[this->presentSize] = 0;
            int parentIndex = 1;
            int localIndex = parentIndex * 2;
            int maxIndex;
            while(localIndex <= presentSize){
                if(localIndex + 1 > presentSize){
                    maxIndex = localIndex;
                }else{
                    maxIndex = this->heap[localIndex] > this->heap[localIndex + 1] ? localIndex : localIndex + 1;
                }
                if(this->heap[maxIndex] > this->heap[parentIndex]){
                    *(this->heap+parentIndex) = *(this->heap+parentIndex) + *(this->heap+maxIndex);
                    *(this->heap+maxIndex) = *(this->heap+parentIndex) - *(this->heap+maxIndex);
                    *(this->heap+parentIndex) = *(this->heap+parentIndex) - *(this->heap+maxIndex);
                }else{
                    break;
                }
                parentIndex = maxIndex;
                localIndex = parentIndex * 2;
            }
            return removedElement;
        }

        // .......... Heap sort algorithm .......
        void sort(){
            int startingIndex = this->presentSize;
            for(int i=startingIndex; i>=1; i--){
                int ans = this->removeElement(i);
                this->heap[i] = ans;
            }
        }
};

int main(){
    const int totalHeapSize = 15;
    int presentSize = 9;
    int arr[presentSize+1] = {0, 5, 3, 17, 10, 84, 19, 6, 22, 9};
    MaxHeap<totalHeapSize> heap(arr, presentSize);
    // heap.displayHeap();
    heap.addElement(15);
    heap.addElement(18);
    heap.addElement(85);
    // cout << endl;
    // heap.displayHeap();
    // heap.removeElement();
    cout << endl;
    // heap.displayHeap();
    // heap.removeElement();
    cout << endl;
    // heap.displayHeap();
    heap.sort();
    cout << endl;
    heap.displayHeap();
    return 0;
}
