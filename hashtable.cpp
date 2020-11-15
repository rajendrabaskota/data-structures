#include <iostream>
using namespace std;


// ................SEPARATE CHAINING......

// class Node{
//     public:
//         string name;
//         int age;
//         Node * prev;
//         Node * next;
//         Node(string name, int age);

// };

// Node::Node(string name, int age){
//     this->name = name;
//     this->age = age;
//     this->prev = NULL;
//     this->next = NULL;
// }


// class LinkedList{
//     public:
//         int size;
//         Node * head;
//         Node * tail;
//         LinkedList();
//         void addElement(string name, int age);
// };

// LinkedList::LinkedList(){
//     this->head = NULL;
//     this->tail = NULL;
//     this->size = 10;
// }

// void LinkedList::addElement(string name, int age){
//     Node * newNode = new Node(name, age);
//     if(this->size==0){
//         head = newNode;
//         tail = newNode;
//     }else{
//         tail->next = newNode;
//         newNode->prev = tail;
//         this->tail = newNode;
//     }
//     this->size++;
// }


// class HashTable{
//     private:
//         int size;
//         LinkedList * slots = new LinkedList[1];
//     public:
//         HashTable(int size);
//         void getAddress();
//         void addElement(int index, string name, int age);
// };

// HashTable::HashTable(int size){
//     this->size = size;
//     LinkedList * newSlots = new LinkedList[size];
//     delete[] slots;
//     slots = newSlots;

//     for(int i=0; i<size; i++){
//         cout << slots[i].size << endl;
//     }
// }

// void HashTable::getAddress(){
//     for(int i=0; i<(this->size); i++){
//         cout << slots[i].size << endl;
//     }
// }

// void HashTable::addElement(int index, string name, int age){
//     cout << "entered" << endl;
//     (slots+index)->addElement(name, age);
//     cout << "exited" << endl;
// }


// int main(){
//     HashTable h1(5);
//     cout << "addresses" << endl;
//      h1.getAddress();
//     // h1.addElement(0, "rajendra", 20);
//     return 0;
// }






// ......OPEN ADDRESSING USING QUADRATIC PROBING ........

class HashTable{
    private:
        int capacity = 8;
        int presentElements;
        float maxLoadFactor;
        int threshold;
        int * key = new int[capacity]{};
        string * value = new string[capacity];

    public:
        HashTable(){
            this->presentElements = 0;
            this->maxLoadFactor = 0.4;
            this->threshold = this->capacity * this->maxLoadFactor;
        }

        int hashFunction(int key){
            return key % this->capacity;
        }

        inline int probeFunction(int probe) {return (probe*probe + probe)/2;}

        void resizeTable(){
            this->capacity = this->capacity * 2;
            this->threshold = this->capacity * this->maxLoadFactor;
            int * newKey = new int[this->capacity]{};
            string * newValue = new string[this->capacity];
            for(int i=0; i<this->capacity/2; i++){
                if(value[i].length() && value[i] != "-1"){
                    int hashValue = this->hashFunction(key[i]);
                    int probe = 1;
                    while(newValue[hashValue].length()){
                        hashValue = (hashValue + probeFunction(probe)) % this->capacity;
                        probe++;
                    }
                    *(newKey+hashValue) = key[i];
                    *(newValue+hashValue) = value[i];
                }
            }

            delete[] key;
            delete[] value;
            key = newKey;
            value = newValue;
        }

        void search(int id){
            int hashValue = this->hashFunction(id);
            int probe = 1;
            while(key[hashValue] != id && key[hashValue] != 0){
                hashValue = (hashValue + probeFunction(probe)) % this->capacity;
            }
            if(key[hashValue] == 0){
                cout << "Element Not Found!!!" << endl;
            }else{
                cout << "Key: " << key[hashValue] << endl;
                cout << "Value: " << value[hashValue] << endl;
            }
        }

        void remove(int id){
            int hashValue = this->hashFunction(id);
            int probe = 1;
            while(key[hashValue] != id && key[hashValue] != 0){
                hashValue = (hashValue + probeFunction(probe)) % this->capacity;
            }
            if(key[hashValue] == 0){
                cout << "Element Not Found!!!" << endl;
            }else{
                key[hashValue] = -1;
                value[hashValue] = "-1";
                this->presentElements--;
            }
        }

        void insert(int id, string name){
            if(this->presentElements == this->threshold){
                resizeTable();
            }
            int hashValue = this->hashFunction(id);
            int probe = 1;
            while(value[hashValue].length() && value[hashValue] != "-1"){
                hashValue = (hashValue + probeFunction(probe)) % this->capacity;
                probe++;
            }
            *(key+hashValue) = id;
            *(value+hashValue) = name;
            this->presentElements++;
        }

        int totalElements(){
            return this->presentElements;
        }

};

int main(){
    HashTable * h1 = new HashTable;
    h1->insert(12, "rajendra");
    h1->insert(5, "deven");
    h1->insert(4, "dip");
    h1->insert(7, "gita");
    h1->search(7);
    h1->search(10);
    h1->remove(15);
    cout << "Total: " << h1->totalElements() << endl;
    return 0;
}