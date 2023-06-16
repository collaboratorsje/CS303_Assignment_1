#include "cs303_assignment1.h"

int main() {
    // Declaring an array of size 150
    int myArray[150];
    // Storing the size of the array as a variable
    int myArraySize = sizeof(myArray) / sizeof(myArray[0]);
    // Opening an input filestream with the openFile function
    ifstream intFile = openFile();
    // Filling the array with the fillArray function
    fillArray(intFile, myArray, myArraySize);
    // While loop to execute program functions multiple times 
    while (true) {
        // Store user input for their command as a command variable by calling the menu function
        string command = menu();
        // Begin if else structure to execute blocks of code corresponding to user's command 
        if (command == "X") {
            break;
        }
        // Finding a number in the array and returning the index, -1 if not in the array
        else if (command == "F") {
            cout << "What number are you looking for? ";
            int number;
            cin >> number;
            int index = findNumber(myArray, myArraySize, number);
            if (index != -1) {
                cout << "The first instance of " << number << " is at index " << index << ".\n" << endl;
            }
            else {
                cout << "That number isn't in the array.\n" << endl;
            }
        }
        // Modifying a value at a specified index in the array with try catch for input validation
        else if (command == "M") {
            int value, index, oldValue, newValue;
            try {
                cout << "Enter the new value: ";
                cin >> value;
                if (cin.fail() || cin.get() != '\n') {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    throw invalid_argument("Invalid value\n");
                }
                cout << "Enter the index of the value to modify: ";
                cin >> index;
                if (cin.fail() || cin.get() != '\n') {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    throw invalid_argument("Invalid index\n");
                }
                // modifyValue function returns a pair, the old and new values
                pair<int, int> valuesPair = modifyValue(myArray, myArraySize, index, value);
                oldValue = valuesPair.first;
                newValue = valuesPair.second;
                cout << "Value at index " << index << " modified:\n" << "Old value: " << oldValue << "\nNew Value: " << newValue << endl;
            }
            catch (const exception& e) {
                cout << "Error: " << e.what() << endl;
            }
        }
        // addValue function with try catch for input validation
        else if (command == "A") {
            int value;
            try {
                cout << "Enter the new value to add to the end of the array: ";
                cin >> value;
                if (cin.fail() || cin.get() != '\n') {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    throw invalid_argument("Invalid value\n");
                }
                addValue(myArray, myArraySize, value);
            }
            catch (const exception& e) {
                cout << "Error: " << e.what() << endl;
            }
        }
        // removeValue function removes the value at the specified index and shifts the array contents down
        else if (command == "R") {
            int index;
            cin >> index;
            removeValue(myArray, myArraySize, index);
        }
        // printArray function prints the array with a for loop
        else if (command == "P") {
            printArray(myArray, myArraySize);
        }
    }
}

