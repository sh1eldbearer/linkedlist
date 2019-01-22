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

	// Returns the key value stored in this node
	T GetNodeData()
	{
		return nodeData;
	}

	// Changes the key value to be stored in this node
	void SetNodeData(T dataToStore)
	{
		nodeData = dataToStore;
	}

	// Returns a pointer to the node immediately preceding this node in the linked list
	LinkedList_Node<T>* GetPrevNode()
	{
		return prevNode;
	}

	// Changes the pointer to the node immediately preceding this node in the linked list
	template <typename T> void SetPrevNode(LinkedList_Node<T>* nodePtr)
	{
		prevNode = nodePtr;
	}

	// Sets the pointer to the node immediately preceding this node in the linked list to nullptr
	void ClearPrevNode()
	{
		prevNode = nullptr;
	}

	// Returns a pointer to the node immediately following this node in the linked list
	LinkedList_Node<T>* GetNextNode()
	{
		return nextNode;
	}

	// Changes the pointer to the node immediately following this node in the linked list
	template <typename T> void SetNextNode(LinkedList_Node<T>* nodePtr)
	{
		nextNode = nodePtr;
	}

	// Sets the pointer to the node immediately following this node in the linked list to nullptr
	void ClearNextNode()
	{
		nextNode = nullptr;
	}
};
#endif // !LinkedList_Node_H