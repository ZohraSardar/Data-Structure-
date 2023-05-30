#include<iostream>
using namespace std;

class heap{
    private:
        int *arr;
        int size;
        int maxSize;
    public:
         heap(int total){
             arr = new int[total];
             size = 0;
             maxSize = total;
         }

        void insert(int val){
            if (size == maxSize){
                cout << "Heap is full! " << endl;
            }
            else{
                size+=1;
                int index = size;
                arr[index] = val;

                while (index > 1){
                    int parent = index / 2;
                    if (arr[index] > arr[parent]){
                        swap(arr[parent], arr[index]);
                        index = parent; //parent is now our index because its on top
                    }
                    else{
                        return ;
                    }
                }                  
        }
}

bool isMaxHeap(int arr[], int n) {
    for(int i=1; i<n; i++) {
        if(arr[(i-1)/2] < arr[i] )
            return false;
    }
    return true;
}
void display(){
    for (int i=1 ; i<= size ;i++){
        cout << arr[i] << '\t';
    }
}

void deleteMe(){
    if (size == 0){
        cout << "Heap is already empty! " << endl;
    }
    arr[1] = arr[size];
    size--;
    int i = 1;
    while (size > i){
        int leftIndex = i*2;
        int rightIndex = i*2+1;
        // if left child > par
        if (leftIndex < size && arr[leftIndex] > arr[i]){
            swap(arr[i] , arr[leftIndex]);
            i = leftIndex;
        }
        // if right child > par
        else if(rightIndex < size && arr[rightIndex] > arr[i]){
            swap(arr[i] , arr[rightIndex]);
            i = rightIndex;
        }
    
        else{
            return ;
        }
    }
}

};

int main(){
     heap h1(20);
	h1.insert(40);
	h1.insert(80);
	 h1.insert(90);
     h1.insert(100);
	
 h1.deleteMe();
	h1.display();
     cout << endl;
   //  cout << "Max Heap or not? " << h1.isMaxHeap(h1);
 // heap h1;
  int arr[] = {100, 15, 10, 7, 12, 2};
  int n = sizeof(arr) / sizeof(arr[0]);
 cout << h1.isMaxHeap(arr , n); 
}
