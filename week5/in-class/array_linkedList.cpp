#include <iostream>
#include <stdexcept>
#include <chrono>
 
using namespace std;

class Node{
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

class  LinkedStack
{
private:
    int length;
public:
    Node *top;
    LinkedStack(){
        top = nullptr;
        this->length = 0;
    }

    void push(int data){
        Node *newNode = new Node(data);
        if (isEmpty()){
            top = newNode;
        }
        else
        {
            newNode->next = top;
            top = newNode; 
        }
        length++;
    }

    int pop(){
        if (isEmpty()){
            throw underflow_error("Stack is Empty");
        }
        else{
            Node *currentNode = top;
            top = top->next;
            length--;
            return currentNode->data();
        }
    }

    bool isEmpty(){
        if (top == nullptr){
            return true;
        }
        else{
            return false;
        }
    }

    int stackTop(){
        if (isEmpty()){
            throw underflow_error("Stack is Empty");
        }
        else{
            return this->top->data();
        }
    }

    void display(){
        Node *currentNode = this->top;
        while (currentNode != nullptr){
            cout << currentNode->data() << " " ;
            currentNode = currentNode->next;
        }
        cout << endl;
    }
};

int main(){
    try
    {
        LinkedStack stack;
        auto startingTime = chrono::high_resolution_clock::now();
        stack.push(8);
        stack.push(10);
        stack.push(10);
        stack.push(5);
        stack.push(11);
        stack.push(15);
        stack.push(23);
        stack.push(6);
        stack.push(18);
        stack.push(20);
        stack.push(17);
        stack.display();
        stack.pop();
        stack.pop();
        stack.pop();
        stack.pop();
        stack.pop();
        stack.display();
        stack.push(4);
        stack.push(30);
        stack.push(3);
        stack.push(1);
        stack.display();
        auto endingTime = chrono::high_resolution_clock::now();
        double totale_time = chrono::duration_cast<chrono::microseconds>(endingTime - startingTime).count();
        cout << totale_time << endl;
    }
    catch (exception& e){
        cerr << endl <<  "Exception: " << e.what() << endl;
    }
}
