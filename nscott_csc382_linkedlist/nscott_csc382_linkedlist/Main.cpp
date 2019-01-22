#include <iostream>
#include <typeinfo>

#include "LinkedList.h"

template<typename T> void GetUserInput(T* userInput);
bool TestUserInput();

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
		std::cout << " 7. Display list in reverse order" << std::endl << std::endl;

		std::cout << "11. Auto-populate some nodes" << std::endl;
		std::cout << "12. Print a detailed list" << std::endl << std::endl;

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
					myList.Delete(myList.Find(userInput, true));
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
		case 11: // Adds a random amount of random values to the list
			std::cout << "How many nodes would you like to create? ";
			GetUserInput(&userInput);
			for (int i = 0; i < userInput; i++)
			{
				myList.Insert(std::rand() % (int)(userInput * 10 + 1), false);
			}
			std::cout << userInput << " nodes created.\n";
			break;
		case 12: // Prints a list of each value, and the adjacent values and node addresses
			myList.PrintList(false, true);
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