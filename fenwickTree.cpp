#include <iostream>

using namespace std;

class FenwickTree{
    private:
        int * tree = new int[1];
        int size;
    public:
        FenwickTree(int * arr, int size){
            this->size = size;
            int * newTree = new int[size+1];
            delete[] this->tree;
            newTree = arr;
            this->tree = newTree;
            this->construction();
        }

        int lsb(int i){
            return i & -i;
        }

        void construction(){
            int j;
            for(int i=1; i<=this->size; i++){
                j = i + lsb(i);
                if(j <= size){
                    *(this->tree+j) = *(this->tree+j) + *(this->tree+i);

                }
            }
            return;
        }

        int sumUpTo(int num){
            int sum = *(this->tree+num);
            while(num != 0){
                num = num - this->lsb(num);
                sum = sum + *(this->tree+num);
            }
            return sum;
        }

        int query(int i){
            return sumUpTo(i);
        }

        int query(int i, int j){
            return sumUpTo(i) - sumUpTo(j-1); 
        } 

        void update(int i, int x){
            *(this->tree+i) = *(this->tree+i) + x;
            while(i <= size){
                i = i + this->lsb(i);
                *(this->tree+i) = *(this->tree+i) + x;
            }
        }

        void show(){
            for(int i=1; i<=this->size; i++){
                cout << *(tree+i) << endl;
            }
        }
};

int main(){
    int size = 10;
    int * arr = new int[size+1]{0, 2, 4, 7, -5, 3, 5, 5, 6, 9, -8};
    FenwickTree * ft1 = new FenwickTree(arr, size);
    
    // for(int i=1; i<=size; i++){
    //     cout << *(arr+i) << endl;
    // }
    cout << endl;
    ft1->show();
    cout << endl;
    cout <<ft1->query(5) << endl;
    cout << "10: " <<ft1->query(10) << endl;
    cout << "4: " <<ft1->query(4) << endl;
    cout  <<ft1->query(10, 5);
    ft1->update(2, 2);
    cout << endl;
    ft1->show();
    delete[] arr;
    delete ft1;
    return 0;
}
