#include <iostream>

using namespace std;

// class Node{

//     public:
//         Node * prev;
//         Node * next;
//         int data;
// };

// class LinkedList{
//     private:
//         int size;
//         Node * head;
//         Node * tail;
//         int a;
//     public:
//         LinkedList(){
//             head = NULL;
//             tail = NULL;
//             size = 0;
//         }

//         void addElement(int num){
//             Node * newNode = new Node;
//             cout << &newNode << endl;
//             newNode->data = num;
//             if(size==0){
//                 head = newNode;
//                 tail = newNode;
//                 newNode->prev = NULL;
//                 newNode->next = NULL;
//             }else{
//                 tail->next = newNode;
//                 newNode->prev = tail;
//                 newNode->next = NULL;
//                 this->tail = newNode;
//             }
//             this->size++;
//         }

//         void removeElement(){
//             cout << "size= " << this->size << endl;
//             if(this->size == 0){
//                 cout << "List underloaded" << endl;
//                 return;
//             }else if(this->size == 1){
//                 this->head = NULL;
//                 this->tail = NULL;
//                 return;
//             }else{
//                 Node * second_element = head->next;
//                 second_element->prev = NULL;
//                 // head->next = NULL;
//                 delete head;
//                 this->head = second_element;
//             }
//             size--;
//         }

//         void displayNode(int index){
//             if(index >= this->size){
//                 cout << "Not Defined" << endl;
//                 return;
//             }
//             Node * requiredNode;
//             Node * reference;
//             reference = head;
//             for(int i=0; i<=index; i++){
//                 cout << reference << endl;
//                 requiredNode = reference;
//                 reference = reference->next;
//             }
//             cout << requiredNode->data << endl;
//         }
// };

// int main(){
//     LinkedList * linkedList = new LinkedList;
//     cout << "done 1" << endl;
//     linkedList->addElement(5);
//     cout << "done 2" << endl;
//     linkedList->addElement(55);
//     cout << "done 3" << endl;
//     linkedList->addElement(555);
//     cout << "done 4" << endl;
//     linkedList->addElement(5555);
//     cout << "done 5" << endl;
//     linkedList->addElement(55555);
//     cout << "done 6" << endl;
//     linkedList->displayNode(4);
//     linkedList->removeElement();
//     linkedList->displayNode(0);
//     cout << "done";
//     return 0;
// }



int main(){
    int * arr = new int[5]{0};
    for(int i=0; i<5; i++){
        cout << arr[i] << endl;
    }
    return 0;
}
