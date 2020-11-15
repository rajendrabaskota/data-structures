#include <iostream>
#include <string>
#include <iterator>
#include <vector>
using namespace std;

// void func(int (&a)[5]){
//     *(&a[0]+1) = 12;
// }

// int main(){
//     int a[5] = {5, 4, 3};
//     int (&b)[5] = a;
//     for(int i=0; i<5; i++){
//         cout << a[i] << endl;
//     }
//     for(int i=0; i<5; i++){
//         b[i] = i;
//     }
//     for(int i=0; i<5; i++){
//         cout << a[i] << endl;
//     }
//     cout << a << endl;
//     return 0;
// }

// int main(){
//     for ( int x = 0; x < 128; x++ ) {
//     cout<< x <<". "<< (char)x <<" "; 
//     //Note the use of the int version of x to 
//     // output a number and the use of (char) to 
//     // typecast the x into a character 	
//     // which outputs the ASCII character that 
//     // corresponds to the current number
//   }
//   cout << endl << endl;
//   char a='(';
//   char b=')';
//   char c='[';
//   char d=']';
  
//   cout << (int)a << endl;
//   cout << (int)b << endl;
//   cout << (int)c << endl;
//   cout << (int)d << endl;

//   return 0;
// }

// int * func(){
//     static int arr[5];
//     static int count = 0;
//     while(count < 5){
//         arr[count] = count +1;
//         count++;
//     }
//     return arr;
// }

// int main(){
//     int * p = func();
//     for(int i=0; i<5; i++){
//         cout << *(p+i) << endl;
//     }
//     return 0;
// }

// vector<int> func(){
//     static vector<int> v1;
//     for(int i=0; i<5; i++){
//         v1.push_back(i+1);
//     }
//     return v1;
// }

// int main(){
//     vector<int> v1 = func();
//     for(int i=0; i<v1.size(); i++){
//         cout << v1.at(i) << endl;
//     }
// }

// int main(){
//     list<int>list1;
//     for(int i=0; i<5; i++){
//         list1.push_back(i+2);
//     }

//     list<int> :: iterator it;
//     for(it=list1.begin(); it!=list1.end(); it++){
//         cout << *it << endl;
//     }
    
//     cout << endl;

//     for(it=list1.begin(); it!=list1.end(); it++){
//         cout << &(*it) << endl;
//     }

//     int a{};
//     int abc{};
//     cout << a << ", " << abc;

//     list1.push_back(10);

//     cout << endl;

//     for(it=list1.begin(); it!=list1.end(); it++){
//         cout << (&(*it)) << endl;
//     }
//     return 0;
// }

// class LinkedList{
//     public:
//         int size;
//         LinkedList();
//         void getAddress();
// };

// LinkedList::LinkedList(){
//     this->size = 5555;
// }

// void LinkedList::getAddress(){
//     cout << this << endl;
// }


int main(){
    string word = "camel";
    for(int i=word.length()-1; i>=0; i--){
        for(int j=i; j<=word.length()-1; j++){
            cout << word[j];
        }
        cout << endl;
    }
    cout << endl;
    int* a = new int;
    string word2 = "gita";
    cout << word2.substr(0, word2.length());
    return 0;
}
