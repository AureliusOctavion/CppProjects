// Siddharth Sriram, CS1436.010, Lab 7
// In this program it will be reading the numbers from a file, and then validating
// the numbers and calculating the avg of all the valid numbers

#include <iostream>
#include <iomanip>  // For using input/output manip.
#include <fstream>  // For file operations
#include <string>

using namespace std;

int main() {
    // Asks user to enter in a file name
    cout << "Enter input file name" << "\n"; 
    string InputFN;
    cin >> InputFN;

    // Goes through the input file and checks whether it's valid or not
    ifstream InputFile(InputFN);  // Opens the filename provided by the user
    if (InputFile.fail()) {  // This checks whether the file was opened or not
        // This is then what's displayed if the file fails to open and then quits the program
        cout << "File \"" << InputFN << "\" could not be opened" << "\n";
        return 1;
    }

    // Goes through the output file and checks whether it's valid or not
    ofstream InvalidOF("invalid-values.txt");
    if (InvalidOF.fail()) {  // This checks whether the output file opened 
        // This is what's displayed if the file doesn't open
        cout << "Could not open output file invalid-values.txt" << "\n";
        InputFile.close();
        return 1;
    }

// Doubles and integers in the program

    double Number; // Declared variable Number
    int TotalValues = 0; // Counts the total numbers read by the program
    int ValidValues = 0; // Counts the valid numbers
    int InvalidValues = 0; // Counts the invalid numbers
    double ValidSum = 0.0; // Sum of valid numbers

    // Process each number in the input file
    while (InputFile >> Number) {

        TotalValues++;  // This increments the total numbers read by the program

        // Checks if the number is within the range 0-105
        if (Number >= 0 && Number <= 105) {

            ValidSum += Number; // Adds the valid number to the sum of valid numbers
            ValidValues++; // Increments the count of valid numbers
        } else {

            InvalidValues++; // Increments count of invalid numbers
            InvalidOF << fixed << setprecision(5) << Number << "\n"; // Writes invalid number to file
        }
    }

    // Close out the input file
    InputFile.close();

    // Close out the output file
    InvalidOF.close();

    // Results outputted to the console
    cout << "Reading from file \"" << InputFN << "\"" << "\n";

    // Total amount of numbers read 
    cout << "Total values: " << TotalValues << "\n";

    // Count for the invalid numbers
    cout << "Invalid values: " << InvalidValues << "\n";

    // Count for the valid numbers
    cout << "Valid values: " << ValidValues << "\n";

    // Calculations for the avg of the valid values if any valid numbers
    if (ValidValues > 0) {

        double avg = ValidSum / ValidValues; // Calculates the average
        // Outputs the average
        cout << fixed << setprecision(4) << "Average of valid values: " << avg << "\n";
    } else {
        // If no valid numbers were found, this error message appears
        cout << "An average cannot be calculated" << "\n";
    }

    return 0; // End of program
}