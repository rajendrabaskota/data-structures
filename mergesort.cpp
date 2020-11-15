#include <iostream>

using namespace std;

void merge(int arr[], int l, int m, int h){
    int nl, nr;
    nl = m - l + 1;
    nr = h - m;
    int larr[nl], rarr[nr];
    for(int i=0; i<nl; i++){
        larr[i] = arr[l+i];
    }
    for(int i=0; i<nr; i++){
        rarr[i] = arr[m+i+1];
    }
    int i=0, j=0, k=l;
    while(i<nl && j<nr){
        if(larr[i] <= rarr[j]){
            arr[k] = larr[i];
            i++;
        }else{
            arr[k] = rarr[j];
            j++;
        }
        k++;
    }
    while(i<nl){
        arr[k] = larr[i];
        i++;
        k++;
    }
    while(j<nr){
        arr[k] = rarr[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int h){
    if(l < h){
        int mid = (l + h-1) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, h);
        merge(arr, l, mid, h);
    }
}

void printArray(int arr[], int size){
    for(int i=0; i<size; i++){
        cout << arr[i] << endl;
    }
}

int main(){
    int size = 8;
    int arr[size] = {5, 2, 4, 3, 10, 8, 9, 13};
    mergeSort(arr, 0, size-1);
    printArray(arr, size);
    return 0;
}
