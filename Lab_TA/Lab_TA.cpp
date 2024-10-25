// Lab_TA.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <forward_list>
using namespace std;
int main()
{
	//traverseLinkedList();
}
struct Node 
{
	int data;
	Node* next;
	Node(int date)
	{
		this->data = data;
		this->next = nullptr;
	}
};
void traverseLinkedList(Node* head) 
{
	Node* current = head;

	while (current != nullptr) 
	{
		cout << current->data << " ";
		current = current->next;
	}
	cout << std::endl;
}

Node* insertAtBeginning(Node* head, int value)//додавання елементу до голови списку
{
	Node* newNode = new Node(value);
	newNode->next = head;
	head = newNode;
	return head;
}

Node* insertAtEnd(Node* head, int value) //додаванняелементу до хвоста списку
{
	Node* newNode = new Node(value);
	if (head == nullptr) 
	{
		return newNode;
	}
	Node* current = head;
	while (current->next !=nullptr)
	{
		current = current->next;
		return head;
	}
	

}

Node* deleteAtPosition(Node* head, int position)
{
	if (head == nullptr || position < 1)
	{
		return head;
	}
	
	if (position == 1 )
	{
		Node* temp = head;
		head = head->next;
		delete temp;
		return head;

		Node* current = head;
		for (int i = 1; i < position - 1 && current != nullptr; i++) 
		{
			current = current->next;
		}
		if (current==NULL || current-> next == nullptr)
		{
			return;
		}

	}
}

Node* removeFirstNode(Node* head) //видалення першого елементу в списку
{
	if (head == nullptr)
		return nullptr;
	Node* temp = head;
	head = head->next;
	delete temp;
	return head;
}
