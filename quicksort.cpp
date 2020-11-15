#include <iostream>

using namespace std;

int partition(int arr[], int l, int h){
    int pivot = arr[l];
    int i=l, j=h;
    while(i < j){
        do{
            i++;
        }while(arr[i] <= pivot);

        while(arr[j] > pivot){
            j--;
        }

        if(i < j){
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }
    int temp = arr[j];
    arr[j] = arr[l];
    arr[l] = temp;
    return j;
}

void quickSort(int arr[], int l, int h){
    if(l < h){
        int j = partition(arr,l, h);
        quickSort(arr, l, j);
        quickSort(arr, j+1, h);
    }
}

int main(){
    int size = 12;
    int arr[size] = {10, 2, 3, 15, 6, 1000, 22, 8, 9, 1, 234, 0};
    quickSort(arr, 0, size-1);
    for(int i=0; i<size; i++){
        cout << arr[i] << endl;
    }
    return 0;
}
