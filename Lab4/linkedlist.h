#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template <typename ItemType>

class LinkedList {

private: 

	struct Node {
		ItemType item;
		Node* next;
		Node* previous;
	};


	Node* root;
	Node* tail;
	int size;

public:
	LinkedList() {
			root= NULL;
		tail=NULL;
		size=0;
	}
	void insert(int index, const ItemType& item) {
		Node* n =  new Node;
		n->item=item; 
		if(root==NULL)
		{
			root=n;
			tail=n;
			n->next= NULL;
			n->previous=NULL;
		}
		else if(index==0)
		{
			n->next=root;
			root->previous=n;
			n->previous=NULL;
			root=n; 
		}
		else if(index==size)
		{
			n->next=NULL;
			n->previous=tail;
			tail->next=n;
			tail=n;
		}
		else
		{
			Node* temp=find_index(index);
			n->next=temp;
			n->previous=temp->previous;
			temp->previous->next=n;
			temp->previous=n;


		}
		size++;
	}

	ItemType remove(int index) {
		ItemType item; 
		if(index<=size-1)
		{
			Node* n=find_index(index);
			if(size==1)
			{
				item=n->item;
				root=NULL;
				tail=NULL;
			}
			else if(index==size-1)
			{
				item=n->item;
				tail=n->previous;
				n->previous->next=NULL;
				n->previous=NULL;
			}
			else if(index==0)
			{
				item=n->item;
				root=n->next;
				n->next=NULL;
				root->previous=NULL;
			}
			else
			{
				item=n->item;
				n->next->previous=n->previous;
				n->previous->next=n->next;
			}
			delete n;
			size--;
		}
		return item;

	}

//  returns a print out of node #: item 

	string print() 
	{
		Node* n=root;
		stringstream line;
		for(int i=0;i<size;i++)
		{
			line <<"node " << i << ": " << n->item<<endl;
			n=n->next;
		}
		return line.str();
	}

	void clear()
	{
		Node* n=root;
		while(n!=NULL)
		{
			root=n->next;
			delete n;
			n=root;
		}	
		size=0;	
	}

	int find_item(const ItemType& item) {
		Node* temp =root;
		int index= 0;
		while (temp != NULL) 
		{
			if (temp->item == item)
			{
				return index; 
			}
			else 
			{
				temp=temp->next;
			}
			index++;
		}
		return -1;

	}
	Node* find_index(int index)
	{
		Node* temp; 
		int split = size/2;
		if(index>split)
		{
			temp=tail; 
			for(int i=size-1; i>index;i--)
			{
				temp=temp->previous;
			}
			return temp;
		}
		else
		{
			temp=root;
			for(int i=0; i<index;i++)
			{
				temp=temp->next;
			}
			return temp;
		}
	}
~LinkedList()
{
	clear();
}
};


#endif












// each node contains:
// A pointer to the previous node.
// A pointer to the next node.
// The item stored in the node.
// The List
// The list is a double-linked list of nodes. At a minimum, a list should contain:

// A pointer to the first node on the list.
// A pointer to the last node on the list.
// A count of how many items are stored on the list. 


// clear remove all things from the linked list 

// insert (index item)
//  insert item at index, increment all other items proceding the item do not insert if index does not exist 

// remove (index)
// remove item at index, decrement all proceeding 
// finding nodes needs to be fast, you will need to split the list in half and search 

// find (item)
// find first occurance of item on list (returns find item index)

// print