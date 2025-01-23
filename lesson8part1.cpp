// Siddharth Sriram, CS1436.010, Lab 8
// The following program will calculate the distance an object travels (in meters) on Earth for a specified number of seconds. 
// You will also calculate the distance traveled on the Moon (in meters) for the specified number of seconds.

#include <iostream>
#include <iomanip>
#include <cmath> // For pow / power function

using namespace std;

// This is the function that asks the user to enter in the time in seconds

double readSeconds(){

    double seconds;
    cout << "Enter the time (in seconds)" << "\n";
    cin >> seconds;

// In the case the user enters number that is less then zero this message is
// outputted 

    if (seconds < 0){

        cout << "The time must be zero or more" << "\n";
    }

    return seconds;

}

// This is the function that does the calculations for the distance an object
// travels (in meters) on Earth for a specified number of seconds. 

double calculateEarthDistance(double seconds){

    const double earthGravity = 9.8;

    // Formula to calculate the distance for earth
    return 0.5 * earthGravity * pow(seconds, 2);

}

// This is the function that does the calculations for the distance an object
// travels (in meters) on Moon for a specified number of seconds. 

double calculateMoonDistance(double seconds){

    const double moonGravity = 1.6;

    // Formula to calculate the distance for moon
    return 0.5 * moonGravity * pow(seconds, 2);

}

// This is the function that displays both the distances for the 
// moon and earth.

void displayResults(double seconds, double earthDistance, double moonDistance){

    cout << fixed << setprecision(4);
    cout << "The object traveled " << earthDistance << " meters in " << setprecision(2) << seconds << " seconds on Earth" << "\n";
    cout << fixed << setprecision(4);
    cout << "The object traveled " << moonDistance << " meters in " << setprecision(2) << seconds << " seconds on the Moon" << "\n";
}

// main function
int main() {

    double seconds;

// This process is looped till the input of the user is zero
    while (true){

        seconds = readSeconds();

        if (seconds == 0){

            break;
        }

        if (seconds > 0){
            // Distance for earth
            double earthDistance = calculateEarthDistance(seconds);
            // Distance for moon
            double moonDistance = calculateMoonDistance(seconds);

            // Displays all the information
            displayResults(seconds, earthDistance, moonDistance);


        }
    }

    return 0; // End of program
}