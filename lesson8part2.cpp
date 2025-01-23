// Siddharth Sriram, CS1436.010, Lab 8
// The following program will calculate the present value deposited money you need to have in order for
// your money to grow to a certain amount you want it to grow to

#include <iostream>
#include <iomanip>
#include <cmath> // For pow / power function

using namespace std;

// This is the function that reads in the the future value and makes 
// sure user enters valid number
double readsinfutureValue(){
    double futureValue;
    do {
        cout << "Enter future value" << "\n"; // Asks user for future value

        cin >> futureValue; // User puts it in
        // In the case the user enters a invalid number this message is outputted asking for a number 
        // greater than zero for it to be valid
        if (futureValue <= 0){
            cout << "The future value must be greater than zero" << "\n";
        }
    } while (futureValue <= 0);
    return futureValue;
}

// This is the function that reads in the interest rate the user enters in
// and then sees if its valid by checking if its greater than zero
double readsininterestRate(){
    double interestRate;
    do {
      cout << "Enter annual interest rate" << "\n"; // Asks user to enter annual interest rate
      cin >> interestRate; // User puts it in
      // In the case the user enters a invalid number this message is outputted asking for a number 
      // greater than zero for it to be valid
      if (interestRate <= 0){ 
        cout << "The annual interest rate must be greater than zero" << "\n";

      } 
     
    } while (interestRate <= 0); // Repeats until valid input

    return interestRate / 100; // Interest rate percent to decimal
}

// This is the function that reads in and checks the number of years user input in
int readsinNumberofYears(){
    int Years;
    do {
        cout << "Enter number of years" << "\n"; // Asks user for number of years
        cin >> Years; // User inputs in
        // In the case the user enters a invalid number this message is outputted asking for a number 
        // greater than zero for it to be valid
        if (Years <= 0){
            cout << "The number of years must be greater than zero" << "\n";
        }
        
    } while (Years <= 0); // Repeats till valid
    return Years;
}

// This is the function that does the calculations for what amount of money the user needs now based on the future value,
// interest rate, and the number of years for his money to grow to a certain amount
double presentValue(double futureValue, double interestRate, int numberYears){

    return futureValue / pow(1 + interestRate, numberYears);
}


// Displays all information and formats
void DisplayOfResults(double presentValue, double futureValue, double interestRate, int Years){

    cout << fixed << setprecision(2);
    cout << "Present value: $" << presentValue << "\n";
    cout << "Future value: $" << futureValue << "\n";
    cout << "Annual interest rate: " << setprecision(3) << interestRate * 100 << "%" << "\n";
    cout << "Years: " << Years << "\n";
}

// main function
int main(){

    // Get the future value
    double futureValue = readsinfutureValue();
    
    // Gets the interest rate and converts to decimal
    double interestRate = readsininterestRate();

    // Gets the number of years
    int Years = readsinNumberofYears();

    // Present Value
    double pValue = presentValue(futureValue, interestRate, Years);

    // Displays all the final values
    DisplayOfResults(pValue, futureValue, interestRate, Years); 

    return 0; // End of program
}