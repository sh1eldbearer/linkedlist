#include <iostream>
#include <typeinfo>

#include "LinkedList.h"

template<typename T> void GetUserInput(T* userInput);
bool TestUserInput();
void AutomatedTesting();

int main()
{
	// Linked list object
	LinkedList<double> myList;
	bool runProgram = true;
	double userInput = 0;
	int menuChoice = 0;

	while (runProgram)
	{
		// Menu display
		std::cout << "**********************************" << std::endl;
		std::cout << "*** DOUBLY-LINKED LIST PROGRAM ***" << std::endl;
		std::cout << "**********************************" << std::endl;
		std::cout << " 1. Add new node " << std::endl;
		std::cout << " 2. Remove node" << std::endl;
		std::cout << " 3. Find data in list" << std::endl; 
		std::cout << " 4. Find lowest value in the list" << std::endl;
		std::cout << " 5. Find highest value in the list" << std::endl;
		std::cout << " 6. Display list" << std::endl;
		std::cout << " 7. Display list in reverse order" << std::endl;
		std::cout << " 8. Display list with additional details" << std::endl << std::endl;

		std::cout << "11. Auto-populate some nodes" << std::endl << std::endl;

		std::cout << "21. Run automated tests" << std::endl << std::endl;

		std::cout << "99. Exit program" << std::endl << std::endl;
		std::cout << "Your choice: ";
		std::cin >> menuChoice;
		std::cin.clear();
		std::cin.ignore();
		std::cout << std::endl;

		switch (menuChoice)
		{
		case 1: // Inputs a new node containing a inputted key value into the list
			std::cout << "What data would you like to store in this node? ";
			GetUserInput(&userInput);
			if (TestUserInput())
			{
				myList.Insert(userInput);
			}
			break;
		case 2: // Deletes the first node found containing the inputted value
			// If the list has no nodes, displays an error message
			if (myList.IsEmpty())
			{
				// Do nothing
			}
			else
			{
				std::cout << "What value would you like to delete from the list? ";
				GetUserInput(&userInput);
				if (TestUserInput())
				{
					myList.Delete(userInput);
				}
			}
			break;
		case 3: // Finds a value in the list
			// If the list has no nodes, displays an error message
			if (myList.IsEmpty())
			{
				std::cout << "There are no nodes in the list." << std::endl;
			}
			else
			{
				std::cout << "What value would you like to find in the list? ";
				GetUserInput(&userInput);
				if (TestUserInput())
				{
					myList.Find(userInput);
				}
			}
			break;
		case 4: // Returns the lowest value stored in the list
			userInput = myList.Minimum();
			if (userInput != NULL)
			{
				std::cout << "The lowest value stored in the list is: " <<
					myList.Minimum() << std::endl;
			}
			break;
		case 5: // Returns the highest value stored in the list
			userInput = myList.Maximum();
			if (userInput != NULL)
			{
				std::cout << "The highest value stored in the list is: " <<
					myList.Maximum() << std::endl;
			}
			break;
		case 6: // Displays the list of the values stored, from head to tail
			myList.PrintList(false,false);
			break;
		case 7: // Displays the list of the values stored, from tail to head
			myList.PrintList(true,false);
			break;
		case 8: // Prints a list of each value, and the adjacent values and node addresses
			myList.PrintList(false, true);
			break;
		case 11: // Adds a random amount of random values to the list
			std::cout << "How many nodes would you like to create? ";
			GetUserInput(&userInput);
			for (int i = 0; i < userInput; i++)
			{
				myList.Insert(std::rand() % (int)(userInput * 10 + 1), false);
			}
			std::cout << userInput << " nodes created.\n";
			break;
		case 21: // Runs automated tests
			AutomatedTesting();
			break;
		case 99: // Exits the program
			runProgram = false;
			break;
		}

		std::cout << std::endl;
	}

	// Bye Felicia
	return 0;
}

// Gets user input
template<typename T> void GetUserInput(T* userInput)
{	
	std::cin >> *userInput;
}

// Tests cin for failure and clears cin's flags and input buffer afterward
bool TestUserInput()
{
	bool failure;

	// Checks to see if there were any problems getting the user's input
	failure = std::cin.fail();
	// Clears cin's failure flag for next input
	std::cin.clear();
	// Clears the input buffer
	std::cin.ignore(256, '\n');

	if (failure) // User did not input a valid value
	{
		std::cout << "Invalid entry. Please try again." << std::endl;
	}

	// Returns whether the input was valid (true) or not (false)
	return !failure;
}

void AutomatedTesting()
{
	LinkedList<float> testList;

	system("cls");

	// Display an empty list
	std::cout << "Printing an empty linked list: ";
	testList.PrintList(false, false);

	// Add 5 nodes to the list
	std::cout << std::endl << "Adding 5 nodes to the list (3.3, 5.5, 2.2, 4.4, 1.1): " << std::endl;
	testList.Insert(3.3f, true);
	testList.PrintList(false, false);
	testList.Insert(5.5f, true);
	testList.PrintList(false, false);
	testList.Insert(2.2f, true);
	testList.PrintList(false, false);
	testList.Insert(4.4f, true);
	testList.PrintList(false, false);
	testList.Insert(1.1f, true);
	testList.PrintList(false, false);
	std::cout << std::endl;

	// Test minimum and maximum
	std::cout << "Minimum value stored in the list (should be 1.1): " 
		<< testList.Minimum() << std::endl;
	std::cout << "Maximum value stored in the list (should be 5.5): " 
		<< testList.Maximum() << std::endl;
	std::cout << std::endl;

	// Find nodes
	testList.Find(2.2f);
	testList.Find(1.1f);
	testList.Find(3.3f);
	testList.Find(7.7f);
	std::cout << std::endl;
	system("pause");
	std::cout << std::endl;

	// Delete nodes
	std::cout << "Deleting head node: ";
	testList.Delete(3.3f);
	testList.PrintList(false, false);
	std::cout << "Deleting a node in the middle of the list: ";
	testList.Delete(2.2f);
	testList.PrintList(false, false);
	std::cout << "Deleting the tail node: ";
	testList.Delete(1.1f);
	testList.PrintList(false, false);
	std::cout << std::endl;

	// Add another node
	testList.Insert(6.6f);
	testList.PrintList(false, false);
	testList.Insert(7.7f);
	testList.PrintList(false, false);
	std::cout << std::endl;

	// Test minimum and maximum again
	std::cout << "Minimum value stored in the list (should be 2.2): "
		<< testList.Minimum() << std::endl;
	std::cout << "Maximum value stored in the list (should be 6.6): "
		<< testList.Maximum() << std::endl;
	std::cout << std::endl;
	system("pause");

	// Delete all remaining nodes
	std::cout << std::endl << "Deleting all remaining nodes: " << std::endl;
	testList.Delete(1.1f);
	testList.Delete(2.2f);
	testList.Delete(3.3f);
	testList.Delete(4.4f);
	testList.Delete(5.5f);
	testList.Delete(6.6f);
	testList.Delete(7.7f);
	testList.Delete(8.8f);
	testList.Delete(1.1f);
	std::cout << std::endl;

	// Print empty list
	std::cout << "And finally, to check if the list is empty: ";
	testList.PrintList(false, false);
	std::cout << std::endl;

	system("pause");
	system("cls");
}