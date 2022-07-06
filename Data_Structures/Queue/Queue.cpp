#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int value;
    Node *next;
    Node(int data) : value(data), next(NULL) { }
};

class Queue
{
public:

    Node *front, *back;
    Queue() {
        front = NULL;
        back = NULL;
    }

    void push(int data) {
        Node *temp = new Node(data);
        if (front == NULL) {
            front = back = temp;    
            return;
        }
        back->next = temp;
        back = temp;
    }

    void pop() {
        if (front == NULL) {
            cout << "Queue Underflow" << '\n';
            return;
        }
        Node *temp = front;
        front = front->next;
        delete temp;
    }

    int peek() {
        if (front == NULL) {
            cout << "Queue Overflow" << '\n';
            return INT_MIN;
        }
        return front->value;
    }

    bool empty() {
        return !front;
    }
};

int main(int argc, char const *argv[])
{
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    cout << q.peek() << '\n';

    q.pop();
    q.pop();
    q.pop();

    cout << q.peek() << '\n';

    cout << q.empty() << '\n';

    while (!q.empty()) {
        q.pop();
    }

    cout << q.empty() << '\n';
}
