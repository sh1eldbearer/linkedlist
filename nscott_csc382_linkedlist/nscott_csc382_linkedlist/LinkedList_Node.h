#ifndef LinkedList_Node_H
#define LinkedList_Node_H

#include <iostream>

template <typename T> class LinkedList_Node
{
private:
	T nodeData = NULL; // The data being held by the this node
	LinkedList_Node<T>* prevNode = nullptr; // A pointer to the previous node in the linked list
	LinkedList_Node<T>* nextNode = nullptr; // A pointer to the next node in the linked list
public:
	LinkedList_Node() {} // Default constructor
	~LinkedList_Node() {} // Default destructor

	T GetNodeData() // Getter for the node's stored data
	{
		return nodeData;
	}

	// Seteter for the node's stored data
	void SetNodeData(T dataToStore)
	{
		nodeData = dataToStore;
	}

	// Getter for the previous node in the linked list
	LinkedList_Node<T>* GetPrevNode()
	{
		return prevNode;
	}

	// Setter for the previous node in the linked list
	template <typename T> void SetPrevNode(LinkedList_Node<T>* nodePtr)
	{
		prevNode = nodePtr;
	}

	// Sets the previous node to null
	void ClearPrevNode()
	{
		prevNode = nullptr;
	}

	// Getter for the next node in the linked list
	LinkedList_Node<T>* GetNextNode()
	{
		return nextNode;
	}

	// Setter for the previous node in the linked list
	template <typename T> void SetNextNode(LinkedList_Node<T>* nodePtr)
	{
		nextNode = nodePtr;
	}

	// Sets the next node to null
	void ClearNextNode()
	{
		nextNode = nullptr;
	}
};
#endif // !LinkedList_Node_H