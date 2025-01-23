// Siddharth Sriram, CS1436.010, Lab 5
// The following program will calculate the number of seconds it will take for sound to travel though a medium.

#include <iostream>
#include <iomanip> // For formatting so table comes out properly
using namespace std;

int main() { // Beginning of the program

    // Display menu of the question which then gives the following options of Air, Water, and Steel
    cout << "Select the medium that sound is traveling through:" << "\n";
    cout << "1 Air" << "\n";
    cout << "2 Water" << "\n";
    cout << "3 Steel" << "\n";

    // Unsigned Integers used throughout program
    unsigned int Menu_Option;

    // User enters the menu option he chooses from the menu that is prompted up before him
    cin >> Menu_Option;

    // Doubles used throughout program
    double Time;
    double Distance;

    // Switch statement begins and take in values you have for the medium through which it must calculate the number of seconds it will take for sound to travel through it
    switch(Menu_Option){
        case 1:
        cout << "Enter distance (in feet)" << "\n"; // Asks you to enter in the given amount of distance the sound has traveled through the medium Air
        cin >> Distance;
        if (Distance <= 0){
            cout << "The distance must be greater than zero" << "\n"; // Outputs when distance is less than zero
        } else {
            Time = Distance / 1100.0; // This calculates the seconds it will take for sound to travel through air by dividing the distance we put in by the speed
            cout << "Air: " << fixed << setprecision(4) << Distance << " ft" << "\n"; // Outputs the distance we entered previously into feet
            cout << "Traveled for " << fixed << setprecision(4) << Time << " seconds" << "\n"; // Gives us the seconds the sound travelled through air

        }
        break; // To stop case so it doesnt do other cases as well

        case 2:
        cout << "Enter distance (in feet)" << "\n"; // Asks you to enter in the given amount of distance the sound has traveled through the medium Water
        cin >> Distance;
        if (Distance <= 0){
            cout << "The distance must be greater than zero" << "\n"; // Outputs when distance is less than zero
        } else {
            Time = Distance / 4900.0; // This calculates the seconds it will take for sound to travel through water by dividing the distance we put in by the speed
            cout << "Water: " << fixed << setprecision(4) << Distance << " ft" << "\n"; // Outputs the distance we entered previously into feet
            cout << "Traveled for " << fixed << setprecision(4) << Time << " seconds" << "\n"; // Gives us the seconds the sound travelled through water
        }
        break; // To stop case so it doesnt do other cases as well
        
        case 3:
        cout << "Enter distance (in feet)" << "\n"; // Asks you to enter in the given amount of distance the sound has traveled through the medium Steel
        cin >> Distance;
        if (Distance <= 0){
            cout << "The distance must be greater than zero" << "\n"; // Outputs when distance is less than zero
        } else {
            Time = Distance / 16400.0; // This calculates the seconds it will take for sound to travel through steel by dividing the distance we put in by the speed
            cout << "Steel: " << fixed << setprecision(4) << Distance << " ft" << "\n"; // Outputs the distance we entered previously into feet
            cout << "Traveled for " << fixed << setprecision(4) << Time << " seconds" << "\n"; // Gives us the seconds the sound travelled through steel
        }
        break; // To stop case so it doesnt do other cases as well
    default: // For invalid values
    cout << "The menu value is invalid. Please run the program again." << "\n"; // This outputs when you choose a menu value that isnt on the menu
    break; // To stop case so it doesnt do other cases as well

    }

    return 0;
}