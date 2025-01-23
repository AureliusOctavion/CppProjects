// Siddharth Sriram, CS1436.010, Lab 9
// This program will calculate the future value. The program will need to read in the present value, the monthly interest rate and the 
// number of months for the investment. The formula is going to compute compounded interest (by month).

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream> // For ifstream and ofstream
#include <cmath> // For power function

using namespace std;

// Read in data via input file and gives status

unsigned int ReadinData(
    ifstream &inputFile, 
    double &presentValue, 
    double &monthlyInterest, 
    int &months
    );

// Calculations for future value based on the formula

double futureValue(
    double presentValue, 
    double interestRate, 
    int months
    );

// Future value and other data to output file

void WrittenData(ofstream &outputFile, 
    double futureValue, 
    double presentValue, 
    double interestRate, 
    int months
);

// Error message when invalid input file name is entered in

void Error(
    double presentValue,
    double interestRate, 
    int months
     );

int main() {

    // Asks the user for the file name he wants put in

    string inputFN;
    cout << "Enter input file name" << "\n";
    cin >> inputFN;

    // File is opened
    ifstream inputFile(inputFN);
    if (!inputFile) {

        // In the case it can't be opened

        cout << "File \"" << inputFN << "\" could not be opened" << "\n";
        return 1;
    }

    // In the case it can't be opened

    ofstream outputFile("output.xls");
    if (!outputFile) {
        cout << "Error opening output file" << "\n";
        inputFile.close();
        return 1;
    }

    // Headers for column

    outputFile << "Future Value\tPresent Value\tMonthly Interest\tMonths" << "\n";

    double presentValue, monthlyInterest, processedFutureValue;
    int months;

    // Loops through to read in the data, process the data, and finally write the data

    while (true) {

        // Reads data

        unsigned int status = ReadinData(
            inputFile, 
            presentValue, 
            monthlyInterest, 
            months
            );
        if (status == 0) {
            break;

        // Correct input

        } else if (status == 1) {

            // Future Value is calculated

            processedFutureValue = futureValue(
            presentValue, 
            monthlyInterest / 100, 
            months);

            // Write the future value to the output file

            WrittenData(
            outputFile, 
            processedFutureValue, 
            presentValue, 
            monthlyInterest, 
            months
            );

        // Invalid input displayed if user enters in wrong 

        } else if (status == 2) {
            Error(presentValue, monthlyInterest, months);
        }
    }

    inputFile.close();
    outputFile.close();
    return 0;
}

// Read in the data from file the user inputted in

unsigned int ReadinData(
ifstream &inputFile, 
double &presentValue, 
double &monthlyInterest, 
int &months
) {

    // Reads these values from the input file that was entered in by user

    if (inputFile >> presentValue >> monthlyInterest >> months) {

        // Are the values that were read in valid?

        if (presentValue > 0 && monthlyInterest > 0 && months > 0) {
            return 1;
        }
        return 2;
    }
    return 0;
}

// Calculates the future value

double futureValue(
    double presentValue, 
    double interestRate, 
    int months
    ) {
    return presentValue * pow((1 + interestRate), months);
}

// Writes the data to the output file

void WrittenData(
    ofstream &outputFile, 
    double futureValue, 
    double presentValue, 
    double interestRate, 
    int months
    ) {

    // Outputs are going to the output file

    outputFile << fixed << setprecision(2) << futureValue << "\t"
             << presentValue << "\t"
             << fixed << setprecision(3) << interestRate << "\t"
             << months << "\n";
}

// Error message is displayed

void Error(
    double presentValue, 
    double interestRate, 
    int months
    ) {
    cout << fixed << setprecision(2) << presentValue << " "
         << fixed << setprecision(3) << interestRate << " "
         << months << "\n";

    // Error message that shows what the problem is

    cout << "One or more of the above values are not greater than zero" << "\n";
}
