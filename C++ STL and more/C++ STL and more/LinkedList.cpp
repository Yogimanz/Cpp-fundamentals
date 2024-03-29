#include "pch.h"
#include "LinkedList.h"
#include <iostream>
#include <cstdlib>

LinkedList::LinkedList()
{
	head = NULL;
}

void LinkedList::AddNode(int value)
{
	struct node* newNode = new node();
	//newNode will be the last element inside the list so it should point to null
	newNode->next = NULL;
	newNode->data = value;
	//check if head exists and if so go to the end of the list then add a node
	if (head != NULL)
	{
		struct node* current = head;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = newNode;
	}
	else
		// head doesnt exist so new elements becomes the first node and head points to it
	{
		head = newNode;
	}
}

void LinkedList::AddNodeAT(int value, int index)
{
	struct node* newNode = new node();
	newNode->data = value;
	if (index <= 0)
		//invalid index inserted, adding element to the start of the list
	{
		AddElementAtFront(value);
	}
	else
	{
		struct node* current = head;
		struct node* trailing= head;
		int i = 0;
		for ( ;i < index; i++)
		{
			if (current != NULL) {
				trailing = current;
				current = current->next;
			}
				
			else
			{
				std::cout << "Index " <<index<< " out of range, adding element to the end of the List." << std::endl;
				AddNode(value);
				break;
			}
				
		}
		if (i == index)
		{
			std::cout << "Sucessfully added the element at position: " << index << std::endl;
			newNode->next = current;
			trailing->next = newNode;
		}
	}
}

void LinkedList::AddElementAtFront(int value)
{
	//New node we are adding is going to  be added to the start of the list 
	struct node* newNode = new node();
	newNode->data = value;
	newNode->next = head;
	head = newNode;
	
}


void LinkedList::DeleteElement(int value)
{
	struct node* current = head;
	struct node* previous = NULL;
	while (current != NULL && current->data != value)
	{
		previous = current;
		current = current->next;
	}

	if (current != NULL)
	{

		if (current == head)
		{
			head = head->next;
			
		}
		else
		previous->next = current->next;
		delete current;
	}

}

void LinkedList::DeleteElementAt(int index)
{
}

void LinkedList::ReverseList()
{
	struct node* current = head;
	struct node* previous = NULL;
	struct node* next = NULL;
	while (current != NULL)
	{
		//move next ahead of current
		next = current->next;	
		//point current to previous, this is the place where elements point in the other direction
		current->next = previous;
		//advance previous to current
		previous = current;
		//advance current to next
		current = next;
	}
	//at the end make head point to previous of current which will be the last element of old List
	//or first elemenent of new reversed list
	head = previous;
}

void LinkedList::PrintList()
{
	// go through the list and print the current element
	struct node* current = head;
	while (current != NULL)
	{
		std::cout << current->data << " ";
		current = current->next;
	}
	std::cout << std::endl;
}


LinkedList::~LinkedList()
{
	struct node* current = head;
	struct node* temp;
	while (current->next != NULL)
	{
		temp = current->next;
		delete current;
		current = temp;
	}
	std::cout << "List is destroyed";
}
