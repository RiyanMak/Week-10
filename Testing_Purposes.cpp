#include <iostream>
#include <string>
#include <cctype>

using namespace std;

void selectionSort(string[], int);
string upperCaseIt(const string&);
void displayNames(const string[], int);
bool binarySearch(const string[], int, string);

int main() {
    const int SIZE = 20;
    string name[SIZE] = {"Collins, Bill", "Smith, Bart", "Michalski, Joe", "Griffin, Jim",
                         "Sanchez, Manny", "Rubin, Sarah", "Taylor, Tyrone", "Johnson, Jill",
                         "Allison, Jeff", "Conroy, Pat", "Harrison, Rose", "Holland, Beth",
                         "Kelly, Sean", "Moreno, Juan", "Moretti, Bella", "Patel, Renee",
                         "Smith, Cathy", "Whitman, Jean", "Wolfe, Bill", "Wu, Eric"};

    cout << "/* SAMPLE OUTPUT CREATED BY A TEST PROGRAM" << endl;
    selectionSort(name, SIZE);
    displayNames(name, SIZE);

    // Predefined search terms (modify as needed)
    string searchTerms[] = {"Bill Wolfe", "Big Bad Wolf"};

    for (const string& searchName : searchTerms) {
        bool found = binarySearch(name, SIZE, upperCaseIt(searchName));
        cout << "Searching for " << searchName << " ... ";
        if (found) {
            cout << searchName << " was found in the array." << endl;
        } else {
            cout << searchName << " was NOT found in the array." << endl;
        }
    }

    cout << "*/" << endl;
    return 0;
}

void selectionSort(string name[], int size) {
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
    string upperStr;
    for (char c : str) {
        upperStr += toupper(c);
    }
    return upperStr;
}

void displayNames(const string names[], int size) {
    cout << "The names in sorted order are:" << endl;
    for (int i = 0; i < size; i++) {
        cout << names[i] << endl;
    }
}

bool binarySearch(const string names[], int size, string value) {
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

