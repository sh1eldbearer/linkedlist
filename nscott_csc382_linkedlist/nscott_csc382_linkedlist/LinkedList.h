#ifndef LinkedList_H
#define LinkedList_H

#include <iostream>

#include "LinkedList_Iterator.h"
#include "LinkedList_Node.h"

template <typename T> class LinkedList
{
private:
	int nodeCount = 0; // Stores a count of the number of nodes in the list
	LinkedList_Node<T>* headNode = nullptr; // Stores a pointer to the first node in the list
	LinkedList_Node<T>* tailNode = nullptr; // Stores a pointer to the last node in the list
	
	// Decreases the count of the number of nodes stored in the linked list
	void DecreaseNodeCount()
	{
		nodeCount--;
	}
	
	// Increases the count of the number of nodes stored in the linked list
	void IncreaseNodeCount()
	{
		nodeCount++;
	}

	// Outputs the key values and addresses of the current node and its adjacent nodes
	void PrintDetails(LinkedList_Node<T>* targetNode)
	{
		// Shows node's value
		std::cout << std::endl << targetNode->GetNodeData() << " Prev: ";
		// Shows previous node's value and address
		if (targetNode->GetPrevNode() != nullptr)
		{
			std::cout << targetNode->GetPrevNode()->GetNodeData();
		}
		else
		{
			std::cout << "NULL";
		}
		std::cout << " (" << targetNode->GetPrevNode() << ") Next: ";
		// Shows next node's value and address
		if (targetNode->GetNextNode() != nullptr)
		{
			std::cout << targetNode->GetNextNode()->GetNodeData();
		}
		else
		{
			std::cout << "NULL";
		}
		std::cout << " (" << targetNode->GetNextNode() << ")";
	}
public:
	LinkedList() {} // Default constructor
	~LinkedList() {} // Default destructor

	 // Creates a new node, and inserts it at the end the linked list
	void Insert(T newData, bool verbose = true)
	{
		// Creates a new node
		LinkedList_Node<T>* newNode = new LinkedList_Node<T>();

		// Sets the data being stored in the new node
		newNode->SetNodeData(newData);
		IncreaseNodeCount();

		// If this is the first node, sets the new node as the head of the list
		if (headNode == nullptr && tailNode == nullptr)
		{
			// Sets the new node as the head
			headNode = newNode;
		}
		// If this is not the first node, adds the new node to the end of the list
		else
		{
			// New node's previous node is the old tail node
			newNode->SetPrevNode(tailNode);
			// Old tail node's next node is the new node
			tailNode->SetNextNode(newNode);
		}
		// Sets the new node as the new tail node
		tailNode = newNode;
		if (verbose)
		{
			std::cout << "Successfully stored " << newNode->GetNodeData()
				<< " as node " << (GetNodeCount() - 1);
			std::cout << std::endl;
		}
	}

	// Finds the first instance of a key value in the linked list
	LinkedList_Node<T>* Find(T dataToFind, bool suppressMsg = false)
	{
		LinkedList_Iterator<T> listIterator(headNode); // Iterator

		// Loops through the list until a matching value is found
		for (listIterator; listIterator.GetCurrentNode() != nullptr; listIterator.IterateFwd())
		{
			if (listIterator.GetNodeData() == dataToFind)
			{
				if (!suppressMsg)
				{
					std::cout << "Value " << dataToFind << " found at " << 
						listIterator.GetCurrentNode() << std::endl;
				}
				return listIterator.GetCurrentNode();
			}
		}
		// If no value is found, returns a nullptr
		if (!suppressMsg)
		{
			std::cout << "Value not found in list." << std::endl;
		}
		return nullptr;
	}
	
	// Deletes a node from the linked list
	void Delete(LinkedList_Node<T>* delNode)
	{
		// Stops the function if a nullptr is passed in
		if (delNode == nullptr)
		{
			std::cout << "Value not found in list." << std::endl;
			return;
		}
		// Node is only node in the list
		else if (delNode == headNode && delNode == tailNode)
		{
			headNode = nullptr;
			tailNode = nullptr;
		}
		// Node is the head node
		else if (delNode == headNode && delNode != tailNode)
		{
			headNode = delNode->GetNextNode();
			headNode->ClearPrevNode();
		}
		// Node is the tail node
		else if (delNode != headNode && delNode == tailNode)
		{
			tailNode = delNode->GetPrevNode();
			tailNode->ClearNextNode();
		}
		// Node is somewhere in the middle of the list
		else
		{
			delNode->GetNextNode()->SetPrevNode(delNode->GetPrevNode());
			delNode->GetPrevNode()->SetNextNode(delNode->GetNextNode());
		}
		DecreaseNodeCount();
		std::cout << "Value " << delNode->GetNodeData() << " deleted from the list." << 
			std::endl;
		// Deletes the node
		delete delNode;

	}

	// Outputs the key values of each node to the console
	void PrintList(bool reverse = false, bool detailed = true) // Prints the values stored in the list
	{
		// As long as there is at least one node in the list, prints the list
		if (!IsEmpty())
		{
			// Prints the list from tail to head 
			if (reverse)
			{
				LinkedList_Iterator<T> listIterator(tailNode); // Iterator
				std::cout << "Current list contents (in reverse order): ";

				// Iterates through the list and outputs the contents of each node
				for (listIterator; listIterator.GetCurrentNode() != nullptr; listIterator.IterateBack())
				{
					// Prints out a detailed message about the node
					if (detailed)
					{
						PrintDetails(listIterator.GetCurrentNode());
					}
					// Simply shows node's value
					else
					{
						std::cout << listIterator.GetNodeData() << " ";
					}
				}
				std::cout << std::endl;
			}
			// Prints the list from head to tail
			else
			{
				LinkedList_Iterator<T> listIterator(headNode); // Iterator
				std::cout << "Current list contents: ";

				// Iterates through the list and outputs the contents of each node
				for (listIterator; listIterator.GetCurrentNode() != nullptr; listIterator.IterateFwd())
				{
					// Prints out a detailed message about the node
					if (detailed)
					{
						PrintDetails(listIterator.GetCurrentNode());
					}
					// Simply shows node's value
					else
					{
						std::cout << listIterator.GetNodeData() << " ";
					}
				}
				std::cout << std::endl;
			}
		}
		// The list is empty
		else
		{
			// Do nothing
		}
	}
	
	// Returns the smallest value stored in the nodes contained in the linked list
	T Minimum()
	{
		if (!IsEmpty())
		{
			LinkedList_Iterator<T> listIterator(headNode); // Iterator
			// Stores the lowest value and initializes it to the value of the head node
			T minValue = listIterator.GetNodeData();

			// Iterates through the list, looking for the lowest value
			for (listIterator; listIterator.GetCurrentNode() != nullptr; listIterator.IterateFwd())
			{
				// The current value is lower than the previous minimum
				if (listIterator.GetNodeData() < minValue)
				{
					// So it becomes the new low value
					minValue = listIterator.GetNodeData();
				}
			}

			// Returns the lowest value
			return minValue;
		}
		else
		{
			return NULL;
		}
	}

	// Returns the largest value stored in the nodes contained in the linked list
	T Maximum()
	{
		if (!IsEmpty())
		{
			LinkedList_Iterator<T> listIterator(headNode); // Iterator
			// Stores the highest value and initializes it to the value of the head node
			T maxValue = listIterator.GetNodeData();

			// Iterates through the list, looking for the highest value
			for (listIterator; listIterator.GetCurrentNode() != nullptr; listIterator.IterateFwd())
			{
				// The current value is higher than the previous minimum
				if (listIterator.GetNodeData() > maxValue)
				{
					// So it becomes the new high value
					maxValue = listIterator.GetNodeData();
				}
			}

			// Returns the highest value
			return maxValue;
		}
		else
		{
			return NULL;
		}
	}

	// Determines if the linked list is empty
	bool IsEmpty()
	{
		if (headNode == nullptr && tailNode == nullptr)
		{
			std::cout << "There are no nodes in the list." << std::endl;
			return true;
		}
		else
		{
			return false;
		}
	}
	
	// Returns the current count of the number of nodes in the linked list
	int GetNodeCount()
	{
		return nodeCount;
	}
};

#endif // !LinkedList_H