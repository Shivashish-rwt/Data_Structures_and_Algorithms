#include<bits/stdc++.h>
using namespace std;

struct Node {
	int val;
	Node *next;
	Node(int x) : val(x), next(NULL) {}
};

void printList(Node *temp) {
	while (temp != NULL) {
		cout << temp->val << " ";
		temp = temp->next;
	}
}

void insertNodeAtFront(Node **head, int val) {
	Node *temp = new Node(val);
	temp->next = *head;
	*head = temp;
}

void insertNodeAtEnd(Node **head, int val) {
	Node *newnode = new Node(val);
	newnode->next = NULL;

	if (*head == NULL) {
		*head = newnode;
		return;
	}
	Node *temp = *head;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = newnode;
}

void insertAfter(Node *prev, int val) {
	if (prev == NULL) {
		cout << "Previous can't be null" << endl;
		return;
	}
	Node *temp = new Node(val);
	temp->next = prev->next;
	prev->next = temp;
}

void deleteNode(Node** headRef, int key) {
	Node* temp = *headRef;
	Node* prev;

	// If head is the node that has to be deleted
	if (temp != NULL && temp->val == key) {
		*headRef = temp->next;
		delete temp;
		return;
	}

	while (temp != NULL && temp->val != key) {
		prev = temp;
		temp = temp->next;
	}

	if (temp == NULL) {
		cout << "Node with given key not found";
		return;
	}

	prev->next = temp->next;
	delete temp;
}

int main() {

	Node *head = NULL;

	insertNodeAtFront(&head, 1);
	insertNodeAtEnd(&head, 2);
	insertNodeAtEnd(&head, 3);
	insertNodeAtEnd(&head, 4);
	deleteNode(&head, 3);

	printList(head);
}
