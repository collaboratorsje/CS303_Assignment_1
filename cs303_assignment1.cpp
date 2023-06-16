#include "cs303_assignment1.h"
// Creates and returns an input filestream
ifstream openFile() {
    ifstream intFile;
    intFile.open("integers.txt");

    if (!intFile.is_open()) {
        cout << "Error opening file" << endl;
    }
    return intFile;
}
// Fills the array with the contents of the input file using a stringstream
// Fills the remaining array positions with 0
void fillArray(ifstream& intFile, int myArray[], int size) {
    int integer, index = 0;
    string line;

    while (getline(intFile, line)) {
        istringstream lineSS(line);

        while (lineSS >> integer) {
            myArray[index] = integer;
            index++;
        }
    }

    for (int i = index; i < size; i++) {
        myArray[i] = 0;
    }
}
// Linearly search the array for the first instance of the specified value and returns the index
int findNumber(const int myArray[],int size, int value) {
    for (int i=0; i<size; i++) {
        if (myArray[i] == value) {
            return i;
        }
    }
    return -1;
}
// Modifies a value at a specified index and returns the old and new values as a pair
// pair is unpacked in main and values are printed to the console
pair<int, int> modifyValue(int myArray[], int size, int index, int newValue) {
    if (index < 0 || index >= size) {
        throw out_of_range("Invalid index");
    }
    int oldValue = myArray[index];   
    myArray[index] = newValue;      
    return make_pair(oldValue, myArray[index]);
}
// Finds the first 0 in the array and assumes this is the "end", adds the value at that index
// Can only add values until the array is full (150)
void addValue(int myArray[], int size, int value) {
    for (int i = 0; i < size; i++) {
        if (myArray[i] == 0) {
            myArray[i] = value;
            return;
        }
    }
    cout << "Array is full. Cannot add more elements." << endl;
}
// removes a value at a specified index, shifts all the array contents down 1 index, sets the last index to 0
void removeValue(int myArray[], int size, int index) {
    for (int i = index; i < size - 1; i++) {
        myArray[i] = myArray[i + 1];
    }
    myArray[size] = 0;
}
// Prints the array with a for loop
void printArray(int myArray[], int size) {
    for (int i = 0; i < size; i++) {
        cout << myArray[i] << " ";
    }
    cout << endl;
}
// Prints the menu commands and returns the user choice
// User must type in a capital letter (did not user toupper)
string menu() {
    string command;
    cout << "MENU:\n";
    cout << "F) Find a value in the array\n";
    cout << "M) Modify a value at a specified index in the array\n";
    cout << "A) Add a value to the end of the array\n";
    cout << "R) Remove a value from the array\n";
    cout << "P) Print the array\n";
    cout << "X) End the program\n";
    cin >> command;
    while (command != "F" && command != "M" && command != "A" && command != "R" && command != "P" && command != "X") {
        cout << "Invalid input. Please enter a valid command: ";
        cin.clear();
        cin >> command;
    }
    return command;
}