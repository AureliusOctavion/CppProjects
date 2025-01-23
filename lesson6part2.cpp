// Siddharth Sriram, CS1436.010, Lab 6
// The following program will convert a set of temperatures from Fahrenheit to Celsius and Kelvin

#include <iostream>
#include <iomanip>
using namespace std;

int main() { // Beginning of the program

// Doubles used throughout the program
double Starting_Temperature;
double Ending_Temperature;
double Increment_Value;
double Fahrenheit;
double Celsius;
double Kelvin;

// Values the user enters in for the starting temperature, ending temperature
// and increment values

do {
    cin >> Starting_Temperature;
    cin >> Ending_Temperature;
    cin >> Increment_Value;

// This checks whether the values the user enters meets the specified requirements if they dont
// it outputs message saying they don't meet specifications

if (Starting_Temperature > Ending_Temperature || Increment_Value <= 0.0) {

    cout << "Starting temperature must be <= ending temperature and increment must be > 0.0" << "\n";
    }

// This repeats if the input the user put is invalid
} while (Starting_Temperature > Ending_Temperature || Increment_Value <= 0.0);

// Table headers
cout << setw(18) << "Fahrenheit";
cout << setw(18) << "Celsius";
cout << setw(18) << "Kelvin" << "\n";

// This loops through the starting temperature to the ending temperature, and then incrementing by increment

for (Fahrenheit = Starting_Temperature; Fahrenheit <= Ending_Temperature; Fahrenheit += Increment_Value) {

    Celsius = (Fahrenheit - 32) / 1.8; // Fahrenheit to Celsius
    Kelvin = Celsius + 273.15; // Celsius to Kelvin

// Outputs all the temperatures calculated for Fahrenheit, Celsius, and Kelvin and display it
cout << fixed << setprecision(4);
cout << setw(18) << Fahrenheit;
cout << setw(18) << Celsius;
cout << setw(18) << Kelvin << "\n";

}

return 0; // End of program

}