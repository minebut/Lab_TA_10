// Lab_TA.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>
using namespace std;

struct Node {
	int data;
	Node* next;
	Node(int data) {
		this->data = data;
		this->next = nullptr;
	}
};

void traverseLinkedList(Node* head) {
	Node* current = head;
	while (current != nullptr) {
		cout << current->data << " ";
		current = current->next;
	}
	cout << endl;
}

Node* insertAtBeginning(Node* head, int value) { // додавання елемента в голову списку
	Node* newNode = new Node(value); 
	newNode->next = head;
	head = newNode;
	return head;
}
Node* insertAtEnd(Node* head, int value) { // додавання елемента в кінець списку
	Node* newNode = new Node(value);
	if (head == nullptr) {
		return newNode;
	}
	Node* current = head;
	while (current->next != nullptr) {
		current = current->next;
	}
	current->next = newNode;
	return head;
}

Node* deleteAtPosition(Node* head, int position) { // видалення k-го елемента
	if (head == nullptr || position < 1) {
		return head;
	}
	if (position == 1) {
		Node* temp = head;
		head = head->next;
		delete temp;
		return head;
	}
	Node* current = head;
	for (int i = 1; i < position - 1 && current->next != nullptr; i++) {
		current = current->next;
	}
	if (current->next != nullptr) {
		Node* temp = current->next;
		current->next = temp->next;
		delete temp;
	}
	return head;
}

Node* removeFirstNode(Node* head) { // видалення першого елемента в списку
	if (head == nullptr)
		return nullptr;
	Node* temp = head;
	head = head->next;
	delete temp;
	return head;
}

Node* removeLastNode(Node* head) {

	if (head->next == nullptr) {
		delete head;
		return nullptr;
	}

	Node* current = head;
	while (current->next->next != nullptr) {
		current = current->next;
	}

	delete current->next;
	current->next = nullptr;
	return head;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Node* head = nullptr;

	head = insertAtBeginning(head, 2);//початковий список
	head = insertAtEnd(head, 3);
	head = insertAtEnd(head, 4);
	cout << "оригінальний список ";
	traverseLinkedList(head);
	


	head = insertAtBeginning(head, 1);
	cout << "список після додавання першого елемента ";
	traverseLinkedList(head);

	head = insertAtEnd(head, 5);
	cout << "список після додавання останього елемента  ";
	traverseLinkedList(head);

	int k;
	cout << "введіть К елемент для видалення --> ";
	cin >> k;
	head = deleteAtPosition(head, k);
	cout << "список після видалення " << k << " елементу " ;
	traverseLinkedList(head);

	head = removeFirstNode(head);
	cout << "список після видалення першого елемента: ";
	traverseLinkedList(head);

	head = removeLastNode(head);
	cout << "список після видалення останьго елемента: ";
	traverseLinkedList(head);

	return 0;
}
