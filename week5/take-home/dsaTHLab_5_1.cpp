#include <iostream>

using namespace std;

class Node
{
private:
    int nodeData;
public:
    Node *next;
    Node(int data){
        this->nodeData = data;
        this->next = nullptr;
    }

    int data(){
        return nodeData;
    }
};

class LinkedList{
public:
    Node *head;
    Node *root;
    LinkedList(){
        this->head = nullptr;
    }

    void push(int data){
        if (this->head == nullptr) {
            this->head = new Node(data);
        } else {
            Node *current = this->head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = new Node(data);
        }
    }
};

void reversePrint(Node* node){
    if (node == nullptr){
        return;
    }
    reversePrint(node->next);
    cout << node->data() << endl;
}

int main(){
    int listCount;
    cin >> listCount;
    LinkedList *arr[listCount];
    for (int i = 0; i < listCount; i++){
        LinkedList *list = new LinkedList();
        arr[i] = list;
        int listLength;
        cin >> listLength;
        for (int j = 0; j < listLength; j++){
            int num;
            cin >> num;
            arr[i]->push(num);
        }
    }

    for (int k = 0; k < listCount; k++){
        reversePrint(arr[k]->head);
    }
}