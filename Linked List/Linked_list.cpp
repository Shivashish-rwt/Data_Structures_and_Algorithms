#include<bits/stdc++.h>
using namespace std;

struct Node {
	int value;
	Node *next;
};

void insertNodeAtFront(Node **head, int value) {
	Node *temp = new Node();
	temp->value = value;
	temp->next = *head;
	*head = temp;
}

void insertNodeAtEnd(Node **head, int value) {
	Node *newnode = new Node();
	newnode->value = value;
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

void insertAfter(Node *prev, int value) {
	if (prev == NULL) {
		cout << "Previous can't be null" << endl;
		return;
	}
	Node *temp = new Node();
	temp->value = value;
	temp->next = prev->next;
	prev->next = temp;
}

void printList(Node *temp) {
	while (temp != NULL) {
		cout << temp->value << " ";
		temp = temp->next;
	}
}

void deleteNode(Node** headRef, int key) {
	Node* temp = *headRef;
	Node* prev;

	// If head is the node that has to be deleted
	if (temp != NULL && temp->value == key) {
		*headRef = temp->next;
		delete temp;
		return;
	}

	while (temp != NULL && temp->value != key) {
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
