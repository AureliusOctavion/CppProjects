// Siddharth Sriram, CS1436.010, Lab 5
// The following program will be reading in the number of seconds and then calculating how far sound can travel in a specified medium in that many seconds.

#include <iostream>
#include <iomanip> // For formatting so table comes out properly
using namespace std;

int main() { // Beginning of the program

    // Display menu of the question which then gives the following options of Carbon Dioxide, Air, Helium, and Hydrogen
    cout << "Select the medium that sound is traveling through:" << "\n";
    cout << "1 Carbon Dioxide" << "\n";
    cout << "2 Air" << "\n";
    cout << "3 Helium" << "\n";
    cout << "4 Hydrogen" << "\n";

    // Unsigned integers used throughout program
    unsigned int Menu_Option;

    // Reads in whatever menu option user has chosen
    cin >> Menu_Option;

    // Doubles used throughout program
    double Time_In_Seconds;
    double Distance;
    double Speed = 0.0; // For the speed which is in meters per second

    // String for the menu options using the if/else statements
    string Medium = "";

    // Boolean values used throughout program
    bool Valid_Input = true;

    // if/else statements for each medium

    // Carbon Dioxide
    if (Menu_Option == 1) {
        Speed = 258.0; // Obtained from provided table
        Medium = "Carbon Dioxide";

    // Air
    } else if (Menu_Option == 2) {
        Speed = 331.5; // Obtained from provided table
        Medium = "Air";

    // Helium
    } else if (Menu_Option == 3) {
        Speed = 972.0; // Obtained from provided table
        Medium = "Helium";

    // Hydrogen
    } else if (Menu_Option == 4) {
        Speed = 1270.0; // Obtained from provided table
        Medium = "Hydrogen";

    // This is outputted when the user enters in an invalid menu value
    } else {
        Valid_Input = false;
        cout << "The menu value is invalid. Please run the program again." << "\n";
    }
    
    // Prompts user to enter in assuming its a valid input the time in seconds
    if (Valid_Input){
        cout << "Enter time (in seconds)" << "\n";
        cin >> Time_In_Seconds;

        // Used to ensure the value user enters in is valid and if not then prompts the next cout statement out
        if (Time_In_Seconds < 0.0 || Time_In_Seconds > 30.0){

            cout << "The time must be between 0.000 and 30.000 (inclusive)" << "\n"; // Outputted out if the time the user enters in is not between set range
        
        } else {

            Distance = Speed * Time_In_Seconds; // Used to calculate the meters it travelled (Math for last output when tested)
            
            // Output for last 2 parts of the table to give the seconds and distance it traveled
            cout << Medium << ": " << fixed << setprecision(3) << Time_In_Seconds << " seconds" << "\n";
            cout << "Traveled " << fixed << setprecision(4) << Distance << " meters" << "\n";

        }
    }

    return 0;

}