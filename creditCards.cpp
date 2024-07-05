/*
	Jazmin Even Dorra

	creditCards.cpp

	Load the list of credit card numbers.
	Sort using
		- Bubble Sort
	Search using
		- Bianry search
 */

// Header files
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Global constant
const int SIZE = 18;	// Maximum numbers to be stored

// Function prototypes
void loadArray(long int[], int&);
void bubbleSort(long int[], int);
int binarySearch(const long int[], int, int);

int main()
{
	//Variables
	int accNumber;		// Account number to be searched
	long int items[SIZE];	// Array of items read
	int numItems;	// Number of items read from file
	char tryAgain = 'y';	// Loop control variable
	int results;			// Variable to check if found

	// Intro
	cout << "Credit Card Account Checker ... \n";

	while (tolower(tryAgain) == 'y')
	{
		// Load array of numbers
		loadArray(items, numItems);

		// Sort using bubble sort
		bubbleSort(items, numItems);

		

		// Prompt user for account number
		cout << "\nEnter a 7-digit account number:	";
		cin >> accNumber;

		results = binarySearch(items, SIZE, accNumber);

		if (results == -1)
			cout << "-> The credit card number is invalid.\n";
		else
		{
			cout << "-> The credit card number is valid.\n";

		}
		
		// Check for another file
		cout << "\nWould you like to check another account number (y/n)? ";
		cin >> tryAgain;
	}

	cout << "\nGood Bye ...";
	return 0;

}

//Load array of items

void loadArray(long int arr[], int& size)
{
	ifstream inFile;

	// Open File
	inFile.open("accNumbers.txt");

	// Initialize size
	size = 0;

	if (inFile)
	{
		// Load elements into array
		while (size < SIZE && inFile >> arr[size])
		{
			size++;
		}

		// Close file
		inFile.close();
	}
	else
		cout << "couldnt read";
	return;
}

void bubbleSort(long int arr[], int size)
{
	int firstUnsorted = 0;	// Index of first unsorted
	bool swap = true;		// True if elements in the array were swapped
	int itemIdx;			// Element being compared

	while (swap)
	{
		// Update swap
		swap = false;

		//bubble up smalles item to firstUnsorted
		itemIdx = size - 1;
		while (itemIdx > firstUnsorted)
		{
			if (arr[itemIdx] < arr[itemIdx - 1])
			{
				// Swap pair of items
				int temp = arr[itemIdx - 1];
				arr[itemIdx - 1] = arr[itemIdx];
				arr[itemIdx] = temp;

				// Update swap
				swap = true;
			}

			//Update itemIdx
			itemIdx--;
		}

		//Increment firstUnsorted
		firstUnsorted++;
	}

	return;
}


int binarySearch(const long int arr[], int size, int value)
{
	int first = 0,			// First array element
		last = size - 1,	//last array element
		middle,				// midpoint of search
		position = -1;		//position of search value
	bool found = false;		// Flag

	while (!found && first <= last)
	{
		middle = (first + last) / 2;	// calculate midpoint
		if (arr[middle] == value)		// if value is found at mid
		{
			found = true;
			position = middle;
		}
		else if (arr[middle] > value)	// If value is in lower half
			last = middle - 1;
		else
			first = middle + 1;
	}

	return position;
}
