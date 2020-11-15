#include <iostream>

using namespace std;

void bubbleSort(int* arr, int arrSize){
    for(int i=0; i<arrSize-2; i++){
        int flag = 0;
        for(int j=0; j<arrSize-i-1; j++){
            if(arr[j+1] < arr[j]){
                arr[j+1] = arr[j+1] + arr[j];
                arr[j] = arr[j+1] - arr[j];
                arr[j+1] = arr[j+1] - arr[j];
                flag = 1;
            }
        }
        if(flag == 0){
            break;
        }
    }
}

int main(){
    int arrSize = 8;
    int arr[arrSize] = {5, 2, 1, 3, 8, 15, 25, 7};
    bubbleSort(arr, arrSize);
    for(int i=0; i<arrSize; i++){
        cout << arr[i] << endl;
    }
    return 0;
}
