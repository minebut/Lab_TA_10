// Lab_TA.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <forward_list>
using namespace std;
int main()
{
	
}

struct List
{
    int inf;
    List* link;
};

void addNode(List*& Head, List*& Tail) 
{
List* p = new List;
cout << "Enter value";
cin >> p->inf;
p->link = NULL;
if (Head == NULL)
{
	Head = p;
	Tail = p;
}
else
{
	Tail->link = p;
	Tail = p;
}