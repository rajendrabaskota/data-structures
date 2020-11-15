#include <iostream>
#include <vector>

using namespace std;

class Node{
    public:
        int value;
        Node * parent;
        Node * left;
        Node * right;

        Node(){
            this->parent = NULL;
            this->left = NULL;
            this->right = NULL;
        }
};

class BST{
    private:
        int size=0;
        Node * head;

    public:
        void addElement(int element){
            Node * node = new Node;
            node->value = element;

            if(this->size == 0){
                this->head = node;
            }else{
                Node * current = this->head;
                while(current != NULL){
                    if(element <= current->value){
                        if(current->left){
                            current = current->left;
                        }else{
                            break;
                        }
                    }else{
                        if(current->right){
                            current = current->right;
                        }else{
                            break;
                        }
                    }
                }
                if(element <= current->value){
                    current->left = node;
                }else{
                    current->right = node;
                }
                node->parent = current;
            }
             
            this->size++;
        }

        void onlyOnePresent(Node * current){
            cout << "this only" << endl;
            Node * presentNode = current->left && !(current->right) ? current->left : current->right;
            Node * parentNode = current->parent;
            delete current;
            presentNode->parent = parentNode;
            if(presentNode->value <= parentNode->value){
                parentNode->left = presentNode;
            }else{
                parentNode->right = presentNode;
            }
        }

        void bothPresent(Node * root){
            cout << "both " << root->value << endl;
            Node * node = root->left;
            while(node->right != NULL){
                node = node->right;
            }

            cout << "node " << node->value << endl;
            root->value = node->value;
            if(!node->left && !node->right){
                if(node->value <= node->parent->value){
                    node->parent->left = NULL;
                }else{
                    node->parent->right = NULL;
                }
                delete node;
            }else if((node->left && !node->right) || (!node->left && node->right)){
                this->onlyOnePresent(node);
            }

        }

        void removeElement(int element){
            Node * current = this->head;
            while(current->value != element){
                if(element < current->value){
                    current = current->left;
                }else if(element > current->value){
                    current = current->right;
                }
            }
            if(!current->left && !current->right){
                if(current->value < current->parent->value){
                    current->parent->left = NULL;
                }else{
                    current->parent->right = NULL;
                }
                delete current;
                cout << "none" << endl;
            }else if((current->left && !current->right) || (!current->left && current->right)){
                this->onlyOnePresent(current);
            }else{
                this->bothPresent(current);
            }
            this->size--;

        }

        Node * forHead(){
            return this->head;
        }

        void inorderTraversal(Node * node){
            if(node == NULL){
                return;
            }
            inorderTraversal(node->left);
            cout << node->value << endl;
            inorderTraversal(node->right);
        }

        int showSize(){
            return this->size;
        }

        vector<int> levelTraversal(Node * node){
            static vector<int>v1;
            static vector<Node *>queue;
            if(queue.size()){
                v1.push_back(queue.at(0)->value);
                queue.erase(queue.begin()+0);
            }else{
                v1.push_back(node->value);
            }

            if(node->left != NULL){
                queue.push_back(node->left);
            }
            if(node->right != NULL){
                queue.push_back(node->right);
            }

            while(queue.size()){
                levelTraversal(queue.at(0));
            }

            return v1;
        }
};

int main(){
    BST * bst1 = new BST;
    int arr[9] = {7, 4, 5, 10, 8, 3, 15, 6, 2};
    for(int i=0; i<sizeof(arr)/sizeof(arr[0]); i++){
        bst1->addElement(arr[i]);
    }
    vector<int>allNodes;
    allNodes = bst1->levelTraversal(bst1->forHead());
    for(int i=0; i<allNodes.size(); i++){
        cout << allNodes.at(i) << endl;
    }
    cout << endl;
    bst1->inorderTraversal(bst1->forHead());
    bst1->removeElement(7);
    cout << "remaining " << bst1->showSize() << endl; 
    cout << endl;
    bst1->inorderTraversal(bst1->forHead());
    cout << endl;
    
    return 0;
}
