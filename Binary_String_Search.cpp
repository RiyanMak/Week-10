//******************************************************************
// Binary String Search
// Programmer: Riyan Maknojia
// Completed : 03/29/24
// Status    : Completed
//
// This program demonstrates the use of sort and display the strings 
// before the array is searched for values.
//******************************************************************

// Include necessary headers
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// Function prototypes
void selectionSort(string[], int);
string upperCaseIt(const string&);
void displayNames(const string[], int);
bool binarySearch(const string[], int, string);

void swap(string& a, string& b) {
    // Swap function to swap two strings
    string temp = a;
    a = b;
    b = temp;
}

int main() {
    const int SIZE = 20;
    // Array of names
    string name[SIZE] =
     {"Collins, Bill", "Smith, Bart", "Michalski, Joe", "Griffin, Jim", 
    "Sanchez, Manny", "Rubin, Sarah", "Taylor, Tyrone", "Johnson, Jill", "Allison, Jeff", 
    "Conroy, Pat", "Harrison, Rose", "Holland, Beth", "Kelly, Sean", "Moreno, Juan", 
    "Moretti, Bella", "Patel, Renee", "Smith, Cathy", "Whitman, Jean", "Wolfe, Bill", "Wu, Eric"};

    // Sort the names using selection sort
    selectionSort(name, SIZE);
    // Display the sorted names
    displayNames(name, SIZE);

    // Search for a name in the sorted array
    string searchName1 = "Wolfe, Bill";
    bool found1 = binarySearch(name, SIZE, searchName1);
    cout << "Searching for " << searchName1 << " ... ";
    if (found1) {
        cout << searchName1 << " was found in the array." << endl;
    } else {
        cout << searchName1 << " was NOT found in the array." << endl;
    }

    // Search for a name that is not in the array
    string searchName2 = "Big Bad Wolf";
    bool found2 = binarySearch(name, SIZE, searchName2);
    cout << "Searching for " << searchName2 << "... ";
    if (found2) {
        cout << searchName2 << " was found in the array." << endl;
    } else {
        cout << searchName2 << " was NOT found in the array." << endl;
    }

    return 0;
}

void selectionSort(string name[], int size) {
    // Selection sort algorithm to sort the names
    int minIndex;
    string minValue;
    for (int start = 0; start < (size - 1); start++) {
        minIndex = start;
        minValue = name[start];
        for (int index = start + 1; index < size; index++) {
            if (name[index] < minValue) {
                minValue = name[index];
                minIndex = index;
            }
        }
        swap(name[minIndex], name[start]);
    }
}

string upperCaseIt(const string& str) {
    // Function to convert a string to uppercase
    string upperStr;
    for (char c : str) {
        upperStr += toupper(c);
    }
    return upperStr;
}

void displayNames(const string names[], int size) {
    // Function to display the sorted names
    cout << "The names in sorted order are:" << endl;
    for (int i = 0; i < size; i++) {
        cout << names[i] << endl;
    }
}

bool binarySearch(const string names[], int size, string value) {
    // Binary search algorithm to search for a name in the sorted array
    string upperValue = upperCaseIt(value);
    int first = 0, last = size - 1, middle;
    bool found = false;
    while (!found && first <= last) {
        middle = (first + last) / 2;
        string upperName = upperCaseIt(names[middle]);
        if (upperName == upperValue) {
            found = true;
        } else if (upperName > upperValue) {
            last = middle - 1;
        } else {
            first = middle + 1;
        }
    }
    return found;
}