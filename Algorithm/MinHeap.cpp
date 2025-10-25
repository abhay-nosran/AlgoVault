#include <bits/stdc++.h>
using namespace std ;
class minHeap{
    vector<int> arr ;
    int size = 5 ;
    int currentSize = 0 ; 

    void increaseSize(){
        size *= 2 ;
        arr.resize(size) ;
    }

    public : 

    minHeap(){
        arr.resize(size,0) ; 
    }

    void insert(int element){
        if(size == currentSize){
            increaseSize() ;
        }

        arr[currentSize] = element ;
        heapifyUp(currentSize) ;
        currentSize++ ;
    }

    void heapifyUp(int index){
        int currentElement = arr[index] ;

        if(index == 0) return ;
        int parentIndex = (index -1)/2 ;

        if(arr[parentIndex] > currentElement){
            // swap it 
            swap(arr[index] , arr[parentIndex]) ;
            heapifyUp(parentIndex) ;
        }
    }

    void heapify(int index){

        int smallest = index ;
        int left = 2*index + 1 , right = 2*index +2 ;
        if(left < currentSize && arr[smallest] > arr[left]){
            smallest = left ;
        }
        if(right < currentSize && arr[smallest] > arr[right]){
            smallest = right ;
        }

        if(index == smallest) return ;
        swap(arr[smallest] , arr[index]) ;
        heapify(smallest) ;
    }
    int extractMin(){
        if(currentSize == 0) return -1;
        int minVal = arr[0] ;
        swap(arr[0],arr[currentSize-1]) ;
        currentSize-- ;
        heapify(0) ;
        return minVal ;
    }




    void print(){

        for(int  i = 0 ; i < currentSize ; i++){
            cout << arr[i] << ' ' ;
        }
        cout << endl ; 
    }

    void remove(int index){
        
        if(index >= currentSize) return ;

        arr[index] = INT_MIN ;
        heapifyUp(index) ;
        extractMin() ;

    }
};
 

int main() {
    minHeap m;
    m.insert(2);
    m.insert(4);
    m.insert(3);
    m.insert(1);

    cout << "Heap: ";
    m.print();

    cout << "Extracted Min: " << m.extractMin() << endl;

    cout << "After extraction: ";
    m.print();

    m.remove(1);
    cout << "After removing index 1: ";
    m.print();
}