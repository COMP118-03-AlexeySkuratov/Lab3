/** \file bugExample.cpp
 *  \brief     A little with logical bugs in it
 *  \details   This program is littered with logical bugs. Your task is the
 *              following:
 *                1) Compile and run the program.
 *                2) For each bug you find you must fix the bug then Check In
 *                   the code with a comment on the fix you did
 *                3) There are a three functions that are not completed, you need to
 *                   complete them and also update the menu and the main function
 *  \author    Harald Gjermundrod
 *  \version   0.1
 *  \date      2017-2017
 *  \bug       Many logical bugs
 *  \copyright University of Nicosia.
 */

#include <iostream>
#include <cassert>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function prototypes
int printMenu();
void fillInArray(int[], const int);
void multArrays(const int[], const int[], int[], const int);
void displayArray(const int[], const int);
int sumOddArray(const int[], const int);
bool isAllPositive(const int[], const int);
void avgOddArray(const int[], const int, int&);

//Random seed

/**
 * <code>main</code> is the main function of this program.
 * <BR>
 * @return Returns 0 if success, any other value otherwise.
 */
int main() {
	int choice;
	const int SIZE = 10;

	srand(time(NULL));
	
	// Initialize array price
	int price[SIZE] = {};
	for (int i = 0; i < SIZE; i++)
	{
		price[i] = rand() % 10;
	}
	// Declare array quantity and total
	int quantity[SIZE] = {}, total[10];
	int average = 0;

	// Interactive menu
	do {
		choice = printMenu();

		switch (choice) {
			// Enter quantity
		case 1:
			fillInArray(quantity, SIZE);
			break;
			// Calculate total
		case 2:
			multArrays(quantity, price, total, SIZE);
			break;
			// Print total
		case 3:
			displayArray(quantity, SIZE);
			break;
			// Exit
		case 4:
			cout << "Sum of odd numbers in array is: " << sumOddArray(quantity, SIZE) << endl;
			break;
		case 5:
			cout << "Are all elements in array positive? 0 - false. 1 - true:  result is " << isAllPositive(quantity, SIZE) << endl;
			break;
		case 6:
			avgOddArray(quantity, SIZE, average);
			cout << "The average of the all odd elements in Array is " << average << endl;
			break;
		case 7:
			// No code needed
			break;
		}
	} while (choice != 7);

	cout << "\nHave a nice day:)" << endl;
	return 0;
}

/**
 * <code>printMenu</code> shows a menu and accepts the choice
 * from the user which is returned.
 * <BR>
 * @return Returns the menu choice
 */
int printMenu() {
	int choice;

	do {
		cout << "\n == MENU ==";
		cout << "\n1) Enter quantity";
		cout << "\n2) Calculate total";
		cout << "\n3) Print total";
		cout << "\n4) Sum odd numbers";
		cout << "\n5) Check if all elements are positive";
		cout << "\n6) Calculate the average of odd elements in Array";
		cout << "\n7) Exit";

		cout << "\nEnter the choice: ";
		cin >> choice;

		if (choice < 1 || choice > 7) {
			cout << "\nWrong choice, try again.";
		}
	} while (choice < 1 || choice > 7);
	return choice;
}

/**
 * <code>fillInArray</code> is a function that will
 * fill in the elements of an array.
 * <BR>
 * @param arr The array to be filled in.
 * @param size The size of the array.
 */
void fillInArray(int arr[], const int size) {
	assert(size > 1);

	for (int i = 0; i < size; ++i) {
		cout << "\nEnter an element for the array at " << i << ": ";
		cin >> arr[i];
	}
}

/**
 * <code>multArrays</code> multiplies the value of elements of the source array
 * to the corresponding value at the destination array. NOTE: precondition
 * is that the arrays have the same size.
 * <BR>
 * @param arrSource The array containing the destination elements.
 * @param arrDest The array containing the source elements.
 * @param size The size of the arrays.
 */	
void multArrays(const int arrQuantity[], const int arrPrice[], int arrTotal[], const int size) {
	assert(size > 0);
	const double VAT = 1.21;


	for (int i = 0; i <= size; ++i) {
		arrTotal[i] = arrQuantity[i] * arrPrice[i + 1] * VAT;
	}
}

/**
 * <code>displayArray</code> prints the value of each of the elements of the
 * array. In addition the function sums up the value of all the elements and
 * print the total.
 * <BR>
 * @param ar The array containing the values
 * @param size The size of the array.
 */
void displayArray(const int arr[], const int size) {
	int sum = 0;

	for (int i = 0; i < size; ++i) {
		cout << "\nValue at " << i << ": " << arr[i];
		sum += arr[i];
	}

	cout << "\nThe total is: " << sum;
}

/**
 * <code>sumOddArray</code> Sums the odd numbers in the array and returns the result
 * <BR>
 * @param ar The array containing the values
 * @param size The size of the array.
 */
int sumOddArray(const int arr[], const int size) {
	//@TODO: You will need to complete this. Including makeing the appropriate comment header
	int sum = 0;

	for (int i = 0; i < size; i ++) 
	{
		if (arr[i] % 2 != 0)
		{
			sum += arr[i];
		}
	}
	return sum;
}

/**
 * <code>isAllPositive</code> If all the values in the array are positive return true
 * <BR>
 * @param ar The array containing the values
 * @param size The size of the array.
 */
bool isAllPositive(const int arr[], const int size) {
	//@TODO: You will need to complete this. Including makeing the appropriate comment header
	bool isPositive = true;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] < 0)
		{
			isPositive = false;
		}
	}
	return isPositive;
}

/**
 * <code>avgOddArray</code> Finds the average of all the odd numbers in the array and stores this in the last argument
 * <BR>
 * @param ar The array containing the values
 * @param size The size of the array.
 * @param avgOdd The average of all the odd numbers. Passed by reference.
 */

void avgOddArray(const int arr[], const int size, int& avgOdd) {
	//@TODO: You will need to complete this. Including makeing the appropriate comment header
	avgOdd = sumOddArray(arr, size) / size;
}