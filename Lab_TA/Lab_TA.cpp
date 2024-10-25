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

Node* insertAtBeginning(Node* head, int value) { // ��������� �������� � ������ ������
	Node* newNode = new Node(value); 
	newNode->next = head;
	head = newNode;
	return head;
}
Node* insertAtEnd(Node* head, int value) { // ��������� �������� � ����� ������
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

Node* deleteAtPosition(Node* head, int position) { // ��������� k-�� ��������
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

Node* removeFirstNode(Node* head) { // ��������� ������� �������� � ������
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

	head = insertAtBeginning(head, 2);//���������� ������
	head = insertAtEnd(head, 3);
	head = insertAtEnd(head, 4);
	cout << "����������� ������ ";
	traverseLinkedList(head);
	


	head = insertAtBeginning(head, 1);
	cout << "������ ���� ��������� ������� �������� ";
	traverseLinkedList(head);

	head = insertAtEnd(head, 5);
	cout << "������ ���� ��������� ��������� ��������  ";
	traverseLinkedList(head);

	int k;
	cout << "������ � ������� ��� ��������� --> ";
	cin >> k;
	head = deleteAtPosition(head, k);
	cout << "������ ���� ��������� " << k << " �������� " ;
	traverseLinkedList(head);

	head = removeFirstNode(head);
	cout << "������ ���� ��������� ������� ��������: ";
	traverseLinkedList(head);

	head = removeLastNode(head);
	cout << "������ ���� ��������� �������� ��������: ";
	traverseLinkedList(head);

	return 0;
}
