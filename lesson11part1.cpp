// Siddharth Sriram, CS1436.010, Lesson 11
// This program will write a program that will determine if a magic square is valid or not, it will simulate a magic square using a 2-dimensional 21x21
// array of int values. The  program will also be able to support input files of 3x3 up to 21x21.

#include <iostream>
#include <fstream> // Used for input and output
#include <string> // Handle strings
using namespace std;

const int MAX_SIZE = 21; // Global constant told to be used by program

// Function prototypes

// From a given file, this reads the magic square

int readSquare(int square[MAX_SIZE][MAX_SIZE], string inputFileName); 

// Checks to see if the square is a valid magic square

bool validateSquare(const int square[MAX_SIZE][MAX_SIZE], int size); 

// Provides the magic square to the user

void MagicSquare_Display(const int square[MAX_SIZE][MAX_SIZE], int size); 

// Beginning of code starts here

int main() {
    string inputFileName;

    // Ask user for file name
    
    cout << "Enter input file name" << endl;  

    // Read the file name from user input

    cin >> inputFileName;  

    // Declares the 2D array for the magic square
    
    int square[MAX_SIZE][MAX_SIZE];  

    // Call readSquare function to read the file

    int size = readSquare(square, inputFileName);  

    // If size is 0, that means the file couldn't be opened
    
    if (size == 0) {  

    // Display error message

        cout << "File \"" << inputFileName << "\" could not be opened" << endl; 
    } else {

        // Display the magic square if the file was opened successfully

        MagicSquare_Display(square, size); 

        // Validate the magic square

        if (validateSquare(square, size)) {

             // If valid, print message

            cout << "Valid magic square" << endl; 
        } else {

            // If invalid, print message

            cout << "Invalid magic square" << endl;  
        }
    }

    return 0;
}

// Function to read the square from a file and return the size of the square

int readSquare(int square[MAX_SIZE][MAX_SIZE], string inputFileName) {

     // Open the file

    ifstream inputFile(inputFileName);  

    // Check if the file failed to open

    if (inputFile.fail()) {  

        return 0;  
    }

    int size;

    // Read the size of the square from the file

    inputFile >> size;  

    // Read the square's values into the array

    for (int IndexRows = 0; IndexRows < size; IndexRows++) {
        for (int IndexColumns = 0; IndexColumns < size; IndexColumns++) {

             // Read each number from the file into the array

            inputFile >> square[IndexRows][IndexColumns];  
        }
    }

// Close the file after reading

    inputFile.close(); 
    return size;  
}

// Function to display the magic square

void MagicSquare_Display(const int square[MAX_SIZE][MAX_SIZE], int size) {
    cout << "Magic square" << endl;

    // Loop through each row

    for (int IndexRows = 0; IndexRows < size; IndexRows++) {  

        // Loop through each column

        for (int IndexColumns = 0; IndexColumns < size; IndexColumns++) { 

            // Output the value in the square

            cout << square[IndexRows][IndexColumns] << " "; 
        }
        cout << endl;
    }
}

// Function to validate if the square is a valid magic square

bool validateSquare(const int square[MAX_SIZE][MAX_SIZE], int size) {

     // Calculate the sum each row, column, and diagonal should add up to

    int SumTarget = size * (size * size + 1) / 2; 

    // Check if each row adds up to the target sum

    for (int IndexRows = 0; IndexRows < size; IndexRows++) {
        int SumofRow = 0;
        for (int IndexColumns = 0; IndexColumns < size; IndexColumns++) {

            // Add values in the row

            SumofRow += square[IndexRows][IndexColumns];  
        }
        if (SumofRow != SumTarget) {
            return false;  
        }
    }

    // Check if each column adds up to the target sum

    for (int IndexColumns = 0; IndexColumns < size; IndexColumns++) {
        int ColumnTotal = 0;
        for (int IndexRows = 0; IndexRows < size; IndexRows++) {

            // Add values in the column

            ColumnTotal += square[IndexRows][IndexColumns];  
        }
        if (ColumnTotal != SumTarget) {

            // If column sum is not equal to target, it's not a valid magic square

            return false;  
        }
    }

    // Check the diagonals

    int Diagonal_One = 0, Diagonal_Two = 0;
    for (int IndexRows = 0; IndexRows < size; IndexRows++) {

        // Diagonal from top left to bottom right

        Diagonal_One += square[IndexRows][IndexRows];  

        // Diagonal from bottom left to top right

        Diagonal_Two += square[IndexRows][size - IndexRows - 1];  

        // If diagonal sums are not equal to target, it's not a valid magic square 
    }
    if (Diagonal_One != SumTarget || Diagonal_Two != SumTarget) { 
        return false;
    }

    // Check if all values from 1 to size * size are present exactly once

    // Use statically allocated array for tracking found numbers

    bool found[MAX_SIZE * MAX_SIZE + 1] = {false};  // The array size is determined at compile-time and initialized to false

    for (int IndexRows = 0; IndexRows < size; IndexRows++) {
        for (int IndexColumns = 0; IndexColumns < size; IndexColumns++) {
            int Number = square[IndexRows][IndexColumns];
            if (Number < 1 || Number > size * size || found[Number]) {
                return false;  
            }

            // Mark the number as found

            found[Number] = true;  
        }
    }

    return true;  // If all checks pass, it's a valid magic square
}
