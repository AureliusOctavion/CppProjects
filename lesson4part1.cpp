// Siddharth Sriram, CS1436.010, Lab 4
// The following program will read in the mass of an object (in kg) and output the weight (in N) on the Earth, on the Moon, and on Venus.
#include <iostream>
#include <iomanip> // For formatting so table comes out properly
using namespace std;

int main() //Beginning of program
{
    // Constant doubles
    const double Earth_Acc_Due_Grav = 9.81;
    const double Moon_Acc_Due_Grav = 1.62;
    const double Venus_Acc_Due_Grav = 8.87;

   // Variable doubles 
    double mass;
    double Earth_Weight;
    double Moon_Weight;
    double Venus_Weight;
    
    // Asks user to enter in mass in kg
    cout << "Enter the mass in kg" << "\n";
    cin >> mass;
    
    // Displays what the mass is in kg which it then takes the value entered here to later get converted to weights for Earth, Moon, and Venus.
    cout << fixed << setprecision(4);
    cout << "The mass is " << mass << " kg" << "\n";
    
    if (mass <= 0){ // Outputted if mass is greater than zero depending on mass entered by user
        cout << "The mass must be greater than zero" << "\n";
        return 1;
    }
    
    
    // To calculate Earth weight
    
    Earth_Weight = mass * Earth_Acc_Due_Grav;
    
    
    // To calculate Moon weight
    
    Moon_Weight = mass * Moon_Acc_Due_Grav;
    
    
    // To calculate Venus weight
    
    Venus_Weight = mass * Venus_Acc_Due_Grav;
    
    
    // Table output seen when program is run and the weight is entered in which then has the program run through the various formulas which are then put into the table 
    cout << left << setw(8) << "Location" << right << setw(14) << "Weight (N)" << endl;
    cout << left << setw(8) << "Earth" << right << setw(14) << Earth_Weight << endl;
    cout << left << setw(8) << "Moon" << right << setw(14) << Moon_Weight << endl;
    cout << left << setw(8) << "Venus" << right << setw(14) << Venus_Weight << endl;

    // Check if the conditions are heavy or light
    if (Earth_Weight >= 1500) {
        cout << "The object is heavy" << "\n"; // Heavy
        } else if (Earth_Weight < 5) {
            cout << "The object is light" << "\n";  // Light
    }

    return 0;
}