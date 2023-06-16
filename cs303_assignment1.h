#include <iostream>
#include <fstream>
#include <sstream>
#include <utility>

using namespace std;

ifstream openFile();
void fillArray(ifstream& intFile, int myArray[], int size);
int findNumber(const int myArray[],int size, int value);
pair<int, int> modifyValue(int myArray[], int size, int index, int newValue);
void addValue(int myArray[], int size, int value);
void removeValue(int myArray[], int size, int index);
void printArray(int myArray[], int size);
string menu();