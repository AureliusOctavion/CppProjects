// Siddharth Sriram, CS1436.010, Lab 10
// This program will will read the contents of a file into an array and 
// calculate various values based on the contents of the file.

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream> // For ifstream and ofstream

using namespace std;

// Global constants that are gonna be used throughout the entire program

const int MAX_COLUMNS = 5;

// readFile function

int readFile(
double values[][MAX_COLUMNS], 
int maxRows, 
string inputFileName
);

// average function

double average(
double values[][MAX_COLUMNS], 
int numberRows
);

// column average function

double columnAverage(
double values[][MAX_COLUMNS], 
int column, 
int numberRows
);

// smallest in row function

double smallestInRow(
double values[][MAX_COLUMNS], 
int numberRows
);

// Beginning of program starts here

int main() {

    // Max number of rows allowed in the array

    const int MAX_ROWS = 30; 

    // Variable to store the input file name

    string inputFileName; 

    // The array to store the data from the file

    double grades[MAX_ROWS][MAX_COLUMNS];

    // Prompt for input file name

    cout << "Enter input file name" << "\n";
    cin >> inputFileName; // Read in file name from user

    // Read data from the file into the array

    int actualRows = readFile(grades, MAX_ROWS, inputFileName);

    // Check for validation during file reading

    if (actualRows == -1) {
        cout << "File \"" << inputFileName << "\" could not be opened" <<  "\n";
        return 1; // Exits out in the case the file could not be opened
    } else if (actualRows == 0) {
        cout << "The input file \"" << inputFileName << "\" did not contain any data" << "\n";
        return 1; // Exits out in the case the file contains no data
    }

    // Outputs the processing information

    cout << "Processing " << actualRows << " rows, and " << MAX_COLUMNS << " columns" << "\n";

    // Does the necessary calculations and then displays the avg of all values

    double AllAverage = average(grades, actualRows); // Compute the overall average
    cout << "Average for all values is " << fixed << setprecision(2) << AllAverage << "\n";

    // Does the necessary calculations and then displays the avg for each column

    for (int RegCol = 0; RegCol < MAX_COLUMNS; ++RegCol) {
        double colAvg = columnAverage(grades, RegCol, actualRows); // Math for the column avg
        cout << "Average for column " << RegCol << " is " << fixed << setprecision(2) << colAvg << "\n";
    }

    // This will find and display the smallest value for each row

    for (int RegRow = 0; RegRow < actualRows; ++RegRow) {
        double smallest = smallestInRow(grades, RegRow); // Math for the smallest value in row
        cout << "Smallest value for row " << RegRow << " is " << fixed << setprecision(2) << smallest << "\n";
    }

    return 0; 
}

// Reads in the input file and and in turn fills array

int readFile(double values[][MAX_COLUMNS], int maxRows, string inputFileName) {
    ifstream InputtedFile(inputFileName); 
    if (!InputtedFile.is_open()) {
        return -1; // In the case could not be opened
    }

    int CountofRow = 0; // Counts in the rows successfully read
    while (CountofRow < maxRows) {
        bool CorrectRow = true; // This shows if the row is complete
        for (int SpecifiedColumnIndex = 0; SpecifiedColumnIndex < MAX_COLUMNS; ++SpecifiedColumnIndex) {
            if (!(InputtedFile >> values[CountofRow][SpecifiedColumnIndex])) {
                CorrectRow = false; // Break if any column in the row fails to read
                break;
            }
        }
        if (!CorrectRow) break; // Stop reading if an incomplete row is seen
        ++CountofRow; // Goes through the row counter
    }

    InputtedFile.close(); // Close the input file
    return CountofRow; // Return the number of rows successfully read
}

// Calculates the average of all values in the array

double average(double values[][MAX_COLUMNS], int numberRows) {

    // Total of all elements
    double Total = 0.0; 

    int NumberofElementsProcessed = 0; // Counter for the number of elements processed

    for (int SpecifiedRowIndex = 0; SpecifiedRowIndex < numberRows; ++SpecifiedRowIndex) {
        for (int SpecifiedColumnIndex = 0; SpecifiedColumnIndex < MAX_COLUMNS; ++SpecifiedColumnIndex) {
            Total += values[SpecifiedRowIndex][SpecifiedColumnIndex]; // Adds the value to the total
            ++NumberofElementsProcessed; // Go through the count
        }
    }

    return (NumberofElementsProcessed == 0) ? 0.0 : Total / NumberofElementsProcessed; // Avoid division by zero
}

// Calculates the average for a specified column

double columnAverage(double values[][MAX_COLUMNS], int column, int numberRows) {

    // Sum of values in the specified column

    double Total = 0.0; 
    for (int SpecifiedRowIndex = 0; SpecifiedRowIndex < numberRows; ++SpecifiedRowIndex) {
        Total += values[SpecifiedRowIndex][column]; // Adds the column value to total
    }

    return Total / numberRows; // Avg for the column
}

// THis finds the smallest value in a certain row thats specified

double smallestInRow(double values[][MAX_COLUMNS], int SpecifiedRowIndex) {
    double Small = values[SpecifiedRowIndex][0]; // Makes the assumption that the first column is the smallest initially
    for (int SpecifiedColumnIndex = 1; SpecifiedColumnIndex < MAX_COLUMNS; ++SpecifiedColumnIndex) {
        if (values[SpecifiedRowIndex][SpecifiedColumnIndex] < Small) { // Changes if smaller value is found
            Small = values[SpecifiedRowIndex][SpecifiedColumnIndex];
        }
    }
    return Small; // Goes back to the smallest value in the row
}
