#include <iostream>

using namespace std;

class UnionFind{
    private:
        int size;
        int arr[];

    public:
        UnionFind(int size, int (&arr)[10][10]){
            this->size = size;
            &arr = arr;
        }

        void display(){
            for(int i=0; i<size; i++){
                cout << arr[i] << endl;
            }
        }
};

int main(){
    int size = 10;
    int arr[size][size];
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            arr[i][j] = i;
        }
    }
    UnionFind * unionfind = new UnionFind(10, arr);
    unionfind->display();
    cout << "displayed" << endl;
    // unionfind->findSize();
    return 0;
}