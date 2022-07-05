#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int value;
    Node *next;
    Node(int data) : value(data), next(NULL) { }
};

struct Stack
{
    Node *top;

    Stack() {
        top = NULL;
    }

    void push(int data)
    {
        Node *temp = new Node(data);
        temp->next = top;
        top = temp;
    }

    bool isEmpty()
    {
        return (top == NULL);
    }

    int peek()
    {
        if (isEmpty()) {
            exit(1);
        } else {
            return top->value;
        }
    }

    void pop()
    {
        if (isEmpty()) {
            cout << "Stack Underflow";
            exit(1);
        } else {
            Node *temp = top;
            top = top->next;
            delete temp;
        }
    }

};

int main(int argc, char const *argv[])
{
    Stack st;
    st.push(10);
    st.push(11);
    st.push(12);

    cout << st.peek() << '\n';

    st.pop();
    st.pop();

    cout << st.peek() << '\n';

    st.push(13);
    st.push(14);

    if (st.isEmpty()) {
        cout << "Empty" << '\n';
    } else {
        cout << "Not Empty" << '\n';
    }

    st.pop();

    while (!st.isEmpty()) {
        cout << st.peek() << '\n';
        st.pop();
    }

}
