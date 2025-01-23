// Siddharth Sriram, CS1436.010, Lab 7
// In this program you will be reading sales information from a file and writing out a bar chart for 
// each of the stores. The bar charts will be created by writing out a sequence of * characters.

#include <iostream>
#include <iomanip> // For using input/output manip.
#include <fstream> // For file operations
#include <string>

using namespace std;

// Program starts here

int main(){
    cout << "Enter input file name" << "\n";
    string InputFN; // InputFN is declared to store file entered by user
    cin >> InputFN; // Read in the file the user chooses

    // Goes through the input file, checks whether its valid or not

    ifstream InputFile(InputFN); // Opens the filename provided by the user
    if (InputFile.fail()){ // This checks whether the file was opened or not
        // This is then whats displayed if the file fails to open and then quits the program
        cout << "File \"" << InputFN << "\" could not be opened" << "\n";
        return 1;


    }

    // Goes through the output file, checks whether its valid or not
    
    ofstream OutputFile("saleschart.txt");
    if (OutputFile.fail()){ // This checks whether the output file opened 
        // This is whats displayed if the file doesnt open
        cout << "Could not open output file saleschart.txt" << "\n";
        InputFile.close();
        return 1;

    }
// Integers and boolean declared
unsigned int StoreNumber;
int Special_Characters;
long long int Sales;
bool ValidData = true;

// The while loop that reads information contained in file until the end of
// file is reached

while (InputFile >> StoreNumber >> Sales){

    // Is the store number within a valid range?
    if (StoreNumber < 1 || StoreNumber > 99){

    // The error is displayed if the store number user puts in is out of range 1-99
        cout << "The store number " << StoreNumber << " is not valid" << "\n";
    } else if (Sales < 0){ // Is the sales value negative?
    // If negative sales value this is displayed
        cout << "The sales value for store " << StoreNumber << " is negative" << "\n";
    } else {

        // Outputs bar chart
        if (ValidData){
            OutputFile << "SALES BAR CHART\n(Each * equals 5,000 dollars)\n";
            ValidData = false; // Doesnt print header again
    }

    OutputFile << "Store " << setw(2) << StoreNumber << ": ";
    Special_Characters = Sales / 5000; // Calculates number of * sales (5000 is the value of each *)
    for (int x = 0; x < Special_Characters; ++x) { // Loops continiously for right number of *
        OutputFile << "*";

    }

    OutputFile << "\n";

    }
}

InputFile.close(); // Closes input file
OutputFile.close(); // Closes output file

return 0; // Ends program

}