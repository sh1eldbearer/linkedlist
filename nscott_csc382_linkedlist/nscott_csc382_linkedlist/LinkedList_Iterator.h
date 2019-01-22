#ifndef LinkedList_Iterator_H
#define LinkedList_Iterator_H

#include "LinkedList_Node.h"

template<class T> class LinkedList_Iterator
{
private:
	LinkedList_Node<T>* currentNode;
public:
	LinkedList_Iterator(LinkedList_Node<T>* startNode = nullptr) :
		currentNode(startNode) { } // Default constructor
	~LinkedList_Iterator() {} // Default destructor	

	// Sets the node this iterator is pointing to
	void SetCurrentNode(LinkedList_Node<T>* targetNode)
	{
		currentNode = targetNode;
	}

	// Returns a pointer to the current node the iterator is referencing
	LinkedList_Node<T>* GetCurrentNode() 
	{
		return currentNode;
	}

	// Returns the key value stored in the current node the iterator is referencing
	T GetNodeData() 
	{
		return currentNode->GetNodeData(); 
	}

	// Attempts to move to the previous node in the linked list
	LinkedList_Node<T>* IterateBack() 
	{
		// Returns a null value if there is no previous node (current node is the head)
		if (currentNode == nullptr)
		{
			return nullptr;
		}
		// Otherwise, iterates back to the previous node and returns it
		else
		{
			currentNode = currentNode->GetPrevNode();
			return currentNode;
		}
	}

	// Attempts to move to the next node in the linked list
	LinkedList_Node<T>* IterateFwd() 
	{
		// Returns a null value if there is no next node (current node is the tail)
		if (currentNode == nullptr)
		{
			return nullptr;
		}
		// Otherwise, iterates forward to the next node and returns it
		else
		{
			currentNode = currentNode->GetNextNode();
			return currentNode;
		}
	}
};

#endif // !LinkedList_Iterator_H

